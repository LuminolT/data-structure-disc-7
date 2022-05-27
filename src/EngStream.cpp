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

#include <stdio.h>

#include <cctype>
#include <iostream>

EngInStream& EngInStream::operator>>(std::string& str) {
    if (_ifs.eof()) {
        _flag = false;
        return *this;
    }
    // get english string and to lower
    _ifs >> str;

    for (auto& c : str) {
        c = tolower(c);
    }

    // delete special charactors
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return !isalpha(c); }),
              str.end());

    return *this;
}