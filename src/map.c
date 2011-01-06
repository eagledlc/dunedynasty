/* $Id$ */

#include <assert.h>
#include <stdio.h>
#include "types.h"
#include "libemu.h"
#include "global.h"
#include "gui/gui.h"
#include "house.h"
#include "map.h"
#include "os/math.h"
#include "pool/pool.h"
#include "pool/unit.h"
#include "structure.h"
#include "team.h"
#include "tools.h"
#include "tile.h"
#include "unit.h"
#include "unknown/unknown.h"

extern void emu_Structure_UpdateMap();
extern void f__10E4_0117_0015_392D();
extern void f__1423_0E4F_0010_843C();
extern void f__151A_000E_0013_5840();
extern void f__22A6_1200_007B_0356();
extern void f__24D0_000D_0039_C17D();
extern void f__2598_0000_0017_EB80();
extern void f__2B6C_0137_0020_C73F();
extern void f__2B6C_0169_001E_6939();
extern void f__B483_0000_0019_F96A();
extern void f__B4CD_057B_001A_D066();
extern void f__B4CD_0AFA_0011_D5DB();
extern void f__B4CD_1CDA_000C_C72C();
extern void overlay(uint16 cs, uint8 force);

uint16 *g_map = NULL;

/**
 * Initialize the map.
 *
 * @init System_Init_Map
 */
void System_Init_Map()
{
	g_map = (uint16 *)&emu_get_memory8(0x2E9C, 0x323F, 0x0);
}

Tile *Map_GetTileByPosition(uint16 position)
{
	return (Tile *)&emu_get_memory8(g_global->mapPointer.s.cs, g_global->mapPointer.s.ip, position * sizeof(Tile));
}

/**
 * Move the viewport position in the given direction.
 *
 * @param direction The direction to move in.
 * @return The new viewport position.
*/
uint16 Map_MoveDirection(uint16 direction)
{
	uint16 x, y;
	MapInfo *mapInfo;

	x = Tile_GetPackedX(g_global->minimapPosition) + g_global->mapScrollOffset[direction][0];
	y = Tile_GetPackedY(g_global->minimapPosition) + g_global->mapScrollOffset[direction][1];

	mapInfo = &g_global->mapInfo[g_global->scenario.mapScale];

	x = max(x, mapInfo->minX);
	y = max(y, mapInfo->minY);

	x = min(x, mapInfo->minX + mapInfo->sizeX - 15);
	y = min(y, mapInfo->minY + mapInfo->sizeY - 10);

	g_global->viewportPosition = Tile_PackXY(x, y);

	return g_global->viewportPosition;
}

/**
 * Sets the selection on given packed tile.
 *
 * @param packed The packed tile to set the selection on.
 */
void Map_SetSelection(uint16 packed)
{
	if (g_global->selectionType == 1) return;

	if (g_global->selectionType == 2) {
		g_global->variable_38EC = Structure_IsValidBuildLocation(packed, g_global->activeStructureType);
		g_global->selectionPosition = packed;
		return;
	}

	if (Map_GetTileByPosition(packed)->overlaySpriteID != g_global->variable_39F2 || g_global->debugScenario != 0) {
		Structure *s;

		s = Structure_Get_ByPackedTile(packed);
		if (s != NULL) {
			StructureInfo *si;

			si = &g_structureInfo[s->o.type];
			if (s->o.houseID == g_global->playerHouseID || g_global->selectionType != 0) {
				emu_push(si->spriteID);
				emu_push(si->variable_2B);
				emu_push(emu_cs); emu_push(0x038B); emu_cs = 0x10E4; f__10E4_0117_0015_392D();
				emu_sp += 4;
			}

			packed = Tile_PackTile(s->o.position);

			Map_SetSelectionSize(si->layout);

			emu_push(g_global->structureStartPos.s.cs); emu_push(g_global->structureStartPos.s.ip + s->o.index * sizeof(Structure));
			emu_push(emu_cs); emu_push(0x03CA); emu_cs = 0x0C3A; emu_Structure_UpdateMap();
			emu_sp += 4;
		} else {
			Map_SetSelectionSize(0);
		}

		if (g_global->selectionType != 1) {
			Unit *u;

			u = Unit_Get_ByPackedTile(packed);
			if (u != NULL) {
				if (u->o.type != UNIT_CARRYALL) {
					Unit_Select(u);
				}
			} else {
				if (g_global->selectionUnit.csip != 0x0) {
					Unit_Select(NULL);
				}
			}
		}
		g_global->selectionPosition = packed;
		return;
	}

	Map_SetSelectionSize(0);
	g_global->selectionPosition = packed;
	return;
}

