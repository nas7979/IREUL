#pragma once
class cTimeLine_Boss22 : public cTimeLine
{
public:
	cTimeLine_Boss22();
	~cTimeLine_Boss22();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	float m_Angle;
};

