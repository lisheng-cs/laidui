# GDB调试技巧

已经学习了基础的调试技巧，还没来得及记笔记


根据搜索结果，以下是一份GDB调试教程的概览：

### 1. GDB简介

GDB（GNU Debugger）是一个由GNU开源组织发布的、在UNIX/LINUX操作系统下的基于命令行的程序调试工具，对于Linux下的C/C++程序员来说，GDB是必不可少的工具。

### 2. GDB安装教程

- **检查是否安装GDB**：

  ```shell
  rpm -qa | grep gdb
  ```

  如果已安装，可以使用以下命令卸载：
  ```shell
  rpm -e --nodeps [软件版本]
  ```
- **下载GDB源码包**：

  ```shell
  wget http://mirrors.ustc.edu.cn/gnu/gdb/gdb-7.9.1.tar.xz
  ```
- **解压GDB源码包**：

  ```shell
  tar -xf gdb-7.9.1.tar.xz
  ```
- **安装GDB**：

  ```shell
  cd gdb-7.9.1
  sudo yum install texinfo
  ./configure
  make
  sudo make install
  ```

  安装成功后，可以通过 `gdb --version`来检查GDB的版本。

### 3. GDB入门操作

- **创建测试代码**：编写一个简单的C/C++程序作为测试代码。
- **启动GDB**：

  ```shell
  gdb test
  ```

  或者不打印版本信息：
  ```shell
  gdb -q test
  ```
- **设置断点**：

  ```shell
  b [行号]  # 在指定行设置断点
  b [函数名]  # 在指定函数设置断点
  ```
- **运行程序**：

  ```shell
  run  # 运行程序，遇到断点时停下
  ```
- **单步执行**：

  ```shell
  next  # 单步执行，不进入函数内部
  step  # 单步执行，进入函数内部
  ```
- **查看变量**：

  ```shell
  print [变量名]  # 打印变量的值
  ```
- **退出GDB**：

  ```shell
  quit  # 退出GDB
  ```

### 4. GDB基本使用命令

- **查看源码**：
  ```shell
  list [行号]  # 查看特定行号的源码
  list [函数名]  # 查看特定函数的源码
  ```
- **查看断点信息**：
  ```shell
  info break  # 查看所有断点信息
  ```
- **删除断点**：
  ```shell
  delete [断点编号]  # 删除特定编号的断点
  delete  # 删除所有断点
  ```
- **查看运行信息**：
  ```shell
  backtrace  # 查看函数调用栈
  frame [帧编号]  # 切换到特定帧编号的栈帧
  ```

这些是GDB调试的基本操作和命令，通过这些步骤和命令，你可以开始使用GDB进行程序调试。

# Docker

正在学习ing....
