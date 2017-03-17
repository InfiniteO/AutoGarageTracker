/*
 * PowerCellAsses.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef POWERCELLCHK_H_
#define POWERCELLCHK_H_
#include "Service.h"

namespace tracker {

class PowerCellChk : public Service {
public:
	PowerCellChk() = default;
	virtual void doService();
	virtual std::ostream& dump(std::ostream& os) const;
	virtual ~PowerCellChk() = default;
};

} /* namespace tracker */

#endif /* POWERCELLCHK_H_ */
