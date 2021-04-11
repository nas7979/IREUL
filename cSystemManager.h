#pragma once
#include "cButton.h"
//전반적인 게임을 관리하는 매니저이다. 게임의 승패, 시간 배율, 씬 전환, 일시 정지 등을 관리한다.
struct RankData
{
	wstring Name;
	int Score;
};
class cSystemManager : public cSingleton<cSystemManager>
{
public:
	cSystemManager();
	~cSystemManager();

	void Init();
	void Update();
	void Render();
	void RenderGlobal();
	void Release();

private:
	float m_Alarm[4];
	int m_Score[2];
	unsigned int m_PauseSeed;
	bool m_Pause;
	float m_DT;
	float m_TimeSpeed;
	int m_Winner;
	cButton* m_PauseButtons[2];
	int m_PauseSelected;
	float m_ScreenGlitchPosRand[2];
	float m_ScreenGlitchSizeRand[2];
	bool m_ScreenGlitch[2];

public:
	void PlayerInit();
	void OnSceneChange();
	void SetPause(bool _Pause) { m_Pause = _Pause; }
	bool GetPause() { return m_Pause; }
	void SetAlarm(int _Index, float _Time) { m_Alarm[_Index] = _Time; }
	void SetDT() { m_DT = DXUTGetElapsedTime(); }
	float GetDT() { return m_DT * m_TimeSpeed; }
	void AddScore(int _Score, int _Side);
	void SetScore(int _Score, int _Side) { m_Score[_Side] = _Score; }
	int GetScore(int _Side) { return m_Score[_Side]; }
	void GameOver(int _Winner);
	void SetTimeSpeed(float _Speed) { m_TimeSpeed = _Speed; }
	float GetTimeSpeed() { return m_TimeSpeed; }
	float AddTimeSpeed(float _Speed) { return m_TimeSpeed += _Speed; }
	void CreateButton();
	unsigned int GetPauseSeed() { return m_PauseSeed; }

	void SetScreenGlitch(bool _Glitch, int _Side) { m_ScreenGlitch[_Side] = _Glitch; }
	bool GetScreenGlitch(int _Side) { return m_ScreenGlitch[_Side]; }

	void SetScreenGlitchPosRand(float _Value, int _Side) { m_ScreenGlitchPosRand[_Side] = _Value; }
	float AddScreenGlitchPosRand(float _Value, int _Side) { return m_ScreenGlitchPosRand[_Side] += _Value; }
	float GetScreenGlitchPosRand(int _Side) { return m_ScreenGlitchPosRand[_Side]; }

	void SetScreenGlitchSizeRand(float _Value, int _Side) { m_ScreenGlitchSizeRand[_Side] = _Value; }
	float AddScreenGlitchSizeRand(float _Value, int _Side) { return m_ScreenGlitchSizeRand[_Side] += _Value; }
	float GetScreenGlitchSizeRand(int _Side) { return m_ScreenGlitchSizeRand[_Side]; }

};

#define SYSTEM cSystemManager::GetInstance()