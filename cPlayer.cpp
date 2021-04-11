#include "DXUT.h"
#include "cPlayer.h"
#include "cBullet.h"
#include "cBulletHoming.h"
#include "cEnemy.h"

cPlayer::cPlayer()
{
}


cPlayer::~cPlayer()
{
}

void cPlayer::Init()
{
	AddComponent<cRenderer>();
	AddComponent<cAnimation>()->AddAnimation("Idle", "Player", 0.03, false);
	GetComponent<cAnimation>()->SetAnimation("Idle");
	GetComponent<cAnimation>()->SetSpeed(0);
	AddComponent<cCollider>()->AddCollider(Vec2(0, 0), 4);
	GetComponent<cCollider>()->AddCollWith(Obj_Enemy);
	GetComponent<cCollider>()->AddCollWith(Obj_EnemyBullet);
	GetComponent<cCollider>()->SetCollFunc([&](cObject* _Other)->void {
		switch (_Other->GetTag())
		{
		case Obj_Enemy:
			if (!m_Invincible)
			{
				Death();
			}
			break;

		case Obj_EnemyBullet:
			if (!m_Invincible)
			{
				_Other->Destroy();
				Death();
			}
			break;
		}
	});

	m_Speed = 600;
	m_Power = 0;
	m_Life = 4;
	m_AttackAble = true;
	m_Dead = false;
	m_Slow = false;
	m_Invincible = false;
	m_Owner->SetRotation(270);
	m_Owner->SetScale(Vec2(0.75, 0.75));
	OBJECT->SetPlayer(m_Owner, m_Owner->GetSide());
	m_Ring = OBJECT->AddObject("Ring", m_Owner->GetPosition() + Vec2(1, 60), 0.5, Obj_None, m_Owner->GetSide());
	m_Ring->AddComponent<cRenderer>();
	m_Ring->AddComponent<cAnimation>()->AddAnimation("Start", "Ring_Start", 0.25, false);
	m_Ring->GetComponent<cAnimation>()->AddAnimation("Idle", "Ring_Idle", 0.15, true);
	m_Ring->GetComponent<cAnimation>()->SetAnimation("Start");
	m_Ring->SetRotation(270);
	m_Ring->SetScale(Vec2(0.75, 0.75));

	m_Owner->SetAlarmSize(4);
	m_Owner->SetAlarm(3, 1);
	m_Owner->SetAlarmFunc([&](int _Index)->void {
		switch (_Index)
		{
		case 0:
			m_AttackAble = true;
			break;

		case 1:
			GetComponent<cRenderer>()->SetEnable(true);
			m_Ring->GetComponent<cRenderer>()->SetEnable(true);
			m_Ring->GetComponent<cRenderer>()->SetGlitch(true);
			GetComponent<cRenderer>()->SetGlitchPosRand(30);
			GetComponent<cRenderer>()->SetGlitchSizeRand(12);
			GetComponent<cRenderer>()->SetGlitch(true);
			GetComponent<cCollider>()->SetEnable(true);
			SCHEDULE->AddSchedule(1, false, [&]()->bool {
				GetComponent<cRenderer>()->SetGlitchPosRand(GetComponent<cRenderer>()->GetGlitchPosRand() - 30 * DT);
				GetComponent<cRenderer>()->SetGlitchSizeRand(GetComponent<cRenderer>()->GetGlitchSizeRand() - 10 * DT);
				return true;
			});
			m_Owner->SetPosition(Vec2(250 + 1100 * m_Owner->GetSide(), 600));
			m_Dead = false;
			m_Ring->GetComponent<cAnimation>()->SetAnimation("Start");
			m_Owner->SetAlarm(3, 1);
			break;

		case 2:
			GetComponent<cRenderer>()->SetColor(0xffffffff);
			GetComponent<cRenderer>()->SetGlitch(false);
			m_Ring->GetComponent<cRenderer>()->SetColor(0xffffffff);
			m_Ring->GetComponent<cRenderer>()->SetGlitch(false);
			GetComponent<cCollider>()->AddCollWith(Obj_Enemy);
			GetComponent<cCollider>()->AddCollWith(Obj_EnemyBullet);
			break;

		case 3:
			m_Ring->GetComponent<cAnimation>()->SetAnimation("Idle");
		}
	});
}

