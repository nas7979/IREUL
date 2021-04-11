#include "DXUT.h"
#include "cTimeLine_Zako2.h"


cTimeLine_Zako2::cTimeLine_Zako2()
{
}


cTimeLine_Zako2::~cTimeLine_Zako2()
{
}

void cTimeLine_Zako2::Init()
{
}

void cTimeLine_Zako2::Update()
{
	m_Time += DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 10:
		{
			cObject* a;
			for (int i = 0; i < 4; i++)
			{
				a = FireFrictionBullet(0, m_Owner->GetPosition(), 9, i * 90, 700, 0, 0.95, RED);
				a->SetAlarmSize(1);
				a->SetAlarmFunc([=](int _Index)->void {
						a->GetComponent<cBulletFriction>()->SetSpeed(500);
						a->GetComponent<cBulletFriction>()->SetFriction(1);
						a->GetComponent<cBulletFriction>()->SetDirection(PointDirection(a->GetPosition(), OBJECT->GetPlayer(a->GetSide())->GetPosition()));
					});
				a->SetAlarm(0, 0.7);
			}
			FireEffect(m_Owner->GetPosition(), RED);
			SOUND->Play("BulletFire1", -1500, true);
		}
		break;

		case 20:
			m_Loop++;
			if (m_Loop == 3)
			{
				GetComponent<cPath>()->AddPath(50, 1.01, m_Owner->GetPosition() + Vec2(500 * m_Dir, 300), m_Owner->GetPosition() + Vec2(0, 300));
			}
			else
			{
				m_Time = 0;
			}

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Zako2::Render()
{
}

void cTimeLine_Zako2::RenderGlobal()
{
}

void cTimeLine_Zako2::Release()
{
}
