#include "DXUT.h"
#include "cBulletBase.h"
#include "cBulletHoming.h"
#include "cPlayer.h"

cBulletBase::cBulletBase()
{
}


cBulletBase::~cBulletBase()
{
	cParticleGlitch* Part = PART->AddParticle<cParticleGlitch>(IMAGE->Find("BulletFire"), m_Owner->GetPosition(), Vec2(0.3, 0.3), 0, 0.4, m_Owner->GetSide(), GetComponent<cRenderer>()->GetColor());
	Part->SetAlpha(255, -1250, 1);
	Part->SetScale(Vec2(20, 20), 0.99);
	Part->SetPosRand(3);
	Part->SetSizeRand(8);
}

void cBulletBase::RenderGlobal()
{
}

void cBulletBase::IsOutMap()
{
	Vec2 Pos = m_Owner->GetPosition();
	if (m_Owner->GetSide() == 0)
	{
		if (Pos.x <= -50 || Pos.x >= 550 || Pos.y <= -50 || Pos.y >= 950)
		{
			m_Owner->Destroy();
		}
	}
	else
	{
		if (Pos.x <= 1050 || Pos.x >= 1650 || Pos.y <= -50 || Pos.y >= 950)
		{
			m_Owner->Destroy();
		}
	}
}
