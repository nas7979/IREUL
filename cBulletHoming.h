#pragma once
#include "cBulletBase.h"
//적을 곡선을 그리며 따라가는 총알 클래스이다. 플레이어의 저속이동 유도탄과 플레이어가 상대 플레이어의 죽음으로 인해 생성된 파워를 먹었을 때 발사되는 빨간 미사일에서만 사용된다.
//곡선을 그리며 날아가지만, 회전 속도가 점점 증가하기 때문에 목표 주변에서 빙빙 돌기만 하는 일은 거의 없다.
class cBulletHoming : public cBulletBase
{
public:
	cBulletHoming();
	~cBulletHoming();

	// Inherited via cBulletBase
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	cObject* m_Target = nullptr;
	int m_TargetID = 0;
	float m_RotSpeed;

public:
	void SetTarget(cObject* _Target);
};

