#pragma once
#include "cBulletBase.h"
//아무 효과가 없는 총알 클래스이다.
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

