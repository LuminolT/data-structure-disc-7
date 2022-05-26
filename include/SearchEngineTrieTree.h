/**
 * @file SearchEngineTrieTree.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_SEARCH_ENGINE_TRIE_TREE_H
#define INCLUDE_SEARCH_ENGINE_TRIE_TREE_H

#include "SearchEngine.h"

class SearchEngineTrieTree : public SearchEngine {
public:
    // Constructor
    SearchEngineTrieTree(std::string file_name);

    // Copy Constructor
    SearchEngineTrieTree(const SearchEngine& other);

    // Move Constructor
    SearchEngineTrieTree(SearchEngine&& other);

    // Destructor
    virtual ~SearchEngineTrieTree() = default;

    /**
     * @brief Search Method
     *
     * @return int
     */
    virtual int Search(std::string) override;

protected:
    TrieTree _tree;
};

#endif  // INCLUDE_SEARCH_ENGINE_TRIE_TREE_H
