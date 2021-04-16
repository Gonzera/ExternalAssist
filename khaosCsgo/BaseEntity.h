#pragma once
#include "Headers.h"

typedef struct {
	float Matrix[3][4];
} Matrix3x4_t;

class CEntity
{
public:
	CEntity* GetLocalPlayer();

	int GetHealth();
	int GetTeam();
	int GetClassId();
	bool isInGame();
	bool isSpoted();
	bool isAlive();
	bool isEnemy();
	bool isDormant();
	Vector3 VecVelocity();
	Vector3 VecOrigin();
	Vector3 VecPunch();
	Vector3 GetViewAngle();
	Vector3 GetEyePos();
	uintptr_t GetBoneMatrix();
	Matrix3x4_t GetBonePos();
	void SetViewAngle(Vector3 angle);
	BYTE m_fFlag();
};

extern CEntity* LocalPlayer;

