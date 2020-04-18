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
|time()|<time.h>|获取秒数时间；<br>基于新纪元1970。|
|ftime()|<sys/timeb.h>|获取秒数和毫秒数；<br>基于新纪元1970；<br>有些标准已废弃。|
|ctime()族|<time.h>|时间格式转换；<br>asctime(),ctime(),gmtime(),localtime(),mktime()...；<br>基于1900年；<br>不获取时间。|
|gettimeofday()族|<sys/time.h>|操作秒和微妙；<br>基于新纪元1970。|
|clock_gettime()族|<time.h>|操作秒和纳秒；<br>基于新纪元1970年；<br>多用于系统实时、相对、绝对等各类时间统计。|

# 2. 结构体一览表

|结构体|头文件|解释|备注|
|:-|:-|:-|:-|
|time_t|<time.h>|长整型别名|time()使用|
|timeb|<sys/timeb.h>|包含毫秒的结构体|ftime()使用|
|tm|<time.h>|包含夏令时,一年中的哪天,星期几,年,月,日,时,分,秒|ctime族使用,包括asctime(),asctime_r(),gmtime(),gmtime_r(),localtime(),localtime_r(),mktime()|
|timeval|<bits/time.h>|秒和微妙|gettimeofday()族使用|
|timezone|<sys/time.h>|格林威治以西的时间(夏令时)|gettimeofday()族使用|
|clockid_t|<time.h>|整型别名|clock_gettime()族使用|
|timespec|<time.h>|秒和纳秒|clock_gettime()族使用|

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
    //*** /usr/include/sys/timeb.h
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

## 3.3. tm

```C
    //*** /usr/include/time.h
    struct tm {
        int tm_sec;    /* Seconds (0-60) */
        int tm_min;    /* Minutes (0-59) */
        int tm_hour;   /* Hours (0-23) */
        int tm_mday;   /* Day of the month (1-31) */
        int tm_mon;    /* Month (0-11) */
        int tm_year;   /* Year - 1900 */
        int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
        int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
        int tm_isdst;  /* Daylight saving time */
    };
```
- tm_sec：0-60范围内的真实秒值，<font color=red>60？</font>；
- tm_min：0-59范围内的真实分钟值；
- tm_hour：0-23范围内的真实小时值；
- tm_mday：1-31范围内的真实日期日值；
- tm_mon：0-11范围内的真实日期月值；
- tm_year：从1900年开始的年值<font color=red>是1900，不是1970</font>；
- tm_wday：0-6范围内的星期值，0代表周日；
- tm_yday：0-365范围内的一年中的第几天，0代表1月1日；
- tm_isdst：夏令时间

## 3.4. timeval

```C
    //*** /usr/include/bits/time.h
    struct timeval
    {
        __time_t tv_sec;
        __suseconds tv_usec;
    };
```
- tv_sec：秒
- tv_usec：微秒

## 3.5. timezone

```C
    //*** /usr/include/sys/time.h
    struct timezone
    {
        int tz_minuteswest;
        int tz_dsttime;
    };
```
- tz_minuteswest：以格林威治以西的时差，单位为分钟
- tz_dsttime：夏令时非零时有效

## 3.6. clockid_t

```C
    //*** /usr/include/bits/types.h
    #define __S32_TYPE      int

    //*** /usr/include/bits/typesizes.h
    #define __CLOCKID_T_TYPE    __S32_TYPE

    //*** /usr/include/bits/types.h
    __STD_TYPE __CLOCK_T_TYPE __clock_t;

    //*** /usr/include/time.h
    typedef __clockid_t clockid_t;  
```

## 3.7. timespec

