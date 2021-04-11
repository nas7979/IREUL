#include "DXUT.h"
#include "cLoadingScene.h"


cLoadingScene::cLoadingScene()
{
}


cLoadingScene::~cLoadingScene()
{
}

void cLoadingScene::Init()
{
	LoadImage("Player", "Player/Player", 6);
	IMAGE->AddAnimation("Player", 6);
	LoadImage("Ring_Start", "Player/Ring_Start", 4);
	IMAGE->AddAnimation("Ring_Start", 4);
	LoadImage("Ring_Idle", "Player/Ring_Idle", 6);
	IMAGE->AddAnimation("Ring_Idle", 6);
	LoadImage("Boss", "Enemy/Boss", 2);
	LoadImage("Zako", "Enemy/Zako", 5);
	LoadImage("Progress", "UI/Progress", 3);
	LoadImage("Score", "UI/Score", 2);
	LoadImage("PowerGauge", "UI/PowerGauge", 3);
	LoadImage("Stage", "Stage/Background");
	LoadImage("Stage_Web", "Stage/Background_Web");
	LoadImage("Stage_Frame", "UI/Background_Frame");
	LoadImage("Back_", "UI/Back_", 4);
	LoadImage("Bullet", "Bullet/Bullet", 6);
	LoadImage("Bullet_Color", "Bullet/Bullet_Color", 6);
	LoadImage("Bullet_Homing", "Bullet/Bullet_Homing");
	LoadImage("Point", "Point");
	LoadImage("EnemyDeathParticle", "Effect/EnemyDeathParticle");
	LoadImage("Item_BigPower", "Item/Item_BigPower");
	LoadImage("Item_SmallPower", "Item/Item_SmallPower");
	LoadImage("Item_BigPower_Arrow", "Item/Item_BigPower_Arrow");
	LoadImage("Item_SmallPower_Arrow", "Item/Item_SmallPower_Arrow");
	LoadImage("Background", "UI/Background");
	LoadImage("Circle", "Effect/Circle");
	LoadImage("BossHp", "UI/BossHp");
	LoadImage("BulletFire", "Effect/BulletFire");
	LoadImage("Life", "UI/Life", 5);
	LoadImage("Btn_Credit", "UI/Btn_Credit");
	LoadImage("Btn_CreditSel", "UI/BtnSel_Credit");
	LoadImage("Btn_Exit", "UI/Btn_Exit");
	LoadImage("Btn_ExitSel", "UI/BtnSel_Exit");
	LoadImage("Btn_How", "UI/Btn_How");
	LoadImage("Btn_HowSel", "UI/BtnSel_How");
	LoadImage("Btn_Start", "UI/Btn_Start");
	LoadImage("Btn_StartSel", "UI/BtnSel_Start");
	LoadImage("Btn_Menu", "UI/Btn_Menu");
	LoadImage("Btn_MenuSel", "UI/BtnSel_Menu");
	LoadImage("Btn_Resume", "UI/Btn_Resume");
	LoadImage("Btn_ResumeSel", "UI/BtnSel_Resume");
	LoadImage("SelectBar", "UI/SelectBar");
	LoadImage("Title_Upper", "UI/Title_Upper");
	LoadImage("Title_Middle", "UI/Title_Middle");
	LoadImage("Title", "UI/Title");
	LoadImage("Pause", "UI/Pause");
	LoadImage("PauseMask", "UI/PauseMask");
	LoadImage("Winner", "UI/Winner");
	LoadImage("Loser", "UI/Loser");
	LoadImage("GameOverMask", "UI/GameOverMask", 2);
	LoadImage("How", "UI/How");
	LoadImage("Credit", "UI/Credit");
	LoadImage("Lim", "UI/Lim");
	LoadImage("Hwang", "UI/Hwang", 2);
	LoadImage("Graphic", "UI/Graphic");
	LoadImage("Pro", "UI/Pro");
	LoadImage("SkillEffect", "Effect/SkillEffect");
	LoadImage("HitPoint", "Player/HitPoint");

	LoadSound("BulletFire", L"BulletFire", 3);
	LoadSound("PlayerFire", L"PlayerFire", 2);
	LoadSound("Item", L"Item");
	LoadSound("EnemyExplosion", L"EnemyExplosion", 3);
	LoadSound("Power", L"se_power", 2);
	LoadSound("Kira", L"se_kira", 3);
	LoadSound("BossDeath", L"BossDeath");
	LoadSound("Skill", L"Skill");
	LoadSound("BGM", L"BGM");

	SCENE->ChangeScene("TITLE");
}

void cLoadingScene::Update()
{
}

void cLoadingScene::Render1()
{
}

void cLoadingScene::Render2()
{
}

void cLoadingScene::RenderGlobal()
{
}

void cLoadingScene::Release()
{
}

void cLoadingScene::LoadImage(string _Key, string _Path, int _Amount)
{
	char Path[128];
	if (_Amount == 1)
	{
		sprintf(Path, "./Resource/Image/%s.png", _Path.c_str());
		IMAGE->AddImage(_Key, Path);
	}
	else
	{
		char Key[64];
		for (int i = 1; i <= _Amount; i++)
		{
			sprintf(Path, "./Resource/Image/%s%d.png", _Path.c_str(), i);
			sprintf(Key, "%s%d", _Key.c_str(), i);
			IMAGE->AddImage(Key, Path);
		}
	}
}

void cLoadingScene::LoadSound(string _Key, LPWSTR _Path, int _Amount)
{
	TCHAR Path[128];
	if (_Amount == 1)
	{
		swprintf(Path, L"./Resource/Sound/%s.wav", _Path);
		SOUND->AddSound(_Key, Path);
	}
	else
	{
		char Key[64];
		for (int i = 1; i <= _Amount; i++)
		{
			swprintf(Path, L"./Resource/Sound/%s%d.wav", _Path, i);
			sprintf(Key, "%s%d", _Key.c_str(), i);
			SOUND->AddSound(Key, Path);
		}
	}
}
