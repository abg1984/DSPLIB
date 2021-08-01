#pragma once

class Observer
{
public:
	virtual ~Observer() = default;
	Observer() = default;
	Observer(const Observer&) = default;
	Observer& operator=(const Observer&) = default;
	Observer(Observer&&) = default;
	Observer& operator=(Observer&&) = default;
	virtual void update() = 0;
};


