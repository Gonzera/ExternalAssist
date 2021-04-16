#include "Misc.h"
CMisc Misc;

void CMisc::BunnyHop() 
{
	

	BYTE m_fFlags = LocalPlayer->m_fFlag();

	Vector3 velocity = LocalPlayer->VecVelocity(); 


	INPUT input;



	if (GetAsyncKeyState(VK_SPACE) && m_fFlags)
	{
   		Memory.WriteMem<int>(Offsets.Client + Offsets.dwForceJump, 6);
	}
}

void CMisc::Radar()
{

	for (int i = 0; i < 64; i++)
	{
		CEntity* Entity = (CEntity*)Memory.ReadMem<uintptr_t>(Offsets.Client + Offsets.dwEntityList + (i * 0x10));

		if (!Entity)
			return;

		bool isSpoted = Entity->isSpoted();
		bool isEnemy = Entity->isEnemy();

		if (!isSpoted && isEnemy)
		{
			Memory.WriteMem<bool>((uintptr_t)Entity + Offsets.m_bSpotted, true);
		}
	}


}

void CMisc::Triggerbot()
{
	int crosshairId = Memory.ReadMem<int>((uintptr_t)LocalPlayer + Offsets.m_iCrosshairId);

	CEntity* Entity = (CEntity*)Memory.ReadMem<uintptr_t>(Offsets.Client + Offsets.dwEntityList + ((crosshairId - 1) * 0x10));

	if (!Entity) 
		return;

	bool isAlive = Entity->isAlive();
	bool isEnemy = Entity->isEnemy();

	if (isEnemy && isAlive)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(2);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
	
}

void CMisc::FlashAlpha()
{
	float newMax = 0.0f; //will add the config file later

	if (true)
	{
		Memory.WriteMem<float>((uintptr_t)LocalPlayer + Offsets.m_flFlashMaxAlpha, newMax);
	}
}