/**
 * Sets the selection size for the given layout.
 *
 * @param layout The layout to determine selection size from.
 * @return The previous layout.
 */
uint16 Map_SetSelectionSize(uint16 layout)
{
	uint16 oldLayout;
	uint16 oldPosition;

	oldLayout = g_global->selectionObjectLayout;
	if (layout & 0x80) return oldLayout;

	oldPosition = Map_SetSelectionObjectPosition(0xFFFF);

	g_global->selectionObjectLayout = layout;
	g_global->selectionWidth        = g_global->layoutSize[layout][0];
	g_global->selectionHeight       = g_global->layoutSize[layout][1];

	Map_SetSelectionObjectPosition(oldPosition);

	return oldLayout;
}

static void Map_InvalidateSelection(uint16 packed, bool enable)
{
	uint16 x, y;

	if (packed == 0xFFFF) return;

	for (y = 0; y < g_global->selectionHeight; y++) {
		for (x = 0; x < g_global->selectionWidth; x++) {
			uint16 curPacked, value;
			uint8 *dest;

			curPacked = packed + Tile_PackXY(x, y);

			Map_Update(curPacked, 0, false);

			dest = &g_global->variable_95E5[curPacked >> 3];
			value = 1 << (curPacked & 0x7);

			if (enable) {
				*dest |= value;
			} else {
				*dest &= ~value;
			}
		}
	}
}

/**
 * Sets the selection object to the given position.
 *
 * @param packed The position to set.
 * @return The previous position.
 */
uint16 Map_SetSelectionObjectPosition(uint16 packed)
{
	uint16 oldPacked;

	oldPacked = g_global->selectionObjectPosition;

	if (packed == oldPacked) return oldPacked;

	Map_InvalidateSelection(oldPacked, false);

	if (packed != 0xFFFF) Map_InvalidateSelection(packed, true);

	g_global->selectionObjectPosition = packed;

	return oldPacked;
}

/**
 * Update the minimap position.
 *
 * @param packed The new position.
 * @param forceUpdate If true force the update even if the position didn't change.
 */
void Map_UpdateMinimapPosition(uint16 packed, bool forceUpdate)
{
	bool cleared;
	uint16 backup;

	if (packed != 0xFFFF && packed == g_global->minimapPreviousPosition && !forceUpdate) return;
	if (g_global->selectionType == 0) return;

	/* Change a value and store the old one. */
	emu_push(2);
	emu_push(emu_cs); emu_push(0x003D); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	emu_sp += 2;
	backup = emu_ax;

	cleared = false;

	if (g_global->minimapPreviousPosition != 0xFFFF && g_global->minimapPreviousPosition != packed) {
		uint16 *m;

		cleared = true;

		for (m = g_global->variable_3566; *m != 0xFFFF; m++) {
			uint16 curPacked;

			curPacked = g_global->minimapPreviousPosition + *m;
			g_global->variable_93E5[curPacked >> 3] &= ~(1 << (curPacked & 0x7));

			Unknown_07D4_1625(curPacked);
		}
	}

	if (packed != 0xFFFF && (packed != g_global->minimapPreviousPosition || forceUpdate)) {
		uint16 *m;
		uint16 mapScale;
		MapInfo *mapInfo;
		uint16 left, top, right, bottom;

		mapScale = g_global->scenario.mapScale;
		mapInfo = &g_global->mapInfo[mapScale];

		left   = (Tile_GetPackedX(packed) - mapInfo->minX) * (mapScale + 1) + 256;
		right  = left + mapScale * 15 + 14;
		top    = (Tile_GetPackedY(packed) - mapInfo->minY) * (mapScale + 1) + 136;
		bottom = top + mapScale * 10 + 9;

		GUI_DrawWiredRectangle(left, top, right, bottom, 15);

		for (m = g_global->variable_3566; *m != 0xFFFF; m++) {
			uint16 curPacked;

			curPacked = packed + *m;
			g_global->variable_93E5[curPacked >> 3] |= (1 << (curPacked & 0x7));
		}
	}

	if (cleared && backup == 0) {
		emu_push(emu_cs); emu_push(0x0175); emu_cs = 0x2B6C; f__2B6C_0137_0020_C73F();

		emu_push(0);
		emu_push(2);
		emu_push(64);
		emu_push(8);
		emu_push(136);
		emu_push(32);
		emu_push(136);
		emu_push(32);
		emu_push(emu_cs); emu_push(0x0199); emu_cs = 0x24D0; f__24D0_000D_0039_C17D();
		emu_sp += 16;

		emu_push(emu_cs); emu_push(0x01A1); emu_cs = 0x2B6C; f__2B6C_0169_001E_6939();
	}

	/* Restore the old value */
	emu_push(backup);
	emu_push(emu_cs); emu_push(0x01A9); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	emu_sp += 2;

	g_global->minimapPreviousPosition = packed;
}

