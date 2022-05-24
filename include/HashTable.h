#include"Assistance.h"
#ifndef _HASHTABLE_H
#define _HASHTABLE_H
//主菜单
void MajorMenu()
{
    system("cls");	//清屏
    cout << "基于哈希表的查找" << endl;
    HashMenu();
}

// 读取TXT内容并整理
//统计文章词频(去掉重复单词)
int StatisticalWord(string word) {
    for (int i = 0; i < MaxSize; i++) {	//循环控制，单词查重
        if (WF[i].word == word) {	//单词重复
            WF[i].frequency++;	//词频+1
            return i;	//退出函数
        }	//if
    }	//for
    //单词不重复
    WF[sum].word = word;	//添加单词
    WF[sum].frequency = 1;	//词频置为一
    WF[sum].key = WordTransitionKey(word);	//添加关键码
    sum++;	//单词总数+1
    return 0;
}

//大写英语单词转化成小写
string WordTransition(string word) {
    for (int i = 0; i < int(word.size()); i++) {	//获取字符串长度，使用length()也可以
        if (word[i] >= 'A' && word[i] <= 'Z')	//判断字符是否是大写字母
            word[i] = word[i] + 32;	//ASCII码表中十进制 A==65  a==97  中间相差32，后面的也是如此
    }	//for
    return word;	//返回小写单词
}

//判断单词中是否有大写字母
int WordJudge(string word) {
    for (int i = 0; i < int(word.size()); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')	//判断单词中是否有大写字母
            return 1;	//如果有，返回1
    }	//for
    return 0;	//没有返回0
}

//词频统计
void StatisticsData() {
    system("cls");	//清屏
    ifstream fin;	//文件读操作，存储设备读取到内存中
    fin.open(file);	//关联文件file
    char ch;	//用于获取字符
    string word;	//用于存放单词
    int count = 0, min;	//count用于标记单词个数，min用于标记最小的单词
    for (int i = 0; fin.get(ch); i++) {	//读取文件内容，并去除符号
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (word == "\0")	//word为空，放入第一个字母
                word = ch;
            else
                word += ch;	//word不为空，拼接字母组成单词
        }	//if
        else {
            if (word != "\0") {	//判断之前的word里面是否有单词
                count++;	//有单词，总数+1
                if (count > MaxSize) {
                    cout << "文章单词超出统计上限，系统已退出" << endl;
                    fin.close();	//关闭文件
                    exit(0);	//退出程序
                    system("pause");	//暂停
                }
                StatisticalWord(word);	//存放到结构体数组里面
            }	//if
            word = "\0";	//重置word，用于存放新单词
        }	//else
    }	//for
    //按照词典排序（选择排序） 从小到大
    WordFrequency temp;	//临时存储空间
    for (int i = 0; i < sum; i++) {
        min = i;	//重置min
        for (int j = i + 1; j < sum; j++) {
            if (WordTransition(WF[j].word) < WordTransition(WF[min].word))	//将单词转换成小写进行比较
                min = j;	//得到最小单词序号
        }	//for
        //交换原始单词，词频
        temp = WF[i];
        WF[i] = WF[min];
        WF[min] = temp;
    }	//for
    for (int i = 0; i < sum; i++) {
        min = i;
        for (int j = i + 1; j < sum; j++) {
            if (WordTransition(WF[j].word) == WordTransition(WF[min].word))	//两个单词相等
                if (WordJudge(WF[j].word) > WordJudge(WF[min].word))	//大写的排前面
                    min = j;	//得到最小单词序号
        }	//for
        //交换原始单词,词频
        temp = WF[i];
        WF[i] = WF[min];
        WF[min] = temp;
    }	//for
    fin.close();	//关闭文件
}

//将单词转换为唯一关键码
int  WordTransitionKey(string word) {
    int a[21] = { 0,2,3,5,7,11,13,17,19,23,27,29,31,37,41,47,51,67,87,101,111 };	//最长识别20个字母的的单词
    int sumkey = 0;
    for (int i = 0; i < int(word.size()); i++) {
        sumkey += int(word[i]);	//每个字符的ASCLL值相加
    }
    sumkey += int('h') * a[int(word.size())];
    return sumkey;
}



//开放地址哈希表类
class HashTable {
public:
    HashTable();	//构造函数，初始化空散列表
    ~HashTable() {};	//析构函数
    int Insert(datatype a);	//插入
    int Search(string word);	//查找
    datatype Get(int a);
    void Print();	//输出
private:
    int H(int k);	//哈希函数(散列函数)
    datatype ht[MaxSize];	//散列表
};

