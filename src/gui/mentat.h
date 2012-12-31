/* $Id$ */

/** @file src/gui/mentat.h Mentat gui definitions. */

#ifndef GUI_MENTAT_H
#define GUI_MENTAT_H

#include <stdbool.h>
#include <stdint.h>
#include "enumeration.h"

extern bool g_disableOtherMovement;
extern bool g_interrogation;
extern char s_mentatFilename[13];

extern void GUI_Mentat_LoadHelpSubjects(bool init);
extern void GUI_Mentat_Draw(bool force);
extern void GUI_Mentat_Animation(enum MentatID mentatID, uint16 speakingMode);
extern void GUI_Mentat_Create_HelpScreen_Widgets(void);
extern void GUI_Mentat_ShowHelp(void);
extern uint16 GUI_Mentat_SplitText(char *str, uint16 maxWidth);

#endif /* GUI_MENTAT_H */
