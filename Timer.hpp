#pragma once

#include <chrono>
#include <string>
#include <iostream>

class Timer
{
  public:
    Timer()
      : timer_name("Unnamed timer")
    {
      Start();
    }

    Timer(std::string timer_name)
      : timer_name(timer_name)
    {
      Start();
    }

    ~Timer()
    {
      if (active)
      Stop();
    }

    void Stop()
    {
      auto endTimepoint = std::chrono::high_resolution_clock::now();

      auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
      auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

      auto duration = end - start;
      double ms = duration * 0.001;
      active = false;
      std::cout << "TIMER " << timer_name << " | usec: " << duration
        << " | ms: " << ms
        << std::endl;
    }
    
    void Start()
    {
      m_StartTimepoint = std::chrono::high_resolution_clock::now();
      active = true;
    }

  private:
    std::chrono::time_point< std::chrono::high_resolution_clock> m_StartTimepoint;
    std::string timer_name;
    bool active;
};
