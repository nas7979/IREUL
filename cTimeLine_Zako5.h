#pragma once
class cTimeLine_Zako5 : public cTimeLine
{
public:
	cTimeLine_Zako5();
	~cTimeLine_Zako5();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

