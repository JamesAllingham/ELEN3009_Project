#include "StopWatch.h"
using namespace std;


float StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<float>(time)/CLOCKS_PER_SEC;
}

void StopWatch::start(){
	_start_time = getProcessTime();
}

float StopWatch::stop(){
	auto _elapsed_time = getProcessTime() - _start_time;
	return _elapsed_time;
}
