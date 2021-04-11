#pragma once
//이미지와 사운드들을 로딩하는 씬
class cLoadingScene : public cScene
{
public:
	cLoadingScene();
	~cLoadingScene();

	// Inherited via cScene
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render1() override;
	virtual void Render2() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;

	void LoadImage(string _Key, string _Path, int _Amount = 1);
	void LoadSound(string _Key, LPWSTR _Path, int _Amount = 1);
};

