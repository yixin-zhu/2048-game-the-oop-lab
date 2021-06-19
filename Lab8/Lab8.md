# 面向对象程序设计
## Lab8运行说明   
#### 朱奕新 19307090029
***
### 编译运行环境
Windows 10

mingw32

gcc version 9.2.0 

***

### 如何编译和运行程序

1. 把所有源代码文件保存到本地。

2. 将所有源代码文件保存到同一文件夹中

3. 在命令行下进入此文件夹

4. 输入g++ main.cpp -o game.exe 并回车来编译。也可以取其他文件名。

     为节省时间，本文件夹下已有一个编译好的game.exe文件。因此可以跳过本步。

5. 运行游戏

普通游戏模式：输入game.exe(或上一步自定的其他名字) 并加上参数再加回车，之后按指令开始游戏即可。

可用参数      

-s 2(或3、4、5)  决定地图大小

-p 打开奖励模式

-log打开日志模式

单步模拟模式：输入game.exe -i 61.in（或其他输入文件的名字） -o 61.out（或其他指定输出文件的名字）再加回车。即可在指定输出文件里得到相应输出。

