#pragma once
class cTimeLine_Boss37 : public cTimeLine
{
public:
	cTimeLine_Boss37();
	~cTimeLine_Boss37();

	// cTimeLine을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

