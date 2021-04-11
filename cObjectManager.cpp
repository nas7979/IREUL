#include "DXUT.h"
#include "cObjectManager.h"


cObjectManager::cObjectManager()
{
}


cObjectManager::~cObjectManager()
{
}

void cObjectManager::Init()
{
	m_Player[0] = nullptr;
	m_Player[1] = nullptr;
}

void cObjectManager::Update()
{
	int TagStart = 0;
	if (SYSTEM->GetPause() == true)
	{
		TagStart = Obj_UI;
	}
	for (int Side = 0; Side < 3; Side++)
	{
		for (int Tag = TagStart; Tag < Obj_End; Tag++)
		{
			for (auto& iter = m_Objects[Side][Tag].begin(); iter != m_Objects[Side][Tag].end();)
			{
				if ((*iter)->m_Destroyed)
				{
					(*iter)->Release();
					SAFE_DELETE(*iter);
					iter = m_Objects[Side][Tag].erase(iter);
				}
				else
				{
					(*iter)->Update();
					CollisionCheck(*iter, Side);
					iter++;
				}
			}
		}
	}
}

void cObjectManager::Render1()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto& iter : m_Objects[0][Tag])
		{
			iter->Render();
		}
	}
}

void cObjectManager::Render2()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto& iter : m_Objects[1][Tag])
		{
			iter->Render();
		}
	}
}

void cObjectManager::RenderGlobal()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto& iter : m_Objects[2][Tag])
		{
			iter->Render();
		}
	}

	for (int Side = 0; Side < 3; Side++)
	{
		for (int Tag = 0; Tag < Obj_End; Tag++)
		{
			for (auto& iter : m_Objects[Side][Tag])
			{
				iter->RenderGlobal();
			}
		}
	}
}

void cObjectManager::Release()
{
	for (int Side = 0; Side < 3; Side++)
	{
		for (int Tag = 0; Tag < Obj_End; Tag++)
		{
			for (auto& iter : m_Objects[Side][Tag])
			{
				iter->Release();
				SAFE_DELETE(iter);
			}
			m_Objects[Side][Tag].clear();
		}
	}
	m_ID = 1;
}

cObject* cObjectManager::AddObject(string _Name, Vec2 _Pos, float _Depth, ObjectTag _Tag, int _Side)
{
	cObject* a = new cObject;
	a->m_Name = _Name;
	a->m_Pos = _Pos;
	a->m_Depth = _Depth;
	a->m_Tag = _Tag;
	a->m_ID = m_ID;
	a->m_Side = _Side;
	m_ID++;
	m_Objects[_Side][_Tag].push_back(a);
	return a;
}

void cObjectManager::CollisionCheck(cObject * _Object, int _Side) 
{
	cCollider* Self = _Object->GetComponent<cCollider>();
	if (Self == nullptr || Self->m_Enable == false)
		return;

	cCollider* Other;
	for (auto& Tag : Self->m_CollWith)
	{
		for (auto& iter : m_Objects[_Side][Tag])
		{
			Other = iter->GetComponent<cCollider>();
			if (Other->m_Enable == false)
				continue;
			for (auto& SelfColl : Self->m_Colliders)
			{
				for (auto& OtherColl : Other->m_Colliders)
				{
					if (D3DXVec2Length(&(SelfColl.WorldPos - OtherColl.WorldPos)) <= SelfColl.Radius + OtherColl.Radius)
					{
						Self->m_CollFunc(iter);
						if (Self->GetEnable() == false)
						{
							return;
						}
						goto Next;
					}
				}
			}
		Next:
			continue;
		}
	}
}

cObject * cObjectManager::GetNearestObject(Vec2 _Pos, ObjectTag _Tag, int _Side)
{
	cObject* Near = nullptr;
	float NearDist = 10000;
	float Dist;
	for (auto& iter : m_Objects[_Side][_Tag])
	{
		Dist = D3DXVec2Length(&(_Pos - iter->GetPosition()));
		if (Dist < NearDist)
		{
			NearDist = Dist;
			Near = iter;
		}
	}
	return Near;
}

list<cObject*> cObjectManager::Find(ObjectTag _Tag, int _Side)
{
	return m_Objects[_Side][_Tag];
}

list<cObject*> cObjectManager::Find(ObjectTag _Tag, string _Name, int _Side)
{
	list<cObject*> list;

	for (auto& iter : m_Objects[_Side][_Tag])
	{
		if (iter->GetName() == _Name)
		{
			list.push_back(iter);
		}
	}

	return list;
}
