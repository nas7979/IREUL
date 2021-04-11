#pragma once
//¹Ì»ç¿ë
class cResultScene : public cScene
{
public:
	cResultScene();
	~cResultScene();

	// Inherited via cScene
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render1() override;
	virtual void Render2() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

	wstring m_Name;
	bool m_OnTyping;
};