void cPlayer::Update()
{
	if (INPUT->KeyDown(VK_F1) && m_Owner->GetSide() == 1)
	{
		m_Invincible = !m_Invincible;
	}
	if (m_Dead)
	{
		if (m_Life != 0)
		{
			for (auto& iter : OBJECT->Find(Obj_EnemyBullet, m_Owner->GetSide()))
			{
				iter->Destroy();
			}
		}
		return;
	}

	if (!INPUT->KeyPress(m_Keys[Key_Left]) || !INPUT->KeyPress(m_Keys[Key_Right]))
	{
		GetComponent<cAnimation>()->SetSpeed(-1);
	}

	if (INPUT->KeyPress(m_Keys[Key_Left]) && m_Owner->GetPosition().x > 10 + 1100 * m_Owner->GetSide())
	{
		m_Owner->Translate(Vec2(-m_Speed, 0) * DT);
		if (GetComponent<cAnimation>()->GetFrame() != 0 && m_Owner->GetScale().y == -0.75)
		{
			GetComponent<cAnimation>()->SetSpeed(-1);
		}
		else
		{
			m_Owner->SetScale(Vec2(0.75, 0.75));
			GetComponent<cAnimation>()->SetSpeed(1);
		}
	}

	if (INPUT->KeyPress(m_Keys[Key_Right]) && m_Owner->GetPosition().x < 490 + 1100 * m_Owner->GetSide())
	{
		m_Owner->Translate(Vec2(m_Speed, 0) * DT);
		GetComponent<cAnimation>()->SetSpeed(1);
		if (GetComponent<cAnimation>()->GetFrame() != 0 && m_Owner->GetScale().y == 0.75)
		{
			GetComponent<cAnimation>()->SetSpeed(-1);
		}
		else
		{
			m_Owner->SetScale(Vec2(0.75, -0.75));
			GetComponent<cAnimation>()->SetSpeed(1);
		}
	}

	if (INPUT->KeyPress(m_Keys[Key_Up]) && m_Owner->GetPosition().y > 30)
	{
		m_Owner->Translate(Vec2(0, -m_Speed) * DT);
	}
	if (INPUT->KeyPress(m_Keys[Key_Down]) && m_Owner->GetPosition().y < 870)
	{
		m_Owner->Translate(Vec2(0, m_Speed) * DT);
	}

	if (INPUT->KeyPress(m_Keys[Key_Slow]))
	{
		m_Slow = true;
		m_Speed = 300;
	}
	else
	{
		m_Slow = false;
		m_Speed = 600;
	}

	if (INPUT->KeyPress(m_Keys[Key_Attack]))
	{
		if (m_AttackAble == true)
		{
			m_AttackAble = false;
			cObject* a;
			if (!m_Slow)
			{
				int Count = 1 + m_Power * 0.5;
				for (int i = -Count; i <= Count; i++)
				{
					a = OBJECT->AddObject("PlayerBullet", m_Owner->GetPosition(), 0.7, Obj_PlayerBullet, m_Owner->GetSide());
					a->AddComponent<cBullet>()->SetDamage(m_Power / (Count * 3) + 1.5);
					a->GetComponent<cBullet>()->SetSpeed(3000);
					a->GetComponent<cBullet>()->SetDirection(270 + i * (10 - Count * 2));
					a->GetComponent<cBullet>()->SetBaseImage(IMAGE->Find("Bullet2"));
					a->GetComponent<cRenderer>()->SetEnable(false);
					a->GetComponent<cRenderer>()->SetColor(SKYBLUE);
					a->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 20);
					a->SetScale(Vec2(2, 2));
				}
				m_Owner->SetAlarm(0, 0.1);
				SOUND->Play("PlayerFire1", -1500, false)->SetFrequency(Random(40000,45000));
			}
			else
			{
				Emitter* Emitter;
				for (int i = 0; i < 5; i++)
				{
					a = OBJECT->AddObject("PlayerBullet", m_Owner->GetPosition(), 0.7, Obj_PlayerBullet, m_Owner->GetSide());
					a->AddComponent<cBulletHoming>()->SetDamage(m_Power / 5 + 1);
					a->GetComponent<cBulletHoming>()->SetSpeed(1250);
					a->GetComponent<cBulletHoming>()->SetDirection(Random(220, 320));
					a->GetComponent<cBulletHoming>()->SetTarget(OBJECT->GetNearestObject(m_Owner->GetPosition(), Obj_Enemy, m_Owner->GetSide()));
					a->GetComponent<cBulletHoming>()->SetBaseImage(IMAGE->Find("Bullet_Homing"));
					a->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 20);
					a->GetComponent<cRenderer>()->SetEnable(false);
					a->GetComponent<cRenderer>()->SetColor(SKYBLUE);
					Emitter = a->AddComponent<cEmitter>()->AddEmitter(Vec2(0, 0), IMAGE->Find("EnemyDeathParticle"), 0.01, 0.7);
					Emitter->AlphaVel.Set(-1000, -1000);
					Emitter->R.Set(0, 255);
					Emitter->Scale.Set(0.5, 1);
					Emitter->ScaleVel.Set(-4, -4);
					Emitter->Direction.Set(-20, 20);
					Emitter->SpeedVel.Set(50, 150);
					a->SetScale(Vec2(3, 3));
				}
				m_Owner->SetAlarm(0, 0.1 + 0.15 / (m_Power + 1));
				SOUND->Play("PlayerFire2", -2000, false)->SetFrequency(Random(40000, 45000));
			}
		}
	}

	if (INPUT->KeyDown(m_Keys[Key_Skill]))
	{
		if (m_Power >= 2)
		{
			SOUND->Play("Skill", -1300, false);
			for (auto& iter : OBJECT->Find(Obj_EnemyBullet, m_Owner->GetSide()))
			{
				iter->Destroy();
			}

			int Count = m_Power * 7.5;

			cParticle* Part = PART->AddParticle<cParticle>(IMAGE->Find("SkillEffect"), m_Owner->GetPosition(), Vec2(1, 1), Random(0, 359), 0.39, m_Owner->GetSide());
			Part->SetScale(Vec2(50, 50), 0.95);
			Part->SetAlpha(255, -200, 1);

			int Side = !m_Owner->GetSide();
			for (int i = 0; i < Count; i++)
			{
				SCHEDULE->AddSchedule(Random(0.f, 4.f), true, [=]()->bool {
					cObject* Bullet;
					Vec2 Pos;
					D3DCOLOR Color;
					do
					{
						Pos = Vec2(Random(0, 500) + 1100 * Side, Random(0, 900));
					} while (D3DXVec2Length(&(Pos - OBJECT->GetPlayer(Side)->GetPosition())) <= 300);
					Color = GetColor(Random(0, 9));
					for (int j = 0; j < 10; j++)
					{
						Bullet = OBJECT->AddObject("EnemyBullet", Pos, 0.5, Obj_EnemyBullet, Side);
						Bullet->AddComponent<cBullet>()->SetBaseImage(IMAGE->Find("Bullet1"));
						Bullet->GetComponent<cBullet>()->SetSpeed(Random(100, 300));
						Bullet->GetComponent<cBullet>()->SetDirection(Random(0, 359));
						Bullet->GetComponent<cRenderer>()->SetImage(IMAGE->Find("Bullet_Color1"));
						Bullet->GetComponent<cRenderer>()->SetColor(Color);
					}

					cParticleGlitch* Part = PART->AddParticle<cParticleGlitch>(IMAGE->Find("BulletFire"), Pos, Vec2(0.5, 0.5), 0, 0.4, Side, Color);
					Part->SetAlpha(255, -1000, 1);
					Part->SetScale(Vec2(25, 25), 0.99);
					Part->SetPosRand(6);
					Part->SetSizeRand(3);

					SOUND->Play("BulletFire2", -1500, true);
					return true;
					});
			}

			SYSTEM->SetScreenGlitch(true, Side);
			SYSTEM->SetScreenGlitchPosRand(40, Side);
			SYSTEM->SetScreenGlitchSizeRand(40, Side);
			SCHEDULE->AddSchedule(1, false, [=]()->bool {
				SYSTEM->AddScreenGlitchPosRand(-40 * DT, Side);
				SYSTEM->AddScreenGlitchSizeRand(-40 * DT, Side);
				return true;
			});
			SCHEDULE->AddSchedule(1, true, [=]()->bool {
				SYSTEM->SetScreenGlitch(false, Side);
				return true;
			});

			m_Power /= 2;
		}
	}

	m_Ring->GetComponent<cRenderer>()->SetGlitchPosRand(GetComponent<cRenderer>()->GetGlitchPosRand());
	m_Ring->GetComponent<cRenderer>()->SetGlitchSizeRand(GetComponent<cRenderer>()->GetGlitchSizeRand());
	m_Ring->SetPosition(m_Owner->GetPosition() + Vec2(0, 60));
}

