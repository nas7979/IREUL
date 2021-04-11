#pragma once
//모든 씬들은 이 클래스를 상속받아 순수가상함수를 오버라이딩하여 사용한다.
//이를 통해 씬들의 관리가 간단해진다.
class cScene
{
public:
	cScene();
	virtual ~cScene();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render1() = 0;
	virtual void Render2() = 0;
	virtual void RenderGlobal() = 0;
	virtual void Release() = 0;
};

