#pragma once
//이미지가 아닌 텍스트를 출력하는 파티클이다.
class cParticleText : public cParticleBase
{
public:
	cParticleText();
	~cParticleText();

	// Inherited via cParticleBase
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	wstring m_Text;
	int m_Size;
	bool m_Kor = false;

public:
	void SetText(wstring _Text) { m_Text = _Text; }
	void SetSize(int _Size) { m_Size = _Size; }
	void SetKorean(bool _Kor) { m_Kor = _Kor; }
};

