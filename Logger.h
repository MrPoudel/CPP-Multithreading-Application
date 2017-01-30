#ifndef __LOGGER_H_INCLUDED__
#define __LOGGER_H_INCLUDED__

/**
 * Logger.h
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

using namespace std;

class Logger {
  private:
    Logger();
    Logger(const Logger& log) = delete; // non construction-copyable
    Logger& operator = (const Logger& log) = delete; // non copyable
    queue<Message> q; // Queue which multiple threads might add/remove from
    mutex m; // Mutex to protect this queue

  //Lazy initialization
  //C++11: For the singleton pattern, double-checked locking is not needed. 
  //If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.
  public:
    static Logger* getInstance();

    void AddToQueue(Message msg);
 
    void RemoveFromQueue();
};

#endif //__LOGGER_H_INCLUDED__
