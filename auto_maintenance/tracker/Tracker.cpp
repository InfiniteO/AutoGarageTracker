/*
 * Tracker.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "Tracker.h"
#include <iostream>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

namespace tracker {

int Tracker::addAuto(detail::ENGINE type, std::string make, std::string model,
		long odometer, int year) {

	if(type + 1 > int(detail::ENGINE::ENGINE_MAX)){
		cout << "Invalid Engine-type:" << type;
		return -1;
	}
	std::shared_ptr<Automobile> aTemp =
			std::make_shared<Automobile>(type, make, model, odometer, year);

	cout << "Auto added with ID: " << aTemp->aID << endl;
	aMap.insert(std::make_pair(aTemp->aID, aTemp));
	return aTemp->aID;

}

bool Tracker::removeAuto(int aID) {

	return aMap.erase(aID);
}

void Tracker::listAuto() {

	cout << "List Auto: "<< endl;
	for (const auto& kv : aMap) {
		cout << *(kv.second);
	}
}

void Tracker::listServices(int aID) {

	auto it = aMap.find(aID);
	if(it != aMap.end())
		it->second->printServices();
	else
		cout << "Invalid service:" << aID;

}

bool Tracker::nowServe(int aID, detail::Services type) {

	auto it = aMap.find(aID);
	if(it != aMap.end()){
		it->second->nowService(type);
		return true;
	}
	else{
		cout << "Invalid service:" << aID;
		return false;
	}
}

void Tracker::printTtree() const {

	std::shared_ptr<bTree> mapTree = std::make_shared<bTree>();
	std::shared_ptr<bTree> aTree;

	for (const auto& kv : aMap) {
		aTree = kv.second->getAtree();
		mapTree->push_back(std::make_pair(boost::lexical_cast<std::string>(kv.first), *aTree));
	}

	boost::property_tree::write_json("AutoGarage.json", *mapTree);
}

} /* namespace tracker */
