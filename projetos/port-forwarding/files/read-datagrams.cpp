#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

typedef unsigned short int ushort;

int main (int argc, char * argv[]) {
    std::cin.setf(std::ios::hex, std::ios::basefield);

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        in.setf(std::ios::hex, std::ios::basefield);

        ushort ihl_, dscp_, total_1, total_2;
        in >> ihl_ >> dscp_ >> total_1 >> total_2;

        ushort ihl = ihl_ & 0x0f;
        ushort dscp = dscp_ >> 2;
        ushort total = (total_1 << 8) + total_2;

        std::cout << "ihl: " << ihl << ", dscp: " << dscp << ", total_length: " << total << std::endl;

        std::getline(std::cin, line);
        std::getline(std::cin, line);
        in.str(line);

        ushort ip1, ip2, ip3, ip4;
        in >> ip1 >> ip2 >> ip3 >> ip4;
        std::string ip = std::to_string(ip1) + "." + std::to_string(ip2) + "." + std::to_string(ip3) + "." + std::to_string(ip4);

        if (ihl > 5) {
            for (unsigned i = 5; i < ihl; i += 2) std::getline(std::cin, line);
            in.str(line);
            in.clear();
            if (ihl % 2) in.ignore(12);
        }
        in.ignore(6);
        ushort porta_1, porta_2;
        in >> porta_1 >> porta_2;
        ushort porta = (porta_1 << 8) + porta_2;

        std::cout << "ip: " << ip << ", port: " << porta << std::endl;
  
        short total_data = total - ihl * 4;
        std::string data;
        ushort tmp;

        if (ihl % 2) {
            std::getline(std::cin, line);
            in.str(line);
            in.clear();
            in.ignore(12);
            for (ushort i = 0; i < 4; i++) {
                in >> tmp;
                data += (char) tmp;
                total_data--;
            }
        }
        while (total_data > 0) {
            std::cin >> tmp;
            data += (char) tmp;
            total_data--;
        }
              
        std::cout << "data: " << data << std::endl;
        std::getline(std::cin, line);
    }
    return 1;
}
