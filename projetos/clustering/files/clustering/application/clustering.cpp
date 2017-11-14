#include <iostream>
#include <set>
#include <cstdlib>

#include "observation.h"
#include "sets.h"

bool cmp (const Observation & lhs, const Observation & rhs) {
    return lhs < rhs;
}

int main(int argc, char * argv[]) {
	srand(std::atoi(argv[1]));
    std::cout.precision(5);
    Set dataset;
    std::cin >> dataset;

    std::set<Observation, obsCmp> sorted = dataset.sort(cmp);
    std::vector<ushort> clusters = dataset.cluster();
	ushort i = 0;
    for (auto itr = dataset.begin(); itr != dataset.end(); itr++)
        std::cout << clusters[i++] + 1 << "," << *itr;

}
