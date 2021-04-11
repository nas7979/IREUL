#include "DXUT.h"
#include "cTimeLine_Boss11.h"
#include "cBoss1.h"

cTimeLine_Boss11::cTimeLine_Boss11()
{
}


cTimeLine_Boss11::~cTimeLine_Boss11()
{
}

void cTimeLine_Boss11::Init()
{
}

void cTimeLine_Boss11::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			m_Dir = 0;
			m_RandDir = Random(0, 90);
			SOUND->Play("Kira1", -1500, true);
		case 8:
		case 11:
		case 14:
		case 17:
		case 20:
		case 23:
		case 26:
		{
			D3DCOLOR Color;
			for (int i = 0; i < 4 + m_Dir; i++)
			{
				Color = (Random(0, 1) == 0 ? PURPLE : Random(0, 1) == 0 ? GREEN : 0xff303030);
				FireFrictionBullet(1, m_Owner->GetPosition(), 7, m_RandDir + i * (360 / (4 + m_Dir)), 1000, 200, 0.94, Color);
				FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(50, 0), m_RandDir + i * (360 / (4 + m_Dir))), Color);
			}
			m_Dir += 4;
		}
			break;

		case 30:
			GetComponent<cPath>()->AddPath(Random(100, 400), 0.98, Vec2(Random(100, 400) + m_Owner->GetSide() * 1100, Random(100, 300)));
			break;

		case 40:
			SOUND->Play("BulletFire3", -1500, true);
			for (int i = 0; i < 5; i++)
			{
				FireFrictionBullet(0, Vec2(0 + m_Owner->GetSide() * 1100, 0), 9, i * 18, 1000, 250, 0.9, GREEN);
			}
			FireEffect(Vec2(0 + m_Owner->GetSide() * 1100, 0), GREEN);
			for (int i = 0; i < 5; i++)
			{
				FireFrictionBullet(0, Vec2(500 + m_Owner->GetSide() * 1100, 0), 9, 90 + i * 18, 1000, 250, 0.9, GREEN);
			}
			FireEffect(Vec2(500 + m_Owner->GetSide() * 1100, 0), GREEN);
			for (int i = 0; i < 5; i++)
			{
				FireFrictionBullet(0, Vec2(500 + m_Owner->GetSide() * 1100, 900), 9, 180 + i * 18, 1000, 250, 0.9, GREEN);
			}
			FireEffect(Vec2(500 + m_Owner->GetSide() * 1100, 900), GREEN);
			for (int i = 0; i < 5; i++)
			{
				FireFrictionBullet(0, Vec2(0 + m_Owner->GetSide() * 1100, 900), 9, 270 + i * 18, 1000, 250, 0.9, GREEN);
			}
			FireEffect(Vec2(0 + m_Owner->GetSide() * 1100, 900), GREEN);
			break;

		case 100:
			GetComponent<cBoss1>()->NextPhase();
			m_Time = 0;
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss11::Render()
{
}

void cTimeLine_Boss11::RenderGlobal()
{
}

void cTimeLine_Boss11::Release()
{
}
