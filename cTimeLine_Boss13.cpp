#include "DXUT.h"
#include "cTimeLine_Boss13.h"
#include "cBoss1.h"

cTimeLine_Boss13::cTimeLine_Boss13()
{
}


cTimeLine_Boss13::~cTimeLine_Boss13()
{
}

void cTimeLine_Boss13::Init()
{
}

void cTimeLine_Boss13::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
		case 15:
		case 25:
		case 35:
		case 45:
		case 55:
		case 65:
		case 75:
		case 85:
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					FireFrictionBullet(0, m_Owner->GetPosition() + RotateVec(Vec2(125, 0), i * 60), 9, j * 30, 700, 200, 0.95, MINT);
				}
				FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(125, 0), i * 60), MINT);
			}
			for (int i = 0; i < 3; i++)
			{
				FireBullet(0, m_Owner->GetPosition() + RotateVec(Vec2(200, 0), 30 + i * 120), 9, PointDirection(m_Owner->GetPosition() + RotateVec(Vec2(200, 0), 30 + i * 120), OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition()), 350, YELLOW);
				FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(200, 0), 30 + i * 120), YELLOW);
			}
			SOUND->Play("BulletFire3", -1500, true);
			break;

		case 120:
			m_Time = 0;
			GetComponent<cBoss1>()->NextPhase();
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss13::Render()
{
}

void cTimeLine_Boss13::RenderGlobal()
{
}

void cTimeLine_Boss13::Release()
{
}
