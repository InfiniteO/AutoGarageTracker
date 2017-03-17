/*
 * OilChange.cpp
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#include "OilChange.h"

using namespace std;

namespace tracker{
/*OilChange::OilChange() {
	// TODO Auto-generated constructor stub

}*/

void OilChange::doService(){
	cout << "Oil Changed" << endl;
	status = true;
	invoice = 100.0;
	return;
}

ostream& OilChange::dump(ostream& os) const{
	return os << "	OilChange: " << printStatus() <<endl;
}

/*OilChange::~OilChange() {
	// TODO Auto-generated destructor stub
}*/

}/* namespace tracker */
