#include "DXUT.h"
#include "cItem.h"
#include "cPlayer.h"
#include "cBulletHoming.h"

cItem::cItem()
{
}


cItem::~cItem()
{
}

void cItem::Init()
{
	AddComponent<cRenderer>()->SetImage(IMAGE->Find(m_Owner->GetName()));
	AddComponent<cCollider>()->AddCollider(Vec2(0, 0), 5);
	GetComponent<cCollider>()->AddCollWith(Obj_Player);
	GetComponent<cCollider>()->SetCollFunc([&](cObject* _Other)->void {
		cPlayer* Player = _Other->GetComponent<cPlayer>();
		m_Owner->Destroy();
		
		bool FireBullet = false;
		if (m_Owner->GetName() == "Item_SmallPower")
		{
			Player->AddPower(0.05);
			if (m_CreatedByOpponentsDeath)
			{
				FireBullet = true;
			}
		}
		else if (m_Owner->GetName() == "Item_BigPower")
		{
			Player->AddPower(0.25);
			if (m_CreatedByOpponentsDeath)
			{
				FireBullet = true;
			}
		}
		SOUND->Play("Item", -500, true);

		if (FireBullet)
		{
			cObject* a;
			Emitter* Emitter;
			for (int i = 0; i < 5; i++)
			{
				int Color = Random(0, 255);
				a = OBJECT->AddObject("PlayerBullet", m_Owner->GetPosition(), 0.7, Obj_PlayerBullet, m_Owner->GetSide());
				a->AddComponent<cBulletHoming>()->SetDamage(1.5);
				a->GetComponent<cBulletHoming>()->SetSpeed(Random(500, 1500));
				a->GetComponent<cBulletHoming>()->SetDirection(Random(0, 359));
				if (OBJECT->Find(Obj_Enemy, m_Owner->GetSide()).size() != 0)
				{
					a->GetComponent<cBulletHoming>()->SetTarget(AtList<cObject*>(&OBJECT->Find(Obj_Enemy, m_Owner->GetSide()), Random(0, OBJECT->Find(Obj_Enemy, m_Owner->GetSide()).size() - 1)));
				}
				a->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 20);
				a->GetComponent<cRenderer>()->SetColor(D3DCOLOR_RGBA(255, 0, 0, 150));
				a->GetComponent<cRenderer>()->SetImage(IMAGE->Find("Bullet_Homing"));
				Emitter = a->AddComponent<cEmitter>()->AddEmitter(Vec2(0, 0), IMAGE->Find("EnemyDeathParticle"), 0.01, 0.7);
				Emitter->AlphaVel.Set(-1000, -1000);
				Emitter->G.Set(Color, Color);
				Emitter->B.Set(Color, Color);
				Emitter->Scale.Set(0.5, 1);
				Emitter->ScaleVel.Set(-4, -4);
				Emitter->Direction.Set(-20, 20);
				Emitter->SpeedVel.Set(50, 150);
				a->SetScale(Vec2(3, 3));
			}
		}
	});
	m_Speed = -300;
	m_Friction = 1;
	m_Magnetic = false;
	m_Arrow = IMAGE->Find(m_Owner->GetName() + "_Arrow");
	m_CreatedByOpponentsDeath = false;
}

void cItem::Update()
{
	if (m_Speed < 300)
	{
		m_Speed += 300 * DT;
	}

	if (m_Magnetic == false && m_CreatedByOpponentsDeath == false)
	{
		if (D3DXVec2Length(&(m_Owner->GetPosition() - OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition())) <= 100 && !OBJECT->GetPlayer(m_Owner->GetSide())->GetComponent<cPlayer>()->GetDead())
		{
			m_Magnetic = true;
			m_Speed = 800;
		}
		m_Owner->Translate(Vec2(0, m_Speed) * DT);
		m_Speed *= pow(m_Friction, DT * 60);
	}
	else
	{
		if (!(OBJECT->GetPlayer(m_Owner->GetSide())->GetComponent<cPlayer>()->GetDead() && m_CreatedByOpponentsDeath))
		{
			Vec2 Dir;
			D3DXVec2Normalize(&Dir, &(OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition() - m_Owner->GetPosition()));
			m_Owner->Translate(Dir * m_Speed * DT);
			m_Speed *= pow(m_Friction, DT * 60);
		}
	}

	if (m_Owner->GetPosition().y >= 1200)
	{
		m_Owner->Destroy();
	}
}

void cItem::Render()
{
	if (m_Owner->GetPosition().y <= -10)
	{
		IMAGE->CenterRender(m_Arrow, Vec2(m_Owner->GetPosition().x, 15), 0, Vec2(1, 1), 0.3);
	}
}

void cItem::RenderGlobal()
{
}

void cItem::Release()
{
}
