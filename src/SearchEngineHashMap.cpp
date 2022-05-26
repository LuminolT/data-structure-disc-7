/**
 * @file SearchEngineHashTab.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SearchEngineHashTab.h"

SearchEngineHashTab::SearchEngineHashTab(std::string file_name) : SearchEngine(file_name) {
    EngInStream ifs(file_name);
    std::string str;
    while (ifs >> str) {
        ++_map[str];
    }
}

int SearchEngineHashTab::Search(std::string str) { return _map[str]; }