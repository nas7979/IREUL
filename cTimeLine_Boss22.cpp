#include "DXUT.h"
#include "cTimeLine_Boss22.h"
#include "cBoss2.h"
#include "cPlayer.h"

cTimeLine_Boss22::cTimeLine_Boss22()
{
}


cTimeLine_Boss22::~cTimeLine_Boss22()
{
}

void cTimeLine_Boss22::Init()
{
	m_Angle = Random(0, 1) == 0 ? -1 : 1;
	m_Angle *= Random(0.75f, 1.125f);
	GetComponent<cPath>()->AddPath(300, 0.99, Vec2(250 + 1100 * m_Owner->GetSide(), 400));
}

void cTimeLine_Boss22::Update()
{
	m_Time += DT + SCENE->GetStage()->GetTimeSpeed(m_Owner->GetSide()) * 0.5 * DT;
	if (m_Last != (int)(m_Time * 10))
	{
		switch ((int)(m_Time * 10))
		{
		case 5:
			if (!OBJECT->GetPlayer(m_Owner->GetSide())->GetComponent<cPlayer>()->GetDead())
			{
				m_Dir = PointDirection(m_Owner->GetPosition(), OBJECT->GetPlayer(m_Owner->GetSide())->GetPosition());
			}
			else
			{
				m_Dir = 90;
			}
		case 8:
		case 11:
		case 14:
		case 17:
		case 20:
		case 23:
		case 26:
		case 29:
		case 32:
		case 35:
		case 38:
		case 41:
		case 44:
		case 47:
		case 50:
		case 53:
		case 56:
		case 59:
		case 62:
		case 65:
		case 68:
		case 71:
		case 74:
		case 77:
		case 80:
		case 83:
		case 86:
		case 89:
		case 92:
		case 95:
		case 98:
			for (int i = 3; i < 57; i++)
			{
				FireBullet(0, m_Owner->GetPosition(), 9, m_Dir + i * 6, 250, MINT);
			}
			FireEffect(m_Owner->GetPosition(), MINT);

			for (int i = 0; i < 1; i++)
			{
				FireBullet(1, m_Owner->GetPosition(), 7, Random(0, 359), 50, RED);
			}
			FireEffect(m_Owner->GetPosition(), RED);

			m_Dir += 10 * m_Angle;
			SOUND->Play("BulletFire2", -1500, true);
			break;

		case 100:
			GetComponent<cPath>()->AddPath(300, 0.99, Vec2(250 + 1100 * m_Owner->GetSide(), 250));
			break;

		case 140:
			m_Time = 0;
			GetComponent<cBoss2>()->NextPhase();

		}
		m_Last = (int)(m_Time * 10);
	}
}

void cTimeLine_Boss22::Render()
{
}

void cTimeLine_Boss22::RenderGlobal()
{
}

void cTimeLine_Boss22::Release()
{
}
