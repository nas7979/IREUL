#pragma once
class cTimeLine_Boss33 : public cTimeLine
{
public:
	cTimeLine_Boss33();
	~cTimeLine_Boss33();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