void cPlayer::Render()
{
	if (m_Dead)
		return;

	if (INPUT->KeyPress(m_Keys[Key_Slow]))
	{
		IMAGE->CenterRender(IMAGE->Find("HitPoint"), m_Owner->GetPosition(), 0, Vec2(1, 1), 0.21);
	}
}

void cPlayer::RenderGlobal()
{
}

void cPlayer::Release()
{
	OBJECT->SetPlayer(nullptr, m_Owner->GetSide());
}

void cPlayer::SetSide(int _Side)
{
	if (_Side == 0)
	{
		m_Keys[Key_Up] = 'W';
		m_Keys[Key_Down] = 'S';
		m_Keys[Key_Left] = 'A';
		m_Keys[Key_Right] = 'D';
		m_Keys[Key_Attack] = 'H';
		m_Keys[Key_Skill] = 'J';
		m_Keys[Key_Slow] = VK_SPACE;
	}
	else
	{
		m_Keys[Key_Up] = VK_UP;
		m_Keys[Key_Down] = VK_DOWN;
		m_Keys[Key_Left] = VK_LEFT;
		m_Keys[Key_Right] = VK_RIGHT;
		m_Keys[Key_Attack] = VK_NUMPAD1;
		m_Keys[Key_Skill] = VK_NUMPAD2;
		m_Keys[Key_Slow] = VK_NUMPAD0;
	}
}

