#pragma once
//모든 총알의 부모 클래스로서, 속도, 각도, 피해량 등과 각종 함수를 담아두고 있다.
//총알들은 전체가 하얀색인 BaseImage와 그 위에 렌더링되는 색상값을 바꿀 수 있는 이미지 총 두 장으로 구성되어 있다.
//GetComponent를 할 대상 오브젝트가 cBullet인지, cBulletFriction인지, cBulletHoming인지 확실하지 않을 땐
//GetComponent<cBulletBase>()를 함으로서 이 클래스를 상속받은 자식 클래스를 가져올 수 있다.
class cBulletBase : public cComponent
{
public:
	cBulletBase();
	virtual ~cBulletBase();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderGlobal() = 0;
	virtual void Release() = 0;

protected:
	float m_Speed;
	float m_Dir;
	float m_Damage = 0;
	Texture* m_BaseImage = nullptr;

public:
	void IsOutMap();
	void SetSpeed(float _Speed) { m_Speed = _Speed; }
	float GetSpeed() { return m_Speed; }
	void SetDirection(float _Direction) { m_Dir = _Direction; }
	float GetDirection() { return m_Dir; }
	void SetDamage(float _Damage) { m_Damage = _Damage; }
	float GetDamage() { return m_Damage; }
	void SetBaseImage(Texture* _Image) { m_BaseImage = _Image; }
};

