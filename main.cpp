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

#include <fstream>
#include <functional>
#include <iostream>

#include "EngStream.h"
#include "FileSearch.h"

int main() {
    std::vector<std::string> file_names = {"1.txt", "2.txt"};
    auto se = FileSearch::GetSearchEngine(SearchEngineType::TrieTree, file_names);

    std::ifstream ifs("test.in");
    std::ofstream ofs("test.out");
    FileSearch::Run(se, ifs);

    // Benchmark Test
    // FileSearch::TestBenchMark();

    return 0;
}