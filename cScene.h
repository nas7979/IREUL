#pragma once
//��� ������ �� Ŭ������ ��ӹ޾� ���������Լ��� �������̵��Ͽ� ����Ѵ�.
//�̸� ���� ������ ������ ����������.
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

