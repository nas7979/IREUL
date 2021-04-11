#pragma once
//�ε��� �Ҹ����� ���� �� ����ϴ� �Ŵ����̴�.
//�Ҹ��� ���� �� ��ġ�� ������ �� �ִ�.
class cSoundManager : public cSingleton<cSoundManager>
{
public:
	cSoundManager();
	~cSoundManager();

	void Init();
	void Update();
	void Render();
	void Release();

private:
	list<LPDIRECTSOUNDBUFFER> m_Channels;
	map<string, CSound*> m_Sounds;
	vector<string> m_PlayedSounds;
	CSoundManager m_Manager;

public:
	void AddSound(string _Key, LPWSTR _Path);
	LPDIRECTSOUNDBUFFER Play(string _key, int _Volume, bool _CheckAlreadyPlayed, bool _Loop = false);
	void StopAll();
};

#define SOUND cSoundManager::GetInstance()