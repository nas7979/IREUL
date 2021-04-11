#pragma once
//���浹���� ����ϸ�, m_Colliders�ȿ� ���� Collider���� ��Ƶ� �� �־� ���� ������ ����� ��ä�ο� ����� ���� �� �ִ�.
//m_Collwith�� �浹�� ������Ʈ�� �±׸� �־� �ξ� �浹���� ���� ������Ʈ����� �浹 üũ�� ���� �ʰ� �������.
struct Collider
{
	Vec2 WorldPos;
	Vec2 LocalPos;
	float Radius;
	Vec2 GetRandomPosInCollider()
	{
		return WorldPos + Vec2(Random(-Radius, Radius), Random(-Radius, Radius));
	}
};
class cCollider : public cComponent
{
	friend class cObjectManager;
public:
	cCollider();
	~cCollider();

	// Inherited via cComponent
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	vector<Collider> m_Colliders;
	vector<ObjectTag> m_CollWith;
	function<void(cObject* _Other)> m_CollFunc;

public:
	void AddCollider(Vec2 _Pos, float _Radius);
	void AddCollWith(ObjectTag _Tag) { m_CollWith.push_back(_Tag); }
	vector<Collider> GetColliders() { return m_Colliders; }
	void SetCollFunc(function<void(cObject* _Other)> _Func) { m_CollFunc = _Func; }
	void ClearCollWith() { m_CollWith.clear(); }
};

