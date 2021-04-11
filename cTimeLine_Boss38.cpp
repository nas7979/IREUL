#include "DXUT.h"
#include "cTimeLine_Boss38.h"
#include "cBoss3.h"

cTimeLine_Boss38::cTimeLine_Boss38()
{
}


cTimeLine_Boss38::~cTimeLine_Boss38()
{
}

void cTimeLine_Boss38::Init()
{
}

void cTimeLine_Boss38::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
		case 10:
		case 15:
		case 20:
		case 25:
			m_Dir = Random(0, 359);
			for (int i = 0; i < 24; i++)
			{
				FireFrictionBullet(1, m_Owner->GetPosition(), 7, m_Dir + i * 15, 600, 200, 0.98, PINK);
			}
			FireEffect(m_Owner->GetPosition(), PINK);
			SOUND->Play("BulletFire3", -1500, true);
			break;

		case 40:
			m_Time = 0;
			GetComponent<cBoss3>()->NextPhase();
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss38::Render()
{
}

void cTimeLine_Boss38::RenderGlobal()
{
}

void cTimeLine_Boss38::Release()
{
}
