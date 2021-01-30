#include "BaseEntity.h"

CEntity* LocalPlayer;

CEntity* CEntity::GetLocalPlayer()
{
	return (CEntity*)(Memory.ReadMem<int>(Offsets.Client + Offsets.dwLocalPlayer));
}

Vector3 CEntity::VecVelocity()
{
	return Memory.ReadMem<Vector3>((uintptr_t)this + Offsets.m_vecVelocity);
}

Vector3 CEntity::VecOrigin()
{
	return Memory.ReadMem<Vector3>((uintptr_t)this + Offsets.m_vecOrigin);
}

Vector3 CEntity::GetViewAngle()
{
	return Memory.ReadMem<Vector3>(Offsets.Client + Offsets.dwClientState_ViewAngles);
}

Vector3 CEntity::VecPunch()
{
	return Memory.ReadMem<Vector3>(Offsets.Client + Offsets.m_viewPunchAngle);
}

void CEntity::SetViewAngle(Vector3 angle)
{
	Memory.WriteMem<Vector3>(Offsets.Client + Offsets.dwClientState_ViewAngles, angle);
}

uintptr_t CEntity::GetBoneMatrix()
{
	return Memory.ReadMem<uintptr_t>((uintptr_t)this + Offsets.m_dwBoneMatrix);
}

bool CEntity::isDormant()
{
	return Memory.ReadMem<bool>((uintptr_t)this + Offsets.m_bDormant);
}

bool CEntity::isSpoted()
{
	return Memory.ReadMem<bool>((uintptr_t)this + Offsets.m_bSpotted);
}

int CEntity::GetHealth()
{
	return Memory.ReadMem<int>((uintptr_t)this + Offsets.m_iHealth);
}

bool CEntity::isAlive()
{
	int health = this->GetHealth();

	if (health <= 0)
		return false;
	else
		return true;
}

int CEntity::GetTeam()
{
	return Memory.ReadMem<int>((uintptr_t)this + Offsets.m_iTeamNum);
}

bool CEntity::isEnemy()
{
	int entityTeam = this->GetTeam();
	int myTeam = LocalPlayer->GetTeam();
	

	if (myTeam != entityTeam)
		return true;
	else
		return false;
}

BYTE CEntity::m_fFlag()
{
	return Memory.ReadMem<BYTE>((uintptr_t)this + Offsets.m_fFlags);
}

int CEntity::GetClassId()
{
	int IClientNetworkable = Memory.ReadMem<int>((uintptr_t)this + 0x8);
	int GetClientClass = Memory.ReadMem<int>(IClientNetworkable + 0x8);
	int pClientClass = Memory.ReadMem<int>(GetClientClass + 0x1);
	int classID = Memory.ReadMem<int>(pClientClass + 0x14);

	return classID;
}