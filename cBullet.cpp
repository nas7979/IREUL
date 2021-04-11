#include "DXUT.h"
#include "cBullet.h"


cBullet::cBullet()
{
}


cBullet::~cBullet()
{
}

void cBullet::Init()
{
	AddComponent<cCollider>();
	AddComponent<cRenderer>();
}

void cBullet::Update()
{
	m_Owner->Translate(RotateVec(Vec2(m_Speed, 0), m_Dir) * DT);
	m_Owner->SetRotation(m_Dir);
	
	IsOutMap();
}

void cBullet::Render()
{
	if (m_BaseImage != nullptr)
	{
		IMAGE->CenterRender(m_BaseImage, m_Owner->GetPosition(), D3DXToRadian(m_Owner->GetRotation()), m_Owner->GetScale(), m_Owner->GetDepth());
	}
}

void cBullet::RenderGlobal()
{
}

void cBullet::Release()
{
}
