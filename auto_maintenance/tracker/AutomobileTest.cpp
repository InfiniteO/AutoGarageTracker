/*
 * AutomobileTest.cpp
 *
 *  Created on: 19-Jan-2017
 *      Author: apple
 */

#include "Automobile.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace tracker;

struct autoFixture
{
	Automobile oAuto;
	autoFixture() : oAuto(detail::ENGINE::PETROL, "Mazda", "Sedan", 20000, 2010)
    {
        BOOST_TEST_MESSAGE("setup Auto");
    }

    ~autoFixture()
    {
        BOOST_TEST_MESSAGE("teardown Auto");
    }
};

BOOST_FIXTURE_TEST_SUITE(tAutomobile, autoFixture)


BOOST_AUTO_TEST_CASE(tnowService)
{
	BOOST_CHECK(true == oAuto.nowService(detail::Services::OIL_CHANGE));
	BOOST_CHECK(true == oAuto.nowService(detail::Services::BLOCK_HEATER_CHK));
	BOOST_CHECK(true == oAuto.nowService(detail::Services::TIRE_ROTATION));

	BOOST_CHECK(false == oAuto.nowService(detail::Services::POWER_CELL_CHK));
	BOOST_CHECK(false == oAuto.nowService(detail::Services::DIESEL_FILTER_CHK));

}

BOOST_AUTO_TEST_CASE(ttotalInvoice)
{
	BOOST_CHECK(true == oAuto.nowService(detail::Services::OIL_CHANGE));
	BOOST_CHECK(true == oAuto.nowService(detail::Services::BLOCK_HEATER_CHK));
	BOOST_CHECK(true == oAuto.nowService(detail::Services::TIRE_ROTATION));

	BOOST_REQUIRE_EQUAL(160.0, oAuto.totalInvoice());
}

BOOST_AUTO_TEST_SUITE_END()



