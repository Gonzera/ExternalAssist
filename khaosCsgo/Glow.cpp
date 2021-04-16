#include "Glow.h"

CGlow Glow;

void CGlow::DoGlow()
{

	uintptr_t glowManager = Memory.ReadMem<uintptr_t>(Offsets.Client + Offsets.dwGlowObjectManager);


	for (int i = 0; i < 64; i++)
	{
		CEntity* Entity = (CEntity*)Memory.ReadMem<uintptr_t>(Offsets.Client + Offsets.dwEntityList + (i * 0x10));
		if (!Entity)
			return;

		int glowIndex = Memory.ReadMem<int>((uintptr_t)Entity + Offsets.m_iGlowIndex);
		bool isEnemy = Entity->isEnemy();
		bool isDormant = Entity->isDormant();

		if (!isDormant && isEnemy) 
		{
			GlowObject_t sGlow = Memory.ReadMem<GlowObject_t>(glowManager + (i * 0x38) + 0x4);

			sGlow.r = 255.f;
			sGlow.g = 0.f;
			sGlow.b = 255.f;
			sGlow.a = 0.5f;
			sGlow.m_bRenderWhenOccluded = true;
			sGlow.m_bRenderWhenUnoccluded = false;

			//Write the modified struct into the entity
			Memory.WriteMem<GlowObject_t>(glowManager + (glowIndex * 0x38) + 0x4, sGlow);
		}

	}
}