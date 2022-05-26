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

#include "SearchEngine.h"
#include "SearchEngineHashMap.h"
#include "SearchEngineRBTree.h"
#include "SearchEngineTrieTree.h"

enum class SearchEngineType { RBTree, HashMap, TrieTree };

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
    void GetSearchEngine(SearchEngineType type, std::vector<std::string> file_name);

    /**
     * @brief
     *
     * @param is
     * @param os
     */
    void RunTest(std::istream& is = std::cin, std::ostream& os = std::cout);

protected:
    SearchEngine* _searchEngine;
};

#endif  // INCLUDE_FILE_SEARCH_H