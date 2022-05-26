/**
 * @file FileSearch.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "FileSearch.h"

#include <iostream>

void FileSearch::RunTest(std::istream &is, std::ostream &os) {
    std::vector<std::string> list = {"1.txt", "2.txt"};
    GetSearchEngine(SearchEngineType::RBTree, list);
    std::string str;

    // split str by '+'
    auto split = [](std::string str) -> std::vector<std::string> {
        std::vector<std::string> ret;
        std::string tmp;
        for (auto c : str) {
            if (c == '+') {
                ret.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }
        ret.push_back(tmp);
        return ret;
    };

    while (getline(is, str)) {
        auto words = split(str);
        std::vector<std::vector<std::pair<std::string, int>>> stats;
        for (auto &word : words) {
            stats.emplace_back(_searchEngine->SearchAll(word));
        }
        std::vector<bool> flags(stats[0].size(), false);
        for (int j = 0; j < stats[0].size(); ++j) {
            bool flag = true;
            for (int i = 0; i < stats.size(); ++i) {
                if (stats[i][j].second == 0) {
                    flag = false;
                    break;
                }
            }
            flags[j] = true;
        }
        for (int j = 0; j < stats[0].size(); ++j) {
            if (flags[j]) {
                os << stats[0][j].first;
                for (int i = 0; i < stats.size(); ++i) {
                    os << stats[i][j].second << " ";
                }
                os << std::endl;
            }
        }
    }
}

void FileSearch::GetSearchEngine(SearchEngineType type, std::vector<std::string> file_names) {
    switch (type) {
    case SearchEngineType::RBTree: _searchEngine = new SearchEngineRBTree(file_names); break;
    case SearchEngineType::HashMap: _searchEngine = new SearchEngineHashMap(file_names); break;
    case SearchEngineType::TrieTree: _searchEngine = new SearchEngineTrieTree(file_names); break;
    default: break;
    }
}