#include "DXUT.h"
#include "cBoss1.h"
#include "cTimeLine_Boss11.h"
#include "cTimeLine_Boss12.h"
#include "cTimeLine_Boss13.h"

cBoss1::cBoss1()
{
}


cBoss1::~cBoss1()
{
}

void cBoss1::Init()
{
	cBoss::Init();
	AddComponent<cRenderer>()->SetImage(IMAGE->Find("Boss1"));
	GetComponent<cCollider>()->AddCollider(Vec2(0, 0), 75);
	GetComponent<cCollider>()->AddCollider(Vec2(40, 0), 75);
	GetComponent<cCollider>()->AddCollider(Vec2(-40, 0), 75);

	m_MaxHp = 1500;

	AddComponent<cTimeLine_Boss11>()->SetEnable(false);
	AddComponent<cTimeLine_Boss12>()->SetEnable(false);
	AddComponent<cTimeLine_Boss13>()->SetEnable(false);
}

void cBoss1::Update()
{
	cBoss::Update();
}

void cBoss1::Render()
{
	cBoss::Render();
}

void cBoss1::RenderGlobal()
{
}

void cBoss1::Release()
{
}

void cBoss1::Death()
{
	GetComponent<cTimeLine_Boss11>()->SetEnable(false);
	GetComponent<cTimeLine_Boss12>()->SetEnable(false);
	GetComponent<cTimeLine_Boss13>()->SetEnable(false);
	cBoss::Death();
}

void cBoss1::NextPhase()
{
	cBoss::NextPhase();
	GetComponent<cTimeLine_Boss11>()->SetEnable(false);
	GetComponent<cTimeLine_Boss12>()->SetEnable(false);
	GetComponent<cTimeLine_Boss13>()->SetEnable(false);

	switch (Random(1, 3))
	{
	case 1:
		GetComponent<cTimeLine_Boss11>()->SetEnable(true);
		GetComponent<cTimeLine_Boss11>()->Init();
		break;
	case 2:
		GetComponent<cTimeLine_Boss12>()->SetEnable(true);
		GetComponent<cTimeLine_Boss12>()->Init();
		break;
	case 3:
		GetComponent<cTimeLine_Boss13>()->SetEnable(true);
		GetComponent<cTimeLine_Boss13>()->Init();
		break;
	}
}
