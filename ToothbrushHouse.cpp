#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include "House.h"
#include "ToothbrushHouse.h"

ToothbrushHouse::ToothbrushHouse(std::string Name, std::map<int,std::string>CandyRanking)
	:House(Name,CandyRanking)
{
}

ToothbrushHouse::~ToothbrushHouse()
{
	std::cout<<"TOOTHBRUSHHOUSE"<<std::endl;
}

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &path)
{
	//lock the door mutex
	door.lock();
	path << "-";
	//put this_thread to sleep for 3 seconds
	std::this_thread::sleep_for(std::chrono::seconds(3));

	//unlock the door mutex
	door.unlock();
	return "TOOTHBRUSH";
}
