#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#include "observation.h"

std::istream & operator>> (std::istream & in, Observation & obs) {
    std::string line, tmp;
    std::getline(in, line);
    std::istringstream buffer(line);
    while (std::getline(buffer, tmp, ',')) obs.features.push_back(std::stof(tmp));
    return in;
}

std::ostream & operator<< (std::ostream & out, const Observation & obs) {
    for (ushort i = 0; i < obs.size(); i++)
        out << obs.features[i] << (i+1 == obs.size() ? "" : ",");
    out << std::endl;
    return out;
}

bool Observation::operator==(const Observation & other) const {
    if (features.size() != other.features.size()) abort();
    for (ushort i = 0; i < features.size(); i++) 
        if (features[i] != other.features[i]) return false;
    return true; 
}

bool Observation::operator<(const Observation & other) const {
    if (features.size() != other.features.size()) abort();
    for (ushort i = 0; i < features.size(); i++) {
        if (features[i] == other.features[i]) continue;
        return features[i] < other.features[i];
        
    }
    return false;
}

double randomDouble(bound bounds) {
    double a = bounds.first;
    double b = bounds.second;
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

Observation::Observation(const std::vector<bound> & bounds) {
    features.reserve(bounds.size());
    for (ushort i = 0; i < bounds.size(); i++)
        features.push_back(randomDouble(bounds[i]));
}

double Observation::euclid(const Observation & obs) const {
    if (size() != obs.size()) abort();
    double dist = 0.0;
    for (ushort i = 0; i < size(); i++)
        dist += pow(obs[i] - features[i], 2);
    return sqrt(dist);
}

ushort Observation::nearest(const std::vector<Observation> & centroids) const {
    if (centroids.empty()) abort();
    ushort nearest = 0;
    double dist = 0.0, min_dist = euclid(centroids[nearest]);
    for (ushort i = 1; i < centroids.size(); i++) {
        dist = euclid(centroids[i]);
        if (dist < min_dist) { nearest = i; min_dist = dist; }
    }
    return nearest;
}
