#pragma once
#include "EventHandler.h"
class Bus
{
	public:	
	void fireEvent(Event&& e)
	{
		for (void* l : events)
		{
			if (typeid(e).name() == ((EventHandler<Event>*)l)->id)
				((EventHandler<Event>*)l)->onEvent(e);
		}
	}
	
	template <class T>
	void unregEvent(const EventHandler<T>& handler)
	{
		void* sos = (void*)&handler;
		for (int i = 0; i < events.size(); i++)
			if (events[i] == sos)
				events.erase(events.begin() + i, events.begin() + i + 1);
	}
};

Bus EventBus;
