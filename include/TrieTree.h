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

class TrieTree {
public:
    // TODO
    TrieTree();

    // TODO
    ~TrieTree();

    // TODO
    void Insert(std::string);

    // TODO (if needed)
    void Remove(std::string);

    // TODO
    int& operator[](std::string);

protected:
    // if needed
};

#endif  // INCLUDE_TRIE_TREE_H