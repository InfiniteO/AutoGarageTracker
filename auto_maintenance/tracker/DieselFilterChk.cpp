/*
 * DieselFilterChk.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "DieselFilterChk.h"

using namespace std;

namespace tracker {

/*DieselFilterChk::DieselFilterChk() {
	// TODO Auto-generated constructor stub

}*/

void DieselFilterChk::doService(){
	if(!status){
		cout << "Diesel Filter Checked" << endl;
		invoice = 20.0;
		status = true;
		return;
	}
	else{
		cout << "Diesel Filter Checked already!" << endl;
	}
}

ostream& DieselFilterChk::dump(ostream& os) const{
	return os << "	DieselFilterChk: " << printStatus() << endl;
}

/*DieselFilterChk::~DieselFilterChk() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace tracker */
