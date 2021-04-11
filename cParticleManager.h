#pragma once
#include "cParticle.h"
#include "cParticleAnim.h"
#include "cParticleBase.h"
#include "cParticleFunc.h"
#include "cParticleText.h"
#include "cParticleGlitch.h"
//파티클들을 관리하는 매니저이다. 파티클의 생성엔 template을 사용하여 AddParticle이후 내가 원하는 클래스의 파티클을 바로 반환하도록 하였다.
//파티클도 오브젝트와 마찬가지로 1P, 2P, 공용으로 나누어 관리된다.
class cParticleManager : public cSingleton<cParticleManager>
{
public:
	cParticleManager();
	~cParticleManager();

	void Init();
	void Update();
	void Render1();
	void Render2();
	void RenderGlobal();
	void Release();

private:
	list<cParticleBase*> m_Particles[3];

public:
	template<typename T>
	T* AddParticle(Texture* _Image, Vec2 _Pos, Vec2 _Scale, float _Rot, float _Depth, int _Side, D3DCOLOR _Color = 0xffffffff)
	{
		T* a = new T;
		a->m_Image = _Image;
		a->m_Pos = _Pos;
		a->m_Scale = _Scale;
		a->m_Rot = _Rot;
		a->m_Depth = _Depth;
		a->m_Color = _Color;
		a->m_Side = _Side;
		a->Init();
		m_Particles[_Side].push_back(a);
		return a;
	}
};

#define PART cParticleManager::GetInstance()
