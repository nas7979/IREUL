#pragma once
//�������Ը� �ʿ��� ������ �Լ��� �����ص� �θ� Ŭ�����̴�.
//��� �������� �Ȱ��� �ʿ��� �Լ����� ���� �����Լ��� �ƴ� �����Լ��� ���������μ�
//�ڽ� Ŭ�������� cBoss::Update()�� ���� �������� ȣ���� �� �ְ� �� �ξ���.
class cBoss : public cEnemy
{
public:
	cBoss();
	virtual ~cBoss();

	// cEnemy��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
	virtual void Death() override;

protected:
	float m_MaxHp;
	int m_Phase;
	bool m_Start;
	bool m_Invincible;

public:
	virtual void NextPhase();
	void SetInvincible(bool _Invincible) { m_Invincible = _Invincible; }
};

