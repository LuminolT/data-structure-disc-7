/**
 * @file main.cpp
 * @Author : Luminolt (copper_sulfate@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */


#include <HashTable.h>
#include <ostream>
#include "include/EngStream.h"
#include "include/FileSearch.h"
#include "include/SearchEngineRBTree.h"

    //int main() {
    // FileSearch::RunTest();
    // EngInStream ifs("1.txt");
    // std::string str;
    // while (ifs >> str) {
    //     std::cout << str << std::endl;
    // }
    //SearchEngineRBTree se("1.txt");
    //std::cout << se.Name() << std::endl;
    //std::cout << se.Search("it") << std::endl;
#include "HashTable.h"				// 散列表类

    int main(void)
    {
        ifstream fin;
        string word;
        const char* file1 = "1.txt";
        const char* file2 = "2.txt";
        fin.open(file1);
        fin.open(file2);
        if (!fin.is_open())
        {
            cout << "not exited" << endl;
            system("pause");
            return 0;
        }
        cout << "暂时为输入tuichu结束" << endl;
        while(word!="tuichu")
        {
            cin >> word;
            StatisticsData(file1);
            OpenHashLocateMenu(word,file1);
            StatisticsData(file2);
            OpenHashLocateMenu(word,file2);
        }

        return 0;


       /* else
            if ((k = ht.Search(x)) == 1)
            a=a+1;
            cout<<a<<endl;
            cout<<k<<endl;
        */
   system("PAUSE");
        return 0;
    }


