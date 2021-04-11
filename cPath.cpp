#include "DXUT.h"
#include "cPath.h"


cPath::cPath()
{
}


cPath::~cPath()
{
}

void cPath::Init()
{
	m_Speed = 0;
	m_Friction = 1;
}

void cPath::Update()
{
	if (m_Speed != 0)
	{
		m_Speed *= pow(m_Friction, DT * 60);
		m_CurLerpPosition += m_Speed * DT;

		if (m_CurLerpPosition >= m_PathLength)
		{
			m_Speed = 0;
			m_Friction = 1;
			m_Owner->SetPosition(m_EndPos);
		}
		else
		{
			Vec2 v1, v2, v3;
			D3DXVec2Lerp(&v1, &m_StartPos, &m_ControlPos, m_CurLerpPosition / m_PathLength);
			D3DXVec2Lerp(&v2, &m_ControlPos, &m_EndPos, m_CurLerpPosition / m_PathLength);
			D3DXVec2Lerp(&v3, &v1, &v2, m_CurLerpPosition / m_PathLength);

			m_Dir = PointDirection(m_Owner->GetPosition(), v3);
			m_Owner->SetPosition(v3);
		}
	}
}

void cPath::Render()
{
}

void cPath::RenderGlobal()
{
}

void cPath::Release()
{
}

void cPath::AddPath(float _Speed, float _Friction, Vec2 _End, Vec2 _Control)
{
	if (_Control == Vec2(0, 0))
	{
		_Control = _End;
	}
	m_Speed = _Speed;
	m_Friction = _Friction;
	m_StartPos = m_Owner->GetPosition();
	Vec2 Prev = m_StartPos;
	m_EndPos = _End;
	m_ControlPos = _Control;
	m_PathLength = 0;
	m_CurLerpPosition = 0;

	Vec2 v1, v2, v3;
	for (int i = 1; i <= 25; i++)
	{
		D3DXVec2Lerp(&v1, &m_StartPos, &_Control, i * 0.04);
		D3DXVec2Lerp(&v2, &_Control, &_End, i * 0.04);
		D3DXVec2Lerp(&v3, &v1, &v2, i * 0.04);
		m_PathLength += D3DXVec2Length(&(Prev - v3));
		Prev = v3;
	}
}
