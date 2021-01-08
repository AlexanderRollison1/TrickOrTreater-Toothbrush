/* Add the needed includes */
#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <sstream>
#include <fstream>

#include "House.h"
#include "TrickOrTreater.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"

void get_command_line_params(int argc, char *argv[], std::string& TOTfile, std::string& Housefile, std::string& Candyfile)
{
	/* if argc is 4, then put argv[1] in TOTfile, argv[2] in Housefile and argv[3] in Candyfile 
	/* else throw an invalid_argument with the message shown in the output */
	if(argc == 4)
	{
		TOTfile = argv[1];
		Housefile = argv[2];
		Candyfile = argv[3];
	}
	else
	{
		throw "Missing command line parameters - Usage : TOTFILENAME HOUSEFILENAME CANDYFILENAME";
	}
}

int main(int argc, char *argv[])
{
	std::string TOTFilename, HouseFilename, CandyFilename;

	/* create a map named CandyRankingMap of type int,string */
	std::map<int,std::string>CandyRankingMap; //,less<int>
	std::string CandyLine;
	char CandyLineA[50] = {};
	std::string CandyName;
	int CandyRanking;
	char *CandyPtr = NULL;

	/* create a vector named Houses of type pointers to House */
	std::vector<House*>Houses;
	std::string HouseLine;

	/* create a vector named TOTs of type TrickOrTreater */
	std::vector<TrickOrTreater>TOTs;
	std::string TotLine;
	
	/* declare an ostringstream named HouseHeading */
	std::ostringstream HouseHeading;
	srand(time(NULL));
	
	/* create a try-catch block for function get_command_line_params */
	try
	{
		get_command_line_params(argc, argv,TOTFilename, HouseFilename, CandyFilename);
	}
	catch(const char *message)
	{
		std::cout<<"Exiting program -"<<std::endl;
		std::cout<<message<<std::endl;
		exit(0);
	}

	/* open all three files from command line for reading - use TOTFH, HouseFH and CandyFH */	
	std::ifstream TOTFH;
	TOTFH.open(TOTFilename, std::ios::in);
	std::ifstream HouseFH;
	HouseFH.open(HouseFilename, std::ios::in);
	std::ifstream CandyFH;
	CandyFH.open(CandyFilename, std::ios::in);
	
	while (getline(CandyFH,CandyLine/* make getline read from CandyFH into CandyLine */))
	{
		strcpy(CandyLineA, CandyLine.c_str());
		CandyPtr = strtok(CandyLineA, "|");
		CandyName = CandyPtr;
		CandyPtr = strtok(NULL, "|");
		CandyRanking = atoi(CandyPtr);
		/* call insert() and make_pair() with CandyRanking and CandyName */
		CandyRankingMap.insert(make_pair(CandyRanking, CandyName));
	}
	/* Close the Candy file - CandyFH */
	CandyFH.close();
	
	HouseHeading << "          ";
	
	while (getline(HouseFH,HouseLine/* make getline read from HouseFH into HouseLine */))
	{
		/* in one line - use new to allocate a House object that is constructed by    */
		/* passing HouseLine and CandyRankingMap and push_back the object into Houses */
		int rand1Or0 = rand()%2;
		if(rand1Or0 == 1)
		{
			Houses.push_back(new ToothbrushHouse{HouseLine, CandyRankingMap}); //we don't need to pass in CandyRankingMap
		}
		else if(rand1Or0 == 0)
		{
			Houses.push_back(new CandyHouse{HouseLine, CandyRankingMap});
		}
		//Houses.push_back(new CandyHouse{HouseLine, CandyRankingMap});
		HouseHeading << HouseLine;
		for (int i = 0; i < 11 - HouseLine.length(); i++)
			HouseHeading << " ";
	}
	HouseHeading << std::endl << std::endl;
	/* Close the House file - HouseFH */
	HouseFH.close();
	/* Create all of the Trick or Treaters */
	while (getline(TOTFH,TotLine/* make getline read from TOTFH into TotLine */))
	{
		TOTs.push_back(TrickOrTreater{TotLine, Houses});
	}
	/* Close the TOT file - TOTFH */
	TOTFH.close();
	
	/* Start all of the trick or treaters using a range based for loop over vector TOT */	
	/* call function startThread() for each iterator for each pass through the loop */
	
	for(TrickOrTreater& it : TOTs)
	{
		it.startThread();
	}
	
	while (TrickOrTreater::ImDone != TOTs.size() ) 
	{
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << HouseHeading.str();

        for (TrickOrTreater& it: TOTs/* range based for loop over TOTs */) 
		{
			std::cout << it.getPath()/* call getPath() for iterator */ << it.getName()/* call getName() for iterator */ << std::endl;
        }
		/* put this_thread to sleep for 5 milliseconds */
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }	
	
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << HouseHeading.str();

	for (TrickOrTreater& it: TOTs/* range based for loop over TOTs */) 
	{
		std::cout << it.getPath()/* call getPath() for iterator */ << it.getName()/* call getName() for iterator */ << std::endl;
	}
	
	for (TrickOrTreater& it: TOTs/* range based for loop over TOTs */)
	{
		std::cout<<it;
	}

	for (TrickOrTreater& it: TOTs/* range based for loop over TOTs */)
	{
		it.joinThread();/* Call function joinThread() for iterator */
	}

	for (auto it: Houses/* range based for loop over Houses */)
	{
		delete it;/* use delete for iterator to return dynamically allocated memory */
	}
	
	return 0;
}
