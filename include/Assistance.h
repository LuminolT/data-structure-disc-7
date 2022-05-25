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
const int MaxSize = 1000;		//文章单词最大容量
const char* file1 = "1.txt";	//待检索文件
const char* file2 = "2.txt";	//待检索文件
static int sum = 0;     		//单词总数(不重复)

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

int StatisticalWord(string word);	//统计文章词频(去掉重复单词)
int  WordTransitionKey(string word);	//将单词转换为唯一关键码


#endif // !_HEAD_H

