#include "DXUT.h"
#include "cSystemManager.h"
#include "cPlayer.h"
#include "cItem.h"
#include "cBoss.h"

cSystemManager::cSystemManager()
{
}


cSystemManager::~cSystemManager()
{
}

void cSystemManager::Init()
{
	PlayerInit();
	OnSceneChange();
}

void cSystemManager::Update()
{
	if (INPUT->KeyDown(VK_ESCAPE) && m_Winner == -1 && SCENE->GetCurSceneKey() != "TITLE")
	{
		m_Pause = !m_Pause;
		m_PauseSeed = time(NULL);
		m_PauseSelected = 0;
		m_PauseButtons[0]->GetComponent<cRenderer>()->SetEnable(m_Pause);
		m_PauseButtons[1]->GetComponent<cRenderer>()->SetEnable(m_Pause);
		m_PauseButtons[0]->SetSelected(true);
	}
	
	if (m_Pause)
	{
		srand(m_PauseSeed);
		if (INPUT->KeyDown('W') || INPUT->KeyDown('S'))
		{
			m_PauseButtons[m_PauseSelected]->SetSelected(false);
			m_PauseSelected = !m_PauseSelected;
			m_PauseButtons[m_PauseSelected]->SetSelected(true);
		}

		if (INPUT->KeyDown('H') || (m_Pause == true && (INPUT->KeyDown('H') || INPUT->KeyDown(VK_SPACE) || INPUT->KeyDown(VK_RETURN))))
		{
			switch (m_PauseSelected)
			{
			case 0:
				m_Pause = false;
				m_PauseButtons[0]->GetComponent<cRenderer>()->SetEnable(m_Pause);
				m_PauseButtons[1]->GetComponent<cRenderer>()->SetEnable(m_Pause);
				break;

			case 1:
				SetAlarm(3, 0);
				m_Pause = false;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			m_Alarm[i] -= DT;
			if (m_Alarm[i] <= 0 && m_Alarm[i] > -100)
			{
				m_Alarm[i] = -100;
				switch (i)
				{
				case 0:
					OnSceneChange();
					SCENE->ChangeScene("STAGE1");
					break;

				case 1:
					OnSceneChange();
					SCENE->ChangeScene("STAGE2");
					break;

				case 2:
					OnSceneChange();
					SCENE->ChangeScene("STAGE3");
					break;

				case 3:
					OnSceneChange();
					PlayerInit();
					SCENE->ChangeScene("TITLE");
					break;

				}
			}
		}
	}
}

void cSystemManager::Render()
{
}

void cSystemManager::RenderGlobal()
{
	if (m_Pause == true)
	{
		IMAGE->Render(IMAGE->Find("PauseMask"), Vec2(0, 0), 0, Vec2(1, 1), 0.1, 0x80ffffff);
		IMAGE->CenterRender(IMAGE->Find("Title_Middle"), Vec2(800, 390), 0, Vec2(1, 1), 0.1);
		if (Random(0, 60) != 0)
		{
			IMAGE->CenterRender(IMAGE->Find("Pause"), Vec2(800, 275), 0, Vec2(1, 1), 0.05);
		}
		else
		{
			IMAGE->CenterRenderGlitch(IMAGE->Find("Pause"), Vec2(800 + Random(-10, 10), 275 + Random(-10, 10)), 0, Vec2(1, 1), 0.05, 20, 20);
		}
	}
}

void cSystemManager::Release()
{
}

void cSystemManager::PlayerInit()
{
	m_Pause = false;
	m_Winner = -1;
	m_TimeSpeed = 1;
	m_Score[0] = m_Score[1] = 0;
}

void cSystemManager::OnSceneChange()
{
	OBJECT->Release();
	PART->Release();
	CAMERA->Init();
	SCHEDULE->Clear();
	m_Pause = false;
	m_TimeSpeed = 1;
	m_Winner = -1;
	m_ScreenGlitch[0] = m_ScreenGlitch[1] = false;
	m_ScreenGlitchPosRand[0] = m_ScreenGlitchPosRand[1] = 0;
	m_ScreenGlitchSizeRand[0] = m_ScreenGlitchSizeRand[1] = 0;
	for (int i = 0; i < 4; i++)
	{
		m_Alarm[i] = -100;
	}
}

void cSystemManager::AddScore(int _Score, int _Side)
{
	m_Score[_Side] += _Score;
	list<cObject*> List = OBJECT->Find(Obj_Enemy, "Boss", !_Side);
	if (List.size() != 0)
	{
		List.front()->GetComponent<cBoss>()->SetInvincible(true);
	}
}

void cSystemManager::GameOver(int _Winner)
{
	if (m_Winner != -1)
		return;

	m_Winner = _Winner;
	if (m_Score[0] == 2 || m_Score[1] == 2)
	{
		int Bigger = max(m_Score[0], m_Score[1]);
		m_Winner = 3;
	}
	OBJECT->Find(Obj_Player, _Winner).front()->GetComponent<cPlayer>()->SetInvincible(true);
	for (int i = 0; i < 4; i++)
	{
		m_Alarm[i] = -100;
	}
	if (m_Winner != 3)
	{
		if (SCENE->GetCurSceneKey() == "STAGE1")
		{
			SetAlarm(1, 2.5);
		}
		else if (SCENE->GetCurSceneKey() == "STAGE2")
		{
			SetAlarm(2, 2.5);
		}
		else if (SCENE->GetCurSceneKey() == "STAGE3")
		{
			SetAlarm(3, 2.5);
		}
	}
	else
	{
		SetAlarm(3, 2.5);
	}
	SCHEDULE->AddSchedule(3, false, [&]()->bool {
		m_TimeSpeed -= 0.3 * DT;
		return true;
	});

	cParticle* Part = PART->AddParticle<cParticle>(IMAGE->Find(_Winner == 0 ? "GameOverMask1" : "GameOverMask2"), Vec2(800, 450), Vec2(1, 1), 0, 0.011, 2);
	Part->SetAlpha(0, 10, 1.1);

	Part = PART->AddParticle<cParticle>(IMAGE->Find("Winner"), Vec2(_Winner == 0 ? 400 : 1200, 300), Vec2(1, 1), 0, 0.01, 2);
	Part->SetAlpha(0, 10, 1.1);

	cParticleGlitch* Glit = PART->AddParticle<cParticleGlitch>(IMAGE->Find("Loser"), Vec2(_Winner == 0 ? 1200 : 400, 300), Vec2(1, 1), 0, 0.01, 2);
	Glit->SetAlpha(0, 10, 1.1);
	Glit->SetPosRand(30);
	Glit->SetSizeRand(30);
}

void cSystemManager::CreateButton()
{
	for (int i = 0; i < 2; i++)
	{
		m_PauseButtons[i] = OBJECT->AddObject("Button", Vec2(800, 450 + 125 * i), 0.05, Obj_UI, 2)->AddComponent<cButton>();
	}
	m_PauseButtons[0]->SetImage("Btn_Resume");
	m_PauseButtons[1]->SetImage("Btn_Menu");
	m_PauseButtons[0]->GetComponent<cRenderer>()->SetEnable(false);
	m_PauseButtons[1]->GetComponent<cRenderer>()->SetEnable(false);
}
