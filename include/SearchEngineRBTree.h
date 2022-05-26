/**
 * @file SearchEngineRBTree.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_SEARCH_ENGINE_RBTREE_H
#define INCLUDE_SEARCH_ENGINE_RBTREE_H

#include <fstream>
#include <map>
#include <string>

#include "SearchEngine.h"

class SearchEngineRBTree : public SearchEngine {
public:
    // Constructor
    SearchEngineRBTree(std::vector<std::string> file_names);

    // Copy Constructor
    SearchEngineRBTree(const SearchEngine& other);

    // Move Constructor
    SearchEngineRBTree(SearchEngine&& other);

    // Destructor
    virtual ~SearchEngineRBTree() = default;

    /**
     * @brief SearchAll
     *
     * @param word
     * @return std::vector<std::pair<std::string, int>>
     */
    virtual std::vector<std::pair<std::string, int>> SearchAll(std::string word) override;

protected:
    std::map<std::string, std::vector<int>> _map;
};

#endif  // INCLUDE_SEARCH_ENGINE_RBTREE_H