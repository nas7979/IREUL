#pragma once
#include "cButton.h"
//≈∏¿Ã∆≤ æ¿
class cTitleScene : public cScene
{
public:
	cTitleScene();
	~cTitleScene();

	// Inherited via cScene
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render1() override;
	virtual void Render2() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

	bool m_OnTitle;
	Vec2 m_Scale[4];
	D3DCOLOR m_Color[4];
	wstring m_Text[4];
	int m_Selected;
	cButton* m_Buttons[4];
	bool m_InTitle;
	bool m_InHow;
	bool m_InCredit;
	float m_HowPos;
};

