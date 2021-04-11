#include "DXUT.h"
#include "cBulletFriction.h"


cBulletFriction::cBulletFriction()
{
}


cBulletFriction::~cBulletFriction()
{
}

void cBulletFriction::Init()
{
	AddComponent<cCollider>();
	AddComponent<cRenderer>();
}

void cBulletFriction::Update()
{
	m_Speed *= pow(m_Friction, DT * 60);

	if (m_Friction > 1)
	{
		if(m_EndSpeed <= m_Speed)
		{
			m_Speed = m_EndSpeed;
			m_Friction = 1;
		}
	}
	else if (m_Friction < 1)
	{
		if (m_EndSpeed >= m_Speed)
		{
			m_Speed = m_EndSpeed;
			m_Friction = 1;
		}
	}

	m_Owner->Translate(RotateVec(Vec2(m_Speed, 0), m_Dir) * DT);
	m_Owner->SetRotation(m_Dir);

	IsOutMap();
}

void cBulletFriction::Render()
{
	if (m_BaseImage != nullptr)
	{
		IMAGE->CenterRender(m_BaseImage, m_Owner->GetPosition(), D3DXToRadian(m_Owner->GetRotation()), m_Owner->GetScale(), m_Owner->GetDepth());
	}
}

void cBulletFriction::RenderGlobal()
{
}

void cBulletFriction::Release()
{
}
