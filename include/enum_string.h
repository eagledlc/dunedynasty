#ifndef ENUM_STRING_H
#define ENUM_STRING_H

enum StringID {
	STR_NULL = 0,
	STR_ATTACK = 1,
	STR_MOVE = 2,
	STR_RETREAT = 3,
	STR_GUARD = 4,
	STR_AREA_GUARD = 5,
	STR_HARVEST = 6,
	STR_RETURN = 7,
	STR_STOP = 8,
	STR_AMBUSH = 9,
	STR_SABOTAGE = 10,
	STR_DIE = 11,
	STR_HUNT = 12,
	STR_TARGET = 13,
	STR_MOVEMENT = 14,
	STR_INITIALIZING_THE_MT32 = 15,
	STR_OLD_SAVE_GAME_FILE_IS_INCOMPATIBLE_WITH_LATEST_VERSION = 16,
	STR_INSUFFICIENT_MEMORY_BY_LD_BYTES = 17,
	STR_THE_SETUP_PROGRAM_MUST_BE_RUN_FIRST = 18,
	STR_S_S_DESTROYED = 19,
	STR_UNIT_IS_UNABLE_TO_DEPLOY_HERE = 20,
	STR_SCORE_D = 21,
	STR_TIME_DH_DM = 22,
	STR_YOU_HAVE_ATTAINED_THE_RANK_OF = 23,
	STR_UNITS_DESTROYED_BY = 24,
	STR_BUILDINGS_DESTROYED_BY = 25,
	STR_SPICE_HARVESTED_BY = 26,
	STR_PLAY_A_GAME = 27,
	STR_REPLAY_INTRODUCTION = 28,
	STR_EXIT_GAME = 29,
	STR_CANCEL = 30,
	STR_DEPLOY = 31,
	STR_LOAD = 32,
	STR_NEXT = 33,
	STR_REPAIR = 34,
	STR_REPAIRING = 35,
	STR_SAVE = 36,
	STR_STOP2 = 37,
	STR_PLACE_IT = 38,
	STR_COMPLETED = 39,
	STR_ON_HOLD = 40,
	STR_BUILD_IT = 41,
	STR_LAUNCH = 42,
	STR_FREMEN = 43,
	STR_SABOTEUR = 44,
	STR_PRESPICE_MOUND = 45,
	STR_D_DONE = 46,
	STR_MENTAT_BRIEFING = 47,
	STR_SELECT_SUBJECT = 48,
	STR_DMG = 49,
	STR_HARVESTER_IS_HEADING_TO_REFINERY = 50,
	STR_CONSTRUCTION_COMPLETE = 51,

	STR_ENEMY_UNIT_APPROACHING  = 52,
	STR_HARKONNEN_APPROACHING   = 53,
	STR_ATREIDES_APPROACHING    = 54,
	STR_ORDOS_APPROACHING       = 55,
	STR_FREMEN_APPROACHING      = 56,
	STR_SARDAUKAR_APPROACHING   = 57,
	STR_MERCENARY_APPROACHING   = 58,
	STR_SABOTEUR_APPROACHING    = 59,

	STR_HARKONNEN_UNIT_DESTROYED    = 60,
	STR_ATREIDES_UNIT_DESTROYED     = 61,
	STR_ORDOS_UNIT_DESTROYED        = 62,
	STR_FREMEN_UNIT_DESTROYED       = 63,
	STR_SARDAUKAR_UNIT_DESTROYED    = 64,
	STR_MERCENARY_UNIT_DESTROYED    = 65,

	STR_HARKONNEN_STRUCTURE_DESTROYED   = 66,
	STR_ATREIDES_STRUCTURE_DESTROYED    = 67,
	STR_ORDOS_STRUCTURE_DESTROYED       = 68,
	STR_FREMEN_STRUCTURE_DESTROYED      = 69,
	STR_SARDAUKAR_STRUCTURE_DESTROYED   = 70,
	STR_MERCENARY_STRUCTURE_DESTROYED   = 71,

