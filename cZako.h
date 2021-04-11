#pragma once
#include "cEnemy.h"
//잡몹 클래스이다. 이름에 따라 이미지가 바뀌고, 체력과 처치 시 보상, 패턴 등을 외부에서 변경할 수 있기 때문에
//관리와 생성, 변형이 매우 편리하다.
class cZako : public cEnemy
{
public:
	cZako();
	~cZako();

	// Inherited via cEnemy
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
	virtual void Death() override;

	void IsOutMap();
};