/**
 * Checks if the given position is inside the map.
 *
 * @param position The tile (packed) to check.
 * @return True if the position is valid.
 */
bool Map_IsValidPosition(uint16 position)
{
	uint16 x, y;
	MapInfo *mapInfo;

	if ((position & 0xC000) != 0) return false;

	x = Tile_GetPackedX(position);
	y = Tile_GetPackedY(position);

	mapInfo = &g_global->mapInfo[g_global->scenario.mapScale];

	return (mapInfo->minX <= x && x < (mapInfo->minX + mapInfo->sizeX) && mapInfo->minY <= y && y < (mapInfo->minY + mapInfo->sizeY));
}

/**
 * Save all Tiles to a file.
 * @param fp The file to save to.
 * @return True if and only if all bytes were written successful.
 */
bool Map_Save(FILE *fp)
{
	uint16 i;

	for (i = 0; i < 0x1000; i++) {
		Tile *tile = Map_GetTileByPosition(i);

		/* If there is nothing on the tile, not unveiled, and it is equal to the mapseed generated tile, don't store it */
		if (!tile->isUnveiled && !tile->hasStructure && !tile->hasUnit && !tile->flag_08 && !tile->flag_10 && (g_map[i] & 0x8000) == 0 && g_map[i] == tile->groundSpriteID) continue;

		/* Store the index, then the tile itself */
		if (fwrite(&i, sizeof(uint16), 1, fp) != 1) return false;
		if (fwrite(tile, sizeof(Tile), 1, fp) != 1) return false;
	}

	return true;
}

/**
 * Load all Tiles from a file.
 * @param fp The file to load from.
 * @param length The length of the data chunk.
 * @return True if and only if all bytes were read successful.
 */
bool Map_Load(FILE *fp, uint32 length)
{
	uint16 i;

	for (i = 0; i < 0x1000; i++) {
		Tile *t = Map_GetTileByPosition(i);

		t->isUnveiled = false;
		t->overlaySpriteID = g_global->variable_39F2 & 0x7F;
	}

	while (length >= sizeof(uint16) + sizeof(Tile)) {
		Tile *t;

		length -= sizeof(uint16) + sizeof(Tile);

		if (fread(&i, sizeof(uint16), 1, fp) != 1) return false;
		if (i >= 0x1000) return false;

		t = Map_GetTileByPosition(i);
		if (fread(t, sizeof(Tile), 1, fp) != 1) return false;

		if (g_map[i] != t->groundSpriteID) {
			g_map[i] |= 0x8000;
		}
	}
	if (length != 0) return false;

	return true;
}

/**
 * Check if a position is unveiled (the fog is removed).
 *
 * @param position For which position to check.
 * @return True if and only if the position is unveiled.
 */
bool Map_IsPositionUnveiled(uint16 position)
{
	Tile *t;

	if (g_global->debugScenario) return true;

	t = Map_GetTileByPosition(position);

	if (!t->isUnveiled) return false;
	if (t->overlaySpriteID <= g_global->variable_39F2 && g_global->variable_39F2 <= t->overlaySpriteID + 15) return false;

	return true;
}

