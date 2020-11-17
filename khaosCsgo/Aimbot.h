#pragma once
#include "Headers.h"

class CAimbot
{
public:
	void DoAimbot(uintptr_t player, int smooth, float fov);
	void DoRCS();
	uintptr_t  GetTarget(float fov);


private:
};
extern CAimbot Aimbot;
