#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_set>

#include "newsfeed.h"

int main (int argc, char * argv[]) {
	NewsFeed feed;
	std::cin >> feed;

	if (argc < 2) abort();
	std::string fname(argv[1]);
	feed.read_buffer(fname);

	feed.render();
	return 1;
}