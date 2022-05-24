/**
 * @file EngStream.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_ENGSTREAM_H
#define INCLUDE_ENGSTREAM_H

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <istream>

class EngInStream {
public:
    // Constructor
    EngInStream(std::string file_name) {
        _flag = true;
        _ifs.open(file_name);
    }

    // Copy Constructor
    EngInStream(const EngInStream& other) = delete;

    // Move Constructor
    EngInStream(EngInStream&& other) = delete;

    // Destructor
    ~EngInStream() = default;

    EngInStream& operator>>(std::string& str);

    operator bool() { return _flag; }

protected:
    std::ifstream _ifs;
    bool _flag;
};

#endif  // INCLUDE_ENGSTREAM_H