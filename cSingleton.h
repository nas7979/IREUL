#pragma once
//모든 매니저들은 이 클래스를 상속받는다.
//싱글톤은 static으로 선언된 p변수와 함수들이 있어서, cSingleton객체의 생성 없이도 변수와 함수를 사용할 수 있다.
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