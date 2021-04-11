#pragma once
#include "cBulletBase.h"
//감속, 혹은 가속할 수 있는 총알 클래스이다. Friction이 1보다 작으면 감속하고, 반대면 가속한다. EndSpeed로 속도의 최댓/ 최솟값을 조절할 수 있다.
class cBulletFriction : public cBulletBase
{
public:
	cBulletFriction();
	~cBulletFriction();

	// Inherited via cBulletBase
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	float m_Friction;
	float m_EndSpeed;

public:
	void SetFriction(float _Friction) { m_Friction = _Friction; }
	float GetFriction() { return m_Friction; }
	void SetEndSpeed(float _Speed) { m_EndSpeed = _Speed; }
	float GetEndSpeed() { return m_EndSpeed; }
};

