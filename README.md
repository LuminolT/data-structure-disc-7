# 文件搜索



[问题描述]

多个由英文单词构成的文本文件，需要查询某个或某些单词出现在哪些文件中以及出现的频率。

测试数据可使用超星平台课程资料中data目录下的tale.txt、leipzig100k.txt、leipzig300k.txt、leipzig1m.txt 。

[输入]

被查询的单词。对于多个单词组合查询，单词之间使用“+”连接。

[输出]

包含被查询单词的文件名，以及在该文件中出现的频率。

 

假设文件1.txt: It was the best of times, it was the worst of times.

文件2.txt: It was the age of wisdom, it was the age of foolishness.

[输入样例]

```
it
times
it+age
```

[输出样例]

```
it
1.txt 2
2.txt 2
times
1.txt 2
it+age
2.txt 2+2
```