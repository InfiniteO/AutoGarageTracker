/*
 * TireRotation.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "TireRotation.h"

using namespace std;

namespace tracker {

/*TireRotation::TireRotation() {
	// TODO Auto-generated constructor stub

}*/

void TireRotation::doService(){
	if(!status){
		cout << "Tire Rotated" << endl;
		status = true;
		invoice = 50.0;
		return;
	}
	else{
		cout << "Tire Rotated already!" << endl;
	}
}

ostream& TireRotation::dump(ostream& os) const{
	return os << "	TireRotation: " << printStatus() << endl;
}

/*TireRotation::~TireRotation() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace tracker */
