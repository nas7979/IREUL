#pragma once
class cTimeLine_Boss121 : public cTimeLine
{
public:
	cTimeLine_Boss121();
	~cTimeLine_Boss121();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

