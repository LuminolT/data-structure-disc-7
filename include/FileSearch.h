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

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>

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
     * @brief Get the Search Engine object
     *
     * @param type
     * @param file_names
     * @return std::shared_ptr<SearchEngine>
     */
    static std::shared_ptr<SearchEngine> GetSearchEngine(SearchEngineType type,
                                                         std::vector<std::string> file_names);
    /**
     * @brief
     *
     * @param se
     * @param is
     * @param os
     */
    static void Run(std::shared_ptr<SearchEngine> se, std::istream& is = std::cin,
                    std::ostream& os = std::cout);

    static void TestBenchMark(std::istream& is = std::cin, std::ostream& os = std::cout);
};

#endif  // INCLUDE_FILE_SEARCH_H