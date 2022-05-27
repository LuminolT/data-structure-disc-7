/**
 * @file SearchEngine.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_SEARCH_ENGINE_H
#define INCLUDE_SEARCH_ENGINE_H

#include <string>
#include <vector>

#include "EngStream.h"

class SearchEngine {
public:
    // Constructor
    SearchEngine(std::vector<std::string> file_names) : _fileNames(file_names) {}

    // Copy Constructor
    SearchEngine(const SearchEngine& other) = default;

    // Move Constructor
    SearchEngine(SearchEngine&& other) = default;

    // Destructor
    virtual ~SearchEngine() = default;

    /**
     * @brief SearchAll
     *
     * @param word
     * @return std::vector<std::pair<std::string, int>>
     */
    virtual std::vector<std::pair<std::string, int>> SearchAll(std::string word) = 0;

protected:
    std::vector<std::string> _fileNames;
};

#endif  // INCLUDE_SEARCH_ENGINE_H