#include "DXUT.h"
#include "cBulletBounce.h"


cBulletBounce::cBulletBounce()
{
}


cBulletBounce::~cBulletBounce()
{
}

void cBulletBounce::Init()
{
	AddComponent<cCollider>();
	AddComponent<cRenderer>();
}

void cBulletBounce::Update()
{
	m_Speed *= pow(m_Friction, DT * 60);

	if (m_Friction > 1)
	{
		if (m_EndSpeed <= m_Speed)
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
	if (m_MaxBounceCount != 0)
	{
		float XPos = 1100 * m_Owner->GetSide();
		if (m_Owner->GetPosition().y < 10)
		{
			m_Dir = -m_Dir;
			m_Owner->SetPosition(Vec2(m_Owner->GetPosition().x, 10));
			m_MaxBounceCount--;
		}
		else if (m_Owner->GetPosition().x < 10 + XPos)
		{
			m_Dir = 180 - m_Dir;
			m_Owner->SetPosition(Vec2(10 + XPos, m_Owner->GetPosition().y));
			m_MaxBounceCount--;
		}
		else if (m_Owner->GetPosition().x > 490 + XPos)
		{
			m_Dir = 180 - m_Dir;
			m_Owner->SetPosition(Vec2(490 + XPos, m_Owner->GetPosition().y));
			m_MaxBounceCount--;
		}
		else if (m_Owner->GetPosition().y >= 950)
		{
			m_Owner->Destroy();
		}
	}
}

void cBulletBounce::Render()
{
	if (m_BaseImage != nullptr)
	{
		IMAGE->CenterRender(m_BaseImage, m_Owner->GetPosition(), D3DXToRadian(m_Owner->GetRotation()), m_Owner->GetScale(), m_Owner->GetDepth());
	}
}

void cBulletBounce::RenderGlobal()
{
}

void cBulletBounce::Release()
{
}
