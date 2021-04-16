#pragma once

#include "Headers.h"

//salve ichigo baixa isso daq https://github.com/frk1/hazedumper

class COffsets
{
public:
	uintptr_t dwLocalPlayer = 0xD8A2BC;
	uintptr_t dwClientState = 0x58EFE4;
	uintptr_t dwEntityList = 0x4DA1F24;
	uintptr_t m_bDormant = 0xED;
	uintptr_t m_bSpotted = 0x93D;
	uintptr_t dwForceJump = 0x524BE84;
	uintptr_t m_fFlags = 0x104;
	uintptr_t dwForceAttack = 0x31D3460;
	uintptr_t dwGlowObjectManager = 0x52EA520;
	uintptr_t m_vecOrigin = 0x138;
	uintptr_t m_vecVelocity = 0x114;
	uintptr_t m_vecViewOffset = 0x108;
	uintptr_t m_viewPunchAngle = 0x3020;
	uintptr_t m_iTeamNum = 0xF4;
	uintptr_t m_iHealth = 0x100;
	uintptr_t m_iCrosshairId = 0xB3E4;
	uintptr_t m_flFlashMaxAlpha = 0xA41C;
	uintptr_t m_iGlowIndex = 0xA438;
	uintptr_t dwClientState_ViewAngles = 0x4D90;
	uintptr_t m_aimPunchAngle = 0x302C;
	uintptr_t m_dwBoneMatrix = 0x26A8;


// ----------------------------
	uintptr_t ClientState;
	uintptr_t Client;					//isso ta na classe de memoria, n precisa do dumper
	uintptr_t Engine;
};

extern COffsets Offsets;