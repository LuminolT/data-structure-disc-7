#ifndef _HEAD_H
#define _HEAD_H

#include<iostream>
#include<thread>
#include<fstream>
#include<string>
#include<ctime>
#include<cmath>
#include<Windows.h>
using namespace std;
using namespace chrono;	//使用命名空间chrono

//常量
const int MaxSize = 1000;	//文章单词最大容量
const char* file = "file.txt";	//待检索文件
static int sum = 0;	//单词总数(不重复)

// 结构体

// 词频顺序存储结构
struct WordFrequency {	//词频
    string word;	//单词
    int frequency;	//频率
    int key;	//关键码
}WF[MaxSize];

typedef WordFrequency datatype;	//为数据类型定义一个新的名字

//词频链式存储结构
struct Node {
    datatype data;	//数据域
    Node* next;	//指针域
};

//二叉排序树链式存储结构
struct BiNode {
    datatype data;	//节点数据域
    BiNode* lchild, * rchild;	//左右孩子指针
};

//ReadFile函数声明
int StatisticalWord(string word);	//统计文章词频(去掉重复单词)
string WordTransition(string word);	//大写英语单词转化成小写
int WordJudge(string word);	//判断单词中是否有大写字母
void StatisticsData();	//数据统计
int  WordTransitionKey(string word);	//将单词转换为唯一关键码

//HashTableMenu函数声明
void HashMenu();	//哈希表菜单
void OpenHashLocateMenu();	//开放地址法哈希查找菜单
void OpenHashLocate();	//开放地址法哈希查找
void LinkHashLocate();	//链地址法哈希查找
void LinkHashWordLocateMenu();	//开放地址法哈希查找菜单

void MajorMenu();	//主菜单


#endif // !_HEAD_H

