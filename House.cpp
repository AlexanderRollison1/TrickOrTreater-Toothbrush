// House Class Template Alexander Rollison 1001681800
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include "House.h"


House::House(std::string Name, std::map<int,std::string>CandyRanking)
	:houseName{Name}, CandyRankingMap{CandyRanking}
{
}

House::~House()
{
}

//std::string House::ringDoorbell(std::ostringstream &path)
//{
//}
