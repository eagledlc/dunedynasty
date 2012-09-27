#ifndef ENUMERATION_H
#define ENUMERATION_H

enum HouseType {
	HOUSE_HARKONNEN = 0,
	HOUSE_ATREIDES  = 1,
	HOUSE_ORDOS     = 2,
	HOUSE_FREMEN    = 3,
	HOUSE_SARDAUKAR = 4,
	HOUSE_MERCENARY = 5,

	HOUSE_MAX       = 6,
	HOUSE_INVALID   = 0xFF
};

enum HouseFlag {
	FLAG_HOUSE_HARKONNEN    = 1 << HOUSE_HARKONNEN, /* 0x01 */
	FLAG_HOUSE_ATREIDES     = 1 << HOUSE_ATREIDES,  /* 0x02 */
	FLAG_HOUSE_ORDOS        = 1 << HOUSE_ORDOS,     /* 0x04 */
	FLAG_HOUSE_FREMEN       = 1 << HOUSE_FREMEN,    /* 0x08 */
	FLAG_HOUSE_SARDAUKAR    = 1 << HOUSE_SARDAUKAR, /* 0x10 */
	FLAG_HOUSE_MERCENARY    = 1 << HOUSE_MERCENARY  /* 0x20 */
};

enum StructureType {
	STRUCTURE_SLAB_1x1          = 0,
	STRUCTURE_SLAB_2x2          = 1,
	STRUCTURE_PALACE            = 2,
	STRUCTURE_LIGHT_VEHICLE     = 3,
	STRUCTURE_HEAVY_VEHICLE     = 4,
	STRUCTURE_HIGH_TECH         = 5,
	STRUCTURE_HOUSE_OF_IX       = 6,
	STRUCTURE_WOR_TROOPER       = 7,
	STRUCTURE_CONSTRUCTION_YARD = 8,
	STRUCTURE_WINDTRAP          = 9,
	STRUCTURE_BARRACKS          = 10,
	STRUCTURE_STARPORT          = 11,
	STRUCTURE_REFINERY          = 12,
	STRUCTURE_REPAIR            = 13,
	STRUCTURE_WALL              = 14,
	STRUCTURE_TURRET            = 15,
	STRUCTURE_ROCKET_TURRET     = 16,
	STRUCTURE_SILO              = 17,
	STRUCTURE_OUTPOST           = 18,

	STRUCTURE_MAX       = 19,
	STRUCTURE_INVALID   = 0xFF
};

enum StructureFlag {
	FLAG_STRUCTURE_SLAB_1x1             = 1 << STRUCTURE_SLAB_1x1,          /* 0x____01 */
	FLAG_STRUCTURE_SLAB_2x2             = 1 << STRUCTURE_SLAB_2x2,          /* 0x____02 */
	FLAG_STRUCTURE_PALACE               = 1 << STRUCTURE_PALACE,            /* 0x____04 */
	FLAG_STRUCTURE_LIGHT_VEHICLE        = 1 << STRUCTURE_LIGHT_VEHICLE,     /* 0x____08 */
	FLAG_STRUCTURE_HEAVY_VEHICLE        = 1 << STRUCTURE_HEAVY_VEHICLE,     /* 0x____10 */
	FLAG_STRUCTURE_HIGH_TECH            = 1 << STRUCTURE_HIGH_TECH,         /* 0x____20 */
	FLAG_STRUCTURE_HOUSE_OF_IX          = 1 << STRUCTURE_HOUSE_OF_IX,       /* 0x____40 */
	FLAG_STRUCTURE_WOR_TROOPER          = 1 << STRUCTURE_WOR_TROOPER,       /* 0x____80 */
	FLAG_STRUCTURE_CONSTRUCTION_YARD    = 1 << STRUCTURE_CONSTRUCTION_YARD, /* 0x__01__ */
	FLAG_STRUCTURE_WINDTRAP             = 1 << STRUCTURE_WINDTRAP,          /* 0x__02__ */
	FLAG_STRUCTURE_BARRACKS             = 1 << STRUCTURE_BARRACKS,          /* 0x__04__ */
	FLAG_STRUCTURE_STARPORT             = 1 << STRUCTURE_STARPORT,          /* 0x__08__ */
	FLAG_STRUCTURE_REFINERY             = 1 << STRUCTURE_REFINERY,          /* 0x__10__ */
	FLAG_STRUCTURE_REPAIR               = 1 << STRUCTURE_REPAIR,            /* 0x__20__ */
	FLAG_STRUCTURE_WALL                 = 1 << STRUCTURE_WALL,              /* 0x__40__ */
	FLAG_STRUCTURE_TURRET               = 1 << STRUCTURE_TURRET,            /* 0x__80__ */
	FLAG_STRUCTURE_ROCKET_TURRET        = 1 << STRUCTURE_ROCKET_TURRET,     /* 0x01____ */
	FLAG_STRUCTURE_SILO                 = 1 << STRUCTURE_SILO,              /* 0x02____ */
	FLAG_STRUCTURE_OUTPOST              = 1 << STRUCTURE_OUTPOST            /* 0x04____ */
};

#endif
