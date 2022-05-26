/**
 * @file TrieTree.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_TRIE_TREE_H
#define INCLUDE_TRIE_TREE_H

#include <iostream>
#include <string>
#include <vector>

class TrieTree {
public:
    // TODO
    TrieTree();

    // TODO
    ~TrieTree();

    /**
     * @brief TODO: Insert Node:
     *
     * @param num
     * @param word
     */
    void Insert(int num, const std::string& word);

    /**
     * @brief TODO: Remove Node (if needed):
     *
     * @param num
     * @param word
     */
    void Remove(int num, const std::string& word);

    /**
     * @brief TODO: Search Node
     *
     * @param num
     * @param word
     * @return std::vector<int> (frequency)
     */
    std::vector<int> SearchAll(const std::string& word);

    /**
     * @brief TODO: Search Node
     *
     * @param num
     * @param word
     * @return int
     */
    int Search(int num, const std::string& word);

protected:
    // if needed
};

#endif  // INCLUDE_TRIE_TREE_H