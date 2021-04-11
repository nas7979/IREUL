#pragma once
#include "cZako.h"
#include "cPath.h"
//스테이지들의 부모 클래스로, 스테이지에 필요한 변수나 함수 등을 이곳에 선언하고 상속해
//자식 클래스에서의 불필요한 중복 선언을 없앤다.
class cStage : public cScene
{
public:
	cStage();
	virtual ~cStage();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render1() override;
	virtual void Render2() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

protected:
	float m_BackPos[2];
	float m_Time[2];
	float m_TimeSpeed[2];
	int m_Last[2];
	float m_LifeRot[3];
	float m_TimeMax;
	int m_Side;

public:
	template<typename T>
	cObject* AddZako(string _Name, Vec2 _Pos, float _Hp, float _Time)
	{
		cObject* a = OBJECT->AddObject(_Name, _Pos, 0.6, Obj_Enemy, m_Side);
		a->AddComponent<cZako>()->SetHp(_Hp);
		a->GetComponent<cZako>()->SetTime(_Time);
		a->AddComponent<T>();
		return a;
	}

	void AddPath(cObject* _Obj, float _Speed, float _Friction, Vec2 _End, Vec2 _Control = Vec2(0, 0))
	{
		_Obj->GetComponent<cPath>()->AddPath(_Speed, _Friction, _End, _Control);
	}

	void AddItem(cObject* _Obj, int _Small, int _Big)
	{
		_Obj->GetComponent<cEnemy>()->SetSmallItem(_Small);
		_Obj->GetComponent<cEnemy>()->SetBigItem(_Big);
	}

	float GetTime(int _Side) { return m_Time[_Side]; }
	void SetTimeSpeed(float _Speed, int _Side) { m_TimeSpeed[_Side] = _Speed; }
	float GetTimeSpeed(int _Side) { return m_TimeSpeed[_Side]; }
	float AddTimeSpeed(float _Val, int _Side) { return m_TimeSpeed[_Side] += _Val; }
};

