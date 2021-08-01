#pragma once

#include <list>
#include "Observer.h"

class Subject
{
public:
	virtual ~Subject() = default;
	Subject() = default;
	Subject(const Subject&) = default;
	Subject& operator=(const Subject&) = default;
	Subject(Subject&&) = default;
	Subject& operator=(Subject&&) = default;

	void attach(Observer* newObserver)
	{
		itsObservers.push_back(newObserver);
	};

	void notify()
	{
		for (auto it = itsObservers.begin(); it != itsObservers.end(); ++it)
		{
			(*it)->update();
		}
	};

private:
	std::list<Observer*> itsObservers;
};



