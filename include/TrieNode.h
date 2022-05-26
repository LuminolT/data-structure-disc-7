//
// Created by gjt20 on 2022/5/26.
//

#ifndef DATA_STRUCTURE_TRIENODE_H
#define DATA_STRUCTURE_TRIENODE_H
#include <vector>
struct TrieNode
{
    std::vector<int>data;
    TrieNode* next[26];
};
#endif  // DATA_STRUCTURE_TRIENODE_H
