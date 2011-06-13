/* $Id$ */

#include <stdio.h>
#include <string.h>
#include "types.h"
#include "libemu.h"
#include "../decompiled/decompiled.h"
#include "../global.h"
#include "input.h"

static InputLocalData *s_input_local = NULL; /*!< Pointer to input data. */

/**
 * Initialize the input system.
 *
 * @init System_Init_Input
 */
void System_Init_Input()
{
	s_input_local = (InputLocalData *)&emu_get_memory8(0x29E8, 0x0, 0x0);
}

/**
 * Clears the given bits in input flags.
 *
 * @param bits The bits to clear.
 * @return The new value of input flags.
 */
uint16 Input_Flags_ClearBits(uint16 bits)
{
	g_global->inputFlags &= ~bits;
	return g_global->inputFlags;
}

/**
 * Sets the given bits in input flags.
 *
 * @param bits The bits to set.
 * @return The new value of input flags.
 */
uint16 Input_Flags_SetBits(uint16 bits)
{
	g_global->inputFlags |= bits;

	if ((g_global->inputFlags & INPUT_FLAG_KEY_RELEASE) != 0) {
		uint8 i;
		for (i = 0; i < 16; i++) s_input_local->activeInputMap[i] = 0;
	}

	return g_global->inputFlags;
}

/** Clear the history buffer. */
void Input_History_Clear()
{
	s_input_local->historyTail = s_input_local->historyHead;
}

/**
 * Get an input from the history buffer.
 * @param index Current index in the history.
 * @return Read input.
 * @note Provided \a index gets updated and written to #historyHead
 */
uint16 Input_ReadHistory(uint16 index)
{
	uint16 value;

	value = g_global->variable_7013 = (g_global->mouseMode == 2) ? g_global->variable_7013 : s_input_local->history[index / 2];
	index = (index + 2) & 0xFF;

	if ((value & 0xFF) >= 0x41) {
		if ((value & 0xFF) <= 0x42) {
			g_global->mouseClickX = g_global->variable_7017 = (g_global->mouseMode == 2) ? g_global->variable_7017 : s_input_local->history[index / 2];
			index = (index + 2) & 0xFF;

			g_global->mouseClickY = g_global->variable_7019 = (g_global->mouseMode == 2) ? g_global->variable_7019 : s_input_local->history[index / 2];
			index = (index + 2) & 0xFF;
		} else if ((value & 0xFF) <= 0x44) {
			g_global->variable_7017 = (g_global->mouseMode == 2) ? g_global->variable_7017 : s_input_local->history[index / 2];
			index = (index + 2) & 0xFF;

			g_global->variable_7019 = (g_global->mouseMode == 2) ? g_global->variable_7019 : s_input_local->history[index / 2];
			index = (index + 2) & 0xFF;
		}
	}
	if (g_global->mouseMode != 0x2) s_input_local->historyHead = index;
	return value;
}

