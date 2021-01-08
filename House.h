#ifndef _HOUSE_
#define _HOUSE_

/* add the necessary includes */
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <string>
#include <map>

/* add an include guard named _HOUSE_  */

class House
{
	public :
		/* create the prototype for the constructor based on House.cpp */
		/* create the prototype for ringDoorbell() based on House.cpp */
		House(std::string Name, std::map<int,std::string>CandyRanking);
		virtual ~House(); 
		
		virtual std::string ringDoorbell(std::ostringstream &path) = 0;
		
	//PROTECTED****
	protected :
		std::string houseName;
		/* declare a mutex named door */
		/* declare a map named CandyRankingMap of type int,string */
		std::mutex door;
		std::map<int, std::string> CandyRankingMap;
};

#endif

