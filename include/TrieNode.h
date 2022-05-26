/**
 * @file TrieNode.h
 * @Author : Olivanpa
 * @brief
 * @version 0.1
 * @date 2022-05-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DATA_STRUCTURE_TRIENODE_H
#define DATA_STRUCTURE_TRIENODE_H
#include <vector>

/**
 * @brief Trie Node Class
 *
 */
struct TrieNode {
    TrieNode() { next.resize(26); }

    ~TrieNode() {
        for (auto &node : next) {
            delete node;
        }
    }

    std::vector<int> data;
    std::vector<TrieNode *> next;
};
#endif  // DATA_STRUCTURE_TRIENODE_H
