#include "DXUT.h"
#include "cTimeLine_Boss37.h"
#include "cBoss3.h"

cTimeLine_Boss37::cTimeLine_Boss37()
{
}


cTimeLine_Boss37::~cTimeLine_Boss37()
{
}

void cTimeLine_Boss37::Init()
{
}

void cTimeLine_Boss37::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			m_Dir = PointDirection(m_Owner->GetPosition(), OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition());
		case 8:
		case 11:
		case 14:
		case 17:
		{
			for (int j = -4; j <= 4; j++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Dir + j * 15, 750, 250, 0.98, GREEN);
			}
			FireEffect(m_Owner->GetPosition(), GREEN);
			SOUND->Play("BulletFire2", -1500, true);
		}
		break;

		case 30:
			m_Time = 0;
			GetComponent<cBoss3>()->NextPhase();
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss37::Render()
{
}

void cTimeLine_Boss37::RenderGlobal()
{
}

void cTimeLine_Boss37::Release()
{
}
