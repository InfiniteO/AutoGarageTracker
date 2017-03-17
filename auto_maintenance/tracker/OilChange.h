/*
 * OilChange.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef OILCHANGE_H_
#define OILCHANGE_H_

#include "Service.h"

namespace tracker{

class OilChange : public Service{
public:
	OilChange() = default;
	virtual void doService() ;
	virtual std::ostream& dump(std::ostream& os) const;
	virtual ~OilChange() = default;
};

}/* namespace tracker */

#endif /* OILCHANGE_H_ */
