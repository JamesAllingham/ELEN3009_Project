#ifndef STOPWATCH_H
#define STOPWATCH_H

class StopWatch { 
public:
	// constructor for a StopWatch object
	StopWatch() {};
	void start();
	float stop();
	void restart();
	
private:	
	float getProcessTime();
	// the start time for a stop watch
	float _start_time = 0.f;
	// the stop time
	float _stop_time = 0.f;
	// the sum of previous times
	float _elapsed_time = 0.f;
};

#endif