```C
    struct timespec {
        time_t   tv_sec;        /* seconds */
        long     tv_nsec;       /* nanoseconds */
    };
```
- tv_sec：秒；
- tv_nsec：纳秒；

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
        /* gcc编译需要struct timeb var格式定义. */
        /* g++编译可以timeb var格式直接定义. */
        #include <stdio.h>
        #include <sys/timeb.h>

        int main(void)
        {
            int m_ulRet = 0;
            struct timeb m_stTimeVal;

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

- POSIX.1-2008删除了ftime()的规范，废弃不用了。

## 4.3. ctime()族

- MAN章节&头文件&定义：
    ```C 
        /* man 3 ctime/asctime/gmtime/localtime/mktime... */ 

        #include <time.h>

       char *asctime(const struct tm *tm);
       char *asctime_r(const struct tm *tm, char *buf);

       char *ctime(const time_t *timep);
       char *ctime_r(const time_t *timep, char *buf);

       struct tm *gmtime(const time_t *timep);
       struct tm *gmtime_r(const time_t *timep, struct tm *result);

       struct tm *localtime(const time_t *timep);
       struct tm *localtime_r(const time_t *timep, struct tm *result);

       time_t mktime(struct tm *tm);      
    ```
- 函数&参数&返回值描述：
    - 函数描述：
    >   - 这个族不会获取时间，而是对已经获取到的时间做格式转换；
    >   - localtime：将time_t类型的时间转换为tm类型本地时间；
    >   - gmtime：将time_t类型的时间转换为tm类型的格林威治(GMT)时间，
    >   - asctime：将tm类型时间转换为字符串型输出；
    >   - ctime：将time_t时间在内部转换成tm时间，并转成字符串输出；
    >   - mktime：将tm类型时间转换成time_t类型；
    >   - 在线程中应该使用对应函数的"_r"模式来处理，来避免线程安全问题；
    - 参数描述：
    >   - const tm*：传入
    >   - char *buf：传出
    >   - const time_t*传入
    - 返回值描述：
    > 根据不同函数功能返回。
- Demo&结果：
    - Demo：
    ```C
        #include <stdio.h>
        #include <time.h>
        #include <string.h> 
        #include <stdlib.h>

        void printTm(const struct tm* tm)
        {
            printf("**%d-%d-%d:%d-%d-%d\n",tm->tm_year+1900,tm->tm_mon+1,\
                    tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);
            printf("**week:%d\n",tm->tm_wday);
            printf("**yday:%d\n",tm->tm_yday);
            printf("**dst:%d\n",tm->tm_isdst);
        }

        int main(void)
        {
            time_t m_tyTimeVal = 0;
            time_t m_tyTimeTempVal = 0;
            struct tm* m_pstTmVal;
            char *m_pucTimeStr;
            
            m_pstTmVal = malloc(sizeof(struct tm));
            m_pucTimeStr = malloc(200);

            printf("******************************** time() ***\n");
            m_tyTimeTempVal = time(NULL);
            printf("**%d\n",(int)m_tyTimeTempVal);
            
            printf("****************************** gmtime() ***\n");
            m_pstTmVal = gmtime(&m_tyTimeTempVal);
            printTm(m_pstTmVal);

            printf("*************************** localtime() ***\n");
            m_pstTmVal = localtime(&m_tyTimeTempVal);
            printTm(m_pstTmVal);
            
            printf("***************************** asctime() ***\n");
            m_pucTimeStr = asctime(m_pstTmVal); 
            printf("**%s",m_pucTimeStr);

            printf("******************************* ctime() ***\n");
            m_pucTimeStr = ctime(&m_tyTimeTempVal);
            printf("**%s",m_pucTimeStr);

            printf("****************************** mktime() ***\n");
            m_tyTimeVal = mktime(m_pstTmVal);
            printf("**%d\n",(int)m_tyTimeVal);
        #if 0
            if(m_pstTmVal)
                free(m_pstTmVal);//Bk?:这里不能free,函数是怎么返回结构体指针的？
            if(m_pucTimeStr)
                free(m_pucTimeStr);
        #endif

            return 0;
        }
    ```
    - 结果：
    ```SHELL
        # ./App 
        ******************************** time() ***
        **206
        ****************************** gmtime() ***
        **1970-1-1:0-3-26
        **week:4
        **yday:0
        **dst:0
        *************************** localtime() ***
        **1970-1-1:8-3-26
        **week:4
        **yday:0
        **dst:0
        ***************************** asctime() ***
        **Thu Jan  1 08:03:26 1970
        ******************************* ctime() ***
        **Thu Jan  1 08:03:26 1970
        ****************************** mktime() ***
        **206
    ```

## 4.4. gettimeofday()族

- MAN章节&头文件&定义：
    ```C
        /* man 2 gettimeofday/settimeofday */

        #include <sys/time.h>

        int gettimeofday(struct timeval *tv, struct timezone *tz);

        int settimeofday(const struct timeval *tv, const struct timezone *tz);
        // settimeofday(): _BSD_SOURCEs //Bk?:未确定用途       
    ```
- 函数&参数&返回值描述：
    - 函数描述：
    >   - gettimeofday：获取时间和时区信息；
    >   - settimeofday：设置时间和时区；
    - 参数描述：
    >   - tv：包含秒和微秒信息，不使用时传NULL，该变量为NULL编译时报警告；
    >   - tz：包含时区和夏令时信息，该参数基本过时(有些系统获取不到值)，常传NULL；
    - 返回值描述：
    > -  0：成功；
    > - -1：失败，并设置errno；
- Demo&结果：
    - Demo：
    ```C
        #include <stdio.h>
        #include <sys/time.h>
        #include <time.h>
        #include <stdlib.h>

        int main(void)
        {
            struct timeval tv;
            system("date");
            gettimeofday(&tv,NULL);
            printf("timeval:%ld.%ld\n\n",tv.tv_sec,tv.tv_usec);
            
            tv.tv_sec = 1587039053;
            tv.tv_usec = 0;
            printf("timeval:%ld.%ld\n\n",tv.tv_sec,tv.tv_usec);
            
            if(settimeofday(&tv,NULL) != 0)
            {
                perror("settimeofday");	
            }
            system("date");
            gettimeofday(&tv,NULL);
            printf("timeval:%ld.%ld\n",tv.tv_sec,tv.tv_usec);
            
            return 0;
        }
    ```
    - 结果：
    ```SHELL
        # ./App 
        Thu Jan  1 08:02:41 CST 1970
        timeval:161.657774

        timeval:1587039053.0

        Thu Apr 16 20:10:53 CST 2020
        timeval:1587039053.2744
    ```
- settimeofday在设置时间的时候，参数很容易出错，导致设置失败；

## 4.5. clock_gettime()族

- MAN章节&头文件&定义：
    ```C     
        /* man 3 clock_getres/clock_gettime/clock_settime */

        #include <time.h>

       int clock_getres(clockid_t clk_id, struct timespec *res);

       int clock_gettime(clockid_t clk_id, struct timespec *tp);

       int clock_settime(clockid_t clk_id, const struct timespec *tp);   
    ```
- 函数&参数&返回值描述：
    - 函数描述：
    >   - clock_getres：检索指定clk_id类型的分辨率；
    >   - clock_gettime：得到指定clk_id类型的时间；
    >   - clock_settime：设置指定clk_id类型的时间；
    - 参数描述：
    >   - clk_id：某种时钟类型
    >       - CLOCK_REALTIME：系统实时时间,随系统实时时间改变而改变；
    >       - CLOCK_MONOTONIC：从系统启动开始计时,不受系统时间被用户改变的影响；
    >       - CLOCK_PROCESS_CPUTIME_ID：本进程在系统CPU中运行的时间；
    >       - CLOCK_THREAD_CPUTIME_ID：本进程在系统CPU中运行的时间。
    >   - tp：时间值
    >   - res：分辨率
    - 返回值描述：
    >   - 0：成功；
    >   - -1：失败，并设置errno。
- Demo&结果：
    - Demo：
    ```C
        #include <stdio.h>
        #include <time.h>

        void printTm(const struct tm* tm)
        {
            printf("**%d-%d-%d:%d-%d-%d\n",tm->tm_year+1900,tm->tm_mon+1,\
                    tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);
            printf("**week:%d\n",tm->tm_wday);
            printf("**yday:%d\n",tm->tm_yday);
            printf("**dst:%d\n",tm->tm_isdst);
        }

        int main(void)
        {
            struct timespec timeVal;

            clock_gettime(CLOCK_REALTIME,&timeVal);
            printf("time:%s\n",ctime(&timeVal.tv_sec));
            printf("time: %ld.%ld\n",timeVal.tv_sec,timeVal.tv_nsec);

            return 0;
        }
    ```
    - 结果：
    ```SHELL
        # ./App 
        time:Thu Jan  1 08:00:23 1970

        time: 23.927505916
    ```

# 5. 其他时间函数

|函数|解释|
|:-|:-|
|clock()|返回程序使用的处理器时间的近似值|
|adjtime()|调整系统时钟|
|adjtimex()|设置David L. Mills的时钟调整算法的调整参数|
|clock_getcpuclockid()||
|pthread_getcpuclockid()||
|timeradd()族|操作timeval类型的两个结构体变量；<br>timeradd()<br>timersub()<br>timerclear()<br>timerisset()<br>timercmp()|
|setitimer()族|为进程提供三种间隔计时器，计时到达给进程发送信号；<br>ITIMER_REAL<br>ITIMER_VIRTUAL<br>ITIMER_PROF|
|timer_create()系列|创建一个间隔计时器<br>相关函数还有：<br>timer_delete()<br>timer_getoverrun()<br>timer_settime<br>timer_gettime|
|timerfd_create()族|创建一个通过文件描述符传递计时器溢出通知的计时器|

# 6. 疑问

- linuxOS能应用的最小时间精度，应用层可以保证的时间精度？
- 验证：printf("%" PRId64"\n",m_tyTimeVal)？
- 格林威治&夏令时&时区？
- POSIX？
- 线程安全？
- 哪些结构体在将来某个时间点就不能使用了(time_t?)？
- ctime族多个函数返回结构体指针，返回的是那个区域(常量?堆区?栈？)？谁释放？
- tm结构体tm_sec成员的值60什么情况下应用？