/**
 * Check if a position is in the viewport.
 *
 * @param position For which position to check.
 * @param retX Pointer to X inside the viewport.
 * @param retY Pointer to Y inside the viewport.
 * @return True if and only if the position is in the viewport.
 */
bool Map_IsPositionInViewport(tile32 position, uint16 *retX, uint16 *retY)
{
	int16 x, y;

	x = (position.s.x >> 4) - (Tile_GetPackedX(g_global->viewportPosition) << 4);
	y = (position.s.y >> 4) - (Tile_GetPackedY(g_global->viewportPosition) << 4);

	if (retX != NULL) *retX = x;
	if (retY != NULL) *retY = y;

	return x >= -16 && x <= 256 && y >= -16 && y <= 176;
}


static void Map_B4CD_04D9(uint16 arg06, struct_395A *s, csip32 csip)
{
	if (s == NULL) return;

	if (arg06 == 1 && s->variable_07 != 0) return;

	s->variable_07 = (arg06 != 0) ? 1 : 0;

	emu_push(g_global->variable_24AC[arg06].s.cs); emu_push(g_global->variable_24AC[arg06].s.ip);
	emu_push(csip.s.cs); emu_push(csip.s.ip);
	emu_push(s->position.s.y); emu_push(s->position.s.x);
	emu_push(24);
	emu_push(emu_cs); emu_push(0x0534); emu_cs = 0x34CD; overlay(0x34CD, 0); f__B4CD_057B_001A_D066();
	emu_sp += 14;
}

static bool Map_06F7_072B(struct_395A *s)
{
	uint16 packed;
	uint16 type;
	Tile *t;
	uint16 loc06;
	uint16 overlaySpriteID;
	uint16 *icon;

	packed = Tile_PackTile(s->position);

	if (!Map_IsPositionUnveiled(packed)) return false;

	type = Map_B4CD_0750(packed);

	if (type == 0xC || type == 0xD) return false;

	t = Map_GetTileByPosition(packed);

	if (type == 0xA) {
		t->groundSpriteID = g_map[packed] & 0x1FF;
		Map_Update(packed, 0, false);
	}

	loc06 = g_global->variable_329E[g_global->variable_3A3E[type][10]];

	if (loc06 == 0xFFFF) return false;

	overlaySpriteID = t->overlaySpriteID;

	if (g_global->variable_39F2 - 16 < overlaySpriteID && overlaySpriteID <= g_global->variable_39F2) return false;

	icon = (uint16 *)emu_get_memorycsip(g_global->iconMap);
	icon = &icon[icon[loc06]];
	if (icon[0] <= overlaySpriteID && overlaySpriteID <= icon[10]) {
		overlaySpriteID -= icon[0];
		if (overlaySpriteID < 4) overlaySpriteID += 2;
	} else {
		overlaySpriteID = Tools_Random_256() & 1;
	}

	emu_push(0xFFFF);
	emu_push(packed);
	emu_push(emu_cs); emu_push(0x0857); emu_cs = 0x34CD; overlay(0x34CD, 0); f__B4CD_0AFA_0011_D5DB();
	emu_sp += 4;

	if (t->groundSpriteID == g_global->variable_39F4) {
		Map_B4CD_14CA(packed, (uint8)g_global->playerHouseID);
		return false;
	}

	t->overlaySpriteID = (overlaySpriteID + icon[0]) & 0x7F;

	Map_Update(packed, 0, false);

	return true;
}

static bool Map_06F7_08BD(struct_395A *s, uint16 arg0A)
{
	emu_push(s->position.s.y); emu_push(s->position.s.x);
	emu_push(arg0A);
	emu_push(emu_cs); emu_push(0x08D3); emu_cs = 0x3483; overlay(0x3483, 0); f__B483_0000_0019_F96A();
	emu_sp += 6;

	return true;
}

static bool Map_06F7_08DD(struct_395A *s)
{
	if (!Map_IsPositionUnveiled(Tile_PackTile(s->position))) return true;

	assert(g_global->variable_66E0.csip == 0x22A61200);

	emu_push(1);
	emu_push(emu_cs); emu_push(0x090B); emu_cs = 0x22A6; f__22A6_1200_007B_0356();
	emu_sp += 2;

	return true;
}

