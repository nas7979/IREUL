#pragma once
//오브젝트의 알람과 비슷하지만, 스케줄은 오브젝트에서만이 아니라 코드 어디에서든 만들어낼 수 있으며,
//스케줄 생성 시 _Once를 false로 넣으면 지속시간이 다할 때까지 매 프레임마다 실행되는 스케줄을 생성할 수 있어
//알람과는 다르게 사용될 수 있다.
struct Schedule
{
	float Time;
	bool Once;
	function<bool()> Function;
};
class cScheduleManager : public cSingleton<cScheduleManager>
{
public:
	cScheduleManager();
	~cScheduleManager();

	void Init();
	void Update();
	void Render();
	void Release();

private:
	list<Schedule> m_Schedules;

public:
	void AddSchedule(float _Time, bool _Once, function<bool()> _Func);
	void Clear();
};

#define SCHEDULE cScheduleManager::GetInstance()