#pragma once
#include "cBoss.h"
//1���������� �����̴�.
class cBoss1 : public cBoss
{
public:
	cBoss1();
	~cBoss1();

	// cEnemy��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
	virtual void Death() override;
	virtual void NextPhase() override;
};

