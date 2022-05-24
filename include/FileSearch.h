/**
 * @file FileSearch.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_FILE_SEARCH_H
#define INCLUDE_FILE_SEARCH_H

#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>

#include "SearchEngine.h"

enum class SearchEngineType { RBTree, HashMap, TrieTree, ACAutomaton };

/**
 * @brief File Search System
 *
 */
class FileSearch {
public:
    /**
     * @brief Search
     *
     * @param file_name
     * @return SearchEngine
     */
    // static SearchEngine SearchByRBTree(SearchEngineType type, std::string file_name);

    /**
     * @brief
     *
     * @param is
     * @param os
     */
    static void RunTest(std::istream& is = std::cin, std::ostream& os = std::cout);
};

#endif  // INCLUDE_FILE_SEARCH_H