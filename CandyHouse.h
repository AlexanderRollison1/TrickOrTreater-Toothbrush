//Alexander Rollison 1001681800
#ifndef CANDY_HOUSE_
#define CANDY_HOUSE_

#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include "House.h"


class CandyHouse : public House
{
	public:
	CandyHouse(std::string Name, std::map<int,std::string>CandyRanking);
	~CandyHouse();
	std::string ringDoorbell(std::ostringstream &path);
};


#endif
