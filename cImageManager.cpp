#include "DXUT.h"
#include "cImageManager.h"


cImageManager::cImageManager()
{
}


cImageManager::~cImageManager()
{
}

void cImageManager::Init()
{
	D3DXCreateSprite(g_Device, &m_Sprite);
	for (int i = 1; i <= 32; i++)
	{
		D3DXCreateFont(g_Device, i, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"System", &m_Fonts[i]);
		D3DXCreateFont(g_Device, i, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"ÈÞ¸ÕµÕ±ÙÇìµå¶óÀÎ", &m_FontsKor[i]);
	}

	LPDIRECT3DSURFACE9 Original;
	g_Device->GetRenderTarget(0, &Original);
	D3DSURFACE_DESC Desc;
	Original->GetDesc(&Desc);
	Original->Release();
	for (int i = 0; i < 2; i++)
	{
		g_Device->CreateRenderTarget(Desc.Width, Desc.Height, Desc.Format, D3DMULTISAMPLE_NONE, 0, true, &m_RenderSurface[i], NULL);
		g_Device->CreateTexture(Desc.Width, Desc.Height, 1, D3DUSAGE_RENDERTARGET, Desc.Format, D3DPOOL_DEFAULT, &m_Texture[i].Image, NULL);
		m_Texture[i].Image->GetSurfaceLevel(0, &m_RenderSurface[i]);
	}
}

void cImageManager::Update()
{
}

void cImageManager::Render()
{
}

void cImageManager::Release()
{
	for (auto& iter : m_Images)
	{
		iter.second->Image->Release();
		SAFE_DELETE(iter.second);
	}
	for (auto& iter : m_Animations)
	{
		SAFE_DELETE(iter.second);
	}
	for (int i = 1; i <= 32; i++)
	{
		m_Fonts[i]->Release();
		m_FontsKor[i]->Release();
	}
	int a;
	for (int i = 0; i < 2; i++)
	{
		a = g_Device->Release();
		a = m_RenderSurface[i]->Release();
		a = m_Texture[i].Image->Release();
	}
	m_Sprite->Release();
}

void cImageManager::Begin()
{
	m_Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
	g_Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DX_FILTER_NONE);
	g_Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DX_FILTER_NONE);
	g_Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DX_FILTER_NONE);
}

void cImageManager::End()
{
	m_Sprite->End();
}

void cImageManager::OnLostDevice()
{
	m_Sprite->OnLostDevice();
}

void cImageManager::OnResetDevice()
{
	m_Sprite->OnResetDevice();
}

void cImageManager::AddImage(string _Key, string _Path)
{
	Texture* Tex = new Texture;
	if (D3DXCreateTextureFromFileExA(g_Device, _Path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_POINT, D3DX_FILTER_POINT, 0, &Tex->Info, 0, &Tex->Image) == S_OK)
	{
		m_Images.insert(make_pair(_Key, Tex));
		return;
	}
	delete Tex;
}

void cImageManager::AddAnimation(string _Key, int _Amount)
{
	char Key[64];
	vector<Texture*>* Vec = new vector<Texture*>;
	for (int i = 1; i <= _Amount; i++)
	{
		sprintf(Key, "%s%d", _Key.c_str(), i);
		Vec->push_back(m_Images[Key]);
	}
	m_Animations.insert(make_pair(_Key, Vec));
}

Texture * cImageManager::Find(string _Key)
{
	return m_Images[_Key];
}

vector<Texture*>* cImageManager::FindAnimation(string _Key)
{
	return m_Animations[_Key];
}

