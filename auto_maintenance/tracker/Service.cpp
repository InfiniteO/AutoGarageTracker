/*
 * Service.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "Service.h"

#include "OilChange.h"
#include "BlockHeaterChk.h"
#include "DieselFilterChk.h"
#include "PowerCellChk.h"
#include "TireRotation.h"

#include <memory>

namespace tracker{
/*Service::Service() {
	// TODO Auto-generated constructor stub

}*/

std::shared_ptr<Service> Service::factoryService(detail::Services choice) {
	switch(choice){
	case detail::Services::OIL_CHANGE: return std::make_shared<OilChange>(); break;
	case detail::Services::TIRE_ROTATION: return std::make_shared<TireRotation>(); break;
	case detail::Services::BLOCK_HEATER_CHK: return std::make_shared<BlockHeaterChk>(); break;
	case detail::Services::DIESEL_FILTER_CHK: return std::make_shared<DieselFilterChk>(); break;
	case detail::Services::POWER_CELL_CHK: return std::make_shared<PowerCellChk>(); break;
	default: return nullptr;
	}
}

std::string Service::printStatus() const{
 if (status){
	 return "*** Completed, invoice: " + std::to_string(invoice)  + " ***";
 }
 else{
	 return "*** Pending ***";
 }
}

std::ostream & operator<<(std::ostream & os, const Service & s){
	return s.dump(os);
}

double Service::getInvoice() const {
	return invoice;
}

std::shared_ptr<bTree> Service::getStree() const {
	std::shared_ptr<bTree> sTree = std::make_shared<bTree>();
	sTree->put("status", status);
	sTree->put("invoice", invoice);
	return sTree;
}

} /* namespace tracker */

