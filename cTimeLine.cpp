#include "DXUT.h"
#include "cTimeLine.h"
#include "cBullet.h"
#include "cBulletFriction.h"


cTimeLine::cTimeLine()
{
	m_Time = 0;
	m_Dir = 0;
	m_Loop = 0;
	m_Effect = IMAGE->Find("BulletFire");
	m_Tex[0] = IMAGE->Find("Bullet_Color1");
	m_BaseTex[0] = IMAGE->Find("Bullet1");
	m_Tex[1] = IMAGE->Find("Bullet_Color3");
	m_BaseTex[1] = IMAGE->Find("Bullet3");
	m_Tex[2] = IMAGE->Find("Bullet_Color4");
	m_BaseTex[2] = IMAGE->Find("Bullet4");
	m_Tex[3] = IMAGE->Find("Bullet_Color5");
	m_BaseTex[3] = IMAGE->Find("Bullet5");
	m_Tex[4] = IMAGE->Find("Bullet_Color6");
	m_BaseTex[4] = IMAGE->Find("Bullet6");
}


cTimeLine::~cTimeLine()
{
}

cObject * cTimeLine::FireBullet(int _Image, Vec2 _Pos, float _Radius, float _Dir, float _Speed, D3DCOLOR _Color)
{
	cObject* a = OBJECT->AddObject("EnemyBullet", _Pos, 0.5, Obj_EnemyBullet, m_Owner->GetSide());
	a->AddComponent<cBullet>()->SetDirection(_Dir);
	a->GetComponent<cBullet>()->SetSpeed(_Speed);
	a->GetComponent<cBullet>()->SetBaseImage(m_BaseTex[_Image]);
	a->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), _Radius);
	a->GetComponent<cRenderer>()->SetImage(m_Tex[_Image]);
	a->GetComponent<cRenderer>()->SetColor(_Color);
	return a;
}

cObject * cTimeLine::FireFrictionBullet(int _Image, Vec2 _Pos, float _Radius, float _Dir, float _Speed, float _EndSpeed, float _Friction, D3DCOLOR _Color)
{
	cObject* a = OBJECT->AddObject("EnemyBullet", _Pos, 0.5, Obj_EnemyBullet, m_Owner->GetSide());
	a->AddComponent<cBulletFriction>()->SetDirection(_Dir);
	a->GetComponent<cBulletFriction>()->SetSpeed(_Speed);
	a->GetComponent<cBulletFriction>()->SetBaseImage(m_BaseTex[_Image]);
	a->GetComponent<cBulletFriction>()->SetEndSpeed(_EndSpeed);
	a->GetComponent<cBulletFriction>()->SetFriction(_Friction);
	a->GetComponent<cCollider>()->AddCollider(Vec2(0, 0), _Radius);
	a->GetComponent<cRenderer>()->SetImage(m_Tex[_Image]);
	a->GetComponent<cRenderer>()->SetColor(_Color);
	return a;
}

void cTimeLine::FireEffect(Vec2 _Pos, D3DCOLOR _Color)
{
	cParticleGlitch* Part = PART->AddParticle<cParticleGlitch>(m_Effect, _Pos, Vec2(0.5, 0.5), 0, 0.4, m_Owner->GetSide(), _Color);
	Part->SetAlpha(255, -1000, 1);
	Part->SetScale(Vec2(25, 25), 0.99);
	Part->SetPosRand(6);
	Part->SetSizeRand(3);
}
