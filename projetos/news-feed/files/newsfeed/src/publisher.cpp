#include <iostream>
#include <sstream>
#include <string>

#include "json/json-forwards.h"
#include "json/json.h"
#include "publisher.h"

std::istream & operator>> (std::istream & in, Publisher & pbs) {
	std::string tmp;
	if (!std::getline(in, tmp)) return in;
	std::istringstream line(tmp);

	Json::Value root;
	line >> root;

	pbs.publisher_id = root.get("publisher_id", "0").asUInt();
	if (pbs.publisher_id == 0) abort();
	std::string str_li = root.get("last_interaction", "").asString();
	if (str_li == "") abort();

	std::istringstream date(str_li);
	date >> pbs.last_interaction;

	pbs.weekly = root["interaction_frequency"].get("5day", 0).asUInt();
	pbs.monthly = root["interaction_frequency"].get("monthly", 0).asUInt();
	pbs.yearly = root["interaction_frequency"].get("yearly", 0).asUInt();

	pbs.relevance = (6 * pbs.weekly + 4 * pbs.monthly + 2 * pbs.yearly) / 12;

	return in;
}

std::ostream & operator<< (std::ostream & out, const Publisher & pbs) {
	out << "{\"publisher_id\": " << pbs.publisher_id << ", \"interaction_frequency\": "
		"{\"yearly\": " << pbs.yearly << ", \"monthly\": " << pbs.monthly << 
		", \"5day\": " << pbs.weekly << "}" 
		<< ", \"last_interaction\": \"" << pbs.last_interaction << "\""
		<< ", \"relevance\": " << pbs.relevance
		<< "}" <<  std::endl;

	return out;
}

bool Publisher::operator==(const Publisher &other) const {
	return publisher_id == other.publisher_id 
		&& weekly == other.weekly && monthly == other.monthly
            && yearly == other.yearly
            && last_interaction == last_interaction;
}

bool Publisher::operator<(const Publisher &other) const {
	return publisher_id < other.publisher_id;
}
