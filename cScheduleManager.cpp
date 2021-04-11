#include "DXUT.h"
#include "cScheduleManager.h"


cScheduleManager::cScheduleManager()
{
}


cScheduleManager::~cScheduleManager()
{
}

void cScheduleManager::Init()
{
}

void cScheduleManager::Update()
{
	for (auto& iter = m_Schedules.begin(); iter != m_Schedules.end();)
	{
		(*iter).Time -= DT;
		if ((*iter).Time <= 0)
		{
			(*iter).Function();
			iter = m_Schedules.erase(iter);
			continue;
		}
		if ((*iter).Once == false)
		{
			if ((*iter).Function() == false)
			{
				iter = m_Schedules.erase(iter);
				continue;
			}
		}
		iter++;
	}
}

void cScheduleManager::Render()
{
}

void cScheduleManager::Release()
{
	Clear();
}

void cScheduleManager::AddSchedule(float _Time, bool _Once, function<bool()> _Func)
{
	m_Schedules.push_back(Schedule{ _Time, _Once, _Func });
}

void cScheduleManager::Clear()
{
	m_Schedules.clear();
}
