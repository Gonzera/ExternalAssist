#pragma once
#include "Headers.h"

class CEntity
{
public:
	CEntity* GetLocalPlayer();

	int GetHealth();
	int GetTeam();
	int GetClassId();
	float GetFlashDuration();
	float GetFlashMaxAlpha();
	bool isInGame();
	bool isSpoted();
	bool isAlive();
	bool isEnemy();
	bool isDormant();
	Vector3 VecVelocity();
	Vector3 VecOrigin();
	BYTE m_fFlag();
};

extern CEntity* LocalPlayer;
