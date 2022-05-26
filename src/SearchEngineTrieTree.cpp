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

SearchEngineTrieTree::SearchEngineTrieTree(std::string file_name) : SearchEngine(file_name) {
    EngInStream ifs(file_name);
    std::string str;
    while (ifs >> str) {
//        ++_tree[str];
        _tree.Insert(file_name[3]-'0', str);
    }
}

int SearchEngineTrieTree::Search(std::string str) {
//    return _tree[str];
    return _tree.Search(1,str);
}