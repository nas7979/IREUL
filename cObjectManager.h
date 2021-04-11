#pragma once
#include "cObject.h"
//������Ʈ���� 1P, 2P, �������� ������ �����ϸ�, �±׺��� �ٸ� ����Ʈ�� ��� �浹 �˻� ����� ȿ���� ������.
//���� ���� �����ϰ� �Ǵ� �÷��̾ �̰��� ��Ƶξ� �˻��� �ʿ伺�� ���ݴ�.
//������Ʈ�� ������ ID�� �Ҵ��Ͽ� ��� ������Ʈ�� ������ ��� �ξ��� �� �� �����Ͱ� ����Ű�� ������Ʈ��
//����Ǿ��ų� �ı��Ǿ����� Ȯ���� �� �ִ�.
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