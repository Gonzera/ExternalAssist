#include "Menu.h"

CMenu Menu;



void CMenu::PrintMenu()
{
	std::cout << R"( 
 /$$   /$$ /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$ 
| $$  /$$/| $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$ /$$/ | $$  | $$| $$  \ $$| $$  \ $$| $$  \__/
| $$$$$/  | $$$$$$$$| $$$$$$$$| $$  | $$|  $$$$$$ 
| $$  $$  | $$__  $$| $$__  $$| $$  | $$ \____  $$
| $$\  $$ | $$  | $$| $$  | $$| $$  | $$ /$$  \ $$
| $$ \  $$| $$  | $$| $$  | $$|  $$$$$$/|  $$$$$$/
|__/  \__/|__/  |__/|__/  |__/ \______/  \______/

)" << '\n';

	std::cout << "F1 - BHOP \n";
}

bool doBhop = 0, doTrigger = 0, doGlow = 0; //declaring variables here so they don't get set to 0 in the loop
void CMenu::HandleBinds()
{

	if (GetAsyncKeyState(VK_F1))
	{
		doBhop = !doBhop;
	}

	if (GetAsyncKeyState(VK_F2))
	{
		doTrigger = !doTrigger;
	}

	if (GetAsyncKeyState(VK_F3))
	{
		doGlow = !doGlow;
	}

	if (doGlow)
		Glow.DoGlow();
	if (doTrigger)
		Misc.Triggerbot();
	if (doBhop)
		Misc.BunnyHop();

}