#include "DXUT.h"
#include "cTimeLine_Boss21.h"
#include "cBulletBounce.h"
#include "cBoss2.h"

cTimeLine_Boss21::cTimeLine_Boss21()
{
}


cTimeLine_Boss21::~cTimeLine_Boss21()
{
}

void cTimeLine_Boss21::Init()
{
	GetComponent<cBoss2>()->SetRot(Random(45, 135));
}

void cTimeLine_Boss21::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 20:
			m_Dir = Random(0, 359);
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
			for (int i = 0; i < 8; i++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Dir + i * 45, 1000, 250, 0.9, RED);
			}
			FireEffect(m_Owner->GetPosition(), RED);
			SOUND->Play("BulletFire2", -1500, true);
			m_Dir += 7;
			break;

		case 35:
		case 40:
		case 45:
		case 85:
		case 90:
		case 95:
			m_Dir = Random(0, 359);
			for (int i = 0; i < 16; i++)
			{
				FireBullet(4, m_Owner->GetPosition(), 25, m_Dir + i * 22.5, 400, YELLOW);
			}
			FireEffect(m_Owner->GetPosition(), YELLOW);
			SOUND->Play("BulletFire1", -1500, true);
			break;

		case 70:
			m_Dir = Random(0, 359);
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
			for (int i = 0; i < 8; i++)
			{
				FireFrictionBullet(0, m_Owner->GetPosition(), 9, m_Dir + i * 45, 1000, 250, 0.9, RED);
			}
			FireEffect(m_Owner->GetPosition(), RED);
			m_Dir -= 7;
			break;

		case 140:
			m_Time = 0;
			GetComponent<cBoss2>()->NextPhase();
		}

		if (GetComponent<cPath>()->GetSpeed() == 0 && m_Time < 9 && m_Time > 0.5)
		{
			for (float i = -2; i <= 2; i++)
			{
				cObject*a = OBJECT->AddObject("EnemyBullet", m_Owner->GetPosition() + RotateVec(Vec2(50, 0), 180 + m_Owner->GetRotation() + i * 100), 0.5, Obj_EnemyBullet, m_Owner->GetSide());
				a->AddComponent<cBulletBounce>()->SetSpeed(300);
				a->GetComponent<cBulletBounce>()->SetDirection(180 + m_Owner->GetRotation() + i * 100);
				a->GetComponent<cBulletBounce>()->SetBaseImage(m_BaseTex[0]);
				a->GetComponent<cBulletBounce>()->SetMaxBounceCount(4);
				a->GetComponent<cRenderer>()->SetImage(m_Tex[0]);
				a->GetComponent<cRenderer>()->SetColor(0xff909090);
				a->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 9);
				FireEffect(m_Owner->GetPosition() + RotateVec(Vec2(50, 0), 180 + m_Owner->GetRotation() + i * 100), 0xff909090);
			}
		}

		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss21::Render()
{
}

void cTimeLine_Boss21::RenderGlobal()
{
}

void cTimeLine_Boss21::Release()
{
}
