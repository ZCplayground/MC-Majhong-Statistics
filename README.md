# MC-Mahjong

这是福州大学 MC 桌游协会麻将部的面麻数据统计程序。

## 先期面麻数据处理

将 [DataProcess.h](https://github.com/ZCplayground/MC-Majhong-Statistics/blob/master/MC-Mahjong/MC-Mahjong/DataProcess.h) 内代码适当修改、编译后运行。

可以将参与人员 ID 及点棒处理成适合输入的形式（加空格、算第四人点棒等）。

可参考[数据处理过程](https://github.com/ZCplayground/MC-Majhong-Statistics/tree/master/%E6%95%B0%E6%8D%AE%E5%A4%84%E7%90%86%E8%BF%87%E7%A8%8B)。

## 面麻数据统计整理

将 [Mahjong.h](https://github.com/ZCplayground/MC-Majhong-Statistics/blob/master/MC-Mahjong/MC-Mahjong/Mahjong.h) 与 [main.cpp](https://github.com/ZCplayground/MC-Majhong-Statistics/blob/master/MC-Mahjong/MC-Mahjong/Mahjong.h) 编译后运行。控制台程序。

### 输入：

一场面麻数据为一行。四个人的 `ID 点棒` 顺序排列，无序排序，中间用空格隔开。例如：

~~~
伊利亚 50300 yuyu 22500 畅畅 23900 紫嫣 3300
妄想 6900 畅畅 5800 yuyu 44600 梨花 42700
~~~

### 输出：

`data.txt`中，列出所有比赛的编号，从一位到四位依次列出 ID 和得点：

~~~
No.1: 1.伊利亚(+48.3) 2.畅畅(-2.1) 3.yuyu(-11.5) 4.紫嫣(-34.7) 
No.2: 1.yuyu(+42.6) 2.梨花(+16.7) 3.妄想(-27.1) 4.畅畅(-32.2) 
~~~

在输入过的 ID ，生成 `ID.txt` 文件，内容是输入的每场比赛，此为 ID 顺位、得点，以及其余三人的得点（仿照天凤），例如在生成的 `畅畅.txt` 文件中：

~~~
2位 畅畅(-2.1) 伊利亚(+48.3) yuyu(-11.5) 紫嫣(-34.7) 
4位 畅畅(-32.2) yuyu(+42.6) 梨花(+16.7) 妄想(-27.1) 
~~~

## 技术统计

 `技术统计.txt` 内容： ID 以及常规统计内容（仅由点棒数据所能产生的数据）

~~~
L22
总场次: 105 top 率: 0.171 连对率：0.419 末位率：0.257 平均顺位：2.524 

noname
总场次: 34 top 率: 0.176 连对率：0.353 末位率：0.441 平均顺位：2.912 

yuyu
总场次: 68 top 率: 0.250 连对率：0.515 末位率：0.221 平均顺位：2.456 

白
总场次: 15 top 率: 0.400 连对率：0.467 末位率：0.133 平均顺位：2.267 

畅畅
总场次: 73 top 率: 0.315 连对率：0.548 末位率：0.192 平均顺位：2.329 
~~~

## TODO

查重、查错处理

- 查重：去掉重复的面麻数据（不同一局多输入）
- 查错：四人点棒之和不为 10W 点。

以下看看下赛季要不要填坑：

1. 重构成支持.exe的命令行，更加易用。写完整文档。
2. 或者用python重写。
3. 看看怎么结合下前端的图表，可视化展示网站上。
---

by 畅畅

2018-02-06

 
