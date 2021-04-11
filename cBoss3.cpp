#include "DXUT.h"
#include "cBoss3.h"
#include "cTimeLine_Boss31.h"
#include "cTimeLine_Boss32.h"
#include "cTimeLine_Boss33.h"
#include "cTimeLine_Boss34.h"
#include "cTimeLine_Boss35.h"
#include "cTimeLine_Boss36.h"
#include "cTimeLine_Boss37.h"
#include "cTimeLine_Boss38.h"


cBoss3::cBoss3()
{
}


cBoss3::~cBoss3()
{
}

void cBoss3::Init()
{
	cBoss::Init();

	AddComponent<cRenderer>();
	AddComponent<cAnimation>()->AddAnimation("Idle", "Player", 0.03, false);
	GetComponent<cAnimation>()->SetAnimation("Idle");
	GetComponent<cAnimation>()->SetSpeed(0);
	m_Ring = OBJECT->AddObject("Ring", m_Owner->GetPosition() + Vec2(1, 60), 0.5, Obj_None, m_Owner->GetSide());
	m_Ring->AddComponent<cRenderer>();
	m_Ring->AddComponent<cAnimation>()->AddAnimation("Start", "Ring_Start", 0.25, false);
	m_Ring->GetComponent<cAnimation>()->AddAnimation("Idle", "Ring_Idle", 0.15, true);
	m_Ring->GetComponent<cAnimation>()->SetAnimation("Start");
	m_Ring->SetRotation(90);

	GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 50);

	m_MaxHp = 2500;
	m_Owner->SetRotation(90);

	AddComponent<cTimeLine_Boss31>()->SetEnable(false);
	AddComponent<cTimeLine_Boss32>()->SetEnable(false);
	AddComponent<cTimeLine_Boss33>()->SetEnable(false);
	AddComponent<cTimeLine_Boss34>()->SetEnable(false);
	AddComponent<cTimeLine_Boss35>()->SetEnable(false);
	AddComponent<cTimeLine_Boss36>()->SetEnable(false);
	AddComponent<cTimeLine_Boss37>()->SetEnable(false);
	AddComponent<cTimeLine_Boss38>()->SetEnable(false);

	if (m_Owner->GetSide() == 1)
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

void cBoss3::Update()
{
	cBoss::Update();

	if (OBJECT->GetPlayer(!m_Owner->GetSide())->GetComponent<cPlayer>()->GetDead() == false)
	{
		if (!INPUT->KeyPress(m_Keys[Key_Left]) || !INPUT->KeyPress(m_Keys[Key_Right]))
		{
			GetComponent<cAnimation>()->SetSpeed(-1);
		}

		if (INPUT->KeyPress(m_Keys[Key_Left]) && m_Owner->GetPosition().x > 10 + 1100 * m_Owner->GetSide())
		{
			m_Owner->Translate(Vec2(-OBJECT->GetPlayer(!m_Owner->GetSide())->GetComponent<cPlayer>()->GetSpeed(), 0) * DT);
			if (GetComponent<cAnimation>()->GetFrame() != 0 && m_Owner->GetScale().y == -1)
			{
				GetComponent<cAnimation>()->SetSpeed(-1);
			}
			else
			{
				m_Owner->SetScale(Vec2(1, 1));
				GetComponent<cAnimation>()->SetSpeed(1);
			}
		}

		if (INPUT->KeyPress(m_Keys[Key_Right]) && m_Owner->GetPosition().x < 490 + 1100 * m_Owner->GetSide())
		{
			m_Owner->Translate(Vec2(OBJECT->GetPlayer(!m_Owner->GetSide())->GetComponent<cPlayer>()->GetSpeed(), 0) * DT);
			GetComponent<cAnimation>()->SetSpeed(1);
			if (GetComponent<cAnimation>()->GetFrame() != 0 && m_Owner->GetScale().y == 1)
			{
				GetComponent<cAnimation>()->SetSpeed(-1);
			}
			else
			{
				m_Owner->SetScale(Vec2(1, -1));
				GetComponent<cAnimation>()->SetSpeed(1);
			}
		}

		if (INPUT->KeyPress(m_Keys[Key_Up]) && m_Owner->GetPosition().y > 30)
		{
			m_Owner->Translate(Vec2(0, -OBJECT->GetPlayer(!m_Owner->GetSide())->GetComponent<cPlayer>()->GetSpeed()) * DT);
		}
		if (INPUT->KeyPress(m_Keys[Key_Down]) && m_Owner->GetPosition().y < 870)
		{
			m_Owner->Translate(Vec2(0, OBJECT->GetPlayer(!m_Owner->GetSide())->GetComponent<cPlayer>()->GetSpeed()) * DT);
		}
	}
	else
	{
		GetComponent<cAnimation>()->SetSpeed(-1);
	}

	m_Ring->GetComponent<cRenderer>()->SetColor(GetComponent<cRenderer>()->GetColor());
	m_Ring->GetComponent<cRenderer>()->SetGlitch(GetComponent<cRenderer>()->GetGlitch());
	m_Ring->GetComponent<cRenderer>()->SetGlitchPosRand(GetComponent<cRenderer>()->GetGlitchPosRand());
	m_Ring->GetComponent<cRenderer>()->SetGlitchSizeRand(GetComponent<cRenderer>()->GetGlitchSizeRand());
	m_Ring->SetPosition(m_Owner->GetPosition() + Vec2(0, -80));
}

