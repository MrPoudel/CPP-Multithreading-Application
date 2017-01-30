#ifndef __MESSAGE_H_INCLUDED__
#define __MESSAGE_H_INCLUDED__

/**
 * Message.h
 *
 * Message class (message objects are written/read into/from std::queue)
 *
 * Author: Nalinaksh Gaur
 */

#include <iostream>

using namespace std;

class Message {
    private:
        string name;    // thread name(id)
	string message; //message string
	
    public:
	Message();
	Message(string name, string message);
	void setName(string name);
	string getName();
	void setMessage(string message);
	string getMessage();
};

#endif //__MESSAGE_H_INCLUDED__
