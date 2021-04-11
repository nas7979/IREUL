#pragma once
//AddAnimation���� �ִϸ��̼��� �߰��� �� ������, SetAnimation���� �߰��ص� �ִϸ��̼ǵ� �� �ϳ��� ��� ����� �� �ִ�.
struct Animation
{
	string Key;
	vector<Texture*>* Animation;
	int MaxFrame;
	float Speed;
	bool Loop;
};
class cAnimation : public cComponent
{
public:
	cAnimation();
	~cAnimation();

	// cComponent��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	vector<Animation*> m_Animations;
	Animation* m_Anim;
	float m_Speed;
	float m_Frame;

public:
	void AddAnimation(string _Key, string _Resource, float _Speed, bool _Loop = true);
	void SetAnimation(string _Key);
	void SetSpeed(float _Speed);
	float GetSpeed() { return m_Speed; }
	void SetFrame(float _Frame);
	float GetFrame() { return m_Frame; }

};

