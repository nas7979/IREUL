#pragma once
#include "cBulletBase.h"
//벽면에서 튕기는 총알이다. 튕기는 수에 제한을 둘 수 있으며, 화면 아래로 가면 사라진다.
class cBulletBounce : public cBulletBase
{
public:
	cBulletBounce();
	~cBulletBounce();

	// cBulletBase을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	float m_Friction = 1;
	float m_EndSpeed = 0;
	int m_MaxBounceCount = -1;

public:
	void SetFriction(float _Friction) { m_Friction = _Friction; }
	float GetFriction() { return m_Friction; }
	void SetEndSpeed(float _Speed) { m_EndSpeed = _Speed; }
	float GetEndSpeed() { return m_EndSpeed; }
	void SetMaxBounceCount(int _Count) { m_MaxBounceCount = _Count; }
};

