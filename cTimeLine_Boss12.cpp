#include "DXUT.h"
#include "cTimeLine_Boss12.h"
#include "cTimeLine_Boss121.h"
#include "cBoss1.h"


cTimeLine_Boss12::cTimeLine_Boss12()
{
}


cTimeLine_Boss12::~cTimeLine_Boss12()
{
}

void cTimeLine_Boss12::Init()
{
	GetComponent<cPath>()->AddPath(300, 0.99, Vec2(250 + 1100 * m_Owner->GetSide(), 250));
}

void cTimeLine_Boss12::Update()
{
	if (m_Owner->GetPosition() == Vec2(250 + 1100 * m_Owner->GetSide(), 250))
	{
		m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
		if (m_Last != (int)(m_Time * 10))
		{
			switch ((int)(m_Time * 10))
			{
			case 5:
			{
				cObject* a;
				for (int i = 0; i < 15; i++)
				{
					a = OBJECT->AddObject("Zako5", m_Owner->GetPosition(), 0.6, Obj_Enemy, m_Owner->GetSide());
					a->AddComponent<cZako>()->SetHp(50);
					a->AddComponent<cTimeLine_Boss121>()->SetDirection(SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()));
					a->GetComponent<cPath>()->AddPath(100, 1, m_Owner->GetPosition() + RotateVec(Vec2(2000, 0), i * 24));
				}
			}
				break;

			case 40:
				for (int i = 0; i < 10; i++)
				{
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), RED);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), GREEN);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), BLUE);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), YELLOW);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), PINK);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), SKYBLUE);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), ORANGE);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), YELLOWGREEN);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), PURPLE);
					FireBullet(0, m_Owner->GetPosition(), 9, Random(0, 359), Random(50, 300), MINT);
				}
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), RED);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), GREEN);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), BLUE);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), YELLOW);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), PINK);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), SKYBLUE);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), ORANGE);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), YELLOWGREEN);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), PURPLE);
				FireEffect(m_Owner->GetPosition() + Vec2(Random(-75, 75), Random(-75, 75)), MINT);
				SOUND->Play("BulletFire1", -1500, true);
				break;

			case 100:
				m_Time = 0;
				GetComponent<cBoss1>()->NextPhase();
			}
			m_Last = (int)(m_Time * 10);
		}
	}
}

void cTimeLine_Boss12::Render()
{
}

void cTimeLine_Boss12::RenderGlobal()
{
}

void cTimeLine_Boss12::Release()
{
}
