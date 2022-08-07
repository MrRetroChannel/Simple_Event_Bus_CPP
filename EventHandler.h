#pragma once
#include "Event.h"
#include <string>
#include <typeinfo>
#include <vector>
#include <iostream>

std::vector<void*> events;

template <class T>
class EventHandler;

template<class T>
void regHandler(const EventHandler<T>& l);

template<class T>
class EventHandler
{
	friend class Bus;
	protected:
	std::string id;
	public:
	EventHandler()
	{
		id = typeid(T).name();
		regHandler<T>(*this);
	}
	virtual void onEvent(T& e)
	{}
	virtual ~EventHandler()
	{}
};

template<class T>
void regHandler(const EventHandler<T>& l)
{
	events.push_back((void*)&l);
}
