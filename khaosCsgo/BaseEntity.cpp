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