#include "DXUT.h"
#include "cAnimation.h"


cAnimation::cAnimation()
{
}


cAnimation::~cAnimation()
{
}

void cAnimation::Init()
{
	m_Frame = 0;
	m_Speed = 1;
}

void cAnimation::Update()
{
	m_Frame += m_Anim->Speed * m_Speed * DT;
	if (m_Frame >= m_Anim->MaxFrame + 1)
	{
		if (m_Anim->Loop)
		{
			m_Frame -= m_Anim->MaxFrame + 1;
		}
		else
		{
			m_Frame = m_Anim->MaxFrame;
		}
	}
	else if (m_Frame < 0)
	{
		if (m_Anim->Loop)
		{
			m_Frame += m_Anim->MaxFrame + 1;
		}
		else
		{
			m_Frame = 0;
		}
	}
	GetComponent<cRenderer>()->SetImage((*m_Anim->Animation)[(int)m_Frame]);
}

void cAnimation::Render()
{
}

void cAnimation::RenderGlobal()
{
}

void cAnimation::Release()
{
	for (auto& iter : m_Animations)
	{
		SAFE_DELETE(iter);
	}
}

void cAnimation::AddAnimation(string _Key, string _Resource, float _Speed, bool _Loop)
{
	Animation* Anim = new Animation;
	Anim->Animation = IMAGE->FindAnimation(_Resource);
	Anim->MaxFrame = Anim->Animation->size() - 1;
	Anim->Loop = _Loop;
	Anim->Speed = 1 / _Speed;
	Anim->Key = _Key;
	m_Animations.push_back(Anim);
	GetComponent<cRenderer>()->SetImage((*Anim->Animation)[0]);
}

void cAnimation::SetAnimation(string _Key)
{
	for (auto& iter : m_Animations)
	{
		if (iter->Key == _Key)
		{
			m_Anim = iter;
			break;
		}
	}
}

void cAnimation::SetSpeed(float _Speed)
{
	m_Speed = _Speed;
}

void cAnimation::SetFrame(float _Frame)
{
	m_Frame = _Frame;
}
