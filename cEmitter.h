#pragma once
//������Ʈ���� �ֱ������� ��ƼŬ�� �����ϰ� ���� ��, �̸� ����ȭ�ϱ� ���� ������Ʈ�̴�.
//����ü RandomFloat �ȿ� ��ƼŬ ������ �ּҰ��� �ִ밪�� �־�����μ� ������ ���� �������� �ٿ���.
struct RandomFloat
{
	RandomFloat(float _Val)
	{
		Min = Max = _Val;
	}
	float Min = 0;
	float Max = 0;
	float Rand()
	{
		return Random(Min, Max);
	}
	void Set(float _Min, float _Max)
	{
		Min = _Min;
		Max = _Max;
	}
};

struct Emitter
{
	Vec2 LocalPos = Vec2(0,0);
	Vec2 WorldPos;
	vector<Texture*> Images;
	float Depth;
	float Delay;
	float Timer = 0;

	RandomFloat SpeedVel = RandomFloat(0);
	RandomFloat SpeedFri = RandomFloat(1);
	RandomFloat Direction = RandomFloat(0);

	RandomFloat Scale = RandomFloat(1);
	RandomFloat ScaleVel = RandomFloat(0);
	RandomFloat ScaleFri = RandomFloat(1);

	bool AssignRotToOwner = true;
	RandomFloat Rot = RandomFloat(0);
	RandomFloat RotVel = RandomFloat(0);
	RandomFloat RotFri = RandomFloat(1);
	
	RandomFloat Alpha = RandomFloat(255);
	RandomFloat AlphaVel = RandomFloat(0);
	RandomFloat AlphaFri = RandomFloat(1);

	RandomFloat R = RandomFloat(255);
	RandomFloat G = RandomFloat(255);
	RandomFloat B = RandomFloat(255);
};

class cEmitter : public cComponent
{
public:
	cEmitter();
	~cEmitter();

	// cComponent��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

private:
	vector<Emitter*> m_Emitters;

public:
	Emitter* AddEmitter(Vec2 _Pos, Texture* _Image, float _Delay, float _Depth);
	Emitter* GetEmitter(int _Index);
};

