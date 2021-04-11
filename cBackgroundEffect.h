#pragma once
//배경의 0과 1이 떨어지는 이펙트를 담당하는 컴포넌트이다.
class cBackgroundEffect : public cComponent
{
public:
	cBackgroundEffect();
	~cBackgroundEffect();

	// cComponent을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

	float m_Speed;
	int m_Alpha;
};

