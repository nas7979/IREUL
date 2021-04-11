#pragma once
//����� 0�� 1�� �������� ����Ʈ�� ����ϴ� ������Ʈ�̴�.
class cBackgroundEffect : public cComponent
{
public:
	cBackgroundEffect();
	~cBackgroundEffect();

	// cComponent��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

	float m_Speed;
	int m_Alpha;
};

