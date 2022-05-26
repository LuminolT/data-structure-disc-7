/**
 * @file main.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <ostream>

// #include "SearchEngineTrieTree.h"
#include "SearchEngineRBTree.h"
#include "SearchEngineTrieTree.h"
#include "include/EngStream.h"
#include "include/FileSearch.h"
#include "include/SearchEngineHashMap.h"
// #include "include/SearchEngineRBTree.h"

int main() {
    // FileSearch::RunTest();
    // EngInStream ifs("1.txt");
    // std::string str;
    // while (ifs >> str) {
    //     std::cout << str << std::endl;
    // }
    SearchEngineRBTree se({"1.txt", "2.txt"});
    auto ret = se.SearchAll("it");
    for (auto &p : ret) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}