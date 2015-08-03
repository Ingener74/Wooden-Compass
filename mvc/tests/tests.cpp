/*
 * tests.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: pavel
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mvc/DataSource.h"
#include "mvc/DataSink.h"

using namespace std;
using namespace mvc;

TEST(MVC, addSink) {
    DataSource ds;

    DataSink s1;
    ds.addSink(&s1);
    EXPECT_EQ(ds.sinksCount(), 1);

    DataSink s2;
    ds.addSink(&s2);
    EXPECT_EQ(ds.sinksCount(), 2);

    DataSink s3;
    ds.addSink(&s3);
    EXPECT_EQ(ds.sinksCount(), 3);
}

TEST(MVC, removeSink) {
    DataSource ds;

    DataSink s1;
    ds.addSink(&s1);

    DataSink s2;
    ds.addSink(&s2);

    DataSink s3;
    ds.addSink(&s3);

    EXPECT_EQ(ds.sinksCount(), 3);

    ds.removeSink(&s1);
    EXPECT_EQ(ds.sinksCount(), 2);

    ds.removeSink(&s2);
    EXPECT_EQ(ds.sinksCount(), 1);

    ds.removeSink(&s3);
    EXPECT_EQ(ds.sinksCount(), 0);
}

class MockDataSink: public DataSink {
public:
    MOCK_METHOD0(update, void(void));
};

TEST(MVC, update) {
    DataSource ds;
    MockDataSink s1;
    MockDataSink s2;
    ds.addSink(&s1);
    ds.addSink(&s2);

    EXPECT_CALL(s1, update()).Times(1);
    EXPECT_CALL(s2, update()).Times(1);
    ds.notifyAll();
}

