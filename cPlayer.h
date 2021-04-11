#pragma once
//�÷��̾�� m_Keys�� ����Ű���� 1P, 2P ���� �����صξ� Ű �Է� ���ǹ��� �ϳ��� ó���� �� �ְ� �Ͽ���.
enum Key {
	Key_Up,
	Key_Down,
	Key_Left,
	Key_Right,
	Key_Attack,
	Key_Shift,
	Key_Skill,
	Key_Slow,
	Key_End
};
class cPlayer : public cComponent
{
public:
	cPlayer();
	~cPlayer();

	// Inherited via cComponent
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	float m_Speed;
	int m_Side;
	int m_Life;
	float m_Power;
	bool m_AttackAble;
	bool m_Dead;
	bool m_Slow;
	bool m_Invincible;
	cObject* m_Ring;
	
	int m_Keys[Key_End];

public:
	void SetSide(int _Side);
	void Death();

	void SetPower(float _Power) { m_Power = _Power; }
	float GetPower() { return m_Power; }
	void AddPower(float _Power);

	void SetLife(int _Life) { m_Life = _Life; }
	int GetLife() { return m_Life; }
	void AddLife(int _Life) { m_Life += _Life; }

	bool GetDead() { return m_Dead; }

	void SetInvincible(bool _Invincible) { m_Invincible = _Invincible; }

	float GetSpeed() { return m_Speed; }
};

