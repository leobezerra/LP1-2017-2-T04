#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <iostream>
#include <string>
#include <queue>

typedef unsigned short int ushort;

class Message {
    private:
        std::string data;
        ushort priority;
    public:
        Message(std::string data_, ushort priority_) : 
            data(data_), priority(priority_) {}
        friend std::ostream & operator<< (std::ostream &, const Message &);
        bool operator<(const Message & other) const
        {
            return priority < other.priority;
        }
};

#endif