	STR_HARKONNEN_UNIT_DEPLOYED = 72,
	STR_ATREIDES_UNIT_DEPLOYED  = 73,
	STR_ORDOS_UNIT_DEPLOYED     = 74,
	STR_FREMEN_UNIT_DEPLOYED    = 75,
	STR_SARDAUKAR_UNIT_DEPLOYED = 76,
	STR_MERCENARY_UNIT_DEPLOYED = 77,

	STR_WORMSIGN = 78,
	STR_SABOTEUR_APPROACHING2 = 79,
	STR_FRIGATE_ARRIVED = 80,
	STR_MISSILE_APPROACHING = 81,
	STR_YOU_HAVE_SUCCESSFULLY_COMPLETED_YOUR_MISSION = 82,
	STR_YOU_HAVE_FAILED_YOUR_MISSION = 83,
	STR_SELECTLOCATION_TOBUILD = 84,
	STR_PICK_TARGETTMINUS_D = 85,
	STR_SELECTTARGET = 86,
	STR_SELECTDESTINATION = 87,
	STR_SPICEHOLDS_4DMAX_4D = 88,
	STR_POWER_INFONEEDEDOUTPUT = 89,
	STR_BASE_IS_UNDER_ATTACK = 90,
	STR_DUNE_II_THE_BATTLE_FOR_ARRAKIS = 91,
	STR_LOAD_A_GAME = 92,
	STR_SAVE_THIS_GAME = 93,
	STR_GAME_CONTROLS = 94,
	STR_QUIT_PLAYING = 95,
	STR_CONTINUE_GAME = 96,
	STR_SELECT_A_SAVED_GAME_TO_LOAD = 97,
	STR_SELECT_A_POSITION_TO_SAVE_TO = 98,
	STR_EMPTY_SLOT_ = 99,
	STR_ENTER_A_DESCRIPTION_OF_YOUR_SAVED_GAME = 100,
	STR_ARE_YOU_SURE_YOU_WANT_TO_QUIT_PLAYING = 101,
	STR_PREVIOUS = 102,
	STR_RESTART_SCENARIO = 103,
	STR_PICK_ANOTHER_HOUSE = 104,
	STR_ON = 105,
	STR_OFF = 106,
	STR_YES = 107,
	STR_NO = 108,
	STR_HINTS_ARE = 109,
	STR_GAME_SPEED = 110,
	STR_MUSIC_IS = 111,
	STR_SOUNDS_ARE = 112,
	STR_SLOWEST = 113,
	STR_SLOW = 114,
	STR_NORMAL = 115,
	STR_FAST = 116,
	STR_FASTEST = 117,
	STR_ARE_YOU_SURE_YOU_WISH_TO_RESTART = 118,
	STR_ARE_YOU_SURE_YOU_WISH_TO_PICK_A_NEW_HOUSE = 119,
	STR_AUTO_SCROLL_IS = 120,
	STR_IS_D_PERCENT_FULL = 121,
	STR_IS_D_PERCENT_FULL_AND_HARVESTING = 122,
	STR_IS_D_PERCENT_FULL_AND_HEADING_BACK = 123,
	STR_IS_D_PERCENT_FULL_AND_AWAITING_PICKUP = 124,
	STR_IS_EMPTY = 125,
	STR_IS_EMPTY_AND_HARVESTING = 126,
	STR_IS_EMPTY_AND_HEADING_BACK = 127,
	STR_IS_EMPTY_AND_AWAITING_PICKUP = 128,
	STR_IS_COMPLETE = 129,
	STR_IS_COMPLETED_AND_READY_TO_PLACE = 130,
	STR_IS_COMPLETED_AND_AWAITING_ORDERS = 131,
	STR_INSUFFICIENT_FUNDS_CONSTRUCTION_IS_HALTED = 132,
	STR_IS_DESTROYED = 133,
	STR_CAN_NOT_PLACE_S_HERE = 134,
	STR_CAN_NOT_PLACE_FOUNDATION_HERE = 135,
	STR_UNABLE_TO_CREATE_MORE = 136,
	STR_PRODUCTION_OF_S_HAS_STARTED = 137,
	STR_REPAIRING_STOPS = 138,
	STR_REPAIRING_STARTS = 139,
	STR_UPGRADING_STOPS = 140,
	STR_UPGRADING_STARTS = 141,
	STR_UPGRADE = 142,
	STR_UPGRADING = 143,
	STR_UPGRADINGD_DONE = 144,
	STR_INSUFFICIENT_SPICE_STORAGE_AVAILABLE_SPICE_IS_LOST = 145,
	STR_RADAR_SCANFRIEND_2DENEMY_2D = 146,

