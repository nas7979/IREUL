#pragma once
//이미지를 렌더링하며, 지지직거리는 효과 또한 m_Glitch를 true로 함으로서 사용할 수 있다.
class cRenderer : public cComponent
{
public:
	cRenderer();
	~cRenderer();
	

	// Inherited via cComponent
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void RenderGlobal() override;

	virtual void Release() override;

private:
	Texture* m_Image;
	D3DCOLOR m_Color = 0xffffffff;
	bool m_Glitch = false;
	float m_GlitchPosRand;
	float m_GlitchSizeRand;

public:
	void SetImage(Texture* _Image) { m_Image = _Image; }
	Texture* GetImage() { return m_Image; }
	void SetColor(D3DCOLOR _Color) { m_Color = _Color; }
	D3DCOLOR GetColor() { return m_Color; }
	void SetGlitch(bool _Glitch) { m_Glitch = _Glitch; }
	bool GetGlitch() { return m_Glitch; }
	void SetGlitchPosRand(float _Rand) { m_GlitchPosRand = _Rand; }
	float GetGlitchPosRand() { return m_GlitchPosRand; }
	void SetGlitchSizeRand(float _Rand) { m_GlitchSizeRand = _Rand; }
	float GetGlitchSizeRand() { return m_GlitchSizeRand; }

};

