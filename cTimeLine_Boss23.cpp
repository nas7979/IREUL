#include "DXUT.h"
#include "cTimeLine_Boss23.h"
#include "cBoss2.h"
#include "cBulletBounce.h"

cTimeLine_Boss23::cTimeLine_Boss23()
{
}


cTimeLine_Boss23::~cTimeLine_Boss23()
{
}

void cTimeLine_Boss23::Init()
{
}

void cTimeLine_Boss23::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
		case 20:
		case 35:
		{
			D3DCOLOR Color;
			cObject* a;
			Vec2 Pos;
			for (int i = 0; i < 40; i++)
			{
				Color = GetColor(Random(0, 9));
				Pos = m_Owner->GetPosition() + RotateVec(Vec2(Random(0, 75), 0), Random(0, 359));				
				a = OBJECT->AddObject("EnemyBullet", Pos, 0.5, Obj_EnemyBullet, m_Owner->GetSide());
				a->AddComponent<cBulletBounce>()->SetSpeed(50);
				a->GetComponent<cBulletBounce>()->SetFriction(1.01);
				a->GetComponent<cBulletBounce>()->SetEndSpeed(250);
				a->GetComponent<cBulletBounce>()->SetDirection(180 + m_Owner->GetRotation() + i * 100);
				a->GetComponent<cBulletBounce>()->SetBaseImage(m_BaseTex[1]);
				a->GetComponent<cBulletBounce>()->SetMaxBounceCount(4);
				a->GetComponent<cRenderer>()->SetImage(m_Tex[1]);
				a->GetComponent<cRenderer>()->SetColor(Color);
				a->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 9);
				FireEffect(Pos, Color);
			}
			SOUND->Play("Kira1", -1500, true);
		}
		break;

		case 120:
			m_Time = 0;
			GetComponent<cBoss2>()->NextPhase();

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss23::Render()
{
}

void cTimeLine_Boss23::RenderGlobal()
{
}

void cTimeLine_Boss23::Release()
{
}
