#include "DXUT.h"
#include "cTimeLine_Zako8.h"


cTimeLine_Zako8::cTimeLine_Zako8()
{
}


cTimeLine_Zako8::~cTimeLine_Zako8()
{
}

void cTimeLine_Zako8::Init()
{
}

void cTimeLine_Zako8::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			for (int i = 0; i < 12; i++)
			{
				FireFrictionBullet(1, m_Owner->GetPosition(), 7, m_Owner->GetRotation() + i * 30, 600, 200, 0.98, PINK);
			}
			FireEffect(m_Owner->GetPosition(), PINK);
			SOUND->Play("BulletFire3", -1500, true);
			break;

		case 15:
			m_Time = 0;
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako8::Render()
{
}

void cTimeLine_Zako8::RenderGlobal()
{
}

void cTimeLine_Zako8::Release()
{
}
