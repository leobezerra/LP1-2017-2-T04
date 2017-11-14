#ifndef __PUBLISHER_H__
#define __PUBLISHER_H__

#include <iostream>

#include "json/json-forwards.h"
#include "json/json.h"
#include "datetime.h"

class Publisher {
	private:
		ushort publisher_id, weekly, monthly, yearly;
		float relevance;
		Datetime last_interaction;
	public:
		friend std::istream & operator>> (std::istream &, Publisher &);
		friend std::ostream & operator<< (std::ostream &, const Publisher &);
		bool operator==(const Publisher &other) const;
  		bool operator<(const Publisher &other) const;
    	ushort getID(void) const { return publisher_id; }
    	float getRelevance(void) const { return relevance; }
    	const Datetime & getLastInteraction(void) const { return last_interaction; }
};

namespace std {

  template <>
  struct hash<Publisher>
  {
    std::size_t operator()(const Publisher& pbs) const
    {
      using std::hash;
      return hash<int>()(pbs.getID());
    }
  };

}

struct activeCmp {
	bool operator()(const Publisher & lhs, const Publisher & rhs) { 
	    return lhs.getLastInteraction() < rhs.getLastInteraction();
	}
};

struct topCmp {
	bool operator()(const Publisher & lhs, const Publisher & rhs) { 
	    return lhs.getRelevance() > rhs.getRelevance();
	}
};

#endif