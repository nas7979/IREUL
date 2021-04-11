#pragma once
#include "cBulletBase.h"
#include "cItem.h"
#include "cPlayer.h"
//모든 잡몹과 보스의 부모 클래스이다. 필요한 변수나 함수가 이곳에 선언되어 있으며, GetComponent를 할 대상 오브젝트가 cZako인지 cBoss의 자식 클래스인지 확실하지 않을 땐
//GetComponent<cEnemy>()를 함으로서 이를 상속받은 컴포넌트들을 찾아올 수 있다.
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

