#include "Misc.h"
CMisc Misc;

void CMisc::BunnyHop() //so to testando se o negocio de memoria realmente funciona.
{
	uintptr_t localPlayer = Memory.ReadMem<int>(Offsets.Client + Offsets.dwLocalPlayer);
	
	BYTE m_fFlags = Memory.ReadMem<BYTE>(localPlayer + Offsets.m_fFlags);
	


	if (GetAsyncKeyState(VK_SPACE) && m_fFlags)
	{
   		Memory.WriteMem<int>(Offsets.Client + Offsets.dwForceJump, 6);
	}
}
