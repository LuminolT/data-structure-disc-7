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

SearchEngineRBTree::SearchEngineRBTree(std::vector<std::string> file_names)
    : SearchEngine(file_names) {
    for (int i = 0; i < file_names.size(); ++i) {
        EngInStream ifs(file_names[i]);
        std::string str;
        while (ifs >> str) {
            auto &tmp = _map[str];
            if (tmp.empty()) {
                tmp.resize(file_names.size());
            }
            ++tmp[i];
        }
    }
}

std::vector<std::pair<std::string, int>> SearchEngineRBTree::SearchAll(std::string word) {
    auto &nums = _map[word];
    std::vector<std::pair<std::string, int>> ret;
    for (int i = 0; i < nums.size(); ++i) {
        ret.emplace_back(std::make_pair(_fileNames[i], nums[i]));
    }
    return ret;
}