void cImageManager::CreateRenderTarget()
{
	LPDIRECT3DSURFACE9 Original;
	g_Device->GetRenderTarget(0, &Original);
	D3DSURFACE_DESC Desc;
	Original->GetDesc(&Desc);
	Original->Release();

	for (int i = 0; i < 2; i++)
	{
		g_Device->CreateRenderTarget(Desc.Width, Desc.Height, Desc.Format, D3DMULTISAMPLE_NONE, 0, true, &IMAGE->m_RenderSurface[i], NULL);
		g_Device->CreateTexture(Desc.Width, Desc.Height, 1, D3DUSAGE_RENDERTARGET, Desc.Format, D3DPOOL_DEFAULT, &IMAGE->m_Texture[i].Image, NULL);
		IMAGE->m_Texture[i].Image->GetSurfaceLevel(0, &IMAGE->m_RenderSurface[i]);
	}
}

void cImageManager::Render(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, _Rot, &(_Pos));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, nullptr, nullptr, nullptr, _Color);
}

void cImageManager::CenterRender(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color)
{
	m_Center = Vec2(_Image->Info.Width * 0.5f, _Image->Info.Height * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, _Rot, &(_Pos - m_Center));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, nullptr, nullptr, nullptr, _Color);
}

void cImageManager::RenderRect(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, _Rot, &(_Pos));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, &_Rect, nullptr, nullptr, _Color);
}

void cImageManager::CenterRenderRect(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color)
{
	m_Center = Vec2(_Image->Info.Width * 0.5f, _Image->Info.Height * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, _Rot, &(_Pos - m_Center));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, &_Rect, nullptr, nullptr, _Color);
}

void cImageManager::RenderGlitchRect(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, float _PosRand, int _SizeRand, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, _Rot, &(_Pos));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Rect.left = _Rect.left;
	m_Rect.right = _Rect.right;
	int RenderPos;
	float RandPos;
	_SizeRand = max(1, _SizeRand);
	_PosRand = max(1, _PosRand);
	for (int i = _Rect.top; i < _Rect.bottom;)
	{
		RandPos = Random(-_PosRand, _PosRand);
		m_Rect.top = RenderPos = i;
		i += min(_Rect.bottom - i, Random(1, _SizeRand));
		m_Rect.bottom = i;
		m_Sprite->Draw(_Image->Image, &m_Rect, nullptr, &Vec3(RandPos, RenderPos, 0), _Color);
	}
}

void cImageManager::RenderGlitch(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, float _PosRand, int _SizeRand, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, _Rot, &(_Pos));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, nullptr, nullptr, nullptr, _Color);
}

void cImageManager::CenterRenderGlitch(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, float _PosRand, int _SizeRand, D3DCOLOR _Color)
{
	m_Center = Vec2(_Image->Info.Width * 0.5f, _Image->Info.Height * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, _Rot, &(_Pos - m_Center));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Rect.left = 0;
	m_Rect.right = _Image->Info.Width;
	int RenderPos;
	_SizeRand = max(1, _SizeRand);
	_PosRand = max(1, _PosRand);
	for (int i = 0; i < _Image->Info.Height;)
	{
		m_Rect.top = RenderPos = i;
		i += min(_Image->Info.Height - i, Random(1, _SizeRand));
		m_Rect.bottom = i;
		m_Sprite->Draw(_Image->Image, &m_Rect, nullptr, &Vec3(Random(-_PosRand, _PosRand), RenderPos, 0), _Color);
	}
}

void cImageManager::CenterRenderBoxGlitch(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, float _PosRand, int _SizeRand, D3DCOLOR _Color)
{
	m_Center = Vec2(_Image->Info.Width * 0.5f, _Image->Info.Height * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, _Rot, &(_Pos - m_Center));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	Vec2 RenderPos;
	_SizeRand = max(1, _SizeRand);
	_PosRand = max(1, _PosRand);
	for (int i = 0; i < _Image->Info.Height;)
	{
		m_Rect.top = RenderPos.y = i;
		i += min(_Image->Info.Height - i, Random(1, max(1, _SizeRand)));
		m_Rect.bottom = i;
		for (int j = 0; j < _Image->Info.Width; j++)
		{
			m_Rect.left = RenderPos.x = j;
			j += min(_Image->Info.Width - j, Random(1, max(1, _SizeRand)));
			m_Rect.right = j;
			m_Sprite->Draw(_Image->Image, &m_Rect, nullptr, &Vec3(RenderPos.x + Random(-_PosRand, _PosRand), RenderPos.y + Random(-_PosRand, _PosRand), 0), _Color);
		}
	}
}

