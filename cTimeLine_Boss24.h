#pragma once
class cTimeLine_Boss24 : public cTimeLine
{
public:
	cTimeLine_Boss24();
	~cTimeLine_Boss24();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

