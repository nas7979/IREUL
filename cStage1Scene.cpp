#include "DXUT.h"
#include "cStage1Scene.h"
#include "cTimeLine_Zako1.h"
#include "cTimeLine_Zako2.h"
#include "cTimeLine_Zako3.h"
#include "cTimeLine_Zako4.h"
#include "cPlayer.h"
#include "cBackgroundEffect.h"
#include "cBoss1.h"

cStage1Scene::cStage1Scene()
{
}


cStage1Scene::~cStage1Scene()
{
}

void cStage1Scene::Init()
{
	cStage::Init();
	m_Time[0] = m_Time[1] = 0;
	m_TimeMax = 70;
}

void cStage1Scene::Update()
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
			case 10:
			case 16:
			case 22:
			case 28:
			case 34:
			case 40:
			case 46:
			case 52:
				for (int i = -1; i <= 1; i += 2)
				{
					a = AddZako<cTimeLine_Zako1>("Zako1", Vec2(250 + 150 * i + XPos, -50), 7, 0.005);
					AddPath(a, 300, 1, Vec2(250 + 400 * i + XPos, 800), Vec2(250 + XPos, 450));
					AddItem(a, 3, 0);
				}
				break;

			case 110:
			case 260:
				for (int i = -1; i <= 1; i++)
				{
					a = AddZako<cTimeLine_Zako2>("Zako3", Vec2(150 + i * 75 + XPos, -50), 75, 0.02);
					AddPath(a, 300, 0.97, Vec2(150 + i * 75 + XPos, 300));
					AddItem(a, 5, 1);
					a->GetComponent<cTimeLine_Zako2>()->SetDirection(-1);
				}
				break;

			case 180:
			case 340:
				for (int i = -1; i <= 1; i++)
				{
					a = AddZako<cTimeLine_Zako2>("Zako3", Vec2(350 + i * 75 + XPos, -50), 75, 0.02);
					AddPath(a, 300, 0.97, Vec2(350 + i * 75 + XPos, 300));
					AddItem(a, 5, 1);
					a->GetComponent<cTimeLine_Zako2>()->SetDirection(1);
				}
				break;

			case 200:
			case 250:
			case 300:
			case 350:
			case 400:
				for (int i = -1; i <= 1; i += 2)
				{
					a = AddZako<cTimeLine_Zako3>("Zako2", Vec2(250 + i * 300 + XPos, 300), 15, 0.0075);
					a->GetComponent<cTimeLine_Zako3>()->SetAngle(i);
					AddItem(a, 4, 0);
					AddPath(a, 400, 0.995, Vec2(250 + XPos, -200), Vec2(250 + XPos, 400));
				}
				break;

			case 460:
				for (int i = -3; i <= 3; i++)
				{
					a = AddZako<cTimeLine_Zako4>("Zako4", Vec2(250 + 60 * i + XPos, -50), 50, 0.01);
					a->GetComponent<cTimeLine_Zako4>()->SetAngle(1);
					AddItem(a, 5, 0);
					AddPath(a, 300, 0.98, Vec2(250 + 60 * i + XPos, 300));
				}
				break;

			case 560:
				for (int i = -3; i <= 3; i++)
				{
					a = AddZako<cTimeLine_Zako4>("Zako4", Vec2(250 + 60 * i + XPos, -50), 50, 0.01);
					a->GetComponent<cTimeLine_Zako4>()->SetAngle(-1);
					AddItem(a, 5, 0);
					AddPath(a, 300, 0.98, Vec2(250 + 60 * i + XPos, 300));
				}
				break;

			case 700:
				a = OBJECT->AddObject("Boss", Vec2(250 + XPos, -200), 0.5, Obj_Enemy, m_Side);
				a->AddComponent<cBoss1>();
				AddPath(a, 350, 0.99, Vec2(250 + XPos, 250));
				break;

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

void cStage1Scene::Render1()
{
	cStage::Render1();
}

void cStage1Scene::Render2()
{
	cStage::Render2();
}

void cStage1Scene::RenderGlobal()
{
	cStage::RenderGlobal();
}

void cStage1Scene::Release()
{
}
