#include "DXUT.h"
#include "cStage3Scene.h"
#include "cBoss3.h"

cStage3Scene::cStage3Scene()
{
}


cStage3Scene::~cStage3Scene()
{
}

void cStage3Scene::Init()
{
	cStage::Init();
	m_TimeMax = 0.01;

	cObject* a;
	for (int i = 0; i < 2; i++)
	{
		a = OBJECT->AddObject("Boss", Vec2(250 + 1100 * i, 300), 0.5, Obj_Enemy, i);
		a->AddComponent<cBoss3>();
	}
}

void cStage3Scene::Update()
{
	cStage::Update();
	cObject* a;
	float XPos;
	for (m_Side = 0; m_Side < 2; m_Side++)
	{
		XPos = 1100 * m_Side;
		m_Time[m_Side] += DT + m_TimeSpeed[m_Side] * DT;

		if (m_Last[m_Side] != (int)(m_Time[m_Side] * 10))
		{
			switch ((int)(m_Time[m_Side] * 10))
			{

			}

			m_Last[m_Side] = (int)(m_Time[m_Side] * 10);
		}


		m_BackPos[m_Side] += m_TimeSpeed[m_Side] * DT * 100 + 300 * DT;
		if (m_BackPos[m_Side] >= 900)
		{
			m_BackPos[m_Side] -= 900;
		}
	}
}

void cStage3Scene::Render1()
{
	cStage::Render1();
}

void cStage3Scene::Render2()
{
	cStage::Render2();
}

void cStage3Scene::RenderGlobal()
{
	cStage::RenderGlobal();
}

void cStage3Scene::Release()
{
}