	STR_HARKONNEN_HARVESTER_DEPLOYED    = 147,
	STR_ATREIDES_HARVESTER_DEPLOYED     = 148,
	STR_ORDOS_HARVESTER_DEPLOYED        = 149,
	STR_FREMEN_HARVESTER_DEPLOYED       = 150,
	STR_SARDAUKAR_HARVESTER_DEPLOYED    = 151,
	STR_MERCENARY_HARVESTER_DEPLOYED    = 152,

	STR_DESTRUCT = 153,

	STR_HARKONNEN_UNIT_LAUNCHED = 154,
	STR_ATREIDES_UNIT_LAUNCHED  = 155,
	STR_ORDOS_UNIT_LAUNCHED     = 156,
	STR_FREMEN_UNIT_LAUNCHED    = 157,
	STR_SARDAUKAR_UNIT_LAUNCHED = 158,
	STR_MERCENARY_UNIT_LAUNCHED = 159,

	STR_FRIGATE_INORBIT_ANDAWAITINGORDER = 160,
	STR_FRIGATEARRIVAL_INTMINUS_D = 161,

	STR_HARKONNEN_VEHICLE_REPAIRED  = 162,
	STR_ATREIDES_VEHICLE_REPAIRED   = 163,
	STR_ORDOS_VEHICLE_REPAIRED      = 164,
	STR_FREMEN_VEHICLE_REPAIRED     = 165,
	STR_SARDAUKAR_VEHICLE_REPAIRED  = 166,
	STR_MERCENARY_VEHICLE_REPAIRED  = 167,

	STR_SAND = 168,
	STR_ROCK = 169,
	STR_DUNE = 170,
	STR_MOUNTAIN = 171,
	STR_SPICE = 172,
	STR_SPICE_BLOOM = 173,
	STR_STRUCTURE = 174,
	STR_PROCEED = 175,
	STR_REPEAT = 176,
	STR_COST_3D = 177,
	STR_COST_999 = 178,
	STR_QTY_2D = 179,
	STR_QTY_99 = 180,
	STR_NO_UNITS_ON_ORDER = 181,
	STR_ITEM_NAME_QTY_TOTAL = 182,
	STR_INVOICE_OF_UNITS_ON_ORDER = 183,
	STR_TOTAL_COST_ = 184,
	STR_OUT_OF_STOCK = 185,
	STR_NEED_STRUCTURE_UPGRADE = 186,
	STR_UPGRADE_COST_D = 187,
	STR_RESUME_GAME = 188,
	STR_UPGRADE2 = 189,
	STR_SEND_ORDER = 190,
	STR_BUILD_THIS = 191,
	STR_INVOICE = 192,
	STR_EXIT = 193,

	STR_CARRYALL    = 194,  STR_ALLPURPOSE_CARRYALL,
	STR_THOPTER     = 196,  STR_ORNITHOPTER,
	STR_INFANTRY    = 198,  STR_LIGHT_INFANTRY_SQUAD,
	STR_TROOPERS    = 200,  STR_HEAVY_TROOPER_SQUAD,
	STR_SOLDIER     = 202,  STR_INFANTRY_SOLDIER,
	STR_TROOPER     = 204,  STR_HEAVY_TROOPER,
	STR_SABOTEUR2   = 206,  STR_INSIDIOUS_SABOTEUR,
	STR_LAUNCHER    = 208,  STR_ROCKET_LAUNCHER,
	STR_DEVIATOR    = 210,  STR_DEVIATOR_LAUNCHER,
	STR_TANK        = 212,  STR_COMBAT_TANK,
	STR_SIEGE_TANK  = 214,  STR_HEAVY_SIEGE_TANK,
	STR_DEVASTATOR  = 216,  STR_DEVASTATOR_TANK,
	STR_SONIC_TANK  = 218,  STR_SONIC_WAVE_TANK,
	STR_TRIKE       = 220,  STR_LIGHT_ATTACK_TRIKE,
	STR_RAIDER_TRIKE= 222,  STR_FAST_RAIDER_TRIKE,
	STR_QUAD        = 224,  STR_HEAVY_ATTACK_QUAD,
	STR_HARVESTER   = 226,  STR_SPICE_HARVESTER,
	STR_MCV         = 228,  STR_MOBILE_CONST_VEHICLE,
	STR_SANDWORM    = 230,  STR_SANDWORM2,