static bool Map_06F7_0913(struct_395A *s)
{
	uint16 packed;

	packed = Tile_PackTile(s->position);

	if (Map_GetTileByPosition(packed)->groundSpriteID != g_global->variable_39F4) return true;

	Map_B4CD_14CA(packed, (uint8)g_global->playerHouseID);

	return false;
}

static bool Map_06F7_0967(struct_395A *s, uint16 arg0A)
{
	uint16 packed;

	packed = Tile_PackTile(s->position);

	if (Structure_Get_ByPackedTile(packed) != NULL) return true;

	emu_push(3);
	emu_push(s->houseID);
	emu_push(0);
	emu_push(s->position.s.y); emu_push(s->position.s.x);
	emu_push(0x33C8); emu_push(((arg0A + (Tools_Random_256() & 0x1) + (g_global->variable_3A3E[Map_B4CD_0750(packed)][7] != 0 ? 0 : 2)) << 4) + 256);
	emu_push(emu_cs); emu_push(0x09E5); emu_cs = 0x151A; f__151A_000E_0013_5840();
	emu_sp += 14;

	return true;
}

static bool Map_06F7_09F4(struct_395A *s, uint16 arg0A)
{
	if ((arg0A & 0x800) != 0) arg0A |= 0xF000;
	s->position.s.x = arg0A;
	s->position.s.y = 0;
	return true;
}

static bool Map_06F7_0A27(struct_395A *s, uint16 arg0A)
{
	if ((arg0A & 0x800) != 0) arg0A |= 0xF000;
	s->position.s.x = 0;
	s->position.s.y = arg0A;
	return true;
}

static bool Map_06F7_0A5A(struct_395A *s)
{
	s->variable_09 = 0;
	return true;
}

static bool Map_06F7_0A6C(struct_395A *s, csip32 csip)
{
	Map_GetTileByPosition(Tile_PackTile(s->position))->flag_10 = false;

	Map_B4CD_04D9(0, s, csip);

	s->variable_0C.csip = 0x0;

	return false;
}

static bool Map_06F7_0AC1(struct_395A *s, uint16 arg0A)
{
	s->variable_00 = g_global->variable_76AC + arg0A;
	return true;
}

static bool Map_06F7_0AE2(struct_395A *s, uint16 arg0A)
{
	s->variable_00 = g_global->variable_76AC + Tools_RandomRange(0, arg0A);
	return true;
}

static bool Map_06F7_0B14(struct_395A *s, uint16 arg0A, csip32 csip)
{
	s->variable_0A = arg0A;
	s->variable_08 = 0;

	Map_B4CD_04D9(2, s, csip);

	return true;
}

static bool Map_06F7_0B42(struct_395A *s, uint16 arg0A, csip32 csip)
{
	s->variable_0A = arg0A;
	s->variable_08 = 1;

	Map_B4CD_04D9(2, s, csip);

	return true;
}

/**
 * ??.
 *
 * @param packed A packed position.
 * @return True if and only if something happened.
 */
static bool Map_06F7_057C(uint16 packed)
{
	Tile *t;
	uint8 i;

	t = Map_GetTileByPosition(packed);

	if (!t->flag_10) return false;

	for (i = 0; i < 32; i++) {
		struct_395A s;
		csip32 csip;

		s = ((struct_395A *)emu_get_memorycsip(g_global->variable_395A))[i];

		/* Temporary */
		csip       = g_global->variable_395A;
		csip.s.ip += i * sizeof(struct_395A);

		if (s.variable_0C.csip == 0x0 || Tile_PackTile(s.position) != packed) continue;

		Map_06F7_0A6C(&s, csip);
	}

	return true;
}

/**
 * Init ??.
 *
 * @param csip The CSIP to use for init.
 * @param position The position to use for init.
 * @return True if and only if an init happened.
 */
static bool Map_06F7_0493(csip32 csip, tile32 position)
{
	uint16 packed;
	uint8 i;

	if (csip.csip == 0x0) return false;

	packed = Tile_PackTile(position);

	Map_06F7_057C(packed);

	for (i = 0; i < 32; i++) {
		struct_395A s;

		s = ((struct_395A *)emu_get_memorycsip(g_global->variable_395A))[i];

		if (s.variable_0C.csip != 0x0) continue;

		s.variable_04 = i;
		s.variable_0C = csip;
		s.variable_09 = 0;
		s.variable_0A = 0;
		s.position    = position;
		s.variable_07 = 0;
		s.variable_00 = g_global->variable_76AC;
		g_global->variable_320E = 0;
		Map_GetTileByPosition(packed)->flag_10 = true;
		return true;
	}

	return false;
}

