#pragma once
class cTimeLine_Zako9 : public cTimeLine
{
public:
	cTimeLine_Zako9();
	~cTimeLine_Zako9();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

