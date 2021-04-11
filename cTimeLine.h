#pragma once
#include "cBullet.h"
#include "cBulletFriction.h"
//���� ź�� ���� ������ ���Ǹ�, ���� ���� ����ϴ� �Ѿ˰� �Ѿ� ����Ʈ ���� �Լ��� ��� TimeLine���� �θ��� �� Ŭ�������� ������ �ξ���.
//���� �Ѿ��� �̹����� m_Tex�� �̸� ��Ƶ����μ� �Ѿ��� ������ ������ �̹����� �˻��� �ʿ䰡 ������ �ߴ�.
//�� Ŭ������ �ڽ� Ŭ�������� ���� ������ ���̹Ƿ� ������ ���� �ʾҴ�.
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

