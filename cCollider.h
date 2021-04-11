#pragma once
//원충돌만을 사용하며, m_Colliders안에 여러 Collider들을 담아둘 수 있어 원을 여러개 사용해 다채로운 모양을 만들어낼 수 있다.
//m_Collwith에 충돌할 오브젝트의 태그를 넣어 두어 충돌하지 않을 오브젝트들과는 충돌 체크도 하지 않게 만들었다.
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

