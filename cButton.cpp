#include "DXUT.h"
#include "cButton.h"


cButton::cButton()
{
}


cButton::~cButton()
{
}

void cButton::Init()
{
	AddComponent<cRenderer>();
	GetComponent<cRenderer>()->SetGlitchPosRand(7);
	GetComponent<cRenderer>()->SetGlitchSizeRand(10);
	m_Selected = false;
}

void cButton::Update()
{
	if (m_Selected)
	{
		GetComponent<cRenderer>()->SetGlitch(true);
		GetComponent<cRenderer>()->SetImage(m_Tex[1]);
	}
	else
	{
		GetComponent<cRenderer>()->SetGlitch(false);
		GetComponent<cRenderer>()->SetImage(m_Tex[0]);
	}
}

void cButton::Render()
{

	if (m_Selected && GetComponent<cRenderer>()->GetEnable())
	{
		IMAGE->CenterRender(IMAGE->Find("SelectBar"), m_Owner->GetPosition() + Vec2(0, 14), 0, Vec2(1, 1), 0.1);
	}
}

void cButton::RenderGlobal()
{
}

void cButton::Release()
{
}

void cButton::SetImage(string _Key)
{
	char Key[32];
	sprintf(Key, "%sSel", _Key.c_str());
	m_Tex[0] = IMAGE->Find(_Key);
	m_Tex[1] = IMAGE->Find(Key);
	GetComponent<cRenderer>()->SetImage(m_Tex[0]);
}
