/**
 * @file SearchEngineHashMap.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_SEARCH_ENGINE_HASH_TAB_H
#define INCLUDE_SEARCH_ENGINE_HASH_TAB_H

#include <unordered_map>

#include "SearchEngine.h"

class SearchEngineHashMap : public SearchEngine {
public:
    // Constructor
    SearchEngineHashMap(std::vector<std::string> file_names);

    // Copy Constructor
    SearchEngineHashMap(const SearchEngine& other);

    // Move Constructor
    SearchEngineHashMap(SearchEngine&& other);

    // Destructor
    virtual ~SearchEngineHashMap() = default;

    /**
     * @brief
     *
     * @param word
     * @return std::vector<std::pair<std::string, int>>
     */
    virtual std::vector<std::pair<std::string, int>> SearchAll(std::string word) override;

protected:
    std::unordered_map<std::string, std::vector<int>> _map;
};

#endif  // INCLUDE_SEARCH_ENGINE_HASH_TAB_H