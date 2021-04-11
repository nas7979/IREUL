#pragma once
//������Ʈ�� �̵��� �����ϴ� ������Ʈ�̴�.
//����� ���� ���� �ֱ� ������ �Ѿ˿� ������� ������, �ַ� ������ ����Ѵ�.
//��� ���� �̵��� �����ϰ�, ������ ��� �̿��� �ε巯�� �������� �����ش�.
//�ε巯�� �������� ���� ���, ��� ���̸� ��Ȯ�ϰ� ���� ���� ���� �̵��ӵ��� �ǵ��� ������ ���� �ٸ� �� �ִ�.
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

