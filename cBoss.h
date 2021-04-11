#pragma once
//보스에게만 필요한 변수와 함수를 선언해둔 부모 클래스이다.
//모든 보스들이 똑같이 필요한 함수들은 순수 가상함수가 아닌 가상함수로 선언함으로서
//자식 클래스에서 cBoss::Update()와 같은 형식으로 호출할 수 있게 해 두었다.
class cBoss : public cEnemy
{
public:
	cBoss();
	virtual ~cBoss();

	// cEnemy을(를) 통해 상속됨
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

