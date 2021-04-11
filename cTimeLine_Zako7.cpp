#include "DXUT.h"
#include "cTimeLine_Zako7.h"


cTimeLine_Zako7::cTimeLine_Zako7()
{
}


cTimeLine_Zako7::~cTimeLine_Zako7()
{
}

void cTimeLine_Zako7::Init()
{
}

void cTimeLine_Zako7::Update()
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
			for (int j = -1; j <= 1; j++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Dir + j * 15, 750, 250, 0.98, GREEN);
			}
			FireEffect(m_Owner->GetPosition(), GREEN);
			SOUND->Play("BulletFire2", -1500, true);
		}
		break;

		case 40:
			m_Time = 0;
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako7::Render()
{
}

void cTimeLine_Zako7::RenderGlobal()
{
}

void cTimeLine_Zako7::Release()
{
}
