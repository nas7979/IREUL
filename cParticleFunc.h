#pragma once
//��ƼŬ�� ���� �Լ��� �־� �ξ Ư���� ������ �� �� �ְ� �Ѵ�.
class cParticleFunc : public cParticleBase
{
public:
	cParticleFunc();
	~cParticleFunc();

	// Inherited via cParticleBase
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	float m_Timer;
	float m_FuncSpeed;
	function<void(cParticleFunc* _Part)> m_Func;

public:
	void SetFuncSpeed(float _Speed) { m_FuncSpeed = _Speed; }
	void SetFunc(function<void(cParticleFunc* _Part)> _Func) { m_Func = _Func; }
};

