#pragma once
class cTimeLine_Boss12 : public cTimeLine
{
public:
	cTimeLine_Boss12();
	~cTimeLine_Boss12();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

