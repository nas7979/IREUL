#pragma once
//로딩된 소리들을 관리 및 재생하는 매니저이다.
//소리는 볼륨 및 피치를 조절할 수 있다.
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