void cPlayer::Death()
{
	if (m_Dead)
		return;
	m_Dead = true;
	m_Owner->SetScale(Vec2(0.75, 0.75));
	m_Life--;
	SOUND->Play(RandomText("EnemyExplosion", 3), -1000, true);
	GetComponent<cRenderer>()->SetEnable(false);
	GetComponent<cRenderer>()->SetColor(0x90ffffff);
	m_Ring->GetComponent<cRenderer>()->SetEnable(false);
	m_Ring->GetComponent<cRenderer>()->SetColor(0x90ffffff);
	GetComponent<cCollider>()->ClearCollWith();
	GetComponent<cCollider>()->SetEnable(false);

	m_Power /= 2;

	if (SCENE->GetCurSceneKey() == "STAGE3")
	{
		if (OBJECT->Find(Obj_Enemy, !m_Owner->GetSide()).size() != 0)
		{
			OBJECT->Find(Obj_Enemy, !m_Owner->GetSide()).front()->GetComponent<cPath>()->AddPath(300, 1, Vec2(250 + 1100 * !m_Owner->GetSide(), 300));
		}
	}

	if (m_Life == 0)
	{
		SYSTEM->AddScore(1, !m_Owner->GetSide());
		SYSTEM->GameOver(!m_Owner->GetSide());
		cParticleGlitch* Glit = PART->AddParticle<cParticleGlitch>(GetComponent<cRenderer>()->GetImage(), m_Owner->GetPosition(), m_Owner->GetScale(), m_Owner->GetRotation(), 0.6, m_Owner->GetSide());
		Glit->SetAlpha(255, -30, 1);
		Glit->SetPosRand(1, 10, 1);
		Glit->SetSizeRand(1, 10, 1);
		Glit->SetScale(Vec2(1, 1), 0.98);
		Glit->SetBox(true);

		if (SCENE->GetCurSceneKey() == "STAGE3")
		{
			if (OBJECT->Find(Obj_Enemy, !m_Owner->GetSide()).size() != 0)
			{
				OBJECT->Find(Obj_Enemy, !m_Owner->GetSide()).front()->GetComponent<cEnemy>()->Death();
				m_Life = 0;
			}
		}
	}
	else
	{
		m_Owner->SetAlarm(1, 2);
		m_Owner->SetAlarm(2, 3);
		if (SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) > SCENE->GetStage()->GetTimeSpeed(!m_Owner->GetSide()))
		{
			cObject* a;
			cParticle* Part;
			Vec2 Pos;
			for (int i = 0; i < m_Power / 0.05; i++)
			{
				Part = PART->AddParticle<cParticle>(IMAGE->Find("Circle"), Pos, Vec2(0.01, 0.01), 0, 0.8, !m_Owner->GetSide(), D3DCOLOR_XRGB(255, 50, 50));
				Part->SetAlpha(255, -750, 1);
				Part->SetScale(Vec2(0.5, 0.5), 0.99);
				Pos = Vec2(Random(0, 500) + 1100 * !m_Owner->GetSide(), Random(0, 900));
				a = OBJECT->AddObject("Item_SmallPower", Pos, 0.4, Obj_Item, !m_Owner->GetSide());
				a->AddComponent<cItem>()->SetMagnetic(true);
				a->GetComponent<cItem>()->SetSpeed(50);
				a->GetComponent<cItem>()->SetFriction(1.01);
				a->GetComponent<cItem>()->SetCreatedByOpponentsDeath(true);
				a->GetComponent<cRenderer>()->SetColor(D3DCOLOR_ARGB(100, 255, 255, 255));
			}
		}

		if (SCENE->GetStage()->AddTimeSpeed(-0.3, m_Owner->GetSide()) < 0)
		{
			SCENE->GetStage()->SetTimeSpeed(0, m_Owner->GetSide());
		}
		for (auto& iter : OBJECT->Find(Obj_Item, m_Owner->GetSide()))
		{
			if (iter->GetComponent<cItem>()->GetMagnetic())
			{
				iter->GetComponent<cItem>()->SetMagnetic(false);
				iter->GetComponent<cItem>()->SetSpeed(300);
			}
		}

		cParticleGlitch* Glit = PART->AddParticle<cParticleGlitch>(GetComponent<cRenderer>()->GetImage(), m_Owner->GetPosition(), m_Owner->GetScale(), m_Owner->GetRotation(), 0.6, m_Owner->GetSide());
		Glit->SetAlpha(255, -1000, 1);
		Glit->SetPosRand(5, 150, 1);
		Glit->SetSizeRand(3, 150, 1);
		Glit->SetScale(Vec2(10, 10), 0.98);
		Glit->SetBox(true);
	}

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

