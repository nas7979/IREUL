
#pragma once
namespace Math
{
	static char StaticText[32];
	static D3DCOLOR Color[12] = { RED, GREEN, BLUE, YELLOW, PINK, SKYBLUE, ORANGE, YELLOWGREEN, PURPLE, MINT, BLACK, WHITE };

	template<typename T>
	T Lerp(T _S, T _E, float _T)
	{
		return _S + (_E - _S) * _T * (DT * 60);
	}
	template<typename T>
	T AtList(list<T>* _List, int _At)
	{
		auto iter = _List->begin();
		for (int i = 0; i < _At; i++)
		{
			iter++;
		}
		return *iter;
	}

	int Random(int _Min, int _Max);
	float Random(float _Min, float _Max);
	float Clamp(float _Val, float _Min, float _Max);
	Vec2 RotateVec(Vec2 _Vec, float _Rot);
	float PointDirection(Vec2 _V1, Vec2 _V2);
	char* RandomText(string _Text, int _Max, int _Min = 1);
	D3DCOLOR GetColor(int _Index);
}