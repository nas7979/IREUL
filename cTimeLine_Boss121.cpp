#include "DXUT.h"
#include "cTimeLine_Boss121.h"


cTimeLine_Boss121::cTimeLine_Boss121()
{
}


cTimeLine_Boss121::~cTimeLine_Boss121()
{
}

void cTimeLine_Boss121::Init()
{
}

void cTimeLine_Boss121::Update()
{
	m_Time += DT + m_Dir * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 8:
		{
			cObject* a = FireBullet(0, m_Owner->GetPosition(), 9, m_Owner->GetRotation(), 0, SKYBLUE);
			a->SetAlarmSize(1);
			a->SetAlarm(0, 3 / (m_Dir + 1));
			a->SetAlarmFunc([=](int _Index)->void {
				a->Destroy();
				cObject* Bullet;
				for (int i = -1; i <= 1; i += 2)
				{
					Bullet = OBJECT->AddObject("EnemyBullet", a->GetPosition(), 0.5, Obj_EnemyBullet, a->GetSide());
					Bullet->AddComponent<cBulletFriction>()->SetBaseImage(IMAGE->Find("Bullet4"));
					Bullet->GetComponent<cBulletFriction>()->SetSpeed(50);
					Bullet->GetComponent<cBulletFriction>()->SetEndSpeed(300);
					Bullet->GetComponent<cBulletFriction>()->SetFriction(1.01);
					Bullet->GetComponent<cBulletFriction>()->SetDirection(a->GetRotation() + 90 * i);
					Bullet->GetComponent<cRenderer>()->SetImage(IMAGE->Find("Bullet_Color4"));
					Bullet->GetComponent<cRenderer>()->SetColor(RED);
					Bullet->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 7.5);
				}
				cParticleGlitch* Part = PART->AddParticle<cParticleGlitch>(IMAGE->Find("BulletFire"), a->GetPosition(), Vec2(0.5, 0.5), 0, 0.4, a->GetSide(), RED);
				Part->SetAlpha(255, -1000, 1);
				Part->SetScale(Vec2(25, 25), 0.99);
				Part->SetPosRand(6);
				Part->SetSizeRand(3);
			});
			SOUND->Play("Kira2", -1500, true);
			m_Time = 0;
		}
			break;

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss121::Render()
{
}

void cTimeLine_Boss121::RenderGlobal()
{
}

void cTimeLine_Boss121::Release()
{
}
