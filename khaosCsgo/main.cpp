#include "Headers.h"


int main()
{
	Memory.getHandle();
	Memory.getRequiredModules();


	Menu.PrintMenu();

	while (true)
	{
		LocalPlayer = LocalPlayer->GetLocalPlayer();

		Menu.HandleBinds();

	}
}


/*
	TODO LIST:

	SAVE CPU USAGE!!!!
	INI PARSING
	MOUSE_EVENT AIMBOT
	RCS
	VIS CHECK (MAYBE BSP PARSING)



	EXTREME LOW PRIORITY:
	DX OVERLAY AND ESP

*/