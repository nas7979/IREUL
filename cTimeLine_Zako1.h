#pragma once
class cTimeLine_Zako1 : public cTimeLine
{
public:
	cTimeLine_Zako1();
	~cTimeLine_Zako1();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

