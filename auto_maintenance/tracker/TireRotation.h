/*
 * TireRotation.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef TireRotation_H_
#define TireRotation_H_
#include "Service.h"

namespace tracker {

class TireRotation : public Service {
public:
	TireRotation() = default;
	virtual void doService();
	virtual std::ostream& dump(std::ostream& os) const;
	virtual ~TireRotation() = default;
};

} /* namespace tracker */

#endif /* TireRotation_H_ */
