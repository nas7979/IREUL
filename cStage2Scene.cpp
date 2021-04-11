#include "DXUT.h"
#include "cStage2Scene.h"
#include "cTimeLine_Zako1.h"
#include "cTimeLine_Zako2.h"
#include "cTimeLine_Zako3.h"
#include "cTimeLine_Zako4.h"
#include "cTimeLine_Zako5.h"
#include "cTimeLine_Zako6.h"
#include "cTimeLine_Zako7.h"
#include "cTimeLine_Zako8.h"
#include "cTimeLine_Zako9.h"
#include "cBoss2.h"

cStage2Scene::cStage2Scene()
{
}


cStage2Scene::~cStage2Scene()
{
}

void cStage2Scene::Init()
{
	cStage::Init();
	m_TimeMax = 76;
}

void cStage2Scene::Update()
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
				a = AddZako<cTimeLine_Zako5>("Zako4", Vec2(250 + XPos, -50), 150, 0.1);
				AddPath(a, 300, 0.99, Vec2(250 + XPos, 250));
				AddItem(a, 7, 3);
				SCHEDULE->AddSchedule(14, false, [=]()->bool {
					if (a->GetDestroyed())
					{
						m_Time[a->GetSide()] = 13.5;
						return false;
					}
					return true;
				});
				break;

			case 150:
			case 220:
				for (int i = -1; i <= 1; i += 2)
				{
					a = AddZako<cTimeLine_Zako7>("Zako1", Vec2(250 + 300 * i + XPos, 150), 35, 0.01);
					AddPath(a, 125, 1, Vec2(250 - 400 * i + XPos, 150));
					AddItem(a, 3, 1);
				}
				break;

			case 160:
			case 230:
				for (int i = -1; i <= 1; i += 2)
				{
					a = AddZako<cTimeLine_Zako6>("Zako4", Vec2(250 + 300 * i + XPos, 200), 53, 0.01);
					AddPath(a, 125, 1, Vec2(250 - 400 * i + XPos, 200));
					AddItem(a, 3, 1);
				}
				break;

			case 190:
			case 205:
			case 221:
			case 235:
			case 250:
			case 265:
			case 280:
				for (int i = -1; i <= 1; i += 2)
				{
					a = AddZako<cTimeLine_Zako3>("Zako2", Vec2(250 + i * 300 + XPos, 300), 8, 0.005);
					a->GetComponent<cTimeLine_Zako3>()->SetAngle(i);
					AddItem(a, 5, 0);
					AddPath(a, 400, 0.995, Vec2(250 + XPos, -200), Vec2(250 + XPos, 400));
				}
				break;

			case 310:
			case 315:
			case 320:
			case 325:
			case 330:
			case 335:
			case 340:
			case 345:
			case 350:
			case 355:
			case 360:
			case 365:
			case 370:
			case 375:
			case 380:
			case 385:
			case 390:
			case 395:
			case 400:
			case 405:
			case 410:
			case 415:
			case 420:
			case 425:
			case 430:
			case 435:
			case 440:
			case 445:
			case 450:
			case 455:
			case 460:
			case 465:
			case 470:
			case 475:
			case 480:
				for (int i = -1; i <= 1; i += 2)
				{
					a = AddZako<cTimeLine_Zako8>("Zako1", Vec2(250 + i * 300 + XPos, Random(0, 400)), 5, 0.001);
					AddPath(a, 300, 1, Vec2(250 - i * 400 + XPos, Random(0, 400)), Vec2(Random(0, 500) + XPos, Random(0, 500)));
					AddItem(a, 2, 0);
				}
				break;

			case 530:
				a = AddZako<cTimeLine_Zako9>("Zako3", Vec2(150 + XPos, -50), 500, 0.1);
				a->GetComponent<cTimeLine_Zako9>()->SetDirection(1);
				AddPath(a, 250, 0.99, Vec2(150 + XPos, 250));
				AddItem(a, 5, 3);
				break;

			case 560:
				a = AddZako<cTimeLine_Zako9>("Zako3", Vec2(350 + XPos, -50), 500, 0.1);
				a->GetComponent<cTimeLine_Zako9>()->SetDirection(-1);
				AddPath(a, 250, 0.99, Vec2(350 + XPos, 250));
				AddItem(a, 5, 3);
				break;

			case 600:
			case 660:
				for (int i = -1; i <= 1; i++)
				{
					a = AddZako<cTimeLine_Zako2>("Zako2", Vec2(250 + 150 * i, -50), 25, 0.025);
					AddPath(a, 150, 1, Vec2(250 + 150 * i, 2000));
					AddItem(a, 3, 1);
				}
				break;


			case 760:
				a = OBJECT->AddObject("Boss", Vec2(250 + XPos, -200), 0.5, Obj_Enemy, m_Side);
				a->AddComponent<cBoss2>();
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

void cStage2Scene::Render1()
{
	cStage::Render1();
}

void cStage2Scene::Render2()
{
	cStage::Render2();
}

void cStage2Scene::RenderGlobal()
{
	cStage::RenderGlobal();
}

void cStage2Scene::Release()
{
}
