#include <iostream>
#include <string>

#include "messages.h"

std::ostream & operator<< (std::ostream & out, const Message & msg) {
    out << "[" << msg.priority << "] " << msg.data;
    return out;
}