	STR_CONCRETE    = 232,  STR_SMALL_CONCRETE_SLAB,
	STR_CONCRETE_4  = 234,  STR_LARGE_CONCRETE_SLAB,
	STR_PALACE      = 236,  STR_HOUSE_PALACE,
	STR_LIGHT_FCTRY = 238,  STR_LIGHT_VEHICLE_FACTORY,
	STR_HEAVY_FCTRY = 240,  STR_HEAVY_VEHICLE_FACTORY,
	STR_HITECH      = 242,  STR_HITECH_FACTORY,
	STR_IX          = 244,  STR_HOUSE_OF_IX,
	STR_WOR         = 246,  STR_WOR_TROOPER_FACILITY,
	STR_CONST_YARD  = 248,  STR_CONSTRUCTION_YARD,
	STR_WINDTRAP    = 250,  STR_WINDTRAP_POWER_CENTER,
	STR_BARRACKS    = 252,  STR_INFANTRY_BARRACKS,
	STR_STARPORT    = 254,  STR_STARPORT_FACILITY,
	STR_REFINERY    = 256,  STR_SPICE_REFINERY,
	STR_REPAIR2     = 258,  STR_REPAIR_FACILITY,
	STR_WALL        = 260,  STR_BASE_DEFENSE_WALL,
	STR_TURRET      = 262,  STR_CANNON_TURRET,
	STR_RTURRET     = 264,  STR_ROCKET_TURRET,
	STR_SPICE_SILO  = 266,  STR_SPICE_STORAGE_SILO,
	STR_OUTPOST     = 268,  STR_RADAR_OUTPOST,

	STR_INSUFFICIENT_POWER_WINDTRAP_IS_NEEDED = 270,

	STR_SAND_FLEA           = 271,
	STR_SAND_SNAKE          = 272,
	STR_DESERT_MONGOOSE     = 273,
	STR_SAND_WARRIOR        = 274,
	STR_DUNE_TROOPER        = 275,
	STR_SQUAD_LEADER        = 276,
	STR_OUTPOST_COMMANDER   = 277,
	STR_BASE_COMMANDER      = 278,
	STR_WARLORD             = 279,
	STR_CHIEF_WARLORD       = 280,
	STR_RULER_OF_ARRAKIS    = 281,
	STR_EMPEROR             = 282,

