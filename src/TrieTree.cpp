/**
 * @file TrieTree.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "TrieTree.h"

TrieTree::TrieTree() { root = new TrieNode; }

TrieTree::~TrieTree() { delete root; }

void TrieTree::Insert(int num, const std::string& word) {
    TrieNode* now = root;
    for (auto letter : word) {
        int go = letter - 'a';
        if (now->next[go] == nullptr)
            now->next[go] = new TrieNode();
        now = now->next[go];
    }
    while (now->data.size() <= num)
        now->data.push_back(0);
    now->data[num]++;
    //    std::cout<<word<<" "<<now->data[1]<<std::endl;
}

void TrieTree::Remove(int num, const std::string& word) {
    TrieNode* now = root;
    for (auto letter : word) {
        int go = letter - 'a';
        now = now->next[go];
    }
    if (now->data[num] > 0)
        now->data[num]--;
}

std::vector<int> TrieTree::SearchAll(const std::string& word) {
    TrieNode* now = root;
    for (auto letter : word) {
        int go = letter - 'a';
        if (now->next[go] == nullptr) {
            std::vector<int> v;
            return v;
        }
        now = now->next[go];
    }
    return now->data;
}

int TrieTree::Search(int num, const std::string& word) {
    TrieNode* now = root;
    for (auto letter : word) {
        int go = letter - 'a';
        if (now->next[go] == nullptr)
            return 0;
        now = now->next[go];
    }
    return now->data[num];
}
