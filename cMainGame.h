#pragma once
//������ ��ü���� ����, �� �Ŵ������� ����, ������Ʈ, ����, ����� �����Ѵ�.
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

