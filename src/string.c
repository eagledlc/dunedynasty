/* $Id$ */

/** @file src/string.c String routines. */

#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"
#include "os/common.h"
#include "os/math.h"
#include "os/strings.h"

#include "string.h"

#include "config.h"
#include "enhancement.h"
#include "file.h"
#include "house.h"
#include "opendune.h"
#include "scenario.h"
#include "table/strings.h"

static char **s_strings = NULL;
static uint16 s_stringsCount = 0;
static char *s_strings_mentat[HOUSE_MAX][40];

const char * const g_languageSuffixes[] = { "ENG", "FRE", "GER", "ITA", "SPA" };
const char * const g_gameSubtitle[] = {
	"The Battle for Arrakis",
	"The Building of A Dynasty",
	"The Building of a Dynasty"
};

static char *s_stringDecompress = " etainosrlhcdupmtasio wb rnsdalmh ieorasnrtlc synstcloer dtgesionr ufmsw tep.icae oiadur laeiyodeia otruetoakhlr eiu,.oansrctlaileoiratpeaoip bm";

/**
 * Decompress a string.
 *
 * @param source The compressed string.
 * @param dest The decompressed string.
 * @return The length of decompressed string.
 */
uint16 String_Decompress(char *source, char *dest)
{
	uint16 count;
	char *s;

	count = 0;

	for (s = source; *s != '\0'; s++) {
		uint8 c = *s;
		if ((c & 0x80) != 0) {
			c &= 0x78;
			c >>= 3;
			dest[count++] = s_stringDecompress[c];
			c <<= 3;
			c += (*s & 0x07);
			c = s_stringDecompress[c + 16];
		}
		dest[count++] = c;
	}
	dest[count] = '\0';
	return count;
}

/**
 * Appends ".(ENG|FRE|...)" to the given string.
 *
 * @param name The string to append extension to.
 * @return The new string.
 */
char *
String_GenerateFilename(const char *name)
{
	static char filename[14];

	assert(g_gameConfig.language < lengthof(g_languageSuffixes));

	snprintf(filename, sizeof(filename), "%s.%s", name, g_languageSuffixes[g_gameConfig.language]);
	return filename;
}

/**
 * Returns a pointer to the string at given index in current string file.
 *
 * @param stringID The index of the string.
 * @return The pointer to the string.
 */
char *String_Get_ByIndex(uint16 stringID)
{
	return s_strings[stringID];
}

char *
String_GetMentatString(enum HouseType houseID, int stringID)
{
	return s_strings_mentat[houseID][stringID];
}

/**
 * Translates 0x1B 0xXX occurences into extended ASCII values (0x7F + 0xXX).
 *
 * @param source The untranslated string.
 * @param dest The translated string.
 */
void String_TranslateSpecial(char *source, char *dest)
{
	if (source == NULL || dest == NULL) return;

	while (*source != '\0') {
		char c = *source++;
		if (c == 0x1B) {
			c = 0x7F + (*source++);
		}
		*dest++ = c;
	}
	*dest = '\0';
}

static void
String_Load(const char *filename, bool compressed)
{
	void *buf;
	uint16 count;
	uint16 i;

	buf = File_ReadWholeFile(String_GenerateFilename(filename));
	count = *(uint16 *)buf / 2;

	s_stringsCount += count;
	s_strings = (char **)realloc(s_strings, s_stringsCount * sizeof(char *));
	s_strings[s_stringsCount - count] = NULL;

	for (i = 0; i < count; i++) {
		char *src = (char *)buf + ((uint16 *)buf)[i];
		char *dst;

		if (strlen(src) == 0 && s_strings[0] != NULL) {
			s_stringsCount--;
			continue;
		}

		if (compressed) {
			dst = (char *)calloc(strlen(src) * 2 + 1, sizeof(char));
			String_Decompress(src, dst);
			String_TranslateSpecial(dst, dst);
		} else {
			dst = strdup(src);
		}

		s_strings[s_stringsCount - count + i] = dst;
	}

	/* EU version has one more string in DUNE langfile. */
	if (s_stringsCount == STR_LOAD_GAME) s_strings[s_stringsCount++] = strdup(s_strings[STR_LOAD_A_GAME]);

	free(buf);
}

