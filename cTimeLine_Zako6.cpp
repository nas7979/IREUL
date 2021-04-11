#include "DXUT.h"
#include "cTimeLine_Zako6.h"


cTimeLine_Zako6::cTimeLine_Zako6()
{
}


cTimeLine_Zako6::~cTimeLine_Zako6()
{
}

void cTimeLine_Zako6::Init()
{
}

void cTimeLine_Zako6::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 10:
			m_Dir = PointDirection(m_Owner->GetPosition(), OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition());
		case 13:
		case 16:
			{
				for (float j = -3.5; j <= 3.5; j++)
				{
					FireBullet(0, m_Owner->GetPosition(), 9, m_Dir + j * 20, 450, RED);
				}
			}
			FireEffect(m_Owner->GetPosition(), RED);
			SOUND->Play("BulletFire1", -1500, true);
			break;

		case 40:
			m_Time = 0;
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako6::Render()
{
}

void cTimeLine_Zako6::RenderGlobal()
{
}

void cTimeLine_Zako6::Release()
{
}
