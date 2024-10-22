# [tmux复习](https://www.ruanyifeng.com/blog/2019/10/tmux.html)

Tmux是一个终端复用器(terminal multipexer), 非常有用，属于常用的开发工具。

# 一、Tmux是什么？

## 1.1会话与进程

命令行的典型方式是，打开一个终端窗口(termianl window)，以下称为"窗口"，在里面输入命令。用户与计算机的这种临时交互，称为一次"会话(session)"

会话的一个重要特点是，窗口与其中启动的进程是连接在一起的。打开窗口，会话开始；关闭窗口，会话结束。

一个典型的例子就是，SSH远程登录计算机，打开一个远程窗口执行命令。这时，网络中断了，再次登录的时候，是找不回上一次执行的命令的。因为上一次SSH会话已经终止了。里面的进程也随之消失了。

## 1.2 Tmux的作用

Tmux就是会话与窗口的解绑工具，将他们彻底分离。

（1）它允许在单个窗口中，同时访问多个会话。这对于同时运行多个命令行程序很有用。

（2） 它可以让新窗口"接入"已经存在的会话。

（3）它允许每个会话有多个连接窗口，因此可以多人实时共享会话。

（4）它还支持窗口任意的垂直和水平拆分。

# 基本用法

## 2.1安装

## 2.2启动与退出

## 2.3 前缀键


Tmux 窗口有大量的快捷键。所有快捷键都要通过前缀键唤起。默认的前缀键是 `Ctrl+b`，即先按下 `Ctrl+b`，快捷键才会生效。

举例来说，帮助命令的快捷键是 `Ctrl+b ?`。它的用法是，在 Tmux 窗口中，先按下 `Ctrl+b`，再按下 `?`，就会显示帮助信息。

然后，按下 ESC 键或 `q`键，就可以退出帮助。

# 会话管理

## 3.1 新建会话

> tmux new -s `<session-name>`

## 3.2 分离会话

> tmux detach

## 3.3 接入会话

> tmux attach -t <session_name>

## 3.4 杀死会话

> tmux kill-session -t `<session-name>`

## 3.5 切换会话

> tmux switch -t `<session-name>`

## 3.6 重命名会话

> tmux rename-session -t `<old-session-name> <new-name>`

## 会话快捷键

* `Ctrl+b d`：分离当前会话。
* `Ctrl+b s`：列出所有会话。
* `Ctrl+b $`：重命名当前会话。

# 窗口操作

## 5.1 划分窗口

> tmux split-window
>
> tmux split-window -h

## 5.2 移动光标

> tmux select-pane -U
>
> tmux select-pane -D
>
> tmux select-pane -L
>
> tmux select-pane -R

## 5.3 交换窗格位置

> tmux swap-pane -U
>
> tmux swap-pane -D

## 5.4 窗格快捷键

* `Ctrl+b %`：划分左右两个窗格。
* `Ctrl+b "`：划分上下两个窗格。
* `Ctrl+b <arrow key>`：光标切换到其他窗格。`<arrow key>`是指向要切换到的窗格的方向键，比如切换到下方窗格，就按方向键 `↓`。
* `Ctrl+b ;`：光标切换到上一个窗格。
* `Ctrl+b o`：光标切换到下一个窗格。
* `Ctrl+b {`：当前窗格与上一个窗格交换位置。
* `Ctrl+b }`：当前窗格与下一个窗格交换位置。
* `Ctrl+b Ctrl+o`：所有窗格向前移动一个位置，第一个窗格变成最后一个窗格。
* `Ctrl+b Alt+o`：所有窗格向后移动一个位置，最后一个窗格变成第一个窗格。
* `Ctrl+b x`：关闭当前窗格。
* `Ctrl+b !`：将当前窗格拆分为一个独立窗口。
* `Ctrl+b z`：当前窗格全屏显示，再使用一次会变回原来大小。
* `Ctrl+b Ctrl+<arrow key>`：按箭头方向调整窗格大小。
* `Ctrl+b q`：显示窗格编号。
