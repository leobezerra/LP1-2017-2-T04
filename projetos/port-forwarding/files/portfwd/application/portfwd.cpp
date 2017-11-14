#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "portforward.h"
#include "messages.h"

int main (int argc, char * argv[]) {
    PortForward portfwd;
    std::cin >> portfwd;

    std::string infile(argv[1]);
    portfwd.parse_buffer(infile);
//    std::cout << portfwd;

    std::string outfile(argv[2]);
    portfwd.persist(outfile);
    return 1;
}
