/*
 * detail.h
 *
 *  Created on: 17-Jan-2017
 *      Author: apple
 */

#ifndef DETAIL_H_
#define DETAIL_H_

#if BOOST_OS_WINDOWS
#include <boost/config/compiler/visualc.hpp>
#elif BOOST_OS_LINUX
#include <boost/config/compiler/gcc.hpp>
#elif BOOST_OS_MACOS
#include <boost/config/compiler/gcc.hpp>
#endif

namespace tracker{ namespace detail{
enum ENGINE{PETROL, DIESEL, ELECTRIC, ENGINE_MAX};
enum Services{OIL_CHANGE, TIRE_ROTATION, BLOCK_HEATER_CHK, DIESEL_FILTER_CHK, POWER_CELL_CHK};

}

}/* namespace tracker, detail */

#endif /* DETAIL_H_ */