//构造函数
HashTable::HashTable() {
    for (int i = 0; i < MaxSize; i++) {
        ht[i].key = 0;	//关键码初始化
        ht[i].word = "";
        ht[i].frequency = 0;	// 0表示该散列单元为空
    }	//for
}

//哈希函数，除留余数法
int HashTable::H(int k) {
    return k % MaxSize;
}

//输出函数
void HashTable::Print() {
    system("cls");	//清屏
    ofstream fout;	//文件写操作 内存写入存储设备
    fout.open("outfile5.txt");	//打开文件
    fout << "单词总数为：" << sum << endl;
    fout << "词频" << "\t" << "单词" << endl;
    for (int i = 0; i < sum; i++) {
        fout << WF[i].frequency << "\t" << WF[i].word << endl;
        cout << WF[i].frequency << "\t" << WF[i].word << endl;

    }	//for
    system("pause");	//暂停
}

//查找函数
int HashTable::Search(string word) {
    int key = WordTransitionKey(word);	//将单词转化为关键码
    int i = H(key);	//计算散列地址，设置比较的起始位置
    while (ht[i].key != 0) {
        if (ht[i].word == word)
            return i;         //查找成功
        else
            i = (i + 1) % MaxSize;	//向后探测一个位置
    }	//while
    return 0;	//查找失败
}

//插入函数
int HashTable::Insert(datatype f_word_key) {
    int key = WordTransitionKey(f_word_key.word);//将单词转化为关键码
    int i = H(key);                        //计算散列地址，设置比较的起始位置
    while (ht[i].key != 0) {	//寻找空的散列单元
        i = (i + 1) % MaxSize;	//向后探测一个位置
    }	//while
    ht[i].key = key;	//关键码赋值
    ht[i].word = f_word_key.word;	//单词赋值
    ht[i].frequency = f_word_key.frequency;	//词频赋值
    return i;	//返回插入位置
}

//获取单词以及频率
datatype  HashTable::Get(int a) {
    return ht[a];
}



//链地址法哈希表类
class HashTableLink {
public:
    HashTableLink();	//构造函数，初始化开散列表
    ~HashTableLink();	//析构函数，释放同义词子表结点
    int Insert(datatype fword);	//插入
    Node* Search(string word);	//查找
    void Print();	//输出

private:
    int H(int k);	//散列函数
    Node* ht[MaxSize];	//开散列表
};

//构造函数
HashTableLink::HashTableLink() {
    for (int i = 0; i < MaxSize; i++)
        ht[i] = NULL;	//链式存储结构指针置空
}

//析构函数，释放空间
HashTableLink :: ~HashTableLink() {
    Node* p = NULL, * q = NULL;
    for (int i = 0; i < MaxSize; i++) {
        p = ht[i];
        q = p;	//用来储存p
        while (p != NULL) {	//p非空
            p = p->next;	//p后移
            delete q;	//删除q
            q = p;
        }	//while
    }	//for
}

//除留余数法-散列函数
int HashTableLink::H(int k) {
    return k % MaxSize;
}

//输出到屏幕和文本文件outfile6.txt
void HashTableLink::Print() {
    system("cls");	//清屏
    ofstream fout;	//文件写操作 内存写入存储设备
    fout.open("outfile6.txt");	//打开文件
    fout << "单词总数为：" << sum << endl;
    fout << "词频" << "\t" << "单词" << endl;
    for (int i = 0; i < sum; i++) {
        fout << WF[i].frequency << "\t" << WF[i].word << endl;
        cout << WF[i].frequency << "\t" << WF[i].word << endl;

    }	//for
    system("pause");	//暂停
}

//查找函数
Node* HashTableLink::Search(string word) {
    int k = WordTransitionKey(word);	//转化为关键码
    int j = H(k);	//计算散列地址
    Node* p = ht[j];	//指针p初始化
    while (p != NULL) {	//p非空
        if (p->data.word == word)
            return p;	//已找到返回指针
        else
            p = p->next;	//p后移
    }	//while
    return nullptr;	//未找到返回空指针
}

