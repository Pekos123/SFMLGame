#include "Event.h"

void Event::AddListener(void(*funcptr)())
{
	listeners.push_back(funcptr);
}

void Event::Invoke()
{
	for (auto funcptr : listeners)
		funcptr();
}