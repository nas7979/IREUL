#include "DXUT.h"
#include "cParticleFunc.h"


cParticleFunc::cParticleFunc()
{
}


cParticleFunc::~cParticleFunc()
{
}

void cParticleFunc::Init()
{
	m_Timer = 0;
}

void cParticleFunc::Update()
{
	m_Timer -= DT;
	if (m_Timer <= 0)
	{
		m_Timer = m_FuncSpeed;
		m_Func(this);
	}
}

void cParticleFunc::Render()
{
	IMAGE->CenterRender(m_Image, m_Pos, D3DXToRadian(m_Rot), m_Scale, m_Depth, m_Color);
}

void cParticleFunc::Release()
{
}