void
String_ReloadMentatText(void)
{
	for (enum HouseType houseID = HOUSE_HARKONNEN; houseID < HOUSE_MAX; houseID++) {
		for (unsigned int i = 0; i < 40; i++) {
			/* Default string. */
			const uint16 stringID
				= STR_HOUSE_HARKONNENFROM_THE_DARK_WORLD_OF_GIEDI_PRIME_THE_SAVAGE_HOUSE_HARKONNEN_HAS_SPREAD_ACROSS_THE_UNIVERSE_A_CRUEL_PEOPLE_THE_HARKONNEN_ARE_RUTHLESS_TOWARDS_BOTH_FRIEND_AND_FOE_IN_THEIR_FANATICAL_PURSUIT_OF_POWER
				+ 40 * g_table_houseRemap6to3[houseID] + i;

			char *def = String_Get_ByIndex(stringID);

			if (s_strings_mentat[houseID][i] && s_strings_mentat[houseID][i] != def)
				free(s_strings_mentat[houseID][i]);

			s_strings_mentat[houseID][i] = def;
		}

		if (g_campaign_selected == 0)
			continue;

		if (!((g_campaign_list[g_campaign_selected].house[0] == houseID) ||
		      (g_campaign_list[g_campaign_selected].house[1] == houseID) ||
		      (g_campaign_list[g_campaign_selected].house[2] == houseID)))
			continue;

		char filename[10];
		snprintf(filename, sizeof(filename), "TEXT%c.%s", g_table_houseInfo[houseID].name[0], g_languageSuffixes[g_gameConfig.language]);

		if (!File_Exists_Ex(SEARCHDIR_CAMPAIGN_DIR, filename))
			continue;

		void *buf = File_ReadWholeFile_Ex(SEARCHDIR_CAMPAIGN_DIR, filename);
		uint16 count = min(40, (*(uint16 *)buf / 2));

		for (unsigned int i = 0; i < count; i++) {
			const bool compressed = true;
			char *src = (char *)buf + ((uint16 *)buf)[i];
			char *dst;

			if (strlen(src) <= 1)
				continue;

			if (compressed) {
				dst = (char *)calloc(strlen(src) * 2 + 1, sizeof(char));
				String_Decompress(src, dst);
				String_TranslateSpecial(dst, dst);
			}
			else {
				dst = strdup(src);
			}

			s_strings_mentat[houseID][i] = dst;
		}

		free(buf);
	}
}

/**
 * Loads the language files in the memory, which is used after that with String_GetXXX_ByIndex().
 */
void String_Init(void)
{
	String_Load("DUNE", false);
	String_Load("MESSAGE", false);
	String_Load("INTRO", false);
	String_Load("TEXTH",true);
	String_Load("TEXTA", true);
	String_Load("TEXTO",true);
	String_Load("PROTECT", true);

	/* US and HitSquad versions use "Load a game" instead of "Load Game." */
	if (s_strings[STR_LOAD_GAME] != NULL) {
		char *str = s_strings[STR_LOAD_GAME];
		while (*str == ' ') str++;
		if (*str == '\0') {
			free(s_strings[STR_LOAD_GAME]);
			s_strings[STR_LOAD_GAME] = strdup(s_strings[STR_LOAD_A_GAME]);
		}
	}

	/* Override the "The Building of a Dynasty" subtitle.  Pick the one that matches the narrator. */
	if ((enhancement_subtitle_override != SUBTITLE_THE_BATTLE_FOR_ARRAKIS) && (g_gameConfig.language == LANGUAGE_ENGLISH)) {
		const char *subtitle1 = g_gameSubtitle[enhancement_subtitle_override];
		char subtitle2[64];

		snprintf(subtitle2, sizeof(subtitle2), "Dune II: %s", subtitle1);

		free(s_strings[STR_THE_BATTLE_FOR_ARRAKIS]);
		s_strings[STR_THE_BATTLE_FOR_ARRAKIS] = strdup(subtitle1);

		free(s_strings[STR_DUNE_II_THE_BATTLE_FOR_ARRAKIS]);
		s_strings[STR_DUNE_II_THE_BATTLE_FOR_ARRAKIS] = strdup(subtitle2);
	}

	if (enhancement_fix_typos && (g_gameConfig.language == LANGUAGE_ENGLISH)) {
		char *str;

		str = s_strings[STR_OLD_SAVE_GAME_FILE_IS_INCOMPATIBLE_WITH_LATEST_VERSION];
		str = strstr(str, "incompatable");
		if (str != NULL)
			str[8] = 'i';

		str = s_strings[STR_ORNITHOPTER];
		str[6] = 'o';

		str = s_strings[STR_WARNING_ORIGINAL_SAVED_GAMES_ARE_INCOMPATIBLE_WITH_THE_NEW_VERSION_THE_BATTLE_WILL_BE_RESTARTED];
		str = strstr(str, "incompatable");
		if (str != NULL)
			str[8] = 'i';

		str = s_strings[STR_STARPORT_THE_STARPORT_IS_USED_TO_ORDER_AND_RECEIVE_SHIPMENTS_FROM_CHOAM];
		if (strncmp(str, "Startport", 9) == 0)
			memmove(str + 4, str + 5, strlen(str + 5) + 1);
	}
}

/**
 * Unloads the language files in the memory.
 */
void String_Uninit(void)
{
	uint16 i;

	for (i = 0; i < s_stringsCount; i++) free(s_strings[i]);
	free(s_strings);
	s_strings = NULL;
}

#if 0
/**
 * Go to the next string.
 * @param ptr Pointer to the current string.
 * @return Pointer to the next string.
 */
uint8 *String_NextString(uint8* ptr)
{
	ptr += *ptr;
	while (*ptr == 0) ptr++;
	return ptr;
}

/**
 * Go to the previous string.
 * @param ptr Pointer to the current string.
 * @return Pointer to the previous string.
 */
uint8 *String_PrevString(uint8 *ptr)
{
	do {
		ptr--;
	} while (*ptr == 0);
	ptr -= *ptr - 1;
	return ptr;
}
#endif
