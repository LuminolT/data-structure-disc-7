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

#include "include/EngStream.h"
#include "include/FileSearch.h"
#include "include/SearchEngineHashMap.h"
#include "include/SearchEngineRBTree.h"
#include "SearchEngineTrieTree.h"

int main() {
    // FileSearch::RunTest();
    // EngInStream ifs("1.txt");
    // std::string str;
    // while (ifs >> str) {
    //     std::cout << str << std::endl;
    // }
    SearchEngineTrieTree se("../1.txt");
    std::cout << se.Name() << std::endl;
    std::cout << se.Search("my") << std::endl;
    return 0;
}