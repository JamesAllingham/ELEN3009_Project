#include "StopWatch.h"
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
}
// sets the stop time for the stopwatch
float StopWatch::stop(){
	float _elapsed_time = getProcessTime() - _start_time;
	return _elapsed_time;
}
