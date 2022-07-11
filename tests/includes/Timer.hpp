#pragma once

#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

class timer
{
  public:
    timer(std::fstream& file)
      : start_timepoint_(time_t())
        , file_(file)
    {
      start();
    }

    ~timer()
    {
      if (active_)
      stop();
    }

    void stop()
    {
      time_t end_timepoint_;

      time(&end_timepoint_);

      double difference = difftime(end_timepoint_, start_timepoint_);

      double ms = difference * 1000;
      active_ = false;
      file_ << "TIMER " << "Time of execution" << " | sec: " << difference
        << " | ms: " << ms
        << std::endl;
    }
    
    void start()
    {
      time(&start_timepoint_);
      active_ = true;
    }

  private:
    time_t start_timepoint_;
    bool active_;
    std::fstream& file_;
};
