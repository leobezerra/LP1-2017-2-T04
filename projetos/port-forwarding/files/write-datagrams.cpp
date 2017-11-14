#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

typedef unsigned short int ushort;

void write_random_byte(ushort size, bool end = false) {
    for (ushort i = 0; i < size; i++) 
        std::cout << std::setw(2) << (rand() % 256) << (i + 1 == size ? "" : " ");
    if (end) std::cout << std::endl;
    else std::cout << " ";
}

void write_ihl_word(ushort ihl, ushort total_length) {
    char iword = (char) 4;
    iword = iword << 4;
    iword += ihl;
    std::cout << (int) iword << " "; 

    char dscp = ((rand() % 10) < 3 ? 46 : 0);
    char ecn = rand() % 4;
    char dscp_ecn = (dscp << 2) + ecn;
    std::cout << std::setw(2) << (int) (dscp_ecn & 0xff) << " "; 

    std::cout << std::setw(2) << (total_length >> 8) << " ";
    std::cout << std::setw(2) << (total_length & 0xff)<< " ";
    write_random_byte(4, true);

    std::cerr << "ihl: " << ihl;
    std::cerr << ", dscp: " << (int) dscp;
    std::cerr << ", total_length: " << total_length << std::endl;
}

void write_ip(const std::string & ip) {
    std::istringstream in(ip);
    std::string tmp;
    while (std::getline(in, tmp, '.')) 
        std::cout << std::setw(2) << std::stoi(tmp) << " ";
}

void write_udp(ushort port, bool breakpoint = false) {
    write_random_byte(2);
    std::cout << std::setw(2) << (port >> 8) << " ";
    std::cout << std::setw(2) << (port & 0xff);
    if (breakpoint) std::cout << std::endl;
    else std::cout << " ";

    write_random_byte(4, !breakpoint);
}

void write_options(ushort ihl) {
    if (ihl > 5) 
        write_random_byte(4, true);
    for (ushort i = 7; i < ihl; i += 2) write_random_byte(8, true);
    if (ihl > 6 && ihl % 2) write_random_byte(4);
}

void write_hex(const std::string & str, ushort start, ushort size, ushort offset = 0) {
    for (ushort i = start; i < start + size; i++) {
        std::cout << std::setw(2) << (int) str[i] << ((i + 1 + offset) % 8 ? " " : "\n");
    }
}

void write_data(ushort ihl, ushort total_length) {
    std::string str;
    for (ushort i = ihl * 4; i < total_length; i++)
        str.push_back((char) ((rand() % 94) + 32));
    std::cerr << "data: " << str << std::endl;

    ushort offset = 0;
    if (ihl % 2) {
        if (total_length >= ihl * 4 + 4) {
            write_hex(str, 0, 4, 4);
            offset = 4;
        }
        else {
            offset = total_length - ihl * 4;
            write_hex(str, 0, offset);
        }
    }

    ushort remaining_data = total_length - (ihl * 4 + offset);
    if (!remaining_data) return;
    ushort total_words = remaining_data / 8;
    for (ushort i = 0; i < total_words; i++)
        write_hex(str, i * 8 + offset, 8, offset);
    if (remaining_data % 8) {
        write_hex(str, total_words * 8 + offset, remaining_data % 8, offset);
        std::cout << std::endl;
    }

}

void write_datagram(const std::string & ip, ushort port) {
    ushort ihl = (rand() % 3) + 5;
    ushort total_length = (rand() % 50) + 40;
    write_ihl_word(ihl, total_length);
    write_random_byte(8, true);

    std::cerr << "ip: " << ip << ", port: " << port << std::endl;
    write_ip(ip);
    write_options(ihl);
    write_udp(port, ihl % 2);

    write_data(ihl, total_length);
}

int main (int argc, char * argv[]) {
    std::cout.width(2);
    std::cout.fill('0');
    std::cout.setf(std::ios::hex, std::ios::basefield);

    std::vector<std::string> ips;
    std::vector<ushort> pids;
    std::vector<ushort> ports;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string field;
        if (std::getline(in, field, ',')) pids.push_back(std::stoi(field));
        if (std::getline(in, field, ',')) ports.push_back(std::stoi(field));
        if (std::getline(in, field, ',')) ips.push_back(field);
    }

    if (argc != 3) abort();
    ushort buffer_size = std::atoi(argv[1]);
    ushort seed = std::atoi(argv[2]);
    srand(seed);
    for (ushort i = 0; i < buffer_size; i++) {
        ushort idx = rand() % ips.size();
        write_datagram(ips[idx], ports[idx]);
    }

    return 1;
}
