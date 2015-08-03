/*
 * DataSink.h
 *
 *  Created on: Aug 3, 2015
 *      Author: pavel
 */

#ifndef MVC_INCLUDE_MVC_DATASINK_H_
#define MVC_INCLUDE_MVC_DATASINK_H_

namespace mvc {

class DataSource;

class DataSink {
public:
    DataSink();
    virtual ~DataSink();

    virtual void update();

    void setDataSource(DataSource*);

private:
    DataSource* _source = nullptr;
};

} /* namespace mvc */

#endif /* MVC_INCLUDE_MVC_DATASINK_H_ */