	STR_THREE_HOUSES_HAVE_COME_TO_DUNE = 283,
	STR_TO_TAKE_CONTROL_OF_THE_LAND = 284,
	STR_THAT_HAS_BECOME_DIVIDED = 285,
	STR_SELECT_YOUR_NEXT_REGION = 286,
	STR_AT_THE_EMPERORS_PALACE = 287,
	STR_YOU_OF_ALL_PEOPLE_SHOULDUNDERSTAND_THE_IMPORTANCE_OF_VICTORY = 288,
	STR_YES_YOUR_EXCELLENCY_I = 289,
	STR_YOU_LET_THE_ATREIDES_DEFEATYOU_AND_MY_SARDAUKAR = 290,
	STR_I_DID_NOT_LET = 291,
	STR_I_WILL_NOT_ALLOW_IT_TO_HAPPEN_AGAIN = 292,
	STR_AT_THE_EMPERORS_PALACEON_DUNE = 293,
	STR_FOOLSI_GAVE_YOU_WEAPONS_AND_TROOPS = 294,
	STR_AND_STILL_YOU_FAILTO_DEFEAT_THE_ATREIDES = 295,
	STR_BUT_EXCELL = 296,
	STR_ENOUGH_TOGETHER_WE_MUST_MAKESURE_THE_ATREIDES_DO_NOT_SUCCEED = 297,
	STR_AT_THE_EMPERORS_PALACE2 = 298,
	STR_I_CANNOT_BELIEVE_THEINCOMPETENCE_I_SEE_BEFORE_ME = 299,
	STR_YOUR_HIGHNESS = 300,
	STR_I_GIVE_YOU_MY_SARDAUKAR_TO_ASSISTAGAINST_THE_ORDOS_AND_YOU_FAILED_ME = 301,
	STR_WE = 302,
	STR_DO_NOT_FAIL_ME_AGAINYOU_ARE_DISMISSED = 303,
	STR_AT_THE_EMPERORS_PALACEON_DUNE2 = 304,
	STR_THE_ORDOS_WERE_NOTSUPPOSED_TO_GET_THIS_FAR = 305,
	STR_YOUR_HIGHNESS_LET_US_EXPLAIN = 306,
	STR_NO_MORE_EXPLANATIONSYOU_ARE_TO_DEFEND_MY_PALACE = 307,
	STR_ONLY_TOGETHER_WILLWE_DEFEAT_THE_ORDOS = 308,
	STR_AT_THE_EMPERORS_PALACE3 = 309,
	STR_YOU_RECEIVE_THE_ASSISTANCEYOU_REQUIRE_AND_THEN_FAIL_ME = 310,
	STR_NO_YOUR = 311,
	STR_MY_SARDAUKAR_COULD_HELP_DEFEAT_THEHARKONNEN_BUT_YOU_WASTED_THEM = 312,
	STR_WE_DIDNT_HAVE = 313,
	STR_I_WANT_NO_EXCUSESDO_NOT_FAIL_ME_AGAIN = 314,
	STR_AT_THE_EMPERORS_PALACEON_DUNE3 = 315,
	STR_I_SHOULD_HAVE_KNOWN_YOUR_HOUSESCOULDNT_STAND_UP_TO_THE_HARKONNEN = 316,
	STR_EXCELLENCY_THEY_ARE = 317,
	STR_SILENCE = 318,
	STR_YOU_ARE_TO_DEFEND_MY_PALACE = 319,
	STR_I_WILL_SHOW_YOU_HOWTO_CRUSH_THE_HARKONNEN = 320,
	STR_THANK_YOU_FOR_PLAYING_DUNE_II = 321,
	STR_SPICE_STORAGE_CAPACITY_LOW_BUILD_SILOS = 322,
	STR_NAME_AND_RANK = 323,
	STR_BATTLE = 324,
	STR_SCORE = 325,
	STR_RESUME_GAME2 = 326,
	STR_CLEAR_LIST = 327,
	STR_ARE_YOU_SURE_YOU_WANT_TO_CLEAR_THE_HIGH_SCORES = 328,
	STR_YOU = 329,
	STR_ENEMY = 330,
	STR_CREDITS_ARE_LOW_HARVEST_SPICE_FOR_MORE_CREDITS = 331,
	STR_NOT_ENOUGH_POWER_FOR_RADAR_BUILD_WINDTRAPS = 332,
	STR_REPAIR_STRUCTURE_FIRST = 333,
	STR_HALL_OF_FAME = 334,
	STR_SELECTPLACE_TOHARVEST = 335,
	STR_HALL_OF_FAME2 = 336,
	STR_THERE_ARE_NO_SAVED_GAMES_TO_LOAD = 337,
	STR_WARNING_ORIGINAL_SAVED_GAMES_ARE_INCOMPATIBLE_WITH_THE_NEW_VERSION_THE_BATTLE_WILL_BE_RESTARTED = 338,
	STR_LOAD_GAME = 339,

