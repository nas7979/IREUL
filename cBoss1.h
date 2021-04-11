#pragma once
#include "cBoss.h"
//1스테이지의 보스이다.
class cBoss1 : public cBoss
{
public:
	cBoss1();
	~cBoss1();

	// cEnemy을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
	virtual void Death() override;
	virtual void NextPhase() override;
};

