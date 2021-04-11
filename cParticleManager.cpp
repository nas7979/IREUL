#include "DXUT.h"
#include "cParticleManager.h"


cParticleManager::cParticleManager()
{
}


cParticleManager::~cParticleManager()
{
}

void cParticleManager::Init()
{
}

void cParticleManager::Update()
{
	float Time = DT;
	for (int i = 0; i < 3; i++)
	{
		for (auto& iter = m_Particles[i].begin(); iter != m_Particles[i].end();)
		{
			(*iter)->m_PosVel *= pow((*iter)->m_PosFri, Time * 60);
			(*iter)->m_ScaleVel *= pow((*iter)->m_ScaleFri, Time * 60);
			(*iter)->m_RotVel *= pow((*iter)->m_RotFri, Time * 60);
			(*iter)->m_AlphaVel *= pow((*iter)->m_AlphaFri, Time * 60);

			(*iter)->m_Pos += RotateVec(Vec2((*iter)->m_PosVel, 0), (*iter)->m_Dir) * Time;
			(*iter)->m_Scale += (*iter)->m_ScaleVel * Time;
			(*iter)->m_Rot += (*iter)->m_RotVel * Time;
			(*iter)->m_Alpha += (*iter)->m_AlphaVel * Time;

			(*iter)->m_Color = ((*iter)->m_Color & 0x00ffffff) | ((int)min(255, (*iter)->m_Alpha) << 24);
			(*iter)->Update();

			if ((*iter)->m_Alpha <= 0 || (*iter)->m_Scale.x <= 0 || (*iter)->m_Scale.y <= 0)
			{
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = m_Particles[i].erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
}

void cParticleManager::Render1()
{
	for (auto& iter : m_Particles[0])
	{
		iter->Render();
	}
}

void cParticleManager::Render2()
{
	for (auto& iter : m_Particles[1])
	{
		iter->Render();
	}
}

void cParticleManager::RenderGlobal()
{
	for (auto& iter : m_Particles[2])
	{
		iter->Render();
	}
}

void cParticleManager::Release()
{
	for (int i = 0; i < 3; i++)
	{
		for (auto& iter : m_Particles[i])
		{
			iter->Release();
			SAFE_DELETE(iter);
		}
		m_Particles[i].clear();
	}
}