	STR_HINT_YOU_MUST_BUILD_A_WINDTRAP_TO_PROVIDE_POWER_TO_YOUR_BASE_WITHOUT_POWER_YOUR_STRUCTURES_WILL_DECAY = 340,
	STR_HINT_CONCRETE       = 341,
	STR_HINT_PALACE         = 342,
	STR_HINT_LIGHT_FACTORY  = 343,
	STR_HINT_HEAVY_FACTORY  = 344,
	STR_HINT_HITECH_FACTORY = 345,
	STR_HINT_HOUSE_IX       = 346,
	STR_HINT_WOR            = 347,
	STR_HINT_CONSTRUCTION_FACILITY  = 348,
	STR_HINT_WINDTRAP       = 349,
	STR_HINT_BARRACKS       = 350,
	STR_HINT_STARPORT       = 351,
	STR_HINT_SPICE_REFINERY = 352,
	STR_HINT_REPAIR_FACILITY= 353,
	STR_HINT_WALL           = 354,
	STR_HINT_GUN_TURRET     = 355,
	STR_HINT_ROCKET_TURRET  = 356,
	STR_HINT_SPICE_SILO     = 357,
	STR_HINT_OUTPOST        = 358,
	STR_HINT_THERE_ISNT_ENOUGH_OPEN_CONCRETE_TO_PLACE_THIS_STRUCTURE_YOU_MAY_PROCEED_BUT_WITHOUT_ENOUGH_CONCRETE_THE_BUILDING_WILL_NEED_REPAIRS = 359,
	STR_HINT_SAND           = 360,
	STR_HINT_SAND_DUNES     = 361,
	STR_HINT_ROCK           = 362,
	STR_HINT_MOUNTAIN       = 363,
	STR_HINT_SPICE_FIELD    = 364,
	STR_HINT_STRUCTURES_MUST_BE_PLACED_ON_CLEAR_ROCK_OR_CONCRETE_AND_ADJACENT_TO_ANOTHER_FRIENDLY_STRUCTURE = 365,
	STR_HINT_SEARCH_FOR_SPICE_FIELDS_TO_HARVEST = 366,
	STR_HINT_WARNING_SANDWORMS_SHAIHULUD_ROAM_DUNE_DEVOURING_ANYTHING_ON_THE_SAND = 367,

	STR_PRESENT = 368,
	STR_THE_BATTLE_FOR_ARRAKIS = 369,
	STR_THE_PLANET_ARRAKIS_KNOWN_AS_DUNE = 370,
	STR_LAND_OF_SAND = 371,
	STR_HOME_OF_THE_SPICE_MELANGE = 372,
	STR_THE_SPICE_CONTROLS_THE_EMPIRE = 373,
	STR_WHOEVER_CONTROLS_DUNECONTROLS_THE_SPICE = 374,
	STR_THE_EMPEROR_HAS_PROPOSED_ACHALLENGE_TO_EACH_OF_THE_HOUSES = 375,
	STR_THE_HOUSE_THAT_PRODUCES_THEMOST_SPICE_WILL_CONTROL_DUNE = 376,
	STR_THERE_ARE_NO_SET_TERRITORIES = 377,
	STR_AND_NO_RULES_OF_ENGAGEMENT = 378,
	STR_VAST_ARMIES_HAVE_ARRIVED = 379,
	STR_NOW_THREE_HOUSES_FIGHTFOR_CONTROL_OF_DUNE = 380,
	STR_THE_NOBLE_ATREIDES = 381,
	STR_THE_INSIDIOUS_ORDOS = 382,
	STR_AND_THE_EVIL_HARKONNEN = 383,
	STR_ONLY_ONE_HOUSE_WILL_PREVAIL = 384,
	STR_YOUR_BATTLE_FOR_DUNE_BEGINS = 385,
	STR_NOW = 386,
	STR_GREETINGS_EMPEROR = 387,
	STR_WHAT_IS_THE_MEANINGOF_THIS_INTRUSION = 388,
	STR_YOU_ARE_FORMALLY_CHARGED_WITH_CRIMESOF_TREASON_AGAINST_HOUSE_ATREIDES = 389,
	STR_THE_HOUSE_SHALL_DETERMINEYOUR_GUILT_OR_INNOCENCE = 390,
	STR_UNTIL_THEN_YOU_SHALL_NOLONGER_REIGN_AS_EMPEROR = 391,
	STR_YOU_ARE_INDEED_NOT_ENTIRELYTRUE_TO_YOUR_WORD_EMPEROR = 392,
	STR_YOU_HAVE_LIED_TO_US = 393,
	STR_WHAT_LIES_WHAT_AREYOU_TALKING_ABOUT = 394,
	STR_YOUR_LIES_OF_LOYALTYYOUR_DECEIT = 395,
	STR_A_CRIME_FOR_WHICH_YOU_WILLINDEED_PAY_DEARLY = 396,
	STR_WITH_YOUR_LIFE = 397,
	STR_NO_NO_NOOO = 398,
	STR_YOU_ARE_AWARE_EMPEROR_THAT_WEHAVE_GROWN_WEARY_OF_YOUR_GAMES = 399,
	STR_WHAT_GAMES_WHAT_AREYOU_TALKING_ABOUT = 400,
	STR_I_AM_REFERRING_TOYOUR_GAME_OF_CHESS = 401,
	STR_WE_WERE_YOUR_PAWNS_ANDDUNE_WAS_YOUR_BOARD = 402,
	STR_WE_HAVE_DECIDED_TO_TAKE_MATTERSINTO_OUR_OWN_HANDS = 403,
	STR_YOU_ARE_TO_BE_OUR_PAWNIN_OUR_GAME = 404,

