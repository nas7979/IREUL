#pragma once
#include "cBulletBase.h"
//����, Ȥ�� ������ �� �ִ� �Ѿ� Ŭ�����̴�. Friction�� 1���� ������ �����ϰ�, �ݴ�� �����Ѵ�. EndSpeed�� �ӵ��� �ִ�/ �ּڰ��� ������ �� �ִ�.
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

