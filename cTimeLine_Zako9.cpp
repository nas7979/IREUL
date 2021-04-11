#include "DXUT.h"
#include "cTimeLine_Zako9.h"


cTimeLine_Zako9::cTimeLine_Zako9()
{
}


cTimeLine_Zako9::~cTimeLine_Zako9()
{
}

void cTimeLine_Zako9::Init()
{
}

void cTimeLine_Zako9::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 20:
		{
			float Dir = Random(0, 359);
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					FireFrictionBullet(0, m_Owner->GetPosition(), 9, Dir + i * 18 + (j * 2 * m_Dir), 500 + j * 100, 250 - j * 15, 0.95, MINT);
				}
			}
			FireEffect(m_Owner->GetPosition(), MINT);
			SOUND->Play("BulletFire1", -1500, true);

			Vec2 Pos;
			for (int i = 0; i < 12; i++)
			{
				Pos = m_Owner->GetPosition() + RotateVec(Vec2(125, 0), 30 * i);
				FireBullet(2, Pos, 7.5, PointDirection(Pos, OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition()), D3DXVec2Length(&(Pos - OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition())) / 1.5, PURPLE);
				FireEffect(Pos, PURPLE);
			}
			m_Loop++;
			if (m_Loop != 10)
			{
				m_Time = 0;
			}
			else
			{
				GetComponent<cPath>()->AddPath(50, 1.01, m_Owner->GetPosition() + Vec2(0, -500));
			}
		}
		break;

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako9::Render()
{
}

void cTimeLine_Zako9::RenderGlobal()
{
}

void cTimeLine_Zako9::Release()
{
}
