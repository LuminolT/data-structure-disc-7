#include"Assistance.h"
#ifndef _HASHTABLE_H
#define _HASHTABLE_H


//统计文章词频
int StatisticalWord(string word)
{
    for (int i = 0; i < MaxSize; i++)
    {
        if (WF[i].word == word)
        {
            WF[i].frequency++;
            return i;
        }
    }
    WF[sum].word = word;
    WF[sum].frequency = 1;
    WF[sum].key = WordTransitionKey(word);
    sum++;
    return 0;
}

//词频统计
void StatisticsData(const char*file)
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
        }	//if
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

void Clear()
{
    for (int i = 0; i < MaxSize; i++)
    {
        WF[i].word = '0';

    }
}

//将单词转换为唯一关键码
int  WordTransitionKey(string word) {
    int a[21] = { 0,2,3,5,7,11,13,17,19,23,27,29,31,37,41,47,51,67,87,101,111 };
    int sumkey = 0;
    for (int i = 0; i < int(word.size()); i++) {
        sumkey += int(word[i]);
    }
    sumkey += int('h') * a[int(word.size())];
    return sumkey;
}

//链地址法哈希表类
class HashTableLink {
public:
    HashTableLink();	//构造函数
    ~HashTableLink();	//析构函数
    int Insert(datatype fword);	//插入
    Node* Search(string word);	//查找

private:
    int H(int k);
    Node* ht[MaxSize];
};

//构造函数
HashTableLink::HashTableLink() {
    for (int i = 0; i < MaxSize; i++)
        ht[i] = NULL;
}

//析构函数，释放空间
HashTableLink :: ~HashTableLink() {
    Node* p = NULL, * q = NULL;
    for (int i = 0; i < MaxSize; i++) {
        p = ht[i];
        q = p;
        while (p != NULL) {
            p = p->next;
            delete q;
            q = p;
        }
    }
}

//除留余数法-散列函数
int HashTableLink::H(int k) {
    return k % MaxSize;
}


//查找函数
Node* HashTableLink::Search(string word) {
    int k = WordTransitionKey(word);
    int j = H(k);
    Node* p = ht[j];
    while (p != NULL) {
        if (p->data.word == word)
            return p;
        else
            p = p->next;
    }
    return nullptr;
}

//插入函数
int HashTableLink::Insert(datatype fword) {
    int k = WordTransitionKey(fword.word);
    fword.key = k;
    int j = H(k);
    Node* p = Search(fword.word);
    if (p != nullptr)
        return -1;
    else {
        p = new Node;
        p->data.key = fword.key;
        p->data.frequency = fword.frequency;
        p->data.word = fword.word;
        p->next = ht[j];
        ht[j] = p;
        return 1;
    }
}


//链地址法哈希查找菜单
void LinkHashWordLocateMenu(string word,const char* file)
{
    int tem = 0;
    string a;
    string b;
    HashTableLink HT;
    for (int i = 0; i < sum; i++)
        HT.Insert(WF[i]);
    double load_factor = sum / MaxSize;


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

        HT.Search(a);
        Node* p = HT.Search(a);
        HT.Search(b);
        Node* q = HT.Search(b);

        if (p != NULL && q!=NULL)
        {
            cout << file << " " << p->data.frequency <<"+"<< q->data.frequency << endl;
        }
        Clear();
    }

    else
    {
        HT.Search(word);
        Node* p = HT.Search(word);

        if (p != NULL)
        {
            cout << file << " " << p->data.frequency << endl;
        }
        Clear();
    }
}

#endif


