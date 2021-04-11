#include "DXUT.h"
#include "cTimeLine_Boss24.h"
#include "cBoss2.h"

cTimeLine_Boss24::cTimeLine_Boss24()
{
}


cTimeLine_Boss24::~cTimeLine_Boss24()
{
}

void cTimeLine_Boss24::Init()
{
}

void cTimeLine_Boss24::Update()
{
	float Dir = PointDirection(m_Owner->GetPosition(), OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition());
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			GetComponent<cPath>()->AddPath(300, 0.98, Vec2(Random(100, 400) + 1100 * m_Owner->GetSide(), Random(100, 350)));
			break;

		case 20:
		case 25:
		case 30:
		case 35:
		case 40:
		case 45:
			FireBullet(4, m_Owner->GetPosition() + RotateVec(Vec2(50,0), Dir), 25, Dir, 400, PURPLE);
			FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(50, 0), Dir), PURPLE);

			for (int i = -3; i <= 3; i++)
			{
				FireBullet(2, m_Owner->GetPosition() + RotateVec(Vec2(50, 0), Dir + i * 9), 7.5, Dir + i * 9, 400, RED);
				FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(50, 0), Dir + i * 9), RED);
			}

			for (int i = 0; i < 12; i++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, Dir + Random(-25.f, 25.f), 800, Random(150, 350), 0.94, SKYBLUE);
			}
			FireEffect(m_Owner->GetPosition(), SKYBLUE);
			SOUND->Play("BulletFire1", -1500, true);
			break;

		case 80:
		case 85:
		case 90:
		case 95:
		case 100:
		case 105:
			m_Dir = Random(0, 359);
			for (int i = 0; i < 5; i++)
			{
				for (float j = -1.5; j <= 1.5; j++)
				{
					FireBullet(4, m_Owner->GetPosition(), 25, m_Dir + i * 72 + j * 5, 250, SKYBLUE);
				}
			}
			FireEffect(m_Owner->GetPosition(), SKYBLUE);

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					FireFrictionBullet(2, m_Owner->GetPosition(), 7.5, m_Dir + i * 40 + j * 8, 700 + j * 50, 300, 0.9, RED);
				}
			}
			FireEffect(m_Owner->GetPosition(), RED);

			for (int i = 0; i < 12; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Dir + i * 30 + j * 6.5, 50, 500, 1.015, PURPLE);
				}
			}
			FireEffect(m_Owner->GetPosition(), PURPLE);
			SOUND->Play("BulletFire2", -1500, true);
			break;

		case 150:
			m_Time = 0;
			GetComponent<cBoss2>()->NextPhase();

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss24::Render()
{
}

void cTimeLine_Boss24::RenderGlobal()
{
}

void cTimeLine_Boss24::Release()
{
}
