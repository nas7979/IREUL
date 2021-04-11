#pragma once
//������Ʈ�� �˶��� ���������, �������� ������Ʈ�������� �ƴ϶� �ڵ� ��𿡼��� ���� �� ������,
//������ ���� �� _Once�� false�� ������ ���ӽð��� ���� ������ �� �����Ӹ��� ����Ǵ� �������� ������ �� �־�
//�˶����� �ٸ��� ���� �� �ִ�.
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