#pragma once
#include "cParticleBase.h"
//�ִϸ��̼��� �ʿ��� ��ƼŬ�� ���� �� ����ϴ� Ŭ�����̴�.
class cParticleAnim : public cParticleBase
{
public:
	cParticleAnim();
	~cParticleAnim();

	// Inherited via cParticleBase
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	vector<Texture*>* m_Anim;
	float m_AnimSpeed = 0;
	int m_Frame = -1;
	float m_Timer = 0;

public:
	void SetAnimation(vector<Texture*>* _Anim) { m_Anim = _Anim; }
	vector<Texture*>* GetAnimation() { return m_Anim; }
	void SetAnimSpeed(float _Speed) { m_AnimSpeed = _Speed; }
};

