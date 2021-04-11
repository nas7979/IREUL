#pragma once
//파티클에 필요한 여러 변수, 함수들을 이곳에 넣어두고, 이를 상속하여 불필요한 중복 선언을 없앴다.
//또한 모든 파티클이 이 클래스를 상속받음으로서 파티클의 관리가 쉬워졌다.
class cParticleBase
{
	friend class cParticleManager;
public:
	cParticleBase();
	virtual ~cParticleBase();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

protected:
	Texture* m_Image;
	D3DCOLOR m_Color = 0xffffffff;
	float m_Depth = 0;
	int m_Side = 0;

	Vec2 m_Pos = Vec2(0, 0);
	float m_PosVel = 0;
	float m_PosFri = 1;
	float m_Dir = 0;

	Vec2 m_Scale = Vec2(1, 1);
	Vec2 m_ScaleVel = Vec2(0, 0);
	float m_ScaleFri = 1;
	
	float m_Rot = 0;
	float m_RotVel = 0;
	float m_RotFri = 1;

	float m_Alpha = 255;
	float m_AlphaVel = 0;
	float m_AlphaFri = 1;

public:
	void SetSpeed(float _Vel, float _Fri, float _Dir);
	void SetScale(Vec2 _Vel, float _Fri);
	void SetRot(float _Vel, float _Fri);
	void SetAlpha(float _Val, float _Vel, float _Fri);
	void SetImage(Texture* _Tex) { m_Image = _Tex; }
	Texture* GetImage() { return m_Image; }
	void SetDepth(int _Depth) { m_Depth = _Depth; }
	void SetSide(int _Side) { m_Side = _Side; }

	void SetPosition(Vec2 _Pos) { m_Pos = _Pos; }
	Vec2 GetPosition() { return m_Pos; }
	void SetPosVel(float _Vel) { m_PosVel = _Vel; }
	float GetPosVel() { return m_PosVel; }
	void SetPosFri(float _Fri) { m_PosFri = _Fri; }
	float GetPosFri() { return m_PosVel; }
	void SetDirection(float _Dir) { m_Dir = _Dir; }

	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }
	Vec2 GetScale() { return m_Scale; }
	void SetScaleVel(Vec2 _Vel) { m_ScaleVel = _Vel; }
	Vec2 GetScaleVel() { return m_ScaleVel; }
	void SetScaleFri(float _Fri) { m_ScaleFri = _Fri; }
	float GetScaleFri() { return m_ScaleFri; }

	void SetRotation(float _Rot) { m_Rot = _Rot; }
	float GetRotation() { return m_Rot; }
	void SetRotVel(float _Vel) { m_RotVel = _Vel; }
	float GetRotVel() { return m_RotVel; }
	void SetRotFri(float _Fri) { m_RotFri = _Fri; }
	float GetRotFri() { return m_RotFri; }

	void SetAlpha(float _Alpha) { m_Alpha = _Alpha; }
	float GetAlpha() { return m_Alpha; }
	void SetAlphaVel(float _Vel) { m_AlphaVel = _Vel; }
	float GetAlphaVel() { return m_AlphaVel; }
	void SetAlphaFri(float _Fri) { m_AlphaFri = _Fri; }
	float GetAlphaFri() { return m_AlphaFri; }
};

