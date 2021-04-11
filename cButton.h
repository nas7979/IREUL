#pragma once
//메뉴나 일시 정지 화면에서의 버튼 클래스이다.
class cButton : public cComponent
{
public:
	cButton();
	~cButton();

	// cComponent을(를) 통해 상속됨
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void RenderGlobal() override;

	virtual void Release() override;

private:
	bool m_Selected;
	Texture* m_Tex[2];

public:
	void SetImage(string _Key);
	void SetSelected(bool _Selected) { m_Selected = _Selected; }
	bool GetSelected() { return m_Selected; }

};

