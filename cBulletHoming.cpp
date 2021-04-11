#include "DXUT.h"
#include "cBulletHoming.h"


cBulletHoming::cBulletHoming()
{
}


cBulletHoming::~cBulletHoming()
{
}

void cBulletHoming::Init()
{
	AddComponent<cCollider>();
	AddComponent<cRenderer>();
	m_RotSpeed = 500;
	m_Dir = 0;
}

void cBulletHoming::Update()
{
	if(m_Target != nullptr)
	{
		if (m_Target->GetID() == m_TargetID && m_Target->GetDestroyed() == false)
		{
			Vec2 Vec;
			D3DXVec2Normalize(&Vec, &(m_Target->GetPosition() - m_Owner->GetPosition()));
			m_Dir += D3DXVec2Dot(&RotateVec(Vec2(0, 1), m_Dir), &Vec) * m_RotSpeed * DT;
			m_RotSpeed += 1000 * DT;
		}
		else
		{
			m_Target = nullptr;
		}
	}
	else
	{
		IsOutMap();
	}

	m_Owner->Translate(RotateVec(Vec2(m_Speed, 0), m_Dir) * DT);
	m_Owner->SetRotation(m_Dir);
}

void cBulletHoming::Render()
{
	if (m_BaseImage != nullptr)
	{
		IMAGE->CenterRender(m_BaseImage, m_Owner->GetPosition(), D3DXToRadian(m_Owner->GetRotation()), m_Owner->GetScale(), m_Owner->GetDepth());
	}
}

void cBulletHoming::RenderGlobal()
{
}

void cBulletHoming::Release()
{
}

void cBulletHoming::SetTarget(cObject * _Target)
{
	if (_Target != nullptr)
	{
		m_Target = _Target;
		m_TargetID = _Target->GetID();
	}
}
