#include "DXUT.h"
#include "cBackgroundEffect.h"


cBackgroundEffect::cBackgroundEffect()
{
}


cBackgroundEffect::~cBackgroundEffect()
{
}

void cBackgroundEffect::Init()
{
	m_Alpha = Random(25, 125);
	m_Speed = Random(50.f, 150.f);
	m_Owner->SetScale(Vec2(1, 1) * Random(0.5f, 1.f));

	m_Owner->SetAlarmSize(1);
	m_Owner->SetAlarmFunc([&](int _Index)->void {
		switch (_Index)
		{
		case 0:
		{
			cParticleFunc* Func = PART->AddParticle<cParticleFunc>(IMAGE->Find(RandomText("Back_", 4)), m_Owner->GetPosition(), m_Owner->GetScale(), 0, 0.199, 2, D3DCOLOR_XRGB(255, 255, 255));
			Func->SetSpeed(m_Speed, 1, 90);
			Func->SetFuncSpeed(1);
			Func->SetAlpha(m_Alpha);
			Func->SetFunc([](cParticleFunc* _Part)->void {
				if (_Part->GetPosition().y >= 950)
				{
					_Part->SetAlpha(0);
				}
				});
			m_Owner->SetAlarm(0, 0.5 * m_Owner->GetScale().x / (m_Speed * 0.01));
			break;
		}
		}
		});
	m_Owner->SetAlarm(0, 0.4);
}

void cBackgroundEffect::Update()
{
	if (Random(0, 1000) == 0)
	{
		if (SCENE->GetCurSceneKey() == "TITLE")
		{
			m_Owner->SetPosition(Vec2(Random(-50, 1650), -50));
		}
		else
		{
			m_Owner->SetPosition(Vec2(Random(-50, 300) + 1350 * m_Owner->GetSide(), -50));
		}
	}
}

void cBackgroundEffect::Render()
{
}

void cBackgroundEffect::RenderGlobal()
{
}

void cBackgroundEffect::Release()
{
}
