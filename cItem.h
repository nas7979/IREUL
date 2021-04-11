#pragma once
//�������� ���� ���� �̸��� ���� �̹����� ȿ���� �ٲ��.
//�ֺ��� �÷��̾ �ٰ����� m_Magnetic�� true�� �Ǿ� �÷��̾�� �����´�.
//����, �������� ȭ�� �������� ������ �ÿ��� ȭ�� ����� ������ y��ġ, �������� x��ġ�� m_Arrow�� �������� �������� ��ġ�� �˷��ش�.
class cItem : public cComponent
{
public:
	cItem();
	~cItem();

	// Inherited via cComponent
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	float m_Speed;
	float m_Friction;
	bool m_Magnetic;
	bool m_CreatedByOpponentsDeath;
	Texture* m_Arrow;

public:
	void SetMagnetic(bool _Magnetic) { m_Magnetic = _Magnetic; }
	bool GetMagnetic() { return m_Magnetic; }
	void SetSpeed(float _Speed) { m_Speed = _Speed; }
	void SetFriction(float _Friction) { m_Friction = _Friction; }
	void SetCreatedByOpponentsDeath(bool _Value) { m_CreatedByOpponentsDeath = _Value; }
};

