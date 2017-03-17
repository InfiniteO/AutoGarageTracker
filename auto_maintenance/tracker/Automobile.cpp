/*
 * Auto.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "Automobile.h"
#include <iostream>

using namespace std;

namespace tracker{

unsigned short Automobile::currentaID = 1;

Automobile::Automobile(): aID(currentaID++), make(new std::string("UNKNOWN")),  model(new std::string("UNKNOWN")){

}

void Automobile::requestService(detail::Services type){
	sMap.insert(std::make_pair(type, (Service::factoryService(type))));

}
Automobile::Automobile(detail::ENGINE type, std::string make, std::string model, long odometer, int year)
 : aID(currentaID++), make(make_shared<std::string>(make)), model(make_shared<std::string>(model)){

	this->type = type;
	this->odometer = odometer;
	this->year = year;

	switch(type){
	case detail::ENGINE::PETROL:
		requestService(detail::Services::OIL_CHANGE);
		requestService(detail::Services::BLOCK_HEATER_CHK);
		requestService(detail::Services::TIRE_ROTATION);
		break;

	case detail::ENGINE::DIESEL:
		requestService(detail::Services::OIL_CHANGE);
		requestService(detail::Services::BLOCK_HEATER_CHK);
		requestService(detail::Services::TIRE_ROTATION);
		requestService(detail::Services::DIESEL_FILTER_CHK);
		break;

	case detail::ENGINE::ELECTRIC:
		requestService(detail::Services::TIRE_ROTATION);
		requestService(detail::Services::POWER_CELL_CHK);
		break;
	case detail::ENGINE::ENGINE_MAX:
		cout << "Automobile::Automobile() error" << endl;
	}

}

bool Automobile::nowService(detail::Services serv) {

	auto it = sMap.find(serv);
	if(it != sMap.end()){
			it->second->doService();
			return true;
	}
	else{
		cout << "Invalid service:" << serv << endl;
		return false;
	}
}

void Automobile::printAuto() const{

	cout << "Auto ID: " << aID << " Type: " << type << " Make: " << *make << " Model: " << *model << " Clicks: " << odometer << " Year: " << year << endl;
}

void Automobile::printServices() const{

	cout << "printServices: Auto ID: " << aID << endl;
	for (const auto& kv : sMap) {
		cout << *(kv.second);
	}
}

ostream& Automobile::dump(ostream& os) const{


	return os << "	Auto ID: " << aID << " Type: " << type  << " Make: " << *make << " Model: " << *model << " Clicks: " << odometer << " Year: " << year << " Total invoice: $" << totalInvoice() <<endl;
}

std::ostream & operator<<(std::ostream & os, const Automobile & a){

	return a.dump(os);
}

double Automobile::totalInvoice() const {

	double totalInvoice = 0.0;

	for (const auto& kv : sMap) {
		totalInvoice += kv.second->getInvoice();
	}
	return totalInvoice;
}

std::shared_ptr<bTree> Automobile::getAtree() const {
	std::shared_ptr<bTree> aTree = std::make_shared<bTree>();
	std::shared_ptr<bTree> mapTree = std::make_shared<bTree>();
	std::shared_ptr<bTree> sTree;
	aTree->put("type", type);
	aTree->put("model", *model);
	aTree->put("make", *make);
	aTree->put("odometer", odometer);
	aTree->put("year", year);
	for (const auto& kv : sMap) {
		sTree = kv.second->getStree();
		//sTree->put("type", kv.first);
		mapTree->add_child(boost::lexical_cast<std::string>(kv.first), *sTree);
	}
	aTree->add_child("Services", *mapTree);
	return aTree;
}

}/* namespace tracker */


