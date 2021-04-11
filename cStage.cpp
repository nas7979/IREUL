#include "DXUT.h"
#include "cStage.h"
#include "cBackgroundEffect.h"

cStage::cStage()
{
}

cStage::~cStage()
{
}

void cStage::Init()
{
	OBJECT->AddObject("Player", Vec2(250, 600), 0.55, Obj_Player, 0)->AddComponent<cPlayer>()->SetSide(0);
	OBJECT->AddObject("Player", Vec2(250 + 1100, 600), 0.55, Obj_Player, 1)->AddComponent<cPlayer>()->SetSide(1);

	m_BackPos[0] = Random(0, 900);
	m_BackPos[1] = Random(0, 900);
	m_Time[0] = m_Time[1] = 0;
	m_TimeSpeed[0] = 0;
	m_TimeSpeed[1] = 0;
	m_LifeRot[0] = Random(0, 5);
	m_LifeRot[1] = Random(0, 5);
	m_LifeRot[2] = Random(0, 5);

	cObject* a;
	for (int i = 0; i < 15; i++)
	{
		a = OBJECT->AddObject("Number", Vec2(Random(-50, 300), -50), 0.199, Obj_None, 0);
		a->AddComponent<cBackgroundEffect>();
	}
	for (int i = 0; i < 15; i++)
	{
		a = OBJECT->AddObject("Number", Vec2(Random(1300, 1650), -50), 0.199, Obj_None, 1);
		a->AddComponent<cBackgroundEffect>();
	}
}

void cStage::Update()
{
	m_LifeRot[0] += 0.8 * DT;
	m_LifeRot[1] += 1.3 * DT;
	m_LifeRot[2] += 0.3 * DT;
}

void cStage::Render1()
{
	IMAGE->Render(IMAGE->Find("Stage"), Vec2(0, m_BackPos[0]), 0, Vec2(1, 1), 0.91, 0xff909090);
	IMAGE->Render(IMAGE->Find("Stage"), Vec2(0, m_BackPos[0] - 900), 0, Vec2(1, 1), 0.91, 0xff909090);
}

void cStage::Render2()
{
	IMAGE->Render(IMAGE->Find("Stage"), Vec2(1100, m_BackPos[1]), 0, Vec2(1, 1), 0.91, 0xff909090);
	IMAGE->Render(IMAGE->Find("Stage"), Vec2(1100, m_BackPos[1] - 900), 0, Vec2(1, 1), 0.91, 0xff909090);
}

void cStage::RenderGlobal()
{
	IMAGE->CenterRender(IMAGE->Find("Stage_Frame"), Vec2(800, 450), 0, Vec2(1, 1), 0.1);
	IMAGE->Render(IMAGE->Find("Background"), Vec2(0, 0), 0, Vec2(1, 1), 0.2);

	if (OBJECT->GetPlayer(0) != nullptr)
	{
		int Scale = -1;
		RECT Rect = { 0,0,0,0 };
		cPlayer* Player;
		for (int Side = 0; Side < 2; Side++)
		{
			Scale *= -1;
			Player = OBJECT->GetPlayer(Side)->GetComponent<cPlayer>();

			IMAGE->CenterRender(IMAGE->Find("PowerGauge1"), Vec2(800 - 560 * Scale, 400), 0, Vec2(Scale, 1), 0.19);
			Rect.bottom = 643;
			Rect.right = 74;
			Rect.top = 643 - (Player->GetPower() / 5) * 643;
			IMAGE->CenterRenderRect((Player->GetPower() >= 2 ? IMAGE->Find("PowerGauge2") : IMAGE->Find("PowerGauge3")), Vec2(800 - 560 * Scale, 400 + Rect.top), 0, Vec2(Scale, 1), 0.19, Rect);

			IMAGE->CenterRender(IMAGE->Find("Life2"), Vec2(800 - 690 * Scale, 125), 0, Vec2(1, 1), 0.19);
			IMAGE->CenterRender(IMAGE->Find("Life3"), Vec2(800 - 690 * Scale, 125), m_LifeRot[0], Vec2(1, 1), 0.19);
			IMAGE->CenterRender(IMAGE->Find("Life4"), Vec2(800 - 690 * Scale, 125), m_LifeRot[1], Vec2(1, 1), 0.19);
			IMAGE->CenterRender(IMAGE->Find("Life5"), Vec2(800 - 690 * Scale, 125), m_LifeRot[2], Vec2(1, 1), 0.19);

			for (int i = 0; i < Player->GetLife(); i++)
			{
				IMAGE->CenterRender(IMAGE->Find("Life1"), Vec2(800 - 690 * Scale, 125), i * D3DXToRadian(90), Vec2(1, 1), 0.18);
			}

			IMAGE->CenterRender(IMAGE->Find("Progress1"), Vec2(800 - 630 * Scale, 475), 0, Vec2(1, 1), 0.19);
			Rect.bottom = 479;
			Rect.right = 40;
			Rect.top = max(0, 479 - (m_Time[Side] / m_TimeMax) * 479);
			IMAGE->CenterRenderRect(IMAGE->Find("Progress2"), Vec2(800 - 630 * Scale, 475 + Rect.top), 0, Vec2(Scale, 1), 0.18, Rect);
			IMAGE->CenterRender(IMAGE->Find("Progress3"), Vec2(800 - 630 * Scale, 475 - 239 + Rect.top), 0, Vec2(Scale, 1), 0.17);

			char Text[16];
			sprintf(Text, "Score%d", min(SYSTEM->GetScore(Side) + 1, 1));
			IMAGE->CenterRender(IMAGE->Find(Text), Vec2(800 - 650 * Scale, 800), 0, Vec2(1, 1), 0.19);
		}
	}
}

void cStage::Release()
{
}
