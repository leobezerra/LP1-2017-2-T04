#ifndef __SETS_H__
#define __SETS_H__

#include <set>
#include <unordered_set>

#include "observation.h"

typedef std::pair<double,double> bound;

class Set : private std::unordered_set<Observation> {
    private:
        std::unordered_set<Observation> data;
    public:
        using std::unordered_set<Observation>::insert;
        using std::unordered_set<Observation>::erase;
        using std::unordered_set<Observation>::find;
        using std::unordered_set<Observation>::empty;
        using std::unordered_set<Observation>::begin;
        using std::unordered_set<Observation>::end;

        friend std::istream & operator>> (std::istream &, Set &);
        friend std::ostream & operator<< (std::ostream &, const Set &);

        bool contains(const Observation &) const;
        Set _union(const Set &) const;
        Set intersection(const Set &) const;
        Set difference(const Set &) const;

        std::set<Observation, obsCmp> sort(obsCmp cmp);

        std::vector<bound> getBounds(void) const;
        Observation centroid (ushort, const std::vector<ushort> &) const;
        std::vector<ushort> cluster(void) const;
};

#endif
