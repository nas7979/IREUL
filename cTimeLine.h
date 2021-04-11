#pragma once
#include "cBullet.h"
#include "cBulletFriction.h"
//적의 탄막 패턴 구현에 사용되며, 가장 많이 사용하는 총알과 총알 이펙트 생성 함수는 모든 TimeLine들의 부모인 이 클래스에서 정의해 두었다.
//또한 총알의 이미지를 m_Tex에 미리 담아둠으로서 총알을 생성할 때마다 이미지를 검색할 필요가 없도록 했다.
//이 클래스의 자식 클래스들은 전부 패턴일 뿐이므로 설명은 적지 않았다.
class cTimeLine : public cComponent
{
public:
	cTimeLine();
	virtual ~cTimeLine();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderGlobal() = 0;
	virtual void Release() = 0;

protected:
	float m_Time;
	int m_Last;
	int m_Loop;
	Texture* m_Tex[5];
	Texture* m_BaseTex[5];
	Texture* m_Effect;
	float m_Dir;

public:
	cObject* FireBullet(int _Image, Vec2 _Pos, float _Radius, float _Dir, float _Speed, D3DCOLOR _Color);
	cObject* FireFrictionBullet(int _Image, Vec2 _Pos, float _Radius, float _Dir, float _Speed, float _EndSpeed, float _Friction, D3DCOLOR _Color);
	void FireEffect(Vec2 _Pos, D3DCOLOR _Color);

	void SetDirection(float _Dir) { m_Dir = _Dir; }
};

