#pragma once
#include "cBulletBase.h"
//�ƹ� ȿ���� ���� �Ѿ� Ŭ�����̴�.
class cBullet : public cBulletBase
{
public:
	cBullet();
	~cBullet();

	// Inherited via cBulletBase
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

