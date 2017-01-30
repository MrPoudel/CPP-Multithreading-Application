/**
 * Logger.cpp
 *
 * Logger class provides a queue based interface for writing & reading Message objects by multiple threads into the shared std::queue
 *
 * Author: Nalinaksh Gaur
 */

#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <chrono>
#include <sstream>
#include "message.h"
#include "Logger.h"

using namespace std;

Logger::Logger() {}

//Lazy initialization
//C++11: For the singleton pattern, double-checked locking is not needed. 
//If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.
Logger* Logger::getInstance()
{
    static Logger instance;
    return &instance;
}

void Logger::AddToQueue(Message msg)
{
    std::lock_guard<std::mutex> guard(m); // Lock will be held from here to end of function
    std::ostringstream ss;
    ss << std::this_thread::get_id();
    msg.setName(ss.str());
    q.push(msg);
}
 
void Logger::RemoveFromQueue()
{
    Message msg;
    {
      std::lock_guard<std::mutex> guard(m); // Lock held from here to end of scope
      while (!q.empty())
      {
          msg = q.front();
          cout<<msg.getName()<<": "<<msg.getMessage()<<endl;
          q.pop();
      }
    }
}

