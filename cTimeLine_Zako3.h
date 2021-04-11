#pragma once
class cTimeLine_Zako3 : public cTimeLine
{
public:
	cTimeLine_Zako3();
	~cTimeLine_Zako3();

	// cTimeLine을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	float m_Angle;

public:
	void SetAngle(float _Angle) { m_Angle = _Angle; }
};

