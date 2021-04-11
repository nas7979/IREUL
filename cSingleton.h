#pragma once
//��� �Ŵ������� �� Ŭ������ ��ӹ޴´�.
//�̱����� static���� ����� p������ �Լ����� �־, cSingleton��ü�� ���� ���̵� ������ �Լ��� ����� �� �ִ�.
template <typename T>
class cSingleton
{
public:
	cSingleton() {};
	virtual ~cSingleton() {};

private:
	static T* p;

public:
	static void CreateInstance()
	{
		p = new T;
		p->Init();
	}

	static T* GetInstance()
	{
		return p;
	}

	static void ReleaseInstance()
	{
		p->Release();
		SAFE_DELETE(p);
	}
};
template<typename T>
T* cSingleton<T>::p = nullptr;