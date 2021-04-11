#pragma once
#include "cComponent.h"
class cComponent;
//오브젝트에 공용적으로 필요한 많은 변수들과 컴포넌트를 담을 리스트를 가지고 있다.
//Alarm을 람다 함수로 만들어 두어 그때그때 타이머를 만들어 줄 필요 없이 Init에서 전부 내용을 넣어준 후 호출할 때엔 SetAlarm(인덱스, 시간)으로 간단하게 처리한다.
enum ObjectTag
{
	Obj_Player,
	Obj_Enemy,
	Obj_PlayerBullet,
	Obj_EnemyBullet,
	Obj_Item,
	Obj_None,
	Obj_UI,
	Obj_End
};
class cObject
{
	friend class cObjectManager;
public:
	cObject();
	~cObject();

	void Init();
	void Update();
	void Render();
	void RenderGlobal();
	void Release();

private:

	Vec2 m_Pos = Vec2(0,0);
	Vec2 m_Scale = Vec2(1,1);
	float m_Rot = 0;
	float m_Depth = 0;
	string m_Name = "";
	ObjectTag m_Tag = Obj_None;
	list<cComponent*> m_Components;
	bool m_Destroyed = false;
	float* m_Alarm = nullptr;
	int m_AlarmSize = 0;
	function<void(int _Index)> m_AlarmFunc;
	int m_ID = 0;
	int m_Side;

public:

	void SetAlarmSize(int _Size) { m_Alarm = new float[_Size]; m_AlarmSize = _Size; for (int i = 0; i < _Size; i++) { m_Alarm[i] = -100; } }
	void SetAlarm(int _Index, float _Time) { m_Alarm[_Index] = _Time; }
	void SetAlarmFunc(function<void(int _Index)> _Func) { m_AlarmFunc = _Func; }

	Vec2 Translate(Vec2 _Pos) { return m_Pos += _Pos; }
	Vec2 Scaling(Vec2 _Scale) { return m_Scale += _Scale; }
	float Rotate(float _Rot) { return m_Rot += _Rot; }

	void SetPosition(Vec2 _Pos) { m_Pos = _Pos; }
	Vec2 GetPosition() { return m_Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }
	Vec2 GetScale() { return m_Scale; }
	void SetRotation(float _Rot) { m_Rot = _Rot; }
	float GetRotation() { return m_Rot; }
	void SetDepth(float _Depth) { m_Depth = _Depth; }
	float GetDepth() { return m_Depth; }
	void SetName(string _Name) { m_Name = _Name; }
	string GetName() { return m_Name; }
	void SetTag(ObjectTag _Tag) { m_Tag = _Tag; }
	ObjectTag GetTag() { return m_Tag; }
	void Destroy() { m_Destroyed = true; }
	bool GetDestroyed() { return m_Destroyed; }
	void SetID(int _ID) { m_ID = _ID; }
	int GetID() { return m_ID; }
	void SetSide(int _Side) { m_Side = _Side; }
	int GetSide() { return m_Side; }

	template<typename T>
	T* AddComponent()
	{
		T* a = new T;
		a->m_Owner = this;
		m_Components.push_back(a);
		a->Init();
		return a;
	}

	template<typename T>
	T* GetComponent()
	{
		for (auto& iter : m_Components)
		{
			if (typeid(*iter) == typeid(T))
			{
				return static_cast<T*>(iter);
			}
		}

		T* Cast;
		for (auto& iter : m_Components)
		{
			Cast = dynamic_cast<T*>(iter);
			if (Cast != nullptr)
			{
				return Cast;
			}
		}
		return nullptr;
	}
};

