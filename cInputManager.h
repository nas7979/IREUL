#pragma once
//키보드 입력을 받는다.
class cInputManager : public cSingleton<cInputManager>
{
public:
	cInputManager();
	~cInputManager();

	void Init();
	void Update();
	void Render();
	void Release();

private:
	bool m_Cur[128];
	bool m_Old[128];

public:
	bool KeyDown(int _Key) { return m_Cur[_Key] && !m_Old[_Key]; }
	bool KeyPress(int _Key) { return m_Cur[_Key]; }
	bool KeyUp(int _Key) { return !m_Cur[_Key] && m_Old[_Key]; }
};

#define INPUT cInputManager::GetInstance()