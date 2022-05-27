/**
 * @file FileSearch.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "FileSearch.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

#include "SearchEngine.h"

void FileSearch::Run(std::shared_ptr<SearchEngine> se, std::istream& is, std::ostream& os) {
    auto _searchEngine = se.get();
    std::string str;

    // split str by '+'
    auto split = [](std::string str) -> std::vector<std::string> {
        std::vector<std::string> ret;
        std::string tmp;
        for (auto c : str) {
            if (c == '+') {
                ret.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }
        ret.push_back(tmp);
        return ret;
    };

    while (getline(is, str)) {
        os << str << std::endl;
        auto words = split(str);
        std::vector<std::vector<std::pair<std::string, int>>> stats;
        for (auto& word : words) {
            stats.emplace_back(_searchEngine->SearchAll(word));
        }
        std::vector<bool> flags(stats[0].size(), true);

        // Notice: Here i is words, j is files
        for (int j = 0; j < stats[0].size(); ++j) {
            bool flag = true;
            for (int i = 0; i < stats.size(); ++i) {
                if (stats[i][j].second == 0) {
                    flag = false;
                    break;
                }
            }
            flags[j] = true && flag;
        }
        for (int j = 0; j < stats[0].size(); ++j) {
            if (flags[j]) {
                os << stats[0][j].first << " ";
                for (int i = 0; i < stats.size() - 1; ++i) {
                    os << stats[i][j].second << "+";
                }
                os << stats.back()[j].second << std::endl;
            }
        }
    }
}

void FileSearch::TestBenchMark(std::istream& is, std::ostream& os) {
    std::vector<std::string> words = {"apple", "people", "night", "of", "a", "an", "period"};

    auto subTest = [&words](std::string file_name) {
        std::cout << ">> " << file_name << std::endl;

        std::cout << std::setw(20) << "word/status";
        std::cout << std::setw(15) << "RBTree(ms)";
        std::cout << std::setw(15) << "HashMap(ms)";
        std::cout << std::setw(15) << "TrieTree(ms)" << std::endl;

        std::cout << std::setw(20) << "Initialization";

        long long duration;
        auto getDuration = [&file_name, &duration](SearchEngineType type) {
            auto start = std::chrono::high_resolution_clock::now();
            auto se = FileSearch::GetSearchEngine(type, {file_name});
            auto end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            return se;
        };

        auto seRB = getDuration(SearchEngineType::RBTree);
        std::cout << std::setw(15) << duration;
        auto seHM = getDuration(SearchEngineType::HashMap);
        std::cout << std::setw(15) << duration;
        auto seTT = getDuration(SearchEngineType::TrieTree);
        std::cout << std::setw(15) << duration << std::endl;

        int number = 0;

        auto getSearchDuration = [&duration, &number](std::shared_ptr<SearchEngine> se,
                                                      std::string word) {
            auto start = std::chrono::high_resolution_clock::now();
            auto res = se.get()->SearchAll(word);
            number = res[0].second;
            auto end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        };

        std::vector<int> numbers;

        for (auto word : words) {
            std::cout << std::setw(20) << word;
            getSearchDuration(seRB, word);
            numbers.emplace_back(number);
            std::cout << std::setw(15) << duration;
            getSearchDuration(seHM, word);
            numbers.emplace_back(number);
            std::cout << std::setw(15) << duration;
            getSearchDuration(seTT, word);
            numbers.emplace_back(number);
            std::cout << std::setw(15) << duration;

            if (numbers[0] == numbers[1] && numbers[1] == numbers[2]) {
                std::cout << "  : Verified (" << number << ")" << std::endl;
            }
            numbers.clear();
        }
    };

    subTest("tale.txt");
    subTest("leipzig100k.txt");
    subTest("leipzig300k.txt");
    subTest("leipzig1m.txt");
}

std::shared_ptr<SearchEngine> FileSearch::GetSearchEngine(SearchEngineType type,
                                                          std::vector<std::string> file_names) {
    switch (type) {
    case SearchEngineType::RBTree: return std::make_shared<SearchEngineRBTree>(file_names);
    case SearchEngineType::HashMap: return std::make_shared<SearchEngineHashMap>(file_names);
    case SearchEngineType::TrieTree: return std::make_shared<SearchEngineTrieTree>(file_names);
    default: return nullptr;
    }
}