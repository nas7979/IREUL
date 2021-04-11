#include "DXUT.h"
#include "cTimeLine_Boss32.h"
#include "cBoss3.h"

cTimeLine_Boss32::cTimeLine_Boss32()
{
}


cTimeLine_Boss32::~cTimeLine_Boss32()
{
}

void cTimeLine_Boss32::Init()
{
	m_Angle = Random(0, 1) == 0 ? -1 : 1;
}

void cTimeLine_Boss32::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			m_Dir = 0;
		case 7:
		case 9:
		case 11:
		case 13:
			for (int i = 0; i < 12; i++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Owner->GetRotation() + i * 30 + m_Dir, 800, 250, 0.95, BLUE);
			}
			m_Dir += 6 * m_Angle;
			FireEffect(m_Owner->GetPosition(), BLUE);
			SOUND->Play("BulletFire3", -1500, true);
			break;

		case 20:
			m_Time = 0;
			GetComponent<cBoss3>()->NextPhase();
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss32::Render()
{
}

void cTimeLine_Boss32::RenderGlobal()
{
}

void cTimeLine_Boss32::Release()
{
}
