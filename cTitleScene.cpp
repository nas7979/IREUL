#include "DXUT.h"
#include "cTitleScene.h"
#include "cBackgroundEffect.h"


cTitleScene::cTitleScene()
{
}


cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	SOUND->StopAll();
	cObject* a;
	for (int i = 0; i < 75; i++)
	{
		a = OBJECT->AddObject("Number", Vec2(Random(-50, 1650), -50), 0.199, Obj_None, 2);
		a->AddComponent<cBackgroundEffect>();
	}

	for (int i = 0; i < 4; i++)
	{
		m_Buttons[i] = OBJECT->AddObject("Button", Vec2(800, 500 + i * 100), 0.1, Obj_UI, 2)->AddComponent<cButton>();
	}
	m_Buttons[0]->SetImage("Btn_Start");
	m_Buttons[1]->SetImage("Btn_How");
	m_Buttons[2]->SetImage("Btn_Credit");
	m_Buttons[3]->SetImage("Btn_Exit");

	m_Buttons[0]->SetSelected(true);

	m_Selected = 0;
	m_InTitle = true;
	m_InHow = false;
	m_InCredit = false;
	m_HowPos = 0;

	SOUND->Play("BGM", -200, false, true);
}

void cTitleScene::Update()
{
	if (INPUT->KeyDown('W'))
	{
		if (m_InTitle)
		{
			m_Buttons[m_Selected]->SetSelected(false);
			m_Selected--;
			if (m_Selected == -1)
			{
				m_Selected = 3;
			}
			m_Buttons[m_Selected]->SetSelected(true);
		}
	}
	if (INPUT->KeyDown('S'))
	{
		if (m_InTitle)
		{
			m_Buttons[m_Selected]->SetSelected(false);
			m_Selected++;
			if (m_Selected == 4)
			{
				m_Selected = 0;
			}
			m_Buttons[m_Selected]->SetSelected(true);
		}
	}

	if (INPUT->KeyPress('W'))
	{
		if (m_InHow)
		{
			m_HowPos += 800 * DT;
			if (m_HowPos > 0)
			{
				m_HowPos = 0;
			}
		}
	}

	if (INPUT->KeyPress('S'))
	{
		if (m_InHow)
		{
			m_HowPos -= 800 * DT;
			if (m_HowPos < -800)
			{
				m_HowPos = -800;
			}
		}
	}

	if (INPUT->KeyDown('H') || INPUT->KeyDown(VK_RETURN) || INPUT->KeyDown(VK_SPACE))
	{
		if (m_InTitle)
		{
			switch (m_Selected)
			{
			case 0:
				SYSTEM->SetAlarm(0, 0);
				break;

			case 1:
				m_InTitle = false;
				m_InHow = true;
				for (int i = 0; i < 4; i++)
				{
					m_Buttons[i]->GetComponent<cRenderer>()->SetEnable(false);
				}
				break;

			case 2:
				m_InTitle = false;
				m_InCredit = true;
				for (int i = 0; i < 4; i++)
				{
					m_Buttons[i]->GetComponent<cRenderer>()->SetEnable(false);
				}
				break;

			case 3:
				exit(0);
				break;
			}
		}
		else if (m_InHow || m_InCredit)
		{
			for (int i = 0; i < 4; i++)
			{
				m_Buttons[i]->GetComponent<cRenderer>()->SetEnable(true);
			}
			m_InHow = false;
			m_InCredit = false;
			m_InTitle = true;
		}
	}

	if (INPUT->KeyDown(VK_ESCAPE))
	{
		if (m_InHow || m_InCredit)
		{
			for (int i = 0; i < 4; i++)
			{
				m_Buttons[i]->GetComponent<cRenderer>()->SetEnable(true);
			}
			m_InHow = false;
			m_InCredit = false;
			m_InTitle = true;
		}
	}
}

void cTitleScene::Render1()
{
}

void cTitleScene::Render2()
{
}

void cTitleScene::RenderGlobal()
{
	IMAGE->Render(IMAGE->Find("Background"), Vec2(0, 0), 0, Vec2(1, 1), 0.9);
	if (m_InTitle)
	{
		IMAGE->CenterRender(IMAGE->Find("Title_Upper"), Vec2(800, 61), 0, Vec2(1, 1), 0.1);
		IMAGE->CenterRender(IMAGE->Find("Title_Middle"), Vec2(800, 390), 0, Vec2(1, 1), 0.1);
		if (Random(0, 60) != 0)
		{
			IMAGE->CenterRender(IMAGE->Find("Title"), Vec2(800, 275), 0, Vec2(1, 1), 0.1);
		}
		else
		{
			IMAGE->CenterRenderGlitch(IMAGE->Find("Title"), Vec2(800 + Random(-10, 10), 275 + Random(-10, 10)), 0, Vec2(1, 1), 0.1, 20, 20);
		}
	}
	else if (m_InHow)
	{
		IMAGE->Render(IMAGE->Find("How"), Vec2(0, 0 + m_HowPos), 0, Vec2(1, 1), 0.1);
	}
	else if (m_InCredit)
	{
		IMAGE->CenterRender(IMAGE->Find("Title_Middle"), Vec2(800, 390), 0, Vec2(1, 1), 0.1);
		IMAGE->CenterRender(IMAGE->Find("Hwang1"), Vec2(500, 450), 0, Vec2(1, 1), 0.1);
		IMAGE->CenterRender(IMAGE->Find("Lim"), Vec2(1100, 450), 0, Vec2(1, 1), 0.1);
		IMAGE->CenterRender(IMAGE->Find("Pro"), Vec2(500, 600), 0, Vec2(1, 1), 0.1);
		IMAGE->CenterRender(IMAGE->Find("Graphic"), Vec2(1100, 600), 0, Vec2(1, 1), 0.1);

		if (Random(0, 60) != 0)
		{
			IMAGE->CenterRender(IMAGE->Find("Credit"), Vec2(800, 275), 0, Vec2(1, 1), 0.1);
		}
		else
		{
			IMAGE->CenterRenderGlitch(IMAGE->Find("Credit"), Vec2(800 + Random(-10, 10), 275 + Random(-10, 10)), 0, Vec2(1, 1), 0.1, 20, 20);
		}

		if (Random(0, 30) != 0)
		{
			IMAGE->CenterRender(IMAGE->Find("Hwang2"), Vec2(400, 550), 0, Vec2(1, 1), 0.11);
		}
		else
		{
			IMAGE->CenterRenderGlitch(IMAGE->Find("Hwang2"), Vec2(400 + Random(-10, 10), 550 + Random(-10, 10)), 0, Vec2(1, 1), 0.11, 30, 50);
		}
	}
}

void cTitleScene::Release()
{
}
