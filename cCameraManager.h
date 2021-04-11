#pragma once
//¹Ì»ç¿ë
class cCameraManager : public cSingleton<cCameraManager>
{
public:
	cCameraManager();
	~cCameraManager();

	void Init();
	void Update();
	void Render();
	void Release();

private:
	Matrix m_Mat;
	Vec2 m_Pos;
	Vec2 m_MoveTo;
	float m_Scale;
	float m_ScaleTo;
	float m_ScaleFrom;
	float m_Dist;
	float m_Speed;
	float m_Friction;
	float m_ShakeForce;
	float m_ShakeTime;
	Vec2 m_ShakePos;

public:
	void Shake(float _Force, float _Time);
	void MoveTo(Vec2 _To, float _Speed, float _Friction, float _Scale);
	Matrix GetMatrix();
};

#define CAMERA cCameraManager::GetInstance()