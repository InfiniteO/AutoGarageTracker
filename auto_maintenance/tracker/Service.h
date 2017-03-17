/*
 * Service.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include "detail.h"

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
typedef boost::property_tree::ptree bTree;

namespace tracker{
class Service {

protected:
	bool status = false;
	double invoice = 0.0;
public:
	Service() = default;
	static std::shared_ptr<Service> factoryService(detail::Services choice);
	virtual void doService() = 0;
	std::string printStatus() const;
	virtual std::ostream& dump(std::ostream& os) const{ return os << "Service: " << printStatus();}
	double getInvoice() const;
	std::shared_ptr<bTree> getStree() const;
	virtual ~Service() = default;

};

/*
 * Stand-alone operator overloading function,
 * which call a overridden virtual function: dump
 */
std::ostream & operator<<(std::ostream & os, const Service & s);

}
#endif /* SERVICE_H_ */
