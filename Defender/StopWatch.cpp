#include "StopWatch.h"
#include <ctime>
using namespace std;

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
float StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<float>(time)/CLOCKS_PER_SEC;
}
// sets the start time of the stopwatch
void StopWatch::start(){
	_start_time = getProcessTime();
	_elapsed_time = 0.f;
}
// sets the stop time for the stopwatch
float StopWatch::stop(){
	_stop_time = getProcessTime();
	_elapsed_time = _stop_time - _start_time + _elapsed_time;
	return _elapsed_time;
}

// restarts the stop watch time
void StopWatch::restart(){
	_start_time = getProcessTime();
	_elapsed_time = 0.f;
}