/**
 * @file SearchEngineRBTree.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SearchEngineRBTree.h"

#include "EngStream.h"

SearchEngineRBTree::SearchEngineRBTree(std::string file_name) : SearchEngine(file_name) {
    EngInStream ifs(file_name);
    std::string str;
    while (ifs >> str) {
        _set.insert(str);
    }
}

int SearchEngineRBTree::Search(std::string str) { return _set.count(str); }