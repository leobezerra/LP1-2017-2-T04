#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>

#include "datagrams.h"

std::istream& operator>> (std::istream & stin, Datagram & dg) {
    stin.setf(std::ios::hex, std::ios::basefield);
    std::string line;
    std::getline(stin, line);
    if (stin.eof()) return stin;

    std::istringstream in(line);
    in.setf(std::ios::hex, std::ios::basefield);

    ushort ihl_, dscp_, total_1, total_2;
    in >> ihl_ >> dscp_ >> total_1 >> total_2;

    dg.ihl = ihl_ & 0x0f;
    dg.dscp = dscp_ >> 2;
    dg.total = (total_1 << 8) + total_2;

    std::getline(stin, line);
    std::getline(stin, line);
    in.str(line);

    ushort ip1, ip2, ip3, ip4;
    in >> ip1 >> ip2 >> ip3 >> ip4;
    dg.ip = std::to_string(ip1) + "." + std::to_string(ip2) + "." + std::to_string(ip3) + "." + std::to_string(ip4);

    if (dg.ihl > 5) {
        for (unsigned i = 5; i < dg.ihl; i += 2) std::getline(stin, line);
        in.str(line);
        in.clear();
        if (dg.ihl % 2) in.ignore(12);
    }
    in.ignore(6);
    ushort porta_1, porta_2;
    in >> porta_1 >> porta_2;
    dg.port = (porta_1 << 8) + porta_2;

    short total_data = dg.total - dg.ihl * 4;
    ushort tmp;

    if (dg.ihl % 2) {
        std::getline(stin, line);
        in.str(line);
        in.clear();
        in.ignore(12);
        for (ushort i = 0; i < 4; i++) {
            in >> tmp;
            dg.data += (char) tmp;
            total_data--;
        }
    }
    while (total_data > 0) {
        stin >> tmp;
        dg.data += (char) tmp;
        total_data--;
    }
              
    std::getline(stin, line);

    return stin; 
}

std::ostream & operator<< (std::ostream & out, const Datagram & dg) {
    out << "ihl: " << dg.ihl;
    out << ", dscp: " << dg.dscp; 
    out << ", total_length: " << dg.total << std::endl;

    out << "ip: " << dg.ip;
    out << ", port: " << dg.port << std::endl; 
 
    out << "data: " << dg.data << std::endl;
    return out;
}
