/*
 * DieselFilterChk.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef DIESELFILTERCHK_H_
#define DIESELFILTERCHK_H_
#include "Service.h"

namespace tracker {

class DieselFilterChk  : public Service{
public:
	DieselFilterChk() = default;
	virtual void doService();
	virtual std::ostream& dump(std::ostream& os) const;
	virtual ~DieselFilterChk() = default;
};

} /* namespace tracker */

#endif /* DIESELFILTERCHK_H_ */
