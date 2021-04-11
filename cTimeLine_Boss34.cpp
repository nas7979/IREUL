#include "DXUT.h"
#include "cTimeLine_Boss34.h"
#include "cBoss3.h"
#include "cBulletBounce.h"

cTimeLine_Boss34::cTimeLine_Boss34()
{
}


cTimeLine_Boss34::~cTimeLine_Boss34()
{
}

void cTimeLine_Boss34::Init()
{
}

void cTimeLine_Boss34::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
		case 10:
		case 15:
		case 20:
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					FireFrictionBullet(2, m_Owner->GetPosition() + RotateVec(Vec2(75, 0), m_Dir + i * 45), 7, m_Dir + i * 45 + 60, 600, 200 + j * 40, 0.9, YELLOW);
					FireFrictionBullet(2, m_Owner->GetPosition() + RotateVec(Vec2(75, 0), m_Dir + i * 45), 7, m_Dir + i * 45 - 60, 600, 200 + j * 40, 0.9, YELLOW);
				}
				FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(100, 400), BLUE);
				FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(75, 0), m_Dir + i * 45), YELLOW);
				FireEffect(m_Owner->GetPosition(), BLUE);
			}
			m_Dir += 10;
			SOUND->Play("BulletFire2", -1500, true);
			break;

		case 35:
			m_Time = 0;
			GetComponent<cBoss3>()->NextPhase();

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss34::Render()
{
}

void cTimeLine_Boss34::RenderGlobal()
{
}

void cTimeLine_Boss34::Release()
{
}
