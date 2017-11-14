#ifndef __NEWS_H__
#define __NEWS_H__

#include <iostream>
#include <string>

#include "datetime.h"

class News {
	private:
		ushort publisher_id;
		Datetime tstamp;
		std::string msg;
	public:
		ushort getPublisherID(void) const { return publisher_id; }
		const Datetime & getTimeStamp(void) const { return tstamp; }
		friend std::istream & operator>> (std::istream &, News &);
		friend std::ostream & operator<< (std::ostream &, const News &);
		bool operator==(const News &) const;
		bool operator<(const News &) const;
};

namespace std {

  template <>
  struct hash<News>
  {
    std::size_t operator()(const News& news) const
    {
      using std::hash;
      return hash<int>()(news.getPublisherID()) ^ hash<Datetime>()(news.getTimeStamp());
    }
  };

}

#endif