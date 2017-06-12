#include "timer.h"

ProgramTimer::ProgramTimer()
	: start(std::chrono::system_clock::now())
{

}

void ProgramTimer::print_time()
{
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
