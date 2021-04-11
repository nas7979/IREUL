#include "DXUT.h"
#include "cZako.h"


cZako::cZako()
{
}


cZako::~cZako()
{
}

void cZako::Init()
{
	AddComponent<cRenderer>()->SetImage(IMAGE->Find(m_Owner->GetName()));
	AddComponent<cCollider>()->AddCollider(Vec2(0, 0), 45);
	AddComponent<cPath>();

	GetComponent<cCollider>()->AddCollWith(Obj_PlayerBullet);
	GetComponent<cCollider>()->SetCollFunc([&](cObject* _Other)->void {
		switch (_Other->GetTag())
		{
		case Obj_PlayerBullet:
		{
			_Other->Destroy();
			m_Hp -= _Other->GetComponent<cBulletBase>()->GetDamage();
			GetComponent<cRenderer>()->SetColor(0xffff0000);
			GetComponent<cRenderer>()->SetGlitchPosRand(Random(5.f, 15.f));
			GetComponent<cRenderer>()->SetGlitchSizeRand(Random(5, 10));
			GetComponent<cRenderer>()->SetGlitch(true);
			m_Owner->SetAlarm(0, 0.05);
			break;
		}
		}
	});

	m_Owner->SetScale(Vec2(0.75, 0.75));
	m_Owner->SetAlarmSize(1);
	m_Owner->SetAlarmFunc([&](int _Index)->void {
		switch (_Index)
		{
		case 0:
			GetComponent<cRenderer>()->SetColor(0xffffffff);
			GetComponent<cRenderer>()->SetGlitch(false);
		}
	});
}

void cZako::Update()
{
	if (m_Hp <= 0)
	{
		Death();
	}
	IsOutMap();
	m_Owner->SetRotation(GetComponent<cPath>()->GetDirection());
}

void cZako::Render()
{
}

void cZako::RenderGlobal()
{
}

void cZako::Release()
{
}

void cZako::Death()
{
	m_Owner->Destroy();
	SCENE->GetStage()->AddTimeSpeed(m_Time, m_Owner->GetSide());
	SOUND->Play(RandomText("EnemyExplosion", 3), -1000, true);
	
	cObject* a;
	for (int i = 0; i < m_SmallItem; i++)
	{
		a = OBJECT->AddObject("Item_SmallPower", m_Owner->GetPosition() + Vec2(Random(-25, 25), Random(-25, 25)), 0.4, Obj_Item, m_Owner->GetSide());
		a->AddComponent<cItem>();
	}
	for (int i = 0; i < m_BigItem; i++)
	{
		a = OBJECT->AddObject("Item_BigPower", m_Owner->GetPosition() + Vec2(Random(-25, 25), Random(-25, 25)), 0.4, Obj_Item, m_Owner->GetSide());
		a->AddComponent<cItem>();
	}

	cParticleGlitch* Glit = PART->AddParticle<cParticleGlitch>(GetComponent<cRenderer>()->GetImage(), m_Owner->GetPosition(), m_Owner->GetScale(), m_Owner->GetRotation(), 0.6, m_Owner->GetSide());
	Glit->SetAlpha(255, -1000, 1);
	Glit->SetPosRand(5, 150, 1);
	Glit->SetSizeRand(3, 150, 1);
	Glit->SetScale(Vec2(10, 10), 0.98);
	Glit->SetBox(true);

	cParticleFunc* Func;
	int Rand;
	for (auto& iter : GetComponent<cCollider>()->GetColliders())
	{
		for (int i = 0; i < 20; i++)
		{
			Rand = Random(0, 255);
			Func = PART->AddParticle<cParticleFunc>(IMAGE->Find("EnemyDeathParticle"), iter.GetRandomPosInCollider(), Vec2(1, 1) * Random(0.5f, 0.75f), 0, 0.4, m_Owner->GetSide(), D3DCOLOR_XRGB(Rand, Rand, Rand));
			Func->SetFuncSpeed(0.02);
			Func->SetSpeed(Random(100, 600), 0.96, Random(0, 359));
			Func->SetFunc([](cParticleFunc* _Part)->void {
				_Part->SetRotFri(_Part->GetRotFri() + Random(1.f, 5.f));
				if (Random(0, 300) <= _Part->GetRotFri())
				{
					_Part->SetAlpha(0.1);
				}
				else
				{
					_Part->SetAlpha(255);
				}
				if (_Part->GetRotFri() >= 200)
				{
					_Part->SetAlpha(0);
				}
				});
		}
	}
}

void cZako::IsOutMap()
{
	Vec2 Pos = m_Owner->GetPosition();
	if (m_Owner->GetSide() == 0)
	{
		if (Pos.x <= -100 || Pos.x >= 600 || Pos.y <= -100 || Pos.y >= 1000)
		{
			m_Owner->Destroy();
		}
	}
	else
	{
		if (Pos.x <= 1000 || Pos.x >= 1700 || Pos.y <= -100 || Pos.y >= 1000)
		{
			m_Owner->Destroy();
		}
	}
}
