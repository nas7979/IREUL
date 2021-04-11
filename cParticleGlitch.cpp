#include "DXUT.h"
#include "cParticleGlitch.h"


cParticleGlitch::cParticleGlitch()
{
}


cParticleGlitch::~cParticleGlitch()
{
}

void cParticleGlitch::Init()
{
}

void cParticleGlitch::Update()
{
	m_PosRandVel *= pow(m_PosRandFri, DT * 60);
	m_SizeRandVel *= pow(m_SizeRandFri, DT * 60);

	m_PosRand += m_PosRandVel * DT;
	m_SizeRand += m_SizeRandVel * DT;
}

void cParticleGlitch::Render()
{
	if (m_Box)
	{
		IMAGE->CenterRenderBoxGlitch(m_Image, m_Pos, D3DXToRadian(m_Rot), m_Scale, m_Depth, m_PosRand, m_SizeRand, m_Color);
	}
	else
	{
		IMAGE->CenterRenderGlitch(m_Image, m_Pos, D3DXToRadian(m_Rot), m_Scale, m_Depth, m_PosRand, m_SizeRand, m_Color);
	}
}

void cParticleGlitch::Release()
{
}
