#include "DXUT.h"
#include "cTimeLine_Zako3.h"


cTimeLine_Zako3::cTimeLine_Zako3()
{
}


cTimeLine_Zako3::~cTimeLine_Zako3()
{
}

void cTimeLine_Zako3::Init()
{
}

void cTimeLine_Zako3::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 10:
			m_Dir = 0;
		case 12:
		case 14:
		case 16:
		case 18:
			for (int i = 0; i < 6; i++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Owner->GetRotation() + i * 60 + m_Dir, 800, 250, 0.95, BLUE);
			}
			m_Dir += 6 * m_Angle;
			FireEffect(m_Owner->GetPosition(), BLUE);
			SOUND->Play("BulletFire3", -1500, true);
			break;

		case 30:
			m_Time = 0;

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako3::Render()
{
}

void cTimeLine_Zako3::RenderGlobal()
{
}

void cTimeLine_Zako3::Release()
{
}
