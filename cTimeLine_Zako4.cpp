#include "DXUT.h"
#include "cTimeLine_Zako4.h"

cTimeLine_Zako4::cTimeLine_Zako4()
{
}

cTimeLine_Zako4::~cTimeLine_Zako4()
{
}

void cTimeLine_Zako4::Init()
{
}

void cTimeLine_Zako4::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 10:
			m_Dir = Random(0, 359);
			SOUND->Play("BulletFire1", -1500, true);
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
			for (int i = 0; i < 5; i++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Dir + i * 72, 1000, 100 + m_Last * 20, 0.9, GREEN);
			}
			FireEffect(m_Owner->GetPosition(), GREEN);
			break;

		case 20:
			if (m_Loop != 4)
			{
				m_Loop++;
				m_Time = 0.7;
			}
			else
			{
				GetComponent<cPath>()->AddPath(50, 1.01, m_Owner->GetPosition() + Vec2(700 * m_Angle, 500), m_Owner->GetPosition() + Vec2(0, 400));
			}
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako4::Render()
{
}

void cTimeLine_Zako4::RenderGlobal()
{
}

void cTimeLine_Zako4::Release()
{
}
