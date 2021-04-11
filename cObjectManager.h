#pragma once
#include "cObject.h"
//오브젝트들을 1P, 2P, 공용으로 나누어 관리하며, 태그별로 다른 리스트에 담아 충돌 검사 등에서의 효율을 높였다.
//또한 자주 참조하게 되는 플레이어를 이곳에 담아두어 검색의 필요성을 없앴다.
//오브젝트에 고유한 ID를 할당하여 어느 오브젝트를 변수로 담아 두었을 때 그 포인터가 가르키는 오브젝트가
//변경되었거나 파괴되었는지 확인할 수 있다.
class cObjectManager : public cSingleton<cObjectManager>
{
public:
	cObjectManager();
	~cObjectManager();

	void Init();
	void Update();
	void Render1();
	void Render2();
	void RenderGlobal();
	void Release();

private:
	list<cObject*> m_Objects[3][Obj_End];
	cObject* m_Player[2] = { nullptr, nullptr };
	int m_ID = 1;

public:
	cObject* AddObject(string _Name, Vec2 _Pos, float _Depth, ObjectTag _Tag, int _Side);
	void CollisionCheck(cObject* _Object, int _Side);
	void SetPlayer(cObject* _Player, int _Side) { m_Player[_Side] = _Player; }
	cObject* GetPlayer(int _Side) { return m_Player[_Side]; }
	void SetID(int _ID) { m_ID = _ID; }
	cObject* GetNearestObject(Vec2 _Pos, ObjectTag _Tag, int _Side);
	list<cObject*> Find(ObjectTag _Tag, int _Side);
	list<cObject*> Find(ObjectTag _Tag, string _Name, int _Side);

};

#define OBJECT cObjectManager::GetInstance()