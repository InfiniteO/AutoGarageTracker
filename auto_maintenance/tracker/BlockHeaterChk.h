/*
 * BlockHeaterChk.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef BLOCKHEATERCHK_H_
#define BLOCKHEATERCHK_H_
#include "Service.h"

namespace tracker {

class BlockHeaterChk : public Service{
public:
	BlockHeaterChk() = default;
	virtual void doService();
	virtual std::ostream& dump(std::ostream& os) const;
	virtual ~BlockHeaterChk() = default;
};

} /* namespace tracker */

#endif /* BLOCKHEATERCHK_H_ */
