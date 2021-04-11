#pragma once
//게임의 전체적인 진행, 즉 매니저들의 생성, 업데이트, 렌더, 릴리즈를 관리한다.
class cMainGame
{
public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();
	void Release();
	void OnLostDevice();
	void OnResetDevice();
};

