#pragma once
class cTimeLine_Boss31 : public cTimeLine
{
public:
	cTimeLine_Boss31();
	~cTimeLine_Boss31();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	float m_RandDir;
};

