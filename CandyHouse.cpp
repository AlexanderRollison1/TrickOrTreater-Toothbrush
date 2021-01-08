//Alexander Rollison 1001681800
#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include <sstream>

#include "House.h"
#include "CandyHouse.h"

CandyHouse::CandyHouse(std::string Name, std::map<int,std::string>CandyRanking)
	:House(Name,CandyRanking)
{
	//houseName = Name;
	//CandyRankingMap = CandyRanking;
}

CandyHouse::~CandyHouse()
{
	std::cout<<"CANDYHOUSE"<<std::endl;
}

std::string CandyHouse::ringDoorbell(std::ostringstream &path)
{
	door.lock();
	path << "+";
	// put this_thread to sleep for 3 seconds
	std::this_thread::sleep_for(std::chrono::seconds(3));
	//Pick a candy from the CandyRankingMap
	int candy = rand() % (CandyRankingMap.size()) + 1;

	// unlock the door mutex
	door.unlock();
	return CandyRankingMap[candy];
}
