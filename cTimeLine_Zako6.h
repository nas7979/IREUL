#pragma once
class cTimeLine_Zako6 : public cTimeLine
{
public:
	cTimeLine_Zako6();
	~cTimeLine_Zako6();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

