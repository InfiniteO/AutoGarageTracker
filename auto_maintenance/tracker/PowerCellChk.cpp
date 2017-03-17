/*
 * PowerCellChk.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "PowerCellChk.h"

using namespace std;

namespace tracker {

/*PowerCellChk::PowerCellChk() {
	// TODO Auto-generated constructor stub

}*/

void PowerCellChk::doService(){
	if(!status){
		cout << "Power Cell Checked" << endl;
		invoice = 30.0;
		status = true;
		return;
	}
	else{
		cout << "Power Cell Checked already!" << endl;
	}
}

ostream& PowerCellChk::dump(ostream& os) const{
	return os << "	PowerCellChk: " << printStatus() << endl;
}

/*PowerCellChk::~PowerCellChk() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace tracker */
