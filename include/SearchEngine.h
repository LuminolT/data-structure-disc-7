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

#include "EngStream.h"

class SearchEngine {
public:
    // Constructor
    SearchEngine(std::string file_name) : _fileName(file_name) {}

    // Copy Constructor
    SearchEngine(const SearchEngine& other) = default;

    // Move Constructor
    SearchEngine(SearchEngine&& other) = default;

    // Destructor
    virtual ~SearchEngine() = default;

    /**
     * @brief Search Method
     *
     * @return int
     */
    virtual int Search(std::string) = 0;

    virtual std::string Name() { return _fileName; }

protected:
    std::string _fileName;
};

#endif  // INCLUDE_SEARCH_ENGINE_H