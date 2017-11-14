#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "datetime.h"

std::istream & operator>> (std::istream & in, Datetime & tstamp) {
	std::string tmp;
	tstamp.elapsed = 0.0;

	std::getline(in, tmp, '-');
	tstamp.years = std::stoi(tmp) - 1970;
	tstamp.elapsed += tstamp.years * 311104000 * 10e6;

	std::getline(in, tmp, '-');
	tstamp.months = std::stoi(tmp);
	tstamp.elapsed += tstamp.months * 2592000 * 10e6;

	std::getline(in, tmp, 'T');
	tstamp.days = std::stoi(tmp);
	tstamp.elapsed += tstamp.days * 86400 * 10e6;

	std::getline(in, tmp, ':');
	tstamp.hours = std::stoi(tmp);
	tstamp.elapsed += tstamp.hours * 3600 * 10e6;

	std::getline(in, tmp, ':');
	tstamp.minutes = std::stoi(tmp);
	tstamp.elapsed += tstamp.minutes * 60 * 10e6;

	std::getline(in, tmp, '.');
	tstamp.seconds = std::stoi(tmp);
	tstamp.elapsed += tstamp.seconds * 10e6;

	std::getline(in, tmp);
	tstamp.micros = std::stoi(tmp);
	tstamp.elapsed += tstamp.micros;

	return in;
}

std::ostream & operator<< (std::ostream & out, const Datetime & tstamp) {
	out << tstamp.years + 1970;
	out << "-" << std::setw(2) << std::setfill('0') << tstamp.months
		<< "-" << std::setw(2) << std::setfill('0') << tstamp.days
		<< "T" << std::setw(2) << std::setfill('0') << tstamp.hours 
		<< ":" << std::setw(2) << std::setfill('0') << tstamp.minutes 
		<< ":" << std::setw(2) << std::setfill('0') << tstamp.seconds 
		<< "." << std::setw(6) << std::setfill('0') << tstamp.micros;
//		<< " (" << tstamp.elapsed << ")";
	return out;
}

bool Datetime::operator==(const Datetime &other) const {
	return years == other.years && months == other.months
		&& days == other.days && hours == other.hours
		&& minutes == other.minutes && seconds == other.seconds
		&& micros == other.micros && elapsed == other.elapsed;	
}

bool Datetime::operator<(const Datetime & other) const {
    return elapsed > other.elapsed;
}