/**
 * Make an explosion on the given position, of a certain type. All units in the
 *  neighbourhoud get an amount of damage related to their distance to the
 *  explosion.
 * @param type The type of explosion.
 * @param position The position of the explosion.
 * @param hitpoints The amount of hitpoints to give people in the neighbourhoud.
 * @param unitOriginEncoded The unit that fired the bullet.
 */
void Map_MakeExplosion(uint16 type, tile32 position, uint16 hitpoints, uint16 unitOriginEncoded)
{
	uint16 reactionDistance = (type == 11) ? 32 : 16;
	uint16 positionPacked = Tile_PackTile(position);

	if (g_global->debugNoExplosionDamage == 0 && hitpoints != 0) {
		PoolFindStruct find;
		find.houseID = 0xFFFF;
		find.index   = 0xFFFF;
		find.type    = 0xFFFF;

		while (true) {
			uint16 distance;
			Team *t;
			UnitInfo *ui;
			Unit *u;
			Unit *us;
			Unit *attack;

			u = Unit_Find(&find);
			if (u == NULL) break;

			ui = &g_unitInfo[u->o.type];

			distance = Tile_GetDistance(position, u->o.position) >> 4;
			if (distance >= reactionDistance) continue;

			if (!(u->o.type == UNIT_SANDWORM && type == 13) && u->o.type != UNIT_FRIGATE) {
				Unit_Damage(u, hitpoints >> (distance >> 2), 0);
			}

			if (u->o.houseID == g_global->playerHouseID) continue;

			us = Tools_Index_GetUnit(unitOriginEncoded);
			if (us == NULL) continue;
			if (us == u) continue;
			if (House_AreAllied(Unit_GetHouseID(u), Unit_GetHouseID(us))) continue;

			t = Unit_GetTeam(u);
			if (t != NULL) {
				UnitInfo *targetInfo;
				Unit *target;

				if (t->variable_0C == 1) {
					Unit_RemoveFromTeam(u);
					Unit_SetAction(u, ACTION_HUNT);
					continue;
				}

				target = Tools_Index_GetUnit(t->target);
				if (target == NULL) continue;

				targetInfo = &g_unitInfo[target->o.type];
				if (targetInfo->bulletType == 0xFFFF) t->target = unitOriginEncoded;
				continue;
			}

			if (u->o.type == UNIT_HARVESTER) {
				UnitInfo *uis = &g_unitInfo[us->o.type];

				if (uis->movementType == MOVEMENT_FOOT && u->targetMove == 0) {
					if (u->actionID != ACTION_MOVE) Unit_SetAction(u, ACTION_MOVE);
					u->targetMove = unitOriginEncoded;
					continue;
				}
			}

			if (ui->bulletType == 0xFFFF) continue;

			if (u->actionID == ACTION_GUARD && u->o.flags.s.byScenario) {
				Unit_SetAction(u, ACTION_HUNT);
			}

			if (u->targetAttack != 0 && u->actionID != ACTION_HUNT) continue;

			attack = Tools_Index_GetUnit(u->targetAttack);
			if (attack != NULL) {
				uint16 packed = Tile_PackTile(u->o.position);
				if (Tile_GetDistancePacked(Tools_Index_GetPackedTile(u->targetAttack), packed) <= ui->variable_50) continue;
			}

			Unit_SetTarget(u, unitOriginEncoded);
		}
	}

	if (g_global->debugNoExplosionDamage == 0 && hitpoints != 0) {
		Structure *s = Structure_Get_ByPackedTile(positionPacked);

		if (s != NULL) {
			if (type == 2) {
				StructureInfo *si = &g_structureInfo[s->o.type];

				if ((si->variable_1A >> 1) > s->o.hitpoints) {
					type = 15;
				}
			}

			emu_push(s->o.houseID);
			emu_push(emu_cs); emu_push(0x0367); emu_cs = 0x1423; f__1423_0E4F_0010_843C();
			emu_sp += 2;

			Structure_Damage(s, hitpoints, 0);
		}
	}

	if (Map_B4CD_0750(positionPacked) == 11 && hitpoints != 0) {
		uint16 loc22;

		loc22 = 0;
		if (g_structureInfo[STRUCTURE_TURRET].hitpoints <= hitpoints) {
			loc22 = 1;
		}

		if (loc22 == 0) {
			uint16 loc24 = hitpoints * 256 / g_structureInfo[STRUCTURE_TURRET].hitpoints;

			if (Tools_Random_256() <= loc24) {
				loc22 = 1;
			}
		}

		if (loc22 != 0) {
			emu_push(positionPacked);
			emu_push(emu_cs); emu_push(0x03DF); emu_cs = 0x34CD; overlay(0x34CD, 0); f__B4CD_1CDA_000C_C72C();
			emu_sp += 2;
		}
	}

	Map_06F7_0493(g_global->variable_3212[type], position);
}

