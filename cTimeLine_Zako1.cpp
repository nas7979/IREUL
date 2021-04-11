#include "DXUT.h"
#include "cTimeLine_Zako1.h"


cTimeLine_Zako1::cTimeLine_Zako1()
{
}


cTimeLine_Zako1::~cTimeLine_Zako1()
{
}

void cTimeLine_Zako1::Init()
{
}

void cTimeLine_Zako1::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			for (int i = 0; i < 5; i++)
			{
				FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), 300, ORANGE);
			}
			FireEffect(m_Owner->GetPosition(), ORANGE);
			SOUND->Play("BulletFire1", -1500, true);
			break;

		case 30:
			m_Time = 0;
			break;
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako1::Render()
{
}

void cTimeLine_Zako1::RenderGlobal()
{
}

void cTimeLine_Zako1::Release()
{
}