void cPlayer::AddPower(float _Power)
{
	m_Power += _Power;
	if (m_Power > 5)
	{
		m_Power = 5;
		cObject* Bullet;
		int Side = !m_Owner->GetSide();
		Vec2 Pos;
		do
		{
			Pos = Vec2(Random(0, 500) + 1100 * Side, Random(0, 900));
		} while (D3DXVec2Length(&(Pos - OBJECT->GetPlayer(Side)->GetPosition())) <= 300);

		for (int i = 0; i < _Power * 20; i++)
		{
			Bullet = OBJECT->AddObject("EnemyBullet", Pos, 0.5, Obj_EnemyBullet, Side);
			Bullet->AddComponent<cBullet>()->SetBaseImage(IMAGE->Find("Bullet1"));
			Bullet->GetComponent<cBullet>()->SetSpeed(Random(150, 300));
			Bullet->GetComponent<cBullet>()->SetDirection(Random(0, 359));
			Bullet->GetComponent<cRenderer>()->SetImage(IMAGE->Find("Bullet_Color1"));
			Bullet->GetComponent<cRenderer>()->SetColor(WHITE);
		}
		cParticleGlitch* Part = PART->AddParticle<cParticleGlitch>(IMAGE->Find("BulletFire"), Pos, Vec2(0.5, 0.5), 0, 0.4, Side, WHITE);
		Part->SetAlpha(255, -1000, 1);
		Part->SetScale(Vec2(25, 25), 0.99);
		Part->SetPosRand(6);
		Part->SetSizeRand(3);
	}
}
