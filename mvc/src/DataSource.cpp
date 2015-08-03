/*
 * DataSource.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: pavel
 */

#include "mvc/DataSink.h"
#include "mvc/DataSource.h"

namespace mvc {

DataSource::DataSource() {
}

DataSource::~DataSource() {
}

void DataSource::addSink(DataSink* sink) {
    _sinks.push_back(sink);
}

void DataSource::removeSink(DataSink* sink) {
    _sinks.remove(sink);
}

void DataSource::notifyAll() {
    for(auto i: _sinks)
        i->update();
}

size_t DataSource::sinksCount() const {
    return _sinks.size();
}

} /* namespace mvc */
