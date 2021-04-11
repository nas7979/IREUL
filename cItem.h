#pragma once
//아이템은 생성 시의 이름에 따라 이미지와 효과가 바뀐다.
//주변에 플레이어가 다가가면 m_Magnetic이 true가 되어 플레이어에게 끌려온다.
//또한, 아이템이 화면 윗쪽으로 나갔을 시에는 화면 상단의 고정된 y위치, 아이템의 x위치에 m_Arrow를 렌더링해 아이템의 위치를 알려준다.
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

