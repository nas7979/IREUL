#pragma once
//�޴��� �Ͻ� ���� ȭ�鿡���� ��ư Ŭ�����̴�.
class cButton : public cComponent
{
public:
	cButton();
	~cButton();

	// cComponent��(��) ���� ��ӵ�
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

