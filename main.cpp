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
        fin.open(file);//关联文件file
        if (!fin.is_open()) {
            cout << "file.txt文件不存在，请检查文件名或者目录下文件是否存在。" << endl;
            system("pause");	//暂停
            return 0;
        }	//if
        StatisticsData();	//数据统计
        MajorMenu();//主菜单
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


