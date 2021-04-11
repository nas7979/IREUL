#pragma once
#include "cStage.h"
class cStage1Scene : public cStage
{
public:
	cStage1Scene();
	~cStage1Scene();

	// Inherited via cScene
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render1() override;
	virtual void Render2() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

