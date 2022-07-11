#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <time.h>

class timer
{
  public:
    timer(std::string name, std::fstream& file)
      : file_(file)
        , name_(name)
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
      clock_t end = clock();

      diff_ms = (int)((double)(end - start_) / CLOCKS_PER_SEC * 1000);

      active_ = false;
      file_ << "Timer: ---" << name_ << "---" << std::endl
        << "ms: " << diff_ms << std::endl
        << std::endl;
    }

    void start()
    {
      start_ = clock();
      active_ = true;
    }

  private:
    clock_t start_;
    bool active_;
    std::fstream& file_;
    int diff_ms;
    std::string name_;
};