//插入函数(前插法)
int HashTableLink::Insert(datatype fword) {
    int k = WordTransitionKey(fword.word);	//转化为关键码
    fword.key = k;	//给关键码赋值
    int j = H(k);	//计算散列地址
    Node* p = Search(fword.word);	//调用查找函数
    if (p != nullptr)	//p非空，表示该内容已经插入过了
        return -1;	//已存在元素k，无法插入
    else {	//p为空，表示该内容未插入
        p = new Node;	//生成新节点
        p->data.key = fword.key;	//关键码赋值
        p->data.frequency = fword.frequency;	//词频赋值
        p->data.word = fword.word;	//单词赋值
        p->next = ht[j];	//新节点插入ht[j]
        ht[j] = p;	//更新节点
        return 1;	//插入成功标志
    }
}

//哈希表菜单
void HashMenu() {
    while (true) {
        system("cls");	//清屏
        cout << "---哈希表---" << endl;
        cout << "1.开放地址法哈希查找" << endl;
        cout << "2.链地址法哈希查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        int n;
        cin >> n;
        switch (n) {
        case 1:
            OpenHashLocate();	//开放地址法哈希查找
            break;
        case 2:
            LinkHashLocate();	//链地址法哈希查找
            break;
        case 3:
            return;	//退出函数
        default:
            cout << "输入的不是有效符号，请重新输入" << endl;
            system("pause");
        }	//switch
    }	//while
    return;
}

//开放地址法哈希查找菜单
void OpenHashLocateMenu() {
    HashTable HT;
    for (int i = 0; i < sum; i++)
        HT.Insert(WF[i]);	//把数据插入到哈希表中
    double bulkfactor = sum / MaxSize;	//装填因子
    system("cls");	//清屏
    cout << "---开放地址单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    auto start = system_clock::now();	//开始时间
    int i = HT.Search(word);	//获取散列地址
    duration<double> diff = system_clock::now() - start;	//现在时间 - 开始时间
    if (i) {
        cout << "此单词为：" << HT.Get(i).word << endl;
        cout << "此单词的词频：" << HT.Get(i).frequency << endl;
        cout << "查找该单词所花费的时间：" << (diff.count()) * 1000 << "毫秒" << endl;
        cout << "平均查找长度：" << (1 + 1 / (1 - bulkfactor)) / 2 << endl;
    }	//if
    else
        cout << "查找失败" << endl;
    system("pause");	//暂停
}

//开放地址法哈希查找
void OpenHashLocate() {
    HashTable HT;
    for (int i = 0; i < sum; i++)
        HT.Insert(WF[i]);	//把数据插入到哈希表中
    while (true) {
        system("cls");	//清屏
        cout << "---基于开放地址法的哈希查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        int n;
        cin >> n;
        switch (n) {
        case 1:
            HT.Print(); //词频统计
            break;
        case 2:
            OpenHashLocateMenu();	//开放地址法的哈希查找菜单
            break;
        case 3:
            return;
        default:
            cout << "输入的不是有效符号，请重新输入" << endl;
            system("pause");	//暂停
        }	//switch
    }	//while
}

//链地址法哈希查找
void LinkHashLocate() {
    HashTableLink HT;
    for (int i = 0; i < sum; i++)
        HT.Insert(WF[i]);	//把数据插入到哈希表
    while (true) {
        system("cls");	//清屏
        cout << "---基于链地址法的哈希查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        int n;
        cin >> n;
        switch (n) {
        case 1:
            HT.Print(); //词频统计
            break;
        case 2:
            LinkHashWordLocateMenu();	//单词查找菜单
            break;
        case 3:
            return;	//退出函数
        default:
            cout << "输入的不是有效符号，请重新输入" << endl;
            system("pause");	//暂停
        }	//switch
    }	//while
}

//链地址法哈希查找菜单
void LinkHashWordLocateMenu() {
    HashTableLink HT;
    for (int i = 0; i < sum; i++)
        HT.Insert(WF[i]);	//把数据插入到哈希表
    double load_factor = sum / MaxSize;//散列表的装填因子
    system("cls");
    cout << "---链地址单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    auto start = system_clock::now();	//开始时间
    HT.Search(word);
    duration<double> diff = system_clock::now() - start;	//现在时间 - 开始时间
    Node* p = HT.Search(word);	//返回目标指针
    if (p != NULL) {
        cout << "此单词为：" << p->data.word << endl;
        cout << "此单词的词频：" << p->data.frequency << endl;
        cout << "查找该单词所花费的时间：" << (diff.count()) * 1000 << "毫秒" << endl;
        cout << "平均查找长度：" << 1 + (load_factor) / 2 << endl;
    }	//if
    else
        cout << "查找失败" << endl;
    system("pause");	//暂停
}

#endif


