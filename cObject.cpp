#include "DXUT.h"
#include "cObject.h"


cObject::cObject()
{
}


cObject::~cObject()
{
}

void cObject::Init()
{
}

void cObject::Update()
{
	for (int i = 0; i < m_AlarmSize; i++)
	{
		m_Alarm[i] -= DT;
		if (m_Alarm[i] <= 0 && m_Alarm[i] > -100)
		{
			m_Alarm[i] = -100;
			m_AlarmFunc(i);
		}
	}
	for (auto& iter : m_Components)
	{
		if (iter->m_Enable)
			iter->Update();
	}
}

void cObject::Render()
{
	for (auto& iter : m_Components)
	{
		if (iter->m_Enable)
			iter->Render();
	}
}

void cObject::RenderGlobal()
{
	for (auto& iter : m_Components)
	{
		if (iter->m_Enable)
			iter->RenderGlobal();
	}
}

void cObject::Release()
{
	for (auto& iter : m_Components)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	SAFE_DELETE(m_Alarm);
}
