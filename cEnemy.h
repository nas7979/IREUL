#pragma once
#include "cBulletBase.h"
#include "cItem.h"
#include "cPlayer.h"
//��� ����� ������ �θ� Ŭ�����̴�. �ʿ��� ������ �Լ��� �̰��� ����Ǿ� ������, GetComponent�� �� ��� ������Ʈ�� cZako���� cBoss�� �ڽ� Ŭ�������� Ȯ������ ���� ��
//GetComponent<cEnemy>()�� �����μ� �̸� ��ӹ��� ������Ʈ���� ã�ƿ� �� �ִ�.
class cEnemy : public cComponent
{
public:
	cEnemy();
	~cEnemy();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderGlobal() = 0;
	virtual void Release() = 0;
	virtual void Death() = 0;

protected:
	float m_Hp;
	float m_Time = 0;
	int m_SmallItem = 0;
	int m_BigItem = 0;

public:
	void SetHp(float _Hp) { m_Hp = _Hp; }
	void AddHp(float _Hp) { m_Hp += _Hp; }
	float GetHp() { return m_Hp; }

	void SetTime(float _Time) { m_Time = _Time; }
	float GetTime() { return m_Time; }

	void SetSmallItem(int _Count) { m_SmallItem = _Count; }
	void SetBigItem(int _Count) { m_BigItem = _Count; }

};

