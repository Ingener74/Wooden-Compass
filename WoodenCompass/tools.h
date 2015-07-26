/*
 * tools.h
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#ifndef WOODENCOMPASS_TOOLS_H_
#define WOODENCOMPASS_TOOLS_H_

#include <memory>
#include <utility>

template<typename T, typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    std::unique_ptr<T> ptr(new T(std::forward<Args>(args)...));
    return ptr;
}

#endif /* WOODENCOMPASS_TOOLS_H_ */
