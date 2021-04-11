#pragma once
#include "cStage.h"
class cStage3Scene : public cStage
{
public:
	cStage3Scene();
	~cStage3Scene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render1() override;
	virtual void Render2() override;
	virtual void RenderGlobal() override;
	virtual void Release() override;
};

