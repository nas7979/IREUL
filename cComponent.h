#pragma once
//모든 컴포넌트들의 부모 클래스로서, 컴포넌트를 가지고 있는 주인 오브젝트 m_Owner를 가지고 있다.
//또한, Get이나 AddComponent를 할 때마다 m_Owner->를 할 필요가 없도록 GetComponent, AddComponent를 이곳에도 정의해 두었다.
class cObject;
class cComponent
{
	friend class cObject;
	friend class cObjectManager;
public:
	cComponent();
	virtual ~cComponent();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderGlobal() = 0;
	virtual void Release() = 0;

protected:
	cObject* m_Owner = nullptr;
	bool m_Enable = true;

public:
	void SetEnable(bool _Enable) { m_Enable = _Enable; }
	bool GetEnable() { return m_Enable; }
	cObject* GetOwner() { return m_Owner; }
	
	template<typename T>
	T* AddComponent()
	{
		return m_Owner->AddComponent<T>();
	}

	template<typename T>
	T* GetComponent()
	{
		return m_Owner->GetComponent<T>();
	}
};

