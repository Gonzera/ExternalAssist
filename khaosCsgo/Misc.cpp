#include "Misc.h"
CMisc Misc;

void CMisc::BunnyHop() //so to testando se o negocio de memoria realmente funciona.
{
	

	BYTE m_fFlags = LocalPlayer->m_fFlag();

	Vector3 velocity = LocalPlayer->VecVelocity(); 


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