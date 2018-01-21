#pragma once

#include <chrono>
class Timer
{
private:
	std::chrono::high_resolution_clock::time_point m_timestamp;
public:
	Timer()
	{
		reset();
	}

	// starts the timer
	void reset()
	{
		m_timestamp = std::chrono::high_resolution_clock::now();
	}

	// returns the time in seconds since reset() was called
	float diff()
	{
		std::chrono::duration<float> fs = std::chrono::high_resolution_clock::now() - m_timestamp;
		return fs.count();
	}
};