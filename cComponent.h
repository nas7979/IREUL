#pragma once
//��� ������Ʈ���� �θ� Ŭ�����μ�, ������Ʈ�� ������ �ִ� ���� ������Ʈ m_Owner�� ������ �ִ�.
//����, Get�̳� AddComponent�� �� ������ m_Owner->�� �� �ʿ䰡 ������ GetComponent, AddComponent�� �̰����� ������ �ξ���.
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

