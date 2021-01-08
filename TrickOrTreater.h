#ifndef _TOT_H
#define _TOT_H
/* add the necessary includes */
#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include <sstream>

#include "House.h"

/* add an include guard called _TOT_H */

class TrickOrTreater
{
	/* create friend function prototype */
	friend std::ostream& operator<<(std::ostream& output, const TrickOrTreater& TOT/* add both parameters */);
	
	public :
		/* create the prototype for the constructor based on TrickOrTreater.cpp */
		TrickOrTreater(std::string Name, std::vector<House*>List);
		std::string getName();
		void startThread();
		void joinThread();
		void GoTrickOrTreating();
		void Walk(int); 
		std::string getPath();
		static int ImDone;
		
		
	private :
		std::string name;
		std::ostringstream path;
		std::thread *TOTThreadPtr = nullptr;
		/* declare a map named Bucket of type string,int */
		/* declare a vector name ListOfHouses of type pointer to House */
		std::map<std::string,int>Bucket;//,less<int>
		std::vector<House*>ListOfHouses;
};

#endif
