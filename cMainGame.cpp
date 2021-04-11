#include "DXUT.h"
#include "cMainGame.h"
#include "cLoadingScene.h"
#include "cStage1Scene.h"
#include "cStage2Scene.h"
#include "cStage3Scene.h"
#include "cResultScene.h"
#include "cTitleScene.h"

cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
}

void cMainGame::Init()
{
	IMAGE->CreateInstance();
	SOUND->CreateInstance();
	OBJECT->CreateInstance();
	PART->CreateInstance();
	INPUT->CreateInstance();
	CAMERA->CreateInstance();
	SCENE->CreateInstance();
	SCHEDULE->CreateInstance();
	SYSTEM->CreateInstance();

	SCENE->AddScene("LOADING", new cLoadingScene);
	SCENE->AddScene("STAGE1", new cStage1Scene);
	SCENE->AddScene("STAGE2", new cStage2Scene);
	SCENE->AddScene("STAGE3", new cStage3Scene);
	SCENE->AddScene("RESULT", new cResultScene);
	SCENE->AddScene("TITLE", new cTitleScene);

	SCENE->ChangeScene("LOADING");
}

void cMainGame::Update()
{
	SYSTEM->SetDT();
	INPUT->Update();
	SYSTEM->Update();
	if (SYSTEM->GetPause() == false)
	{
		SCENE->Update();
		OBJECT->Update();
		SCHEDULE->Update();
		PART->Update();
		CAMERA->Update();
	}
	else
	{
		OBJECT->Update();
	}
	SOUND->Update();
}

void cMainGame::Render()
{
	LPDIRECT3DSURFACE9 OriginalTarget;
	D3DLOCKED_RECT Rect;
	g_Device->GetRenderTarget(0, &OriginalTarget);
	g_Device->SetRenderTarget(0, IMAGE->GetRenderSurface(0));
	IMAGE->Begin();
	CAMERA->Render();

	SCENE->Render1();
	OBJECT->Render1();
	PART->Render1();

	IMAGE->End();

	g_Device->SetRenderTarget(0, IMAGE->GetRenderSurface(1));
	IMAGE->Begin();
	CAMERA->Render();

	SCENE->Render2();
	OBJECT->Render2();
	PART->Render2();

	IMAGE->End();

	g_Device->SetRenderTarget(0, OriginalTarget);
	IMAGE->Begin();
	CAMERA->Render();

	SCENE->RenderGlobal();
	PART->RenderGlobal();
	if (SYSTEM->GetPause())
	{
		srand(timeGetTime());
	}
	OBJECT->RenderGlobal();
	SYSTEM->RenderGlobal();
	if (SYSTEM->GetPause())
	{
		srand(SYSTEM->GetPauseSeed());
	}

	if (SCENE->GetCurSceneKey() == "STAGE1" || SCENE->GetCurSceneKey() == "STAGE2" || SCENE->GetCurSceneKey() == "STAGE3")
	{
		if (SYSTEM->GetScreenGlitch(0))
		{
			IMAGE->RenderGlitchRect(&IMAGE->GetTexture(0), Vec2(796 - 500, 9), 0, Vec2(1, 1), 0.11, RECT{ 0,0,500,900 }, SYSTEM->GetScreenGlitchPosRand(0), SYSTEM->GetScreenGlitchSizeRand(0));
		}
		else
		{
			IMAGE->RenderRect(&IMAGE->GetTexture(0), Vec2(796 - 500, 9), 0, Vec2(1, 1), 0.11, RECT{ 0,0,500,900 });

		}

		if (SYSTEM->GetScreenGlitch(1))
		{
			IMAGE->RenderGlitchRect(&IMAGE->GetTexture(1), Vec2(805, 9), 0, Vec2(1, 1), 0.11, RECT{ 1100,0,1600,900 }, SYSTEM->GetScreenGlitchPosRand(1), SYSTEM->GetScreenGlitchSizeRand(1));
		}
		else
		{
			IMAGE->RenderRect(&IMAGE->GetTexture(1), Vec2(805, 9), 0, Vec2(1, 1), 0.11, RECT{ 1100,0,1600,900 });

		}
	}

	IMAGE->End();
	OriginalTarget->Release();
}

void cMainGame::Release()
{
	OBJECT->ReleaseInstance();
	PART->ReleaseInstance();
	CAMERA->ReleaseInstance();
	INPUT->ReleaseInstance();
	SCENE->ReleaseInstance();
	SYSTEM->ReleaseInstance();
	SOUND->ReleaseInstance();
	IMAGE->ReleaseInstance();
	SCHEDULE->ReleaseInstance();
}

void cMainGame::OnLostDevice()
{
	IMAGE->OnLostDevice();
}

void cMainGame::OnResetDevice()
{
	LPDIRECT3DSURFACE9 Original;
	g_Device->GetRenderTarget(0, &Original);
	D3DSURFACE_DESC Desc;
	Original->GetDesc(&Desc);
	Original->Release();
	int a;
	for (int i = 0; i < 2; i++)
	{
		a = g_Device->Release();
		a = IMAGE->GetRenderSurface(i)->Release();
		a = IMAGE->GetTexture(i).Image->Release();
	}
	IMAGE->OnResetDevice();
	IMAGE->CreateRenderTarget();
}
