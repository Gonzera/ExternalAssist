#pragma once
#include "Headers.h"

//pasted gang

class Vector3
{
public:
	float x, y, z;
};

struct GlowObject_t
{
	float r;
	float g;
	float b;
	float a;
	uint8_t unk1[16];
	bool m_bRenderWhenOccluded;
	bool m_bRenderWhenUnoccluded;
};

struct CLRender_t
{
	BYTE r;
	BYTE g;
	BYTE b;
};

enum eClassIds
{
	CC4 = 34,
	CCSPlayer = 40,
	CPlantedC4 = 128
};