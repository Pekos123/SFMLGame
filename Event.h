#pragma once
#include <vector>
class Event
{
private:
	std::vector<void(*)()> listeners;
public:
	void AddListener(void(*funcptr)());
	void Invoke();
};

