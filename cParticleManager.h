#pragma once
#include "cParticle.h"
#include "cParticleAnim.h"
#include "cParticleBase.h"
#include "cParticleFunc.h"
#include "cParticleText.h"
#include "cParticleGlitch.h"
//��ƼŬ���� �����ϴ� �Ŵ����̴�. ��ƼŬ�� ������ template�� ����Ͽ� AddParticle���� ���� ���ϴ� Ŭ������ ��ƼŬ�� �ٷ� ��ȯ�ϵ��� �Ͽ���.
//��ƼŬ�� ������Ʈ�� ���������� 1P, 2P, �������� ������ �����ȴ�.
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
