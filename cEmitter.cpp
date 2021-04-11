#include "DXUT.h"
#include "cEmitter.h"


cEmitter::cEmitter()
{
}


cEmitter::~cEmitter()
{
}

void cEmitter::Init()
{
}

void cEmitter::Update()
{
	for (auto& iter : m_Emitters)
	{
		iter->WorldPos = m_Owner->GetPosition() + RotateVec(iter->LocalPos, m_Owner->GetRotation());
		iter->Timer -= DT;
		if (iter->Timer <= 0)
		{
			cParticle* Part = PART->AddParticle<cParticle>(iter->Images[Random(0, iter->Images.size() - 1)], iter->WorldPos, Vec2(1, 1) * iter->Scale.Rand(), iter->Rot.Rand(), iter->Depth,
				m_Owner->GetSide(), D3DCOLOR_XRGB((int)iter->R.Rand(), (int)iter->G.Rand(), (int)iter->B.Rand()));

			if (iter->AssignRotToOwner == false)
			{
				Part->SetSpeed(iter->SpeedVel.Rand(), iter->SpeedFri.Rand(), iter->Direction.Rand());
				Part->SetRot(iter->RotVel.Rand(), iter->RotFri.Rand());
			}
			else
			{
				Part->SetSpeed(iter->SpeedVel.Rand(), iter->SpeedFri.Rand(), m_Owner->GetRotation() + iter->Direction.Rand());
				Part->SetRot(m_Owner->GetRotation() + iter->RotVel.Rand(), iter->RotFri.Rand());
			}
			Part->SetScale(Vec2(1,1) * iter->ScaleVel.Rand(), iter->ScaleFri.Rand());
			Part->SetAlpha(iter->Alpha.Rand(), iter->AlphaVel.Rand(), iter->AlphaFri.Rand());
			iter->Timer = iter->Delay;
		}
	}
}

void cEmitter::Render()
{
}

void cEmitter::RenderGlobal()
{
}

void cEmitter::Release()
{
	for (auto& iter : m_Emitters)
	{
		SAFE_DELETE(iter);
	}
}

Emitter * cEmitter::AddEmitter(Vec2 _Pos, Texture * _Image, float _Delay, float _Depth)
{
	Emitter* a = new Emitter;
	a->LocalPos = _Pos;
	a->Images.push_back(_Image);
	a->Delay = _Delay;
	a->Timer = _Delay;
	a->Depth = _Depth;
	m_Emitters.push_back(a);
	return a;
}

Emitter * cEmitter::GetEmitter(int _Index)
{
	return m_Emitters[_Index];
}