void cImageManager::RenderText(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, 0, &(_Pos));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	(_Kor ? m_FontsKor[_Size] : m_Fonts[_Size])->DrawTextW(m_Sprite, _Text.c_str(), -1, NULL, DT_NOCLIP | DT_CENTER, _Color);
}

void cImageManager::CenterRenderText(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color)
{
	m_Rect.left = m_Rect.top = 0;
	(_Kor ? m_FontsKor[_Size] : m_Fonts[_Size])->DrawTextW(m_Sprite, _Text.c_str(), -1, &m_Rect, DT_NOCLIP | DT_CALCRECT, _Color);
	m_Center = Vec2((float)m_Rect.right * 0.5f, (float)m_Rect.bottom * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, 0, &(_Pos - m_Center));
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	(_Kor ? m_FontsKor[_Size] : m_Fonts[_Size])->DrawTextW(m_Sprite, _Text.c_str(), -1, NULL, DT_NOCLIP | DT_CENTER, _Color);
}

void cImageManager::RenderView(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, _Rot, &(_Pos));
	m_Mat *= CAMERA->GetMatrix();
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, nullptr, nullptr, nullptr, _Color);
}

void cImageManager::CenterRenderView(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, D3DCOLOR _Color)
{
	m_Center = Vec2(_Image->Info.Width * 0.5f, _Image->Info.Height * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, _Rot, &(_Pos - m_Center));
	m_Mat *= CAMERA->GetMatrix();
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, nullptr, nullptr, nullptr, _Color);
}

void cImageManager::RenderRectView(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, _Rot, &(_Pos));
	m_Mat *= CAMERA->GetMatrix();
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, &_Rect, nullptr, nullptr, _Color);
}

void cImageManager::CenterRenderRectView(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, D3DCOLOR _Color)
{
	m_Center = Vec2(_Image->Info.Width * 0.5f, _Image->Info.Height * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, _Rot, &(_Pos - m_Center));
	m_Mat *= CAMERA->GetMatrix();
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	m_Sprite->Draw(_Image->Image, &_Rect, nullptr, nullptr, _Color);
}

void cImageManager::RenderTextView(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color)
{
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &_Scale, NULL, 0, &(_Pos));
	m_Mat *= CAMERA->GetMatrix();
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	(_Kor ? m_FontsKor[_Size] : m_Fonts[_Size])->DrawTextW(m_Sprite, _Text.c_str(), -1, NULL, DT_NOCLIP | DT_CENTER, _Color);
}

void cImageManager::CenterRenderTextView(wstring _Text, int _Size, Vec2 _Pos, Vec2 _Scale, float _Depth, bool _Kor, D3DCOLOR _Color)
{
	m_Rect.left = m_Rect.top = 0;
	(_Kor ? m_FontsKor[_Size] : m_Fonts[_Size])->DrawTextW(m_Sprite, _Text.c_str(), -1, &m_Rect, DT_NOCLIP | DT_CALCRECT, _Color);
	m_Center = Vec2((float)m_Rect.right * 0.5f, (float)m_Rect.bottom * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &m_Center, 0, &_Scale, &m_Center, 0, &(_Pos - m_Center));
	m_Mat *= CAMERA->GetMatrix();
	m_Mat._43 = _Depth;
	m_Sprite->SetTransform(&m_Mat);
	(_Kor ? m_FontsKor[_Size] : m_Fonts[_Size])->DrawTextW(m_Sprite, _Text.c_str(), -1, NULL, DT_NOCLIP | DT_CENTER, _Color);
}
