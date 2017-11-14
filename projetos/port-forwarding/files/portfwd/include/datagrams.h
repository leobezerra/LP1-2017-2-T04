#ifndef __DATAGRAMS_H__
#define __DATAGRAMS_H__

#include <iostream>
#include <string>

#include "portforward.h"
#include "messages.h"

typedef unsigned short int ushort;

class Datagram {
    private:
        ushort ihl, dscp, total, port;
        std::string data, ip;
    public:
        friend std::istream& operator>> (std::istream &, Datagram &);
        friend std::ostream& operator<< (std::ostream &, const Datagram &);
        Message getMessage() { return Message(data, dscp); } 
        TableEntry getTableEntry() { return TableEntry(ip, port, 0); } 
};

#endif
