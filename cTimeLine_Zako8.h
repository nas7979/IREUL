#pragma once
class cTimeLine_Zako8 : public cTimeLine
{
public:
	cTimeLine_Zako8();
	~cTimeLine_Zako8();

	// cTimeLine을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

