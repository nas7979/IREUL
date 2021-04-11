#pragma once
//��� �Ѿ��� �θ� Ŭ�����μ�, �ӵ�, ����, ���ط� ��� ���� �Լ��� ��Ƶΰ� �ִ�.
//�Ѿ˵��� ��ü�� �Ͼ���� BaseImage�� �� ���� �������Ǵ� ������ �ٲ� �� �ִ� �̹��� �� �� ������ �����Ǿ� �ִ�.
//GetComponent�� �� ��� ������Ʈ�� cBullet����, cBulletFriction����, cBulletHoming���� Ȯ������ ���� ��
//GetComponent<cBulletBase>()�� �����μ� �� Ŭ������ ��ӹ��� �ڽ� Ŭ������ ������ �� �ִ�.
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

