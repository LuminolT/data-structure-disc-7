#include"Assistance.h"
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

// 将单词转换为唯一关键码
int  WordTransitionKey(string word)
{
    int a[21] = { 0,2,3,5,7,11,13,17,19,23,27,29,31,37,41,47,51,67,87,101,111 };
    int sumkey = 0;

    for (int i = 0; i < int(word.size()); i++)
    {
        sumkey += int(word[i]);
    }

    sumkey =sumkey+ int('h') * a[int(word.size())]+int(word[1])-int(word[0]);
    return sumkey;
}


void Clear()
{
    for (int i = 0; i < MaxSize; i++)
    {
        WF[i].word = '0';

    }
}

//统计文章词频
int StatisticalWord(string word)
{
    WF[sum].word = word;
    WF[sum].frequency = 1;
    WF[sum].key = WordTransitionKey(word);
    sum++;
    return 0;
}

//词频统计
void StatisticsData(const char* file)
{
    ifstream fin;
    fin.open(file);
    char ch;
    string word;
    int count = 0, min;
    for (int i = 0; fin.get(ch); i++) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (word == "\0")
                word = ch;
            else
                word += ch;
        }
        else {
            if (word != "\0")
            {
                count++;
                if (count > MaxSize)
                {
                    cout << "文章单词超出统计上限，系统已退出" << endl;
                    fin.close();
                    exit(0);
                    system("pause");
                }
                StatisticalWord(word);
            }
            word = "\0";
        }
    }
    fin.close();
}


class HashTable {
public:
    HashTable();
    ~HashTable() {};
    int Insert(datatype a);
    int Search(string word);
    datatype Get(int a);

private:
    int H(int k);
    datatype ht[MaxSize];
};

//构造函数
HashTable::HashTable() {
    for (int i = 0; i < MaxSize; i++) {
        ht[i].key = 0;
        ht[i].word = "";
        ht[i].frequency = 0;
    }	//for
}

//哈希函数，除留余数法
int HashTable::H(int k) {
    return k % MaxSize;
}


//查找函数
int HashTable::Search(string word)
{
    int x = 0;
    int key = WordTransitionKey(word);
    int i = H(key);
    while (ht[i].key != 0)
    {
        if (ht[i].word == word)
        {
            ht[i].frequency += 1;
            return i;
        }
        else
            i = (i + 1) % MaxSize;
    }
    return 0;
}

//插入函数
int HashTable::Insert(datatype f_word_key) {
    int key = WordTransitionKey(f_word_key.word);
    int i = H(key);
    while (ht[i].key != 0)
    {
        i = (i + 1) % MaxSize;
    }
    ht[i].key = key;
    ht[i].word = f_word_key.word;
    ht[i].frequency = f_word_key.frequency;
    return i;
}

//获取单词以及频率
datatype  HashTable::Get(int a) {
    return ht[a];
}


//开放地址法哈希查找菜单
void OpenHashLocateMenu(string word, const char* file)
{
    int tem = 0;
    string a;
    string b;
    HashTable HT;
    for (int i = 0; i < sum; i++)
        HT.Insert(WF[i]);
    for(int i=0;i<word.length();i++)
    {
        if(word[i]=='+')
        {
            tem = i;
        }
    }

    if(tem!=0)
    {
        for(int i = 0; i < tem; i++)
        {
            a = a + word[i];
        }
        for (int i = tem+1; i < word.length(); i++)
        {
            b = b + word[i];
        }

        int i = HT.Search(a);
        int j = HT.Search(b);
        if (i != NULL && j!=NULL)
        {
            cout << file << " " << HT.Get(i).frequency <<"+"<< HT.Get(j).frequency << endl;
        }
        Clear();
    }

    else
    {
        int i = HT.Search(word);
        if (i)
        {
            cout << file << " " << HT.Get(i).frequency << endl;
        }
        Clear();
    }

}

#endif


