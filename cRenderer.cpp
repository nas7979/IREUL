#include "DXUT.h"
#include "cRenderer.h"


cRenderer::cRenderer()
{
}


cRenderer::~cRenderer()
{
}

void cRenderer::Init()
{
}

void cRenderer::Update()
{
}

void cRenderer::Render()
{
	if (!m_Glitch)
	{
		IMAGE->CenterRender(m_Image, m_Owner->GetPosition(), D3DXToRadian(m_Owner->GetRotation()), m_Owner->GetScale(), m_Owner->GetDepth(), m_Color);
	}
	else
	{
		IMAGE->CenterRenderGlitch(m_Image, m_Owner->GetPosition(), D3DXToRadian(m_Owner->GetRotation()), m_Owner->GetScale(), m_Owner->GetDepth(), m_GlitchPosRand, m_GlitchSizeRand, m_Color);
	}
}

void cRenderer::RenderGlobal()
{
}

void cRenderer::Release()
{
}
