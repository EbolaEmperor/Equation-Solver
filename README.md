# 解方程工具

### 简介

该工具可以得到一些简单方程的近似解

目前仅支持五大基本运算符，解的范围不得超过1e8

### 代码结构

- **analyze.h**：表达式解析。用于求出将x代入后某个表达式的值
- **algo.cpp**：算法核心。使用模拟退火算法得到方程的近似解
- **main.py**：UI界面。用于工具的可视化

### 使用方法

先根据你的系统，在下面选择一个版本进行下载

- [Linux-64bit](https://github.com/EbolaEmperor/Equation-Solver/raw/master/Release/Linux_64bit.zip)
- [Windows-32bit](https://github.com/EbolaEmperor/Equation-Solver/raw/master/Release/Windows_64bit.zip)

解压后运行可执行文件Equation-Solver即可

如果使用Linux系统，请给解压后的两个文件授予可执行权限

### 源码编译方法

先编译algo.cpp，然后运行main.py
