#include "DXUT.h"
#include "cCollider.h"


cCollider::cCollider()
{
}


cCollider::~cCollider()
{
}

void cCollider::Init()
{
}

void cCollider::Update()
{
	for (auto& iter : m_Colliders)
	{
		iter.WorldPos = m_Owner->GetPosition() + RotateVec(iter.LocalPos, m_Owner->GetRotation());
	}
}

void cCollider::Render()
{
}

void cCollider::RenderGlobal()
{
}

void cCollider::Release()
{
}

void cCollider::AddCollider(Vec2 _Pos, float _Radius)
{
	m_Colliders.push_back(Collider{ Vec2(-1000,-1000),_Pos,_Radius });
}
