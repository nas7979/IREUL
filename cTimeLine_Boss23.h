#pragma once
class cTimeLine_Boss23 : public cTimeLine
{
public:
	cTimeLine_Boss23();
	~cTimeLine_Boss23();

	// cTimeLine��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

