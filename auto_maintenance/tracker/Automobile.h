/*
 * Auto.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include "Service.h"
#include <string>
#include <map>
//#include <boost/scoped_ptr.hpp>

namespace tracker{
class Automobile{

private:
	static unsigned short currentaID;
	detail::ENGINE type{detail::ENGINE::PETROL};
	std::shared_ptr<std::string> make;
	std::shared_ptr<std::string> model;
	int year{1970};
	long odometer{0};
	std::map<int, std::shared_ptr<Service>> sMap;

	void requestService(detail::Services type);
public:
	const unsigned short aID;
	Automobile();
	Automobile(detail::ENGINE type, std::string make, std::string model, long odometer, int year);
	bool nowService(detail::Services serv);
	void printAuto() const;
	virtual std::ostream& dump(std::ostream& os) const;
	void printServices() const;
	double totalInvoice() const;
	std::shared_ptr<bTree> getAtree() const;
	virtual ~Automobile() = default;
};

/*
 * Stand-alone operator overloading function,
 * which call a  member function: dump
 */
std::ostream & operator<<(std::ostream & os, const Automobile & s);

}/* namespace tracker */

#endif /* AUTOMOBILE_H_ */
