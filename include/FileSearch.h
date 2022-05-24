/**
 * @file FileSearch.h
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_FILE_SEARCH_H
#define INCLUDE_FILE_SEARCH_H

#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>

class FileSearch {
public:
    /**
     * @brief RBTree Method
     *
     * @param is
     * @param os
     */
    static void SearchByRBTree(std::istream& is, std::ostream& os);

    /**
     * @brief Hash Map Method
     *
     * @param is
     * @param os
     */
    static void SearchByHashMap(std::istream& is, std::ostream& os);

    /**
     * @brief Trie Tree Method
     *
     * @param is
     * @param os
     */
    static void SearchByTrieTree(std::istream& is, std::ostream& os);

    /**
     * @brief AC Automaton Method
     *
     * @param is
     * @param os
     */
    static void SearchByACAutomaton(std::istream& is, std::ostream& os);

    /**
     * @brief
     *
     * @param is
     * @param os
     */
    static void RunTest(std::istream& is = std::cin, std::ostream& os = std::cout);
};

#endif  // INCLUDE_FILE_SEARCH_H