#pragma once
class cTimeLine_Boss38 : public cTimeLine
{
public:
	cTimeLine_Boss38();
	~cTimeLine_Boss38();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

