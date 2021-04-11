#include "DXUT.h"
#include "cTimeLine_Boss33.h"
#include "cBoss3.h"
#include "cBulletBounce.h"

cTimeLine_Boss33::cTimeLine_Boss33()
{
}


cTimeLine_Boss33::~cTimeLine_Boss33()
{
}

void cTimeLine_Boss33::Init()
{
}

void cTimeLine_Boss33::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			m_Dir = Random(0, 359);
			SOUND->Play("BulletFire1", -1500, true);
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
			for (int i = 0; i < 10; i++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Dir + i * 36, 1000, 100 + m_Last * 20, 0.9, GREEN);
			}
			FireEffect(m_Owner->GetPosition(), GREEN);
			break;

		case 25:
			m_Time = 0;
			GetComponent<cBoss3>()->NextPhase();
		}

		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss33::Render()
{
}

void cTimeLine_Boss33::RenderGlobal()
{
}

void cTimeLine_Boss33::Release()
{
}
