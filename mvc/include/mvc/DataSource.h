/*
 * DataSource.h
 *
 *  Created on: Aug 3, 2015
 *      Author: pavel
 */

#ifndef MVC_INCLUDE_MVC_DATASOURCE_H_
#define MVC_INCLUDE_MVC_DATASOURCE_H_

#include <list>
#include <cstddef>

namespace mvc {

class DataSink;

class DataSource {
public:
    DataSource();
    virtual ~DataSource();

    void addSink(DataSink*);
    void removeSink(DataSink*);
    void notifyAll();

    size_t sinksCount() const;

private:
    std::list<DataSink*> _sinks;
};

} /* namespace mvc */

#endif /* MVC_INCLUDE_MVC_DATASOURCE_H_ */
