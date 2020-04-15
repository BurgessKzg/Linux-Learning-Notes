> &emsp;&emsp;声明：如果涉及侵权，请联系本人删除侵权内容。  
> &emsp;&emsp;声明：本文由本人以以往工作经验为依据，总结而得，如果错误，欢迎指正，便于后人参考，少走弯路。  

> 在开发过程中经常需要交叉编译，这就会面临如下问题：
>   - 直接用"gcc"、"g++"、"arm-gcc"、"arm-g++"编译需要每次敲命令行，太繁琐；
>   - 不同的编译工具："gcc"、"g++"、"arm-gcc"、"arm-g++"，不同的文件类型：".c"和".cpp"，写四个Makefile处理需要在使用时区分，还是繁琐；
>   - 用一个Makefile来处理，需要优化，优化如下。

# 1. 共用处理

> &emsp;&emsp;共用的变量，标志放在开始位置

```Makefile
    TARGET := App   #1

    LOCAL_LDFLAGS := -lpthread  #2
    LOCAL_LDFLAGS += -W

    MAP_FILE_NAME := $(TARGET)  #3
    LOCAL_LDFLAGS += -Wl,-Map=./$(MAP_FILE_NAME).map
```
- #1：定义终极目标为：APP
- #2：添加链接选项到：LOCAL_LDFLAGS
- #3：实现".map"文件生成

# 2. 分支处理

> &emsp;&emsp;分支处理可以用两种方式实现，我采用第二种

- 方式一：
```Makefile
ifeq ()
    # 分支一
endif
ifeq ()
    # 分支二
endif
ifeq ()
    # 分支三
endif
ifeq ()
    # 分支四
endif
```

- 方式二：
```Makefile
ifeq ()
    # 分支一
else ifeq ()
    # 分支二
else ifeq ()
    # 分支三
else ifeq ()
    # 分支四
endif
```

## 2.1. x86_gcc分支

> 这个分支的应用场景：
>   - 编译工具：gcc
>   - 编译文件类型：.c

```Makefile
    # x86_gcc ###################################################
    ifeq ($(tool),x86_gcc)  #1
    SRCS := $(shell ls *.c) #2
    OBJS := $(patsubst %.c,%.o,$(SRCS)) #3

    CC := gcc   #4

    $(TARGET) : $(OBJS) #5
        $(CC) -o $@ $^ $(LOCAL_LDFLAGS)

    %.o:%.c
        $(CC) -c -o $@ $< $(LOCAL_LDFLAGS)
```
- #1：`make tool=`中给`tool`赋值`x86_gcc`；
- #2：获取源文件
- #3：转换目标文件
- #4：确定编译工具
- #5：编译

## 2.2. x86_g++分支

> 这个分支的应用场景：
>   - 编译工具：g++
>   - 编译文件类型：.cpp

```Makefile
    # x86_g++ ###################################################
    else ifeq ($(tool),x86_g++) #1

    SRCS := $(shell ls *.cpp)   #2
    OBJS := $(patsubst %.cpp,%.o,$(SRCS))   #3

    CC := g++   #4

    $(TARGET) : $(OBJS) #5
        $(CC) -o $@ $^ $(LOCAL_LDFLAGS)

    %.o:%.cpp
        $(CC) -c -o $@ $< $(LOCAL_LDFLAGS)
```
- #1：`make tool=`中给`tool`赋值`x86_g++`；
- #2：获取源文件
- #3：转换目标文件
- #4：确定编译工具
- #5：编译

## 2.3. arm_gcc分支

> 这个分支的应用场景：
>   - 编译工具：arm-gcc
>   - 编译文件类型：.c

```Makefile
    # arm_gcc ###################################################
    else ifeq ($(tool),arm_gcc) #1

    SRCS := $(shell ls *.c) #2
    OBJS := $(patsubst %.c,%.o,$(SRCS)) #3

    CC := /usr/local/gcc-3.4.6-glibc-2.3.3/bin/aarch32-linux-gnu-gcc    #4

    $(TARGET) : $(OBJS) #5
        $(CC) -o $@ $^ $(LOCAL_LDFLAGS)

    %.o:%.c
        $(CC) -c -o $@ $< $(LOCAL_LDFLAGS)
```
- #1：`make tool=`中给`tool`赋值`arm_gcc`；
- #2：获取源文件
- #3：转换目标文件
- #4：确定编译工具
- #5：编译

