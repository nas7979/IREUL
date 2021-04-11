#include "DXUT.h"
#include "cTimeLine_Zako5.h"


cTimeLine_Zako5::cTimeLine_Zako5()
{
}


cTimeLine_Zako5::~cTimeLine_Zako5()
{
}

void cTimeLine_Zako5::Init()
{
}

void cTimeLine_Zako5::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 20:
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					FireFrictionBullet(2, m_Owner->GetPosition() + RotateVec(Vec2(75, 0), m_Dir + i * 45), 7, m_Dir + i * 45 + 60, 600, 200 + j * 40, 0.9, YELLOW);
					FireFrictionBullet(2, m_Owner->GetPosition() + RotateVec(Vec2(75, 0), m_Dir + i * 45), 7, m_Dir + i * 45 - 60, 600, 200 + j * 40, 0.9, YELLOW);
				}
				FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(100, 400), BLUE);
				FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(75, 0), m_Dir + i * 45), YELLOW);
				FireEffect(m_Owner->GetPosition(), BLUE);
			}
			m_Dir += 10;
			m_Loop++;
			if (m_Loop != 20)
			{
				m_Time = 1.4;
			}
			else
			{
				GetComponent<cPath>()->AddPath(50, 1.01, m_Owner->GetPosition() + Vec2(0, -500));
			}
			SOUND->Play("BulletFire2", -1500, true);
			break;

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako5::Render()
{
}

void cTimeLine_Zako5::RenderGlobal()
{
}

void cTimeLine_Zako5::Release()
{
}
