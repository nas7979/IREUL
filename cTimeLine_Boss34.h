#pragma once
class cTimeLine_Boss34 : public cTimeLine
{
public:
	cTimeLine_Boss34();
	~cTimeLine_Boss34();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

