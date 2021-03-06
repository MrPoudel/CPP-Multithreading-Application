# C++-Multithreading-Application
A multithreaded application in C++ is created for reading/writing messages from/to a shared queue. 

Source files
##############
Message.h/cpp
##############

The Message class defines accessor/mutator methods to retrieve/modify the name and message members. Name is the actual therad id while message is a string containing some information. Objects of this class are created in the main thread, and passed to various threads to be written into the shared queue.

#############
Logger.h/cpp
#############

This class provides the shared resource, which is std::queue<Message>. This class is made as a singleton class to ensure that only a single instance can be createad. This is done by making the constructor, Copy constructor and assignment operator private. A public static method getInstance() is provided which creates an instance of Logger first time it is called, while for the rest of the time, it just returns the same instance. This method implements Lazy initialization. Also, in C++11, for the singleton pattern, double-checked locking is not needed : "If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization."

Logger class also contains std::mutex member to provided mutual exclusion to the std::queue accessed by multiple threads. std::lock_guard is used to guard the mutex. It locks the mutex until the scope of the block/function.

################
Application.cpp 
################

This file contains the main funtion. Logger::getInstance() is called to create a single instance of the Logger class. Multiple threads are created and are passed the Message objects. The threads invoke the Logger::AddToQueue to write the Message objects into the queue. Finally a thread is createad to read all the Message objects from the queue and write it to the standard output.

############
COMPILATION:
############

The source code was compiled on MAC OS with C++11 compiler using the command below:

    clang++ -std=c++11 -stdlib=libc++ Application.cpp Message.cpp Logger.cpp -o app

    ./app

#################
Possible Output:
#################

    0x108d60000: Message-0
    0x108de3000: Message-1
    0x108e66000: Message-2
    0x108f6c000: Message-4
    0x108ee9000: Message-3

