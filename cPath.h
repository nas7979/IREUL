#pragma once
//오브젝트의 이동을 관리하는 컴포넌트이다.
//계산할 것이 조금 있기 때문에 총알엔 사용하지 않으며, 주로 적에게 사용한다.
//곡선과 직선 이동이 가능하고, 베지어 곡선을 이용해 부드러운 움직임을 보여준다.
//부드러운 움직임을 얻은 대신, 곡선의 길이를 정확하게 구할 수가 없어 이동속도가 의도한 값과는 조금 다를 수 있다.
class cPath : public cComponent
{
public:
	cPath();
	~cPath();

	// Inherited via cComponent
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	Vec2 m_StartPos;
	Vec2 m_EndPos;
	Vec2 m_ControlPos;
	float m_Speed;
	float m_Friction;
	float m_PathLength;
	float m_CurLerpPosition;
	float m_Dir;

public:
	void AddPath(float _Speed, float _Friction, Vec2 _End, Vec2 _Control = Vec2(0, 0));
	float GetDirection() { return m_Dir; }
	float GetSpeed() { return m_Speed; }
};

