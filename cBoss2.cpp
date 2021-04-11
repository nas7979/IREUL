#include "DXUT.h"
#include "cBoss2.h"
#include "cTimeLine_Boss21.h"
#include "cTimeLine_Boss22.h"
#include "cTimeLine_Boss23.h"
#include "cTimeLine_Boss24.h"

cBoss2::cBoss2()
{
}


cBoss2::~cBoss2()
{
}

void cBoss2::Init()
{
	cBoss::Init();
	AddComponent<cRenderer>()->SetImage(IMAGE->Find("Boss2"));
	GetComponent<cCollider>()->AddCollider(Vec2(15, 0), 100);
	GetComponent<cCollider>()->AddCollider(Vec2(-15, 0), 100);

	m_MaxHp = 2000;

	AddComponent<cTimeLine_Boss21>()->SetEnable(false);
	AddComponent<cTimeLine_Boss22>()->SetEnable(false);
	AddComponent<cTimeLine_Boss23>()->SetEnable(false);
	AddComponent<cTimeLine_Boss24>()->SetEnable(false);
	m_Rot = 90;
}

void cBoss2::Update()
{
	cBoss::Update();
	m_Owner->SetRotation(Lerp<float>(m_Owner->GetRotation(), m_Rot, 0.1));
}

void cBoss2::Render()
{
	cBoss::Render();
}

void cBoss2::RenderGlobal()
{
}

void cBoss2::Release()
{
}

void cBoss2::Death()
{
	GetComponent<cTimeLine_Boss21>()->SetEnable(false);
	GetComponent<cTimeLine_Boss22>()->SetEnable(false);
	GetComponent<cTimeLine_Boss23>()->SetEnable(false);
	GetComponent<cTimeLine_Boss24>()->SetEnable(false);
	cBoss::Death();
}

void cBoss2::NextPhase()
{
	cBoss::NextPhase();
	m_Rot = 90;
	GetComponent<cTimeLine_Boss21>()->SetEnable(false);
	GetComponent<cTimeLine_Boss22>()->SetEnable(false);
	GetComponent<cTimeLine_Boss23>()->SetEnable(false);
	GetComponent<cTimeLine_Boss24>()->SetEnable(false);

	switch (Random(1, 4))
	{
	case 1:
		GetComponent<cTimeLine_Boss21>()->SetEnable(true);
		GetComponent<cTimeLine_Boss21>()->Init();
		break;
	case 2:
		GetComponent<cTimeLine_Boss22>()->SetEnable(true);
		GetComponent<cTimeLine_Boss22>()->Init();
		break;
	case 3:
		GetComponent<cTimeLine_Boss23>()->SetEnable(true);
		GetComponent<cTimeLine_Boss23>()->Init();
		break;
	case 4:
		GetComponent<cTimeLine_Boss24>()->SetEnable(true);
		GetComponent<cTimeLine_Boss24>()->Init();
		break;
	}
}
