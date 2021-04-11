#pragma once
#include "cBulletBase.h"
//���� ��� �׸��� ���󰡴� �Ѿ� Ŭ�����̴�. �÷��̾��� �����̵� ����ź�� �÷��̾ ��� �÷��̾��� �������� ���� ������ �Ŀ��� �Ծ��� �� �߻�Ǵ� ���� �̻��Ͽ����� ���ȴ�.
//��� �׸��� ���ư�����, ȸ�� �ӵ��� ���� �����ϱ� ������ ��ǥ �ֺ����� ���� ���⸸ �ϴ� ���� ���� ����.
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