## 2.4. arm_g++分支

> 这个分支的应用场景：
>   - 编译工具：arm-g++
>   - 编译文件类型：.cpp

```Makefile
# arm_g++ ###################################################
    else ifeq ($(tool),arm_g++) #1

    SRCS := $(shell ls *.cpp)   #2
    OBJS := $(patsubst %.cpp,%.o,$(SRCS))   #3

    CC := /usr/local/gcc-3.4.6-glibc-2.3.3/bin/aarch32-linux-gnu-g++    #4

    $(TARGET) : $(OBJS) #5
        $(CC) -o $@ $^ $(LOCAL_LDFLAGS)

    %.o:%.cpp
        $(CC) -c -o $@ $< $(LOCAL_LDFLAGS)
    endif
```
- #1：`make tool=`中给`tool`赋值`arm_g++`；
- #2：获取源文件
- #3：转换目标文件
- #4：确定编译工具
- #5：编译

# 3. 优化

## 3.1. 参数错误

> 由于这个Makefile要实现四个分支，需要通过"tool"的值来判断，传错参数的情况发生的概率比较高，所以加入以下内容来判断参数是否错误：

```Makefile
    ifneq ($(tool),)    #1
    .PHONY : PARAERROR  #2
    PARAERROR :
        @echo "Error : Parameters error."   #3
        @exit   #4
    endif
```
- #1：经过之前的分支判断，如果"tool"不为空，说明参数传错；
- #2：定义伪目标，便于添加命令；
- #3：显示错误提示；
- #4：退出；
- 该代码段必须放到"分支"之后，"参数空"判断前；

## 3.2. 参数空

> 后续会添加".clean"处理，如果不加参数空判断，会使得使用"make"时执行".clean"的命令，体验不好，处理如下：

```Makefile
ifeq ($(1),)    #1
.PHONY : PARAEMPTY  #2
PARAEMPTY :
	@echo "Error : Please enter parameters."    #3
	@exit   #4
endif
```
- #1：判断参数是否为空；
- #2：定义伪目标；
- #3：显示提示信息；
- #4：退出
- 该代码段必须放到伪目标".clean"之前；

## 3.3. 伪目标.clean

> 添加伪目标，方便删除编译结果，便于重新编译，实现如下：

```Makefile
    PHONY : clean
    clean :
        -rm -f $(TARGET) $(MAP_FILE_NAME).map *.o
```

# 4. 编译

> &emsp;&emsp;如果直接应用当前的makefile，每次编译需要使用如下中的一个指令，需要在命令行输入参数，还是有点不方便：

```Shell
    make tool=x86_gcc   # 用于编译分支一
    make tool=x86_g++   # 用于编译分支二
    make tool=arm_gcc   # 用于编译分支三
    make tool=arm_g++   # 用于编译分支四
```

> &emsp;&emsp;为了再方便一点，做如下处理：

- 1. 在用户家目录的".bashrc"文件尾添加如下内容：
    ```Shell
        alias makexc='make tool=x86_gcc'
        alias makex+='make tool=x86_g++'
        alias makeac='make tool=arm_gcc'
        alias makea+='make tool=arm_g++'
        alias makecl='make clean'
    ```
- 2. 命令行执行`source ~/.bashrc`，重新加载该文件；
- 3. 接下来可以在终端直接输入"makexc"、"makex+"、"makeac"、"makea+"、"makecl"命令来分别执行"make tool=x86_gcc" 、"make tool=x86_g++"、"make tool=arm_gcc"、"make tool=arm_g++"、"make clean"命令。

# 5. 备注

- 需要用到其他编译选型(-D、-std=c++11...)可自行添；
- makefile中的"ifeq ()"中间需要一个空格；
- makefile中命令开始必须是一个"tab"；
- 这里的交叉编译工具链是胡诌的，实际按照自己使用的修改；
- 命令前加"@"表示不回显命令；
- 命令前加"-"表示出错继续向下处理。