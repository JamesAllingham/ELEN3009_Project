#include "StopWatch.h"
#include <ctime>

#include "gtest/gtest.h"

TEST (StopWatch, StopWatchReturnsATimeWithinOneMillisecondOfActualTimer)
{
	//Make the Stopwatch return a value within 0.001s 
	StopWatch stop_watch;
	clock_t time = clock();
	float start_time = static_cast<float>(time)/CLOCKS_PER_SEC;
	int i;
	stop_watch.start();
	while (static_cast<float>(time)/CLOCKS_PER_SEC - start_time < 0.1f)
	{
		time = clock();
		++i;
	}
	auto stop_watch_time = stop_watch.stop();
	EXPECT_TRUE(stop_watch_time > 0.099f && stop_watch_time < 0.101f);
}