	STR_ORDERS_HARKONNEN_0  = 405,  STR_WIN_HARKONNEN_0,    STR_LOSE_HARKONNEN_0,   STR_ADVICE_HARKONNEN_0,
	STR_ORDERS_HARKONNEN_1  = 409,  STR_WIN_HARKONNEN_1,    STR_LOSE_HARKONNEN_1,   STR_ADVICE_HARKONNEN_1,
	STR_ORDERS_HARKONNEN_2  = 413,  STR_WIN_HARKONNEN_2,    STR_LOSE_HARKONNEN_2,   STR_ADVICE_HARKONNEN_2,
	STR_ORDERS_HARKONNEN_3  = 417,  STR_WIN_HARKONNEN_3,    STR_LOSE_HARKONNEN_3,   STR_ADVICE_HARKONNEN_3,
	STR_ORDERS_HARKONNEN_4  = 421,  STR_WIN_HARKONNEN_4,    STR_LOSE_HARKONNEN_4,   STR_ADVICE_HARKONNEN_4,
	STR_ORDERS_HARKONNEN_5  = 425,  STR_WIN_HARKONNEN_5,    STR_LOSE_HARKONNEN_5,   STR_ADVICE_HARKONNEN_5,
	STR_ORDERS_HARKONNEN_6  = 429,  STR_WIN_HARKONNEN_6,    STR_LOSE_HARKONNEN_6,   STR_ADVICE_HARKONNEN_6,
	STR_ORDERS_HARKONNEN_7  = 433,  STR_WIN_HARKONNEN_7,    STR_LOSE_HARKONNEN_7,   STR_ADVICE_HARKONNEN_7,
	STR_ORDERS_HARKONNEN_8  = 437,  STR_WIN_HARKONNEN_8,    STR_LOSE_HARKONNEN_8,   STR_ADVICE_HARKONNEN_8,
	STR_ORDERS_HARKONNEN_9  = 441,  STR_WIN_HARKONNEN_9,    STR_LOSE_HARKONNEN_9,   STR_ADVICE_HARKONNEN_9,
	STR_ORDERS_ATREIDES_0   = 445,  STR_WIN_ATREIDES_0,     STR_LOSE_ATREIDES_0,    STR_ADVICE_ATREIDES_0,
	STR_ORDERS_ATREIDES_1   = 449,  STR_WIN_ATREIDES_1,     STR_LOSE_ATREIDES_1,    STR_ADVICE_ATREIDES_1,
	STR_ORDERS_ATREIDES_2   = 453,  STR_WIN_ATREIDES_2,     STR_LOSE_ATREIDES_2,    STR_ADVICE_ATREIDES_2,
	STR_ORDERS_ATREIDES_3   = 457,  STR_WIN_ATREIDES_3,     STR_LOSE_ATREIDES_3,    STR_ADVICE_ATREIDES_3,
	STR_ORDERS_ATREIDES_4   = 461,  STR_WIN_ATREIDES_4,     STR_LOSE_ATREIDES_4,    STR_ADVICE_ATREIDES_4,
	STR_ORDERS_ATREIDES_5   = 465,  STR_WIN_ATREIDES_5,     STR_LOSE_ATREIDES_5,    STR_ADVICE_ATREIDES_5,
	STR_ORDERS_ATREIDES_6   = 469,  STR_WIN_ATREIDES_6,     STR_LOSE_ATREIDES_6,    STR_ADVICE_ATREIDES_6,
	STR_ORDERS_ATREIDES_7   = 473,  STR_WIN_ATREIDES_7,     STR_LOSE_ATREIDES_7,    STR_ADVICE_ATREIDES_7,
	STR_ORDERS_ATREIDES_8   = 477,  STR_WIN_ATREIDES_8,     STR_LOSE_ATREIDES_8,    STR_ADVICE_ATREIDES_8,
	STR_ORDERS_ATREIDES_9   = 481,  STR_WIN_ATREIDES_9,     STR_LOSE_ATREIDES_9,    STR_ADVICE_ATREIDES_9,
	STR_ORDERS_ORDOS_0      = 485,  STR_WIN_ORDOS_0,        STR_LOSE_ORDOS_0,       STR_ADVICE_ORDOS_0,
	STR_ORDERS_ORDOS_1      = 489,  STR_WIN_ORDOS_1,        STR_LOSE_ORDOS_1,       STR_ADVICE_ORDOS_1,
	STR_ORDERS_ORDOS_2      = 493,  STR_WIN_ORDOS_2,        STR_LOSE_ORDOS_2,       STR_ADVICE_ORDOS_2,
	STR_ORDERS_ORDOS_3      = 497,  STR_WIN_ORDOS_3,        STR_LOSE_ORDOS_3,       STR_ADVICE_ORDOS_3,
	STR_ORDERS_ORDOS_4      = 501,  STR_WIN_ORDOS_4,        STR_LOSE_ORDOS_4,       STR_ADVICE_ORDOS_4,
	STR_ORDERS_ORDOS_5      = 505,  STR_WIN_ORDOS_5,        STR_LOSE_ORDOS_5,       STR_ADVICE_ORDOS_5,
	STR_ORDERS_ORDOS_6      = 509,  STR_WIN_ORDOS_6,        STR_LOSE_ORDOS_6,       STR_ADVICE_ORDOS_6,
	STR_ORDERS_ORDOS_7      = 513,  STR_WIN_ORDOS_7,        STR_LOSE_ORDOS_7,       STR_ADVICE_ORDOS_7,
	STR_ORDERS_ORDOS_8      = 517,  STR_WIN_ORDOS_8,        STR_LOSE_ORDOS_8,       STR_ADVICE_ORDOS_8,
	STR_ORDERS_ORDOS_9      = 521,  STR_WIN_ORDOS_9,        STR_LOSE_ORDOS_9,       STR_ADVICE_ORDOS_9,

	STR_SECURITY_COUNT          = 525,
	STR_SECURITY_TEXT_HARKONNEN = 526,  STR_SECURITY_CORRECT_HARKONNEN, STR_SECURITY_WRONG_HARKONNEN,
	STR_SECURITY_TEXT_ATREIDES  = 529,  STR_SECURITY_CORRECT_ATREIDES,  STR_SECURITY_WRONG_ATREIDES,
	STR_SECURITY_TEXT_ORDOS     = 532,  STR_SECURITY_CORRECT_ORDOS,     STR_SECURITY_WRONG_ORDOS,
	STR_SECURITY_QUESTIONS      = 535
};

#endif
