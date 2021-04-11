#include "DXUT.h"
#include "cTimeLine_Boss36.h"
#include "cBoss3.h"

cTimeLine_Boss36::cTimeLine_Boss36()
{
}


cTimeLine_Boss36::~cTimeLine_Boss36()
{
}

void cTimeLine_Boss36::Init()
{
}

void cTimeLine_Boss36::Update()
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
			for (float j = -4.5; j <= 4.5; j++)
			{
				FireBullet(0, m_Owner->GetPosition(), 9, m_Dir + j * 20, 450, RED);
			}
		}
		FireEffect(m_Owner->GetPosition(), RED);
		SOUND->Play("BulletFire1", -1500, true);
		break;

		case 30:
			m_Time = 0;
			GetComponent<cBoss3>()->NextPhase();
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss36::Render()
{
}

void cTimeLine_Boss36::RenderGlobal()
{
}

void cTimeLine_Boss36::Release()
{
}
