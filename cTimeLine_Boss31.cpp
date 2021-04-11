#include "DXUT.h"
#include "cTimeLine_Boss31.h"
#include "cBoss3.h"

cTimeLine_Boss31::cTimeLine_Boss31()
{
}


cTimeLine_Boss31::~cTimeLine_Boss31()
{
}

void cTimeLine_Boss31::Init()
{
}

void cTimeLine_Boss31::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			cObject* a;
			for (int i = 0; i < 10; i++)
			{
				a = FireFrictionBullet(0, m_Owner->GetPosition(), 9, i * 36, 700, 0, 0.95, RED);
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
			break;

		case 15:
			GetComponent<cBoss3>()->NextPhase();
			m_Time = 0;
		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss31::Render()
{
}

void cTimeLine_Boss31::RenderGlobal()
{
}

void cTimeLine_Boss31::Release()
{
}
