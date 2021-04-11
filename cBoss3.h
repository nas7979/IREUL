#pragma once
#include "cBoss.h"
#include "cPlayer.h"
//3스테이지의 보스이다.
class cBoss3 : public cBoss
{
public:
	cBoss3();
	~cBoss3();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
	virtual void Death() override;
	virtual void NextPhase() override;

private:
	cObject* m_Ring;
	int m_Keys[Key_End];

};

