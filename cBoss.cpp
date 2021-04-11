#include "DXUT.h"
#include "cBoss.h"


cBoss::cBoss()
{
}


cBoss::~cBoss()
{
}

void cBoss::Init()
{
	AddComponent<cPath>();
	AddComponent<cCollider>()->AddCollWith(Obj_PlayerBullet);
	GetComponent<cCollider>()->SetCollFunc([&](cObject* _Other)->void {
		switch (_Other->GetTag())
		{
		case Obj_PlayerBullet:
		{
			if (m_Start)
			{
				m_Hp -= _Other->GetComponent<cBulletBase>()->GetDamage();
			}
			_Other->Destroy();
			GetComponent<cRenderer>()->SetColor(0xffff0000);
			GetComponent<cRenderer>()->SetGlitchPosRand(Random(5.f, 15.f));
			GetComponent<cRenderer>()->SetGlitchSizeRand(Random(1, 5));
			GetComponent<cRenderer>()->SetGlitch(true);
			m_Owner->SetAlarm(0, 0.05);
			break;
		}
		}
		});

	m_Owner->SetAlarmSize(1);
	m_Owner->SetAlarmFunc([&](int _Index)->void {
		switch (_Index)
		{
		case 0:
			GetComponent<cRenderer>()->SetColor(0xffffffff);
			GetComponent<cRenderer>()->SetGlitch(false);
		}
		});

	m_Owner->SetRotation(90);
	m_Hp = 0;
	m_Start = false;
	m_Invincible = false;
}

void cBoss::Update()
{
	if (!m_Start)
	{
		m_Hp += m_MaxHp / 3 * DT;
		if (m_Hp >= m_MaxHp)
		{
			m_Hp = m_MaxHp;
			m_Start = true;
			NextPhase();
		}
	}

	if (m_Hp <= 0 && !m_Invincible)
	{
		Death();
	}
}

void cBoss::Render()
{
	if (m_Hp > 0)
	{
		IMAGE->Render(IMAGE->Find("BossHp"), Vec2(10 + m_Owner->GetSide() * 1100, 20), 0, Vec2(m_Hp / m_MaxHp * 480, 1), 0.2);
	}
}

void cBoss::RenderGlobal()
{
}

void cBoss::Release()
{
}

void cBoss::Death()
{
	for (auto& iter : OBJECT->Find(Obj_EnemyBullet, m_Owner->GetSide()))
	{
		iter->Destroy();
	}

	SYSTEM->AddScore(1, m_Owner->GetSide());
	SYSTEM->GameOver(m_Owner->GetSide());
	m_Owner->Destroy();
	SCENE->GetStage()->AddTimeSpeed(m_Time, m_Owner->GetSide());
	SOUND->Play("BossDeath", 0, true);

	Vec2 Pos = m_Owner->GetPosition();
	int Side = m_Owner->GetSide();
	Texture* Image = GetComponent<cRenderer>()->GetImage();
	float Rot = m_Owner->GetRotation();
	Vec2 Scale = m_Owner->GetScale();

	cParticleGlitch* Glit = PART->AddParticle<cParticleGlitch>(Image, Pos, Scale, Rot, 0.6, Side);
	Glit->SetAlpha(255 * 120, -255 * 60, 1);
	Glit->SetPosRand(1, 20, 1);
	Glit->SetSizeRand(1, 10, 1);
	Glit->SetBox(false);

	for (int i = 0; i < 5; i++)
	{
		SCHEDULE->AddSchedule(Random(0.f, 2.f), true, [=]()->bool {
			Vec2 RandPos = Pos + Vec2(Random(-50, 50), Random(-50, 50));
			cParticleGlitch* Glit = PART->AddParticle<cParticleGlitch>(Image, RandPos, Scale, Rot, 0.6, Side);
			Glit->SetAlpha(255 * Random(2, 10), -255 * 60, 1);
			Glit->SetPosRand(Random(5, 20));
			Glit->SetSizeRand(Random(10, 30));
			Glit->SetBox(true);

			int Rand;
			cParticleFunc* Func;
			for (int i = 0; i < 25; i++)
			{
				Rand = Random(0, 255);
				Func = PART->AddParticle<cParticleFunc>(IMAGE->Find("EnemyDeathParticle"), RandPos, Vec2(1, 1) * Random(0.5f, 0.75f), 0, 0.4, Side, D3DCOLOR_XRGB(Rand, Rand, Rand));
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
			SOUND->Play(RandomText("EnemyExplosion", 3), -1000, true);
			return true;
		});
	}

	SCHEDULE->AddSchedule(2, true, [=]()->bool {

		int Rand;
		cParticleFunc* Func;
		for (int i = 0; i < 100; i++)
		{
			Rand = Random(0, 255);
			Func = PART->AddParticle<cParticleFunc>(IMAGE->Find("EnemyDeathParticle"), Pos + Vec2(Random(-100,100),Random(-100,100)), Vec2(1, 1) * Random(0.5f, 0.75f), 0, 0.4, Side, D3DCOLOR_XRGB(Rand, Rand, Rand));
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

		cParticleGlitch* Glit = PART->AddParticle<cParticleGlitch>(Image, Pos, Scale, Rot, 0.6, Side);
		Glit->SetAlpha(255, -1000, 1);
		Glit->SetPosRand(5, 150, 1);
		Glit->SetSizeRand(3, 150, 1);
		Glit->SetScale(Vec2(10, 10), 0.98);
		Glit->SetBox(true);

		for (int i = 0; i < 6; i++)
		{
			Glit = PART->AddParticle<cParticleGlitch>(Image, Pos + RotateVec(Vec2(75, 0), i * 60) + Vec2(Random(-20, 20), Random(-20, 20)), Scale, Rot, 0.6, Side);
			Glit->SetAlpha(255 * Random(2, 10), -255 * 60, 1);
			Glit->SetPosRand(Random(25, 75), 0, 1);
			Glit->SetSizeRand(Random(20, 40), 0, 1);
			Glit->SetBox(true);
		}

		SOUND->Play("EnemyExplosion1", -1000, true);
		SOUND->Play("EnemyExplosion2", -1000, true);
		SOUND->Play("EnemyExplosion3", -1000, true);

		return true;
		});


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

void cBoss::NextPhase()
{
	if (m_Hp != m_MaxHp)
	{
		cObject* a;
		for (int i = 0; i < 30; i++)
		{
			a = OBJECT->AddObject("Item_SmallPower", m_Owner->GetPosition() + Vec2(Random(-125, 125), Random(-125, 125)), 0.4, Obj_Item, m_Owner->GetSide());
			a->AddComponent<cItem>();
		}
	}
}