/**
 * Get ??
 *
 * @param packed The packed tile to get ??
 * @return ??
 */
uint16 Map_B4CD_0750(uint16 packed)
{
	Tile *t;
	int16 locsi;

	t = Map_GetTileByPosition(packed);

	if (t->groundSpriteID == g_global->variable_39F8) return 10;

	if (t->groundSpriteID == g_global->variable_39F4 || t->groundSpriteID == g_global->variable_39F4 + 1) return 14;

	if (t->groundSpriteID > g_global->variable_39FA && t->groundSpriteID < (uint16)(g_global->variable_39FA + 75)) return 11;

	if (t->overlaySpriteID == g_global->variable_39FA) return 13;

	if (Structure_Get_ByPackedTile(packed) != NULL) return 12;

	locsi = t->groundSpriteID - g_global->variable_39F6;
	if (locsi < 0 || locsi > 82) return 4;

	return g_global->variable_24B8[locsi];
}

/**
 * Checks wether a packed tile is visible in the viewport.
 *
 * @param packed The packed tile.
 * @return True if the tile is visible.
 */
static bool Map_IsTileVisible(uint16 packed)
{
	uint8 x, y;
	uint8 x2, y2;

	x = Tile_GetPackedX(packed);
	y = Tile_GetPackedY(packed);
	x2 = Tile_GetPackedX(g_global->minimapPosition);
	y2 = Tile_GetPackedY(g_global->minimapPosition);

	return x >= x2 && x < x2 + 15 && y >= y2 && y < y2 + 10;
}

/**
 * Updates ??.
 *
 * @param packed The packed tile.
 * @param type The type of update.
 * @param ignoreInvisible Wether to ignore tile visibility check.
 */
void Map_Update(uint16 packed, uint16 type, bool ignoreInvisible)
{
	if (!ignoreInvisible && !Map_IsTileVisible(packed)) return;

	switch (type) {
		default:
		case 0: {
			uint8 i;
			uint16 curPacked;
			uint8 v;

			if ((g_global->variable_8DE5[packed >> 3] & (1 << (packed & 7))) != 0) return;

			g_global->variable_39E2++;

			for (i = 0; i < 9; i++) {
				curPacked = (packed + g_global->variable_2462[i]) & 0xFFF;
				v = (1 << (curPacked & 7));
				g_global->variable_8FE5[curPacked >> 3] |= v;
				g_global->variable_3A08 |= g_global->variable_95E5[curPacked >> 3] & v;
			}

			g_global->variable_8DE5[curPacked >> 3] |= v;
			return;
		}

		case 1:
		case 2:
		case 3:
			g_global->variable_8FE5[packed >> 3] |= (1 << (packed & 7));
			return;
	}
}

/**
 * Make a deviator missile explosion on the given position, of a certain type. All units in the
 *  given radius may become deviated.
 * @param type The type of explosion.
 * @param position The position of the explosion.
 * @param radius The radius.
 */
void Map_DeviateArea(uint16 type, tile32 position, uint16 radius)
{
	PoolFindStruct find;

	Map_06F7_0493(g_global->variable_3212[type], position);


	find.type    = 0xFFFF;
	find.index   = 0xFFFF;
	find.houseID = 0xFFFF;

	while (true) {
		Unit *u;

		u = Unit_Find(&find);

		if (u == NULL) break;
		if (Tile_GetDistance(position, u->o.position) / 16 >= radius) continue;

		Unit_Deviate(u, 0);
	}
}

