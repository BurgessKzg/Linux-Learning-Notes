> &emsp;&emsp;声明：如果涉及侵权，请联系本人删除侵权内容。  
> &emsp;&emsp;声明：本文由本人以以往工作经验为依据，总结而得，如果错误，欢迎指正，便于后人参考，少走弯路。 

> 开发中经常会用到时间，针对不同应用，对时间的需求有所不同：
>   - 时间精度(计时等，秒级、毫秒级、微秒级、纳秒级)；
>   - 时间格式(RTC显示等，年、月、日、时、分、秒的常用不同排列组合)；
>   - 时间计时(周期报文的发送等);
>   - 时间点(闹钟等)；
>   - 时间段(进程运行时间统计等)；

# 1. 函数一览表

|函数|头文件|解释|
|:-|:-|:-|
|time()|<time.h>|返回从新纪元(1970-01-01 00:00:00 +0000(UTC))开始的秒数。|
|ftime()|<sys/timeb.h>|以秒和毫秒的形式返回自新纪元(1970-01-01 00:00:00 +0000 (UTC))以来的当前时间。|
|ctime()族|<time.h>|处理时间和日期的相关函数,包括asctime(),ctime(),gmtime(),localtime(),mktime()等。|
|gettimeofday()族|||
|clock_gettime()族|||
|adjtime()|||
|adjtimex()|||
|clock_getcpuclockid()|||
|pthread_getcpuclockid()|||
|sysconf()|||
|timeradd()族|||
|setitimer()族|||
|timer_create()系列|||
|timerfd_create()族|||

# 2. 结构体一览表

|结构体|头文件|解释|备注|
|:-|:-|:-|:-|
|time_t|<time.h>|长整型(4字节)的别名|time()使用|
|timeb|???|包含毫秒的结构体|ftime()使用|
|tm|???|包含夏令时,一年中的哪天,星期几,年,月,日,时,分,秒|ctime族使用,包括asctime(),asctime_r(),gmtime(),gmtime_r(),localtime(),localtime_r(),mktime()|

# 3. 结构体介绍

## 3.1. time_t

```C
    //*** /usr/include/bits/types.h
    #define __SLONGWORD_TYPE    long int

    //*** /usr/include/bits/typesizes.h
    #define __TIME_T_TYPE       __SLONGWORD_TYPE

    //*** /usr/include/bits/types.h
    __STD_TYPE __TIME_T_TYPE __time_t;/* Seconds since the Epoch. */

    //*** /usr/include/time.h
    typedef __time_t time_t;
```
- 开始计时时间：1970年1月1日0时0分0秒
- 要求该类型表达时间不晚于：2038年1月18日19时14分07秒 

## 3.2. timeb

```C
    struct timeb {
        time_t         time;
        unsigned short millitm;
        short          timezone;
        short          dstflag;
    };
```
- time：存放秒级的值；
- millitm：存放一秒内的毫秒级的值；
- timezone：以格林威治以西的时间分钟为单位度量的本地时区(负值表示格林威治以东的时间分钟)(UTC时间和本地时间的相差分钟数)；
- dstflag：如果非零，是<font color=red>夏令时时间；</font>
- POSIX.1-2001表示:timezone和dstflag字段的内容是未指定的,避免依赖他们。

# 4. 函数介绍

## 4.1. time()

- MAN章节&头文件&定义：
    ```C
        /* man 2 time */

        #include <time.h>

        time_t time(time_t *tloc);
    ```
- 函数&参数&返回值描述：
    - 函数描述：
    > &emsp;&emsp;返回从新纪元(1970-01-01 00:00:00 +0000 (UTC)开始的秒数。
    - 参数描述：
    > &emsp;&emsp;如果tloc非NULL，则返回值也存储在tloc指向的内存中。
    - 返回值描述：
    >   - 成功：返回从新纪元开始的秒数值；
    >   - 失败：返回-1，并设置errno;
- Demo&结果：
    - Demo：
    ```C
        #include <stdio.h>
        #include <time.h>

        int main(void)
        {
            time_t m_tyTimeVal = 0;

            m_tyTimeVal = time(NULL);
            printf("%d\n",(int)m_tyTimeVal);

            return 0;
        }
    ```
    - 结果：
    ```SHELL
        /* 算算什么时间... */
        1587039053
    ```

## 4.2. ftime()

- MAN章节&头文件&定义：
    ```C   
        /* man 3 ftime */  

        #include <sys/timeb.h>

        int ftime(struct timeb *tp);
    ```
- 函数&参数&返回值描述：
    - 函数描述：
    > &emsp;&emsp;以秒和毫秒的形式返回自新纪元(1970-01-01 00:00:00 +0000 (UTC))以来的当前时间。
    - 参数描述：
    > &emsp;&emsp;传出参数，存放获取的时间值。
    - 返回值描述：
    >   - 总是返回0；
    >   - POSIX.1-2001指定在某些系统文档中错误返回-1。
- Demo&结果：
    - Demo：
    ```C
        /* 用gcc编译时找不到timeb，用g++可以. */
        #include <stdio.h>
        #include <sys/timeb.h>

        int main(void)
        {
            int m_ulRet = 0;
            timeb m_stTimeVal;

            m_ulRet = ftime(&m_stTimeVal);
            printf("     ret : %d\n",m_ulRet);
            printf("    time : %d\n"
                " millitm : %d\n"
                "timezone : %d\n"
                " dstflag : %d\n",
                (int)m_stTimeVal.time,
                m_stTimeVal.millitm,
                m_stTimeVal.timezone,
                m_stTimeVal.dstflag);

            return 0;
        }
    ```
    - 结果：
    ```SHELL
             ret : 0
            time : 1587031235
         millitm : 84
        timezone : 0
         dstflag : 0
    ```


## 4.n. timer_create()系列
timer_delete
timer_create
timer_getoverrun
timer_settime&timer_gettime


- <font color=red>time_t对应的printf格式符：PRId64</font>
    ```Cpp 
        /* g++编译时使用"-D__STDC_FORMAT_MACROS -std=c++11" */

        #include <stdio.h>
        #include <stdint.h>
        #include <inttypes.h>

        void TimeTest(void)
        {
            time_t m_tyTimeVal = 0;
            //PRId64前保留一个空格
            printf("%" PRId64"\n",m_tyTimeVal);
        }        
    ```


- linuxOS能应用的最小时间精度？
- 验证：printf("%" PRId64"\n",m_tyTimeVal);
- 夏令时是什么意思？
- POSIX是什么？
- gcc编译ftime.c时找不到timeb结构体？



## 4.

- MAN章节&头文件&定义：
    ```C        
    ```
- 函数&参数&返回值描述：
    - 函数描述：
    >
    - 参数描述：
    >
    - 返回值描述：
    >
- Demo&结果：
    - Demo：
    ```C
    ```
    - 结果：
    ```SHELL
    ```