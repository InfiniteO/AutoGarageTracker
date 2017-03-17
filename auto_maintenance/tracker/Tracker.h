/*
 * Tracker.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef TRACKER_H_
#define TRACKER_H_

#include "Automobile.h"

namespace tracker {

class Tracker {
private:
	std::map<int, std::shared_ptr<Automobile>> aMap;
public:
	Tracker() = default;
	int addAuto(detail::ENGINE type, std::string make, std::string model, long odometer, int year);
	bool removeAuto(int aID);
	void listAuto();
	void listServices(int aID);
	bool nowServe(int aID, detail::Services type);
	void printTtree() const;
	~Tracker() = default;
};

} /* namespace tracker */

#endif /* TRACKER_H_ */
