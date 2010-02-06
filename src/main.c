#include <stdio.h>
#include "types.h"
#include "libemu.h"

extern void emu_Input_Keyboard_EventHandler();
extern void Interrupt_User_Clock();
extern void Interrupt_Timer();
extern void emu_EntryPoint();
extern void f__2756_050F_000B_0871();
extern void emu_Mouse_EventHandler();

extern void System_Init_Map();
extern void System_Init_Input();
extern void System_Init_Global();
extern void System_Init_House();
extern void System_Init_Unit();
extern void System_Init_Window();
extern void System_Init_File();
extern void System_Init_Structure();

#if defined(__APPLE__)
int SDL_main(int argc, char **argv)
#else
int main(int argc, char **argv)
#endif /* __APPLE__ */
{
	emu_hard_link(0x29E8, 0x0D47, &emu_Input_Keyboard_EventHandler);
	emu_hard_link(0x0070, 0x00E0, &Interrupt_User_Clock);
	emu_hard_link(0x0070, 0x0040, &Interrupt_Timer);
	emu_hard_link(0x01F7, 0x0000, &emu_EntryPoint);
	emu_hard_link(0x2756, 0x050F, &f__2756_050F_000B_0871);
	emu_hard_link(0x29A3, 0x0054, &emu_Mouse_EventHandler);

	emu_init(argc, argv);
	emu_overlay = 1;

	System_Init_Map();
	System_Init_Input();
	System_Init_Global();
	System_Init_House();
	System_Init_Unit();
	System_Init_Window();
	System_Init_File();
	System_Init_Structure();

	emu_hard_jump(emu_cs, emu_ip);
	while (1) emu_hard_jump_recursive(emu_deep);

	return 1;
}
