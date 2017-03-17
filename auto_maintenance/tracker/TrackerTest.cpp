/*
 * TrackerTest.cpp
 *
 *  Created on: 19-Jan-2017
 *      Author: apple
 */

#include "Tracker.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE tTracker
#include <boost/test/unit_test.hpp>

using namespace tracker;

struct tracFixture
{
	Tracker oTrac;
	tracFixture() : oTrac()
    {
        BOOST_TEST_MESSAGE("setup Tracker");
    }

    ~tracFixture()
    {
        BOOST_TEST_MESSAGE("teardown Tracker");
    }
};

BOOST_FIXTURE_TEST_SUITE(tTracker, tracFixture)


BOOST_AUTO_TEST_CASE(tAddRemove)
{
	BOOST_CHECK_GE(oTrac.addAuto(detail::ENGINE::PETROL, "Mazda", "Sedan", 20000, 2010), 1);
	BOOST_CHECK(false == oTrac.removeAuto(-1));

}

BOOST_AUTO_TEST_CASE(tnowServe)
{
	BOOST_CHECK_GE(oTrac.addAuto(detail::ENGINE::PETROL, "Mazda", "Sedan", 20000, 2010), 1);

	BOOST_CHECK(false == oTrac.nowServe(-1, detail::Services::OIL_CHANGE));
}

BOOST_AUTO_TEST_SUITE_END()



