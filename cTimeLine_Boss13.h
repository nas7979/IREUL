#pragma once
class cTimeLine_Boss13 : public cTimeLine
{
public:
	cTimeLine_Boss13();
	~cTimeLine_Boss13();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

