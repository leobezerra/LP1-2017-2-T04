#ifndef __PORTFWD_H__
#define __PORTFWD_H__

#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <queue>

#include "messages.h"

typedef unsigned short int ushort;

class TableEntry {
    private:
        std::string ip;
        ushort port, pid;
    public:
        TableEntry(std::string _ip, ushort _port, ushort _pid) :
            ip(_ip), port(_port), pid(_pid) {}

        bool operator==(const TableEntry &other) const { 
            return ip == other.ip &&
                    port == other.port;
        }
        bool operator<(const TableEntry &other) const { 
            if (pid < other.pid) return true;
            else if (pid == other.pid) {
                if (port < other.port) return true;
                else if (port == other.port) { return ip < other.ip; }
                else return false;
            }
            else return false;
        }
        friend std::ostream& operator<< (std::ostream &, const TableEntry &);
        const std::string & getIP() const { return ip; }
        const ushort & getPort() const { return port; }
        const ushort & getPID() const { return pid; }

};

namespace std {

  template <>
  struct hash<TableEntry>
  {
    std::size_t operator()(const TableEntry & entry) const
    {
        using std::hash;
        using std::string;
        return hash<std::string>()(entry.getIP()) ^ hash<int>()(entry.getPort());
    }
  };

}

class PortForward {
    private:
        std::unordered_map<TableEntry,std::priority_queue<Message> > portTable;
    public:
        friend std::istream& operator>> (std::istream &, PortForward &);
        friend std::ostream& operator<< (std::ostream &, PortForward &);
        void parse_buffer(const std::string &);
        void persist(const std::string &);
};

#endif
