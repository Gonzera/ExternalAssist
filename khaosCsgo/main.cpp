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

		Misc.Radar();
	}
}