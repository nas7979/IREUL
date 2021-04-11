#include "DXUT.h"
#include "cSoundManager.h"


cSoundManager::cSoundManager()
{
}


cSoundManager::~cSoundManager()
{
}

void cSoundManager::Init()
{
	m_Manager.Initialize(DXUTGetHWND(), 2);
}

void cSoundManager::Update()
{
	m_PlayedSounds.clear();
	DWORD Status;
	for (auto& iter = m_Channels.begin(); iter != m_Channels.end();)
	{
		(*iter)->GetStatus(&Status);
		if ((Status & DSBSTATUS_PLAYING) == false)
		{
			(*iter)->Release();
			iter = m_Channels.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void cSoundManager::Render()
{
}

void cSoundManager::Release()
{
	for (auto& iter : m_Channels)
	{
		iter->Release();
	}
	for (auto& iter : m_Sounds)
	{
		SAFE_DELETE(iter.second);
	}
}

void cSoundManager::AddSound(string _Key, LPWSTR _Path)
{
	CSound** a = new CSound*();
	m_Manager.Create(a, _Path, DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY);
	m_Sounds.insert(make_pair(_Key, (*a)));
	delete a;
}

LPDIRECTSOUNDBUFFER cSoundManager::Play(string _key, int _Volume, bool _CheckAlreadyPlayed, bool _Loop)
{
	if (_CheckAlreadyPlayed)
	{
		for (auto& iter : m_PlayedSounds)
		{
			if (_key == iter)
			{
				return nullptr;
			}
		}
		m_PlayedSounds.push_back(_key);
	}
	LPDIRECTSOUNDBUFFER a;
	m_Manager.GetDirectSound()->DuplicateSoundBuffer(m_Sounds[_key]->GetBuffer(0), &a);
	a->Play(0, 0, _Loop ? DSBPLAY_LOOPING : 0);
	a->SetVolume(_Volume);
	m_Channels.push_back(a);
	return a;
}

void cSoundManager::StopAll()
{
	for (auto& iter : m_Channels)
	{
		iter->Release();
	}
	m_Channels.clear();
}
