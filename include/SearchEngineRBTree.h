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

#include "SearchEngine.h"

class SearchEngineRBTree : public SearchEngine {
public:
    // Constructor
    SearchEngineRBTree(std::string file_name);

    // Copy Constructor
    SearchEngineRBTree(const SearchEngine& other);

    // Move Constructor
    SearchEngineRBTree(SearchEngine&& other);

    // Destructor
    virtual ~SearchEngineRBTree() = default;

    /**
     * @brief Search Method
     *
     * @return int
     */
    virtual int Search(std::string) override;

protected:
    std::map<std::string, int> _map;
};

#endif  // INCLUDE_SEARCH_ENGINE_RBTREE_H