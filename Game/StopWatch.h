#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>

/**
* StopWatch class - used to keep track of the time between events occurring such as the time between successive Missile shots from a Flyer.
*/
class StopWatch { 
public:
	/**
    * Constructor. 
	* Does not require any parameters.
    */
	StopWatch() {};
	/**
    * start() function which begins the timer.
	* No parameters or return value.
    */
	void start();
	/**
    * stop() function which ends the timer.
	* @return the value of the timer when it was stopped. 
    */
	float stop();	
	
private:	
	float getProcessTime();
	// the start time for a stop watch
	float _start_time = 0.f;
};

#endif
