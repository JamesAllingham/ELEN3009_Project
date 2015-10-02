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
    * Begins the timer.
	* No parameters or return value.
    */
	void start();
	/**
    * Ends the timer.
	* @return a float value of the timer when it was stopped. 
    */
	float stop();	
	
private:	
	/**
    * Converts c_time to a float
	* @return the float value c_time from a clock(). 
    */
	float getProcessTime();
	// the start time for a stop watch
	float _start_time = 0.f;
};

#endif
