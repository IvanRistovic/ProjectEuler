#ifndef __H_TIMER_H__
#define __H_TIMER_H__

#include <iostream>
#include <chrono>

class ProgramTimer {
public:
	ProgramTimer();

	void print_time();

private:
	std::chrono::time_point<std::chrono::system_clock> start;
	std::chrono::time_point<std::chrono::system_clock> end;
};

#endif
