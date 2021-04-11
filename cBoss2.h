#pragma once
#include "cBoss.h"
//2스테이지의 보스이다.
class cBoss2 : public cBoss
{
public:
	cBoss2();
	~cBoss2();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
	virtual void Death() override;
	virtual void NextPhase() override;

private:
	float m_Rot;

public:
	void SetRot(float _Rot) { m_Rot = _Rot; }
	float GetRot() { return m_Rot; }
};

