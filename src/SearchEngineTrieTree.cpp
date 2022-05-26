/**
 * @file SearchEngineTrieTree.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SearchEngineTrieTree.h"

SearchEngineTrieTree::SearchEngineTrieTree(std::vector<std::string> file_names)
    : SearchEngine(file_names) {
    for (int i = 0; i < file_names.size(); ++i) {
        EngInStream ifs(file_names[i]);
        std::string str;
        while (ifs >> str) {
            _tree.Insert(i, str);
        }
    }
}

std::vector<std::pair<std::string, int>> SearchEngineTrieTree::SearchAll(std::string word) {
    std::vector<std::pair<std::string, int>> ret;
    auto nums = _tree.SearchAll(word);
    for (int i = 0; i < _fileNames.size(); ++i) {
        ret.emplace_back(std::make_pair(_fileNames[i], nums[i]));
    }
    return ret;
}