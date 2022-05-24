/**
 * @file EngStream.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "EngStream.h"

EngInStream& EngInStream::operator>>(std::string& str) {
    if (_ifs.eof()) {
        _flag = false;
    }
    _ifs >> str;
    if (!(str.back() > 'A' && str.back() < 'Z' || str.back() > 'a' && str.back() < 'z')) {
        str.pop_back();
    }
    // to lower
    for (auto& c : str) {
        c = std::tolower(c);
    }
    return *this;
}