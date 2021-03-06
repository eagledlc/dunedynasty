/** @file include/enum_unit.h */

#ifndef ENUM_UNIT_H
#define ENUM_UNIT_H

enum UnitType {
	UNIT_CARRYALL           = 0,
	UNIT_ORNITHOPTER        = 1,
	UNIT_INFANTRY           = 2,
	UNIT_TROOPERS           = 3,
	UNIT_SOLDIER            = 4,
	UNIT_TROOPER            = 5,
	UNIT_SABOTEUR           = 6,
	UNIT_LAUNCHER           = 7,
	UNIT_DEVIATOR           = 8,
	UNIT_TANK               = 9,
	UNIT_SIEGE_TANK         = 10,
	UNIT_DEVASTATOR         = 11,
	UNIT_SONIC_TANK         = 12,
	UNIT_TRIKE              = 13,
	UNIT_RAIDER_TRIKE       = 14,
	UNIT_QUAD               = 15,
	UNIT_HARVESTER          = 16,
	UNIT_MCV                = 17,
	UNIT_MISSILE_HOUSE      = 18,
	UNIT_MISSILE_ROCKET     = 19,
	UNIT_MISSILE_TURRET     = 20,
	UNIT_MISSILE_DEVIATOR   = 21,
	UNIT_MISSILE_TROOPER    = 22,
	UNIT_BULLET             = 23,
	UNIT_SONIC_BLAST        = 24,
	UNIT_SANDWORM           = 25,
	UNIT_FRIGATE            = 26,

	UNIT_MAX                = 27,
	UNIT_INVALID            = 0xFF
};

enum UnitFlag {
	FLAG_UNIT_CARRYALL          = 1 << UNIT_CARRYALL,           /* 0x______01 */
	FLAG_UNIT_ORNITHOPTER       = 1 << UNIT_ORNITHOPTER,        /* 0x______02 */
	FLAG_UNIT_INFANTRY          = 1 << UNIT_INFANTRY,           /* 0x______04 */
	FLAG_UNIT_TROOPERS          = 1 << UNIT_TROOPERS,           /* 0x______08 */
	FLAG_UNIT_SOLDIER           = 1 << UNIT_SOLDIER,            /* 0x______10 */
	FLAG_UNIT_TROOPER           = 1 << UNIT_TROOPER,            /* 0x______20 */
	FLAG_UNIT_SABOTEUR          = 1 << UNIT_SABOTEUR,           /* 0x______40 */
	FLAG_UNIT_LAUNCHER          = 1 << UNIT_LAUNCHER,           /* 0x______80 */
	FLAG_UNIT_DEVIATOR          = 1 << UNIT_DEVIATOR,           /* 0x____01__ */
	FLAG_UNIT_TANK              = 1 << UNIT_TANK,               /* 0x____02__ */
	FLAG_UNIT_SIEGE_TANK        = 1 << UNIT_SIEGE_TANK,         /* 0x____04__ */
	FLAG_UNIT_DEVASTATOR        = 1 << UNIT_DEVASTATOR,         /* 0x____08__ */
	FLAG_UNIT_SONIC_TANK        = 1 << UNIT_SONIC_TANK,         /* 0x____10__ */
	FLAG_UNIT_TRIKE             = 1 << UNIT_TRIKE,              /* 0x____20__ */
	FLAG_UNIT_RAIDER_TRIKE      = 1 << UNIT_RAIDER_TRIKE,       /* 0x____40__ */
	FLAG_UNIT_QUAD              = 1 << UNIT_QUAD,               /* 0x____80__ */
	FLAG_UNIT_HARVESTER         = 1 << UNIT_HARVESTER,          /* 0x__01____ */
	FLAG_UNIT_MCV               = 1 << UNIT_MCV,                /* 0x__02____ */
	FLAG_UNIT_MISSILE_HOUSE     = 1 << UNIT_MISSILE_HOUSE,      /* 0x__04____ */
	FLAG_UNIT_MISSILE_ROCKET    = 1 << UNIT_MISSILE_ROCKET,     /* 0x__08____ */
	FLAG_UNIT_MISSILE_TURRET    = 1 << UNIT_MISSILE_TURRET,     /* 0x__10____ */
	FLAG_UNIT_MISSILE_DEVIATOR  = 1 << UNIT_MISSILE_DEVIATOR,   /* 0x__20____ */
	FLAG_UNIT_MISSILE_TROOPER   = 1 << UNIT_MISSILE_TROOPER,    /* 0x__40____ */
	FLAG_UNIT_BULLET            = 1 << UNIT_BULLET,             /* 0x__80____ */
	FLAG_UNIT_SONIC_BLAST       = 1 << UNIT_SONIC_BLAST,        /* 0x01______ */
	FLAG_UNIT_SANDWORM          = 1 << UNIT_SANDWORM,           /* 0x02______ */
	FLAG_UNIT_FRIGATE           = 1 << UNIT_FRIGATE,            /* 0x04______ */

	FLAG_UNIT_NONE              = 0
};

enum UnitActionType {
	ACTION_ATTACK       = 0,
	ACTION_MOVE         = 1,
	ACTION_RETREAT      = 2,
	ACTION_GUARD        = 3,
	ACTION_AREA_GUARD   = 4,
	ACTION_HARVEST      = 5,
	ACTION_RETURN       = 6,
	ACTION_STOP         = 7,
	ACTION_AMBUSH       = 8,
	ACTION_SABOTAGE     = 9,
	ACTION_DIE          = 10,
	ACTION_HUNT         = 11,
	ACTION_DEPLOY       = 12,
	ACTION_DESTRUCT     = 13,

	ACTION_MAX      = 14,
	ACTION_CANCEL   = 15,
	ACTION_INVALID  = 0xFF
};

enum UnitDisplayMode {
	DISPLAYMODE_SINGLE_FRAME        = 0,
	DISPLAYMODE_UNIT                = 1, /* Ground: N,NE,E,SE,S.  Air: N,NE,E. */
	DISPLAYMODE_ROCKET              = 2, /* N,NNE,NE,ENE,E. */
	DISPLAYMODE_INFANTRY_3_FRAMES   = 3, /* N,E,S; 3 frames per direction. */
	DISPLAYMODE_INFANTRY_4_FRAMES   = 4, /* N,E,S; 4 frames per direction. */
	DISPLAYMODE_ORNITHOPTER         = 5, /* N,NE,E; 3 frames per direction. */
};

enum UnitMovementType {
	MOVEMENT_FOOT       = 0,
	MOVEMENT_TRACKED    = 1,
	MOVEMENT_HARVESTER  = 2,
	MOVEMENT_WHEELED    = 3,
	MOVEMENT_WINGER     = 4,
	MOVEMENT_SLITHER    = 5,

	MOVEMENT_MAX        = 6,
	MOVEMENT_INVALID    = 0xFF
};

#endif
