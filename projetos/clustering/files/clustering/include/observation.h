#ifndef __OBSERVATION_H__
#define __OBSERVATION_H__

#include <vector>

typedef unsigned short int ushort;
typedef std::pair<double,double> bound;

class Observation {
    private:
        std::vector<double> features;
    public:
        Observation(void) = default;
        Observation(const std::vector<bound> &);
        friend std::istream & operator>> (std::istream &, Observation &);
        friend std::ostream & operator<< (std::ostream &, const Observation &);
        ushort size() const { return features.size(); }
        void resize(ushort size) { features.resize(size); }
        bool operator==(const Observation &) const;
        bool operator<(const Observation &) const;
        double & operator[](int idx) { return features[idx]; }
        const double & operator[](int idx) const { return features[idx]; }
        double euclid(const Observation &) const;
        ushort nearest(const std::vector<Observation> &) const;
};

namespace std {

  template <>
  struct hash<Observation>
  {
    std::size_t operator()(const Observation & obs) const
    {
        if (!obs.size()) abort();
        using std::hash;
        std::size_t h = hash<double>()(obs[0]);
        for (ushort i = 1; i < obs.size(); i++)
            h ^= hash<double>()(obs[i]); 
        return h;
    }
  };

}

typedef bool (*obsCmp)(const Observation &, const Observation &);

#endif
