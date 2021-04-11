#include "DXUT.h"
#include "cTimeLine_Boss35.h"
#include "cBoss3.h"


cTimeLine_Boss35::cTimeLine_Boss35()
{
}


cTimeLine_Boss35::~cTimeLine_Boss35()
{
}

void cTimeLine_Boss35::Init()
{
	m_Dir = Random(-1.f, 1.f);
}

void cTimeLine_Boss35::Update()
{
	float Dir = PointDirection(m_Owner->GetPosition(), OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition());
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
		case 15:
		case 25:
		{
			float Dir = Random(0, 359);
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					FireFrictionBullet(0, m_Owner->GetPosition(), 9, Dir + i * 18 + (j * 2 * m_Dir), 500 + j * 100, 250 - j * 15, 0.95, MINT);
				}
			}
			FireEffect(m_Owner->GetPosition(), MINT);
			SOUND->Play("BulletFire1", -1500, true);

			Vec2 Pos;
			for (int i = 0; i < 12; i++)
			{
				Pos = m_Owner->GetPosition() + RotateVec(Vec2(125, 0), 30 * i);
				FireBullet(2, Pos, 7.5, PointDirection(Pos, OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition()), D3DXVec2Length(&(Pos - OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition())) / 1.5, PURPLE);
				FireEffect(Pos, PURPLE);
			}
		}
		break;

		case 40:
			m_Time = 0;
			GetComponent<cBoss3>()->NextPhase();

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss35::Render()
{
}

void cTimeLine_Boss35::RenderGlobal()
{
}

void cTimeLine_Boss35::Release()
{
}
