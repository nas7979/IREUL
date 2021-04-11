#pragma once
#include "cParticleBase.h"
//아무 기능도 없는 가장 평범한 파티클이다.
class cParticle : public cParticleBase
{
public:
	cParticle();
	~cParticle();

	// Inherited via cParticleBase
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

