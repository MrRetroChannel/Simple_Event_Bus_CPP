#include "EventSystem.h"
#include <iostream>

class GoldEvent : public Event
{
	public:
	int gold;
	GoldEvent(int a) : gold(a)
	{}	
};

class SosEvent : public Event
{
	public:
	std::string sos;
	SosEvent(const char* a) : sos(a)
	{}
};

class Listener : public EventHandler<GoldEvent>, public EventHandler<SosEvent>
{
	public:
		void onEvent(GoldEvent& e) override
		{
			std::cout << e.gold << '\n';
		}
		
		void onEvent(SosEvent& e) override
		{
			std::cout << e.sos;
		}
};

int main()
{
	Keyboard board;
	KeyListener l;
	Listener a;

	EventBus.fireEvent(GoldEvent(20));
}
