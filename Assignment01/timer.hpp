#ifndef TIMER_HPP
#define TIMER_HPP
#include<ctime>
#include<cstdio>
using std::printf;
using std::clock;
class timer
{
	clock_t start_time;
	clock_t end_time;
	public:
	void start();
	void stop();
	double last_timing();
	void print();
};

void timer::start()
{
	start_time = clock();
}

void timer::stop()
{
	end_time = clock();
}

double timer::last_timing()
{
	return ((double)(end_time-start_time))/CLOCKS_PER_SEC;
}

void timer::print()
{
	printf("Time taken: %f seconds\n",last_timing());
}

#endif