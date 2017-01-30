/**
 * Message.cpp
 *
 * Message class (message objects are written/read into/from std::queue)
 *
 * Author: Nalinaksh Gaur
 */

#include <iostream>
#include "Message.h"

using namespace std;

Message::Message(){}
	
Message::Message(string name, string message){
    setName(name);
    setMessage(message);
}

void Message::setName(string name){
    this->name = name;
}

string Message::getName(){
    return name;
}
	
void Message::setMessage(string message){
    this->message = message;
}

string Message::getMessage(){
    return message;
}