/**
 * ??.
 *
 * @return g_global->variable_320E.
 */
uint32 Map_06F7_0602()
{
	uint8 i;

	if (g_global->variable_320E > g_global->variable_76AC) return g_global->variable_320E;

	g_global->variable_320E += 10000;

	for (i = 0; i < 32; i++) {
		struct_395A s;
		csip32 csip;

		s = ((struct_395A *)emu_get_memorycsip(g_global->variable_395A))[i];

		/* Temporary */
		csip       = g_global->variable_395A;
		csip.s.ip += i * sizeof(struct_395A);

		if (s.variable_0C.csip == 0x0) continue;

		if (s.variable_00 <= g_global->variable_76AC) {
			uint16 data;
			uint16 action;

			data = ((uint16 *)emu_get_memorycsip(s.variable_0C))[s.variable_09++];
			action = min((data >> 12) & 0xF, 0xE);
			data &= 0xFFF;

			switch(action) {
				case  1: Map_06F7_0B14(&s, data, csip); break;
				case  2: Map_06F7_0AC1(&s, data); break;
				case  3: Map_06F7_0AE2(&s, data); break;
				case  4: Map_06F7_0B42(&s, data, csip); break;
				case  5: Map_06F7_0A5A(&s); break;
				case  6: Map_06F7_09F4(&s, data); break;
				case  7: Map_06F7_0A27(&s, data); break;
				case  8: Map_06F7_072B(&s); break;
				case  9: Map_06F7_08BD(&s, data); break;
				case 10: Map_06F7_08DD(&s); break;
				case 11: Map_06F7_0967(&s, data); break;
				case 13: Map_06F7_0913(&s); break;
				default: Map_06F7_0A6C(&s, csip); break;
			}
		}

		if (s.variable_0C.csip == 0x0 || s.variable_00 > g_global->variable_320E) continue;

		g_global->variable_320E = s.variable_00;
	}

	return g_global->variable_320E;
}

void Map_B4CD_14CA(uint16 packed, uint8 houseID)
{
	if (g_global->variable_38BC == 0) {
		Unit_Unknown10EC(Unit_Get_ByPackedTile(packed));
		Map_GetTileByPosition(packed)->groundSpriteID = g_map[packed] & 0x1FF;
		Map_MakeExplosion(0x13, Tile_UnpackTile(packed), 0, 0);
	}

	if (houseID == g_global->playerHouseID) {
		emu_push(36);
		emu_push(emu_cs); emu_push(0x153C); emu_cs = 0x3483; overlay(0x3483, 0); emu_Unknown_B483_0363();
		emu_sp += 2;
	}

	Map_B4CD_154C(packed, 5);
}

void Map_B4CD_154C(uint16 packed, uint16 radius)
{
	uint16 x;
	uint16 y;
	int i;
	int j;

	if (radius == 0) return;

	x = Tile_GetPackedX(packed);
	y = Tile_GetPackedY(packed);

	for (i = -radius; i <= radius; i++) {
		for (j = -radius; j <= radius; j++) {
			uint16 curPacked = Tile_PackXY(x + j, y + i);
			uint16 distance  = Tile_GetDistancePacked(packed, curPacked);

			if (distance > radius) continue;

			if (distance == radius && (Tools_Random_256() & 1) == 0) continue;

			if (Map_B4CD_0750(curPacked) == 0x8) continue;

			emu_push(1);
			emu_push(curPacked);
			emu_push(emu_cs); emu_push(0x15D9); emu_cs = 0x34CD; overlay(0x34CD, 0); f__B4CD_0AFA_0011_D5DB();
			emu_sp += 4;

			if (g_global->debugScenario == 0) continue;

			emu_push(curPacked);
			emu_push(emu_cs); emu_push(0x15EA); emu_cs = 0x07D4; emu_Unknown_07D4_02F8();
			emu_sp += 2;
		}
	}

	emu_push(1);
	emu_push(packed);
	emu_push(emu_cs); emu_push(0x1604); emu_cs = 0x34CD; overlay(0x34CD, 0); f__B4CD_0AFA_0011_D5DB();
	emu_sp += 4;
}