void cBoss3::Render()
{
	cBoss::Render();
}

void cBoss3::RenderGlobal()
{
}

void cBoss3::Release()
{
}

void cBoss3::Death()
{
	cBoss::Death();
	m_Ring->Destroy();
	OBJECT->GetPlayer(!m_Owner->GetSide())->GetComponent<cPlayer>()->SetLife(1);
	OBJECT->GetPlayer(!m_Owner->GetSide())->GetComponent<cPlayer>()->Death();
}

void cBoss3::NextPhase()
{
	if (m_Hp != m_MaxHp)
	{
		cObject* a;
		for (int i = 0; i < 12; i++)
		{
			a = OBJECT->AddObject("Item_SmallPower", m_Owner->GetPosition() + Vec2(Random(-125, 125), Random(-125, 125)), 0.4, Obj_Item, m_Owner->GetSide());
			a->AddComponent<cItem>();
		}
	}

	GetComponent<cTimeLine_Boss31>()->SetEnable(false);
	GetComponent<cTimeLine_Boss32>()->SetEnable(false);
	GetComponent<cTimeLine_Boss33>()->SetEnable(false);
	GetComponent<cTimeLine_Boss34>()->SetEnable(false);
	GetComponent<cTimeLine_Boss35>()->SetEnable(false);
	GetComponent<cTimeLine_Boss36>()->SetEnable(false);
	GetComponent<cTimeLine_Boss37>()->SetEnable(false);
	GetComponent<cTimeLine_Boss38>()->SetEnable(false);

	switch (Random(1, 8))
	{
	case 1:
		GetComponent<cTimeLine_Boss31>()->SetEnable(true);
		GetComponent<cTimeLine_Boss31>()->Init();
		break;
	case 2:
		GetComponent<cTimeLine_Boss32>()->SetEnable(true);
		GetComponent<cTimeLine_Boss32>()->Init();
		break;
	case 3:
		GetComponent<cTimeLine_Boss33>()->SetEnable(true);
		GetComponent<cTimeLine_Boss33>()->Init();
		break;
	case 4:
		GetComponent<cTimeLine_Boss34>()->SetEnable(true);
		GetComponent<cTimeLine_Boss34>()->Init();
		break;
	case 5:
		GetComponent<cTimeLine_Boss35>()->SetEnable(true);
		GetComponent<cTimeLine_Boss35>()->Init();
		break;
	case 6:
		GetComponent<cTimeLine_Boss36>()->SetEnable(true);
		GetComponent<cTimeLine_Boss36>()->Init();
		break;
	case 7:
		GetComponent<cTimeLine_Boss37>()->SetEnable(true);
		GetComponent<cTimeLine_Boss37>()->Init();
		break;
	case 8:
		GetComponent<cTimeLine_Boss38>()->SetEnable(true);
		GetComponent<cTimeLine_Boss38>()->Init();
		break;
	}
}
