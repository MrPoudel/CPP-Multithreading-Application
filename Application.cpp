/**
 * Application.cpp
 *
 * C++ std::thread API example.
 * Lock-based solution.
 *
 * Author: Nalinaksh Gaur
 * 
 * Compiled on Mac using the following command:
 *
 *   "clang++ -std=c++11 -stdlib=libc++ Application.cpp Message.cpp Logger.cpp"
 */

#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <chrono>
#include <sstream>
#include "Logger.h"
#include "Message.h"

using namespace std;

int main()
{

    Message M[5];
    for(int msg_num = 0; msg_num < 5; msg_num++)
        M[msg_num].setMessage("Message-" + to_string(msg_num));

    Logger* log = Logger::getInstance();
    try {
          thread t1(&Logger::AddToQueue, log, M[0]);
          thread t2(&Logger::AddToQueue, log, M[1]);
          thread t3(&Logger::AddToQueue, log, M[2]);
          thread t4(&Logger::AddToQueue, log, M[3]);
          thread t5(&Logger::AddToQueue, log, M[4]);

          this_thread::sleep_for(chrono::milliseconds(100));

          thread t6(&Logger::RemoveFromQueue, log);

          t1.join();
          t2.join();
          t3.join();
          t4.join();
          t5.join();
          t6.join();
    }
    catch(std::exception e)
    {
       cout<<"caught exception"<<endl;
    }    

    return 0;
}
