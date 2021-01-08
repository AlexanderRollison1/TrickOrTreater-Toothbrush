//Alexander Rollison 1001681800
#ifndef TOOTHBRUSH_HOUSE_
#define TOOTHBRUSH_HOUSE_

#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include <sstream>

#include "House.h"

class ToothbrushHouse : public House
{
	public:
	ToothbrushHouse(std::string Name, std::map<int,std::string>CandyRanking);
	~ToothbrushHouse();
	std::string ringDoorbell(std::ostringstream &path);
};

#endif
