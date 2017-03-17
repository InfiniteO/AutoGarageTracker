/*
 * BlockHeaterChk.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "BlockHeaterChk.h"

using namespace std;

namespace tracker {

/*BlockHeaterChk::BlockHeaterChk() {
	// TODO Auto-generated constructor stub

}*/

void BlockHeaterChk::doService(){
	if(!status){
		cout << "Block Heater Checked" << endl;
		status = true;
		invoice = 10.0;
		return;
	}
	else{
		cout << "Block Heater Checked already" << endl;
	}
}

ostream& BlockHeaterChk::dump(ostream& os) const{
	return os << "	BlockHeaterChk: " << printStatus() << endl;
}

/*BlockHeaterChk::~BlockHeaterChk() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace tracker */
