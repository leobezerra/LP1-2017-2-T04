#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#include "portforward.h"
#include "datagrams.h"
#include "messages.h"

std::istream& operator>> (std::istream & stin, PortForward & pf) {
    std::string ip;
    ushort pid, port;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string field;
        if (std::getline(in, field, ',')) pid = std::stoi(field);
        else abort();
        if (std::getline(in, field, ',')) port = std::stoi(field);
        else abort();
        if (std::getline(in, field, ',')) ip = field;
        else abort();
        TableEntry entry(ip, port, pid);
        pf.portTable.insert(std::make_pair(entry, std::priority_queue<Message>()));
    }

    return stin; 
}

std::ostream & operator<< (std::ostream & out, const TableEntry & entry) {
    out << entry.pid << "," << entry.port << "," << entry.ip;
    return out;
}

void PortForward::parse_buffer(const std::string & fname) {
    std::ifstream in(fname);
    std::vector<Datagram> msgs;
    do {
        Datagram msg;
        in >> msg;
        if (in.eof()) break;
        msgs.push_back(msg);
    }
    while (1);

    for (ushort i = 0; i < msgs.size(); i++) {
        TableEntry key(msgs[i].getTableEntry());
        Message msg(msgs[i].getMessage());
        portTable.at(key).push(msg);
    }
}

void PortForward::persist(const std::string & fname) {
    std::ofstream out(fname);
    std::vector<TableEntry> entries;
    for (auto itr = portTable.begin(); itr != portTable.end(); itr++)
        entries.push_back(itr->first);
    std::sort(entries.begin(), entries.end());
    for (auto itr = entries.begin(); itr != entries.end(); itr++) {
        out << *itr << std::endl;
        std::priority_queue<Message> queue(portTable.at(*itr));
        while (!queue.empty()) {
            out << queue.top() << std::endl;
            queue.pop();
        }
    }        
}

std::ostream & operator<< (std::ostream & out, PortForward & pf) {
    for (auto itr = pf.portTable.begin(); itr != pf.portTable.end(); itr++)
    {
        std::cout << itr->first << ": ";
        std::cout << "[" << itr->second.size() << "]" << std::endl;
    }
    return out;
}
