#pragma once
//직선 혹은 사각형 모양으로 깨지는 이펙트를 가진 파티클이다.
class cParticleGlitch : public cParticleBase
{
public:
	cParticleGlitch();
	~cParticleGlitch();

	// cParticleBase을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	float m_PosRand = 0;
	float m_PosRandVel = 0;
	float m_PosRandFri = 1;
	float m_SizeRand = 0;
	float m_SizeRandVel = 0;
	float m_SizeRandFri = 1;
	bool m_Box = false;

public:
	void SetPosRand(float _Rand, float _Vel, float _Fri) { m_PosRand = _Rand; m_PosRandVel = _Vel; m_PosRandFri = _Fri; }
	void SetPosRand(float _Rand) { m_PosRand = _Rand; }
	float GetPosRand() { return m_PosRand; }
	void SetPosRandVel(float _Vel) { m_PosRandVel = _Vel; }
	void SetPosRandFri(float _Fri) { m_PosRandFri = _Fri; }

	void SetSizeRand(float _Rand, float _Vel, float _Fri) { m_SizeRand = _Rand; m_SizeRandVel = _Vel; m_SizeRandFri = _Fri; }
	void SetSizeRand(float _Rand) { m_SizeRand = _Rand; }
	float GetSizeRand() { return m_SizeRand; }
	void SetSizeRandVel(float _Vel) { m_SizeRandVel = _Vel; }
	void SetSizeRandFri(float _Fri) { m_SizeRandFri = _Fri; }

	void SetBox(bool _Box) { m_Box = _Box; }
};

