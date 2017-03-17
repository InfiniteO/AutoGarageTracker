/*
 * AutoGarage.cpp
 *
 *  Created on: 18-Jan-2017
 *      Author: apple
 */

/*
 * a simple object oriented library for tracking automobile maintenance.
 * The system support car types: electric, gas and diesel.
 * Each vehicle have a make, model, year and odometer reading.
 * Maintenance tasks should include 2-3 things like oil changes or tire rotations.
 * However, not all maintenance tasks can be applied to all vehicles (an electric car won’t need an oil change).

   Tracker library or API should be capable of listing, adding, updating and removing entries at runtime.
   Unit tests supplied to demonstrate features.
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "tracker/Tracker.h"

using namespace std;
using namespace tracker;

//#ifndef BOOST_TEST_MODULE
int main() {

	std::shared_ptr<tracker::Tracker> aTracker = make_shared<tracker::Tracker>();

	std::string fileName{"input.txt"};
	//std::getline(std::cin, fileName);
	int type, service, id, year;
	long odometer;
	std::string make, model;
	stringstream ss;
	std::string pick, object, token, waste;
	char ch;

	std::ifstream file(fileName.c_str());
	if(!file){
		cout << "Can't open input file" << endl;
		return 1;
	}
	try{

		cout << "Pick operation: 1: Add Auto 2: List Auto 3: Do Service 4: List Services 5: Remove Auto 6: JSON output" <<endl;

		while(std::getline(file, pick)) {

			switch (boost::lexical_cast<int>(pick)) {
			case 1:
				cout << "Add Auto: Enter (Engine-type, make, model, odometer, year)" << endl;
				//pick.resize (pick.size () - 1);
				ss.clear ();
				ss.str ("");
				//file >> object;

				std::getline(file, object);
				cout << "	Auto input: " << object << endl;
				ss << object;
				//ss >> type >> ch >> make >> ch >> model >> ch >> odometer >> ch >> year >> waste;
				ss >> token;
				//cout << "token: "<< token << flush;
				type = boost::lexical_cast<int>(token);
				//ss >> ch;//space
				ss >> make;
				//ss >> ch;//space
				ss >> model;
				//ss >> ch;//space
				ss >> token;
				odometer = boost::lexical_cast<long>(token);
				//ss >> ch;//space
				ss >> token;
				year = boost::lexical_cast<int>(token);


				//file >> type >> ch >> odometer >> ch >> year >> ch >> make >> ch >> model >> waste;

				aTracker->addAuto(static_cast<detail::ENGINE>(type), make, model, odometer, year);
				cout << "	Auto created: " << type << ", "  << make << ", " << model << ", " << odometer << ", " << year << waste << endl;
				break;

			case 2:
				cout << "List Auto:" << endl;
				aTracker->listAuto();
				break;

			case 3:
				cout << "Do Service: Enter (ID, Service)" << endl;
				ss.clear ();
				ss.str ("");

				std::getline(file, object);
				cout << "	(ID, Service) input: " << object << endl;
				ss << object;

				ss >> token;
				//cout << "token: "<< token << flush;
				id = boost::lexical_cast<int>(token);

				ss >> token;
				//cout << "token: "<< token << flush;
				service = boost::lexical_cast<int>(token);

				aTracker->nowServe(id, static_cast<detail::Services>(service));

				break;

			case 4:
				cout << "List Services: Enter (ID)" << endl;
				ss.clear ();
				ss.str ("");

				std::getline(file, object);
				cout << "	(ID) input: " << object << endl;
				ss << object;

				ss >> token;
				//cout << "token: "<< token << flush;
				id = boost::lexical_cast<int>(token);

				aTracker->listServices(id);
				break;

			case 5:
				cout << "Remove Auto: Enter ID" << endl;
				ss.clear ();
				ss.str ("");

				std::getline(file, object);
				cout << "	ID input: " << object << endl;
				ss << object;

				ss >> token;
				//cout << "token: "<< token << flush;
				id = boost::lexical_cast<int>(token);

				aTracker->removeAuto(id);
				break;

			case 6:
				aTracker->printTtree();
				cout << "Check out the .json file!" << endl;
				break;
			default:
				cout << "Invalid pick" << endl;
				return 1;

			}//switch
		}//while(1)
	}//try
	catch( boost::bad_lexical_cast & e ){

	      std::cout << "Exception caught : " << e.what() << std::endl;
	}
	catch (exception& e){

	    cout << e.what() << '\n';
	}

	cout << "End state:" << endl;
	aTracker->listAuto();

	return 0;
}
//#endif //#ifdef BOOST_TEST_MODULE
