#pragma once
#include "cEnemy.h"
//��� Ŭ�����̴�. �̸��� ���� �̹����� �ٲ��, ü�°� óġ �� ����, ���� ���� �ܺο��� ������ �� �ֱ� ������
//������ ����, ������ �ſ� ���ϴ�.
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

