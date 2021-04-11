#pragma once
#include "cSingleton.h"
//로딩된 이미지들을 모아두고 관리하며, 폰트 또한 관리한다.
//텍스트와 이미지를 렌더링한다.
struct Texture
{
	LPDIRECT3DTEXTURE9 Image;
	D3DXIMAGE_INFO Info;
};
class cImageManager : public cSingleton<cImageManager>
{
public:
	cImageManager();
	~cImageManager();

	void Init();
	void Update();
	void Render();
	void Release();
	void Begin();
	void End();
	void OnLostDevice();
	void OnResetDevice();

private:
	map<string, Texture*> m_Images;
	map<string, vector<Texture*>*> m_Animations;
	LPD3DXFONT m_Fonts[33];
	LPD3DXFONT m_FontsKor[33];
	LPD3DXSPRITE m_Sprite;
	LPDIRECT3DSURFACE9 m_RenderSurface[2];
	Texture m_Texture[2];

	Matrix m_Mat;
	RECT m_Rect;
	Vec2 m_Center;

public:
	void AddImage(string _Key, string _Path);
	void AddAnimation(string _Key, int _Amount);
	Texture* Find(string _Key);
	vector<Texture*>* FindAnimation(string _Key);

	LPDIRECT3DSURFACE9 GetRenderSurface(int _Side) { return m_RenderSurface[_Side]; }
	Texture GetTexture(int _Side) { return m_Texture[_Side]; }
	void CreateRenderTarget();

	void Render(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color = 0xffffffff);
	void CenterRender(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color = 0xffffffff);
	void RenderRect(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color = 0xffffffff);
	void CenterRenderRect(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color = 0xffffffff);
	void RenderGlitchRect(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, float _PosRand, int _SizeRand,  D3DCOLOR _Color = 0xffffffff);
	void RenderGlitch(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, float _PosRand, int _SizeRand, D3DCOLOR _Color = 0xffffffff);
	void CenterRenderGlitch(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, float _PosRand, int _SizeRand, D3DCOLOR _Color = 0xffffffff);
	void CenterRenderBoxGlitch(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, float _PosRand, int _SizeRand, D3DCOLOR _Color = 0xffffffff);
	void RenderText(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color = 0xffffffff);
	void CenterRenderText(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color = 0xffffffff);

	void RenderView(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color = 0xffffffff);
	void CenterRenderView(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color = 0xffffffff);
	void RenderRectView(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color = 0xffffffff);
	void CenterRenderRectView(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color = 0xffffffff);
	void RenderTextView(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color = 0xffffffff);
	void CenterRenderTextView(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color = 0xffffffff);
};

#define IMAGE cImageManager::GetInstance()