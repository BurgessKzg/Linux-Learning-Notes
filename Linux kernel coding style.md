&emsp;&emsp;翻译于：https://www.kernel.org/doc/html/latest/process/coding-style.html#indentation

&emsp;&emsp;对于编码风格，着实体验了一把邯郸学步的感觉。起初的代码风格来源于教程，或者说没有代码风格。后来，就职于不同的公司，发现公司不同，代码编写规范各异。尤其是对于代码风格没有强制要求的公司，部门内部每个人都有自己的风格，见到优秀的学习一下，最后渐渐的发现自己的代码编写规范一直在变，到后来自己看自己之前写的代码都觉得别扭。所以查看了linux内核的编码规范，用于规范自己的代码风格。

# 1. 缩进(Indentation)

- 缩进使用"Tab"键，**固定八个**字符；

- 代码不要超过**三层**缩进；

- switch语句中：
    - "switch"和"case"关键字左对齐；
    - 分支指令一层缩进；
    - "break"关键字与分支指令对齐(不是与"case"关键字左对齐);
        ```C
            switch (suffix) {
            case 'G':
            case 'g':
                    mem <<= 30;
                    break;
            case 'M':
            case 'm':
                    mem <<= 20;
                    break;
            case 'K':
            case 'k':
                    mem <<= 10;
                    fallthrough;
            default:
                    break;
            }
        ```

- 单独一行里不要写多个语句，包括不要把多个赋值语句放在同一行；

- 内核的代码风格是十分简洁的，请尽量避免使用复杂的表达式；

- 除了在注释、文档和Kconfig中，不要使用**空格**作为缩进；

- 不要在**行末**留有空格

# 2. 换行(Breaking long lines and strings)

- 规范代码风格的目的是提高代码的**可读性**和**维护性**；

- 强烈推荐单行的宽度限制为**八十列**；

- 拆分超过八十列宽度的语句为多行：
    - 如果超过八十列的部分可以提高可读性且**不会隐藏信息时**可以**不拆分**；
    - 适用范围：宽度超过八十列的语句或有很长参数列表的函数头；
    - 拆分出的子句长度应该比主句**短**；
    - 拆分出的子句尽量**靠右**；
    - 不要拆分用户可见的字符串(如"printk"的信息，否则会导致使用"grep"时找不到这些信息);

<font color=red><br>

- 疑问：
    - 在编辑器中怎么限制(提醒)单行的宽度为"八十列"？
    - "不会隐藏信息时"指什么？
    - "用户可见的字符串"指什么？
    - "用户可见的字符串"出现了"隐藏信息时"怎么处理？

</font>

# 3. 花括号和空格(Placing Braces and Spaces)

## 3.1. 花括号(大括号)

- 把左括号放在行末，右括号放在行首；

- 适用范围：**非函数**的语句块(if,switch,for,while,do)；

- 函数的左括号应该放在行首；

- 右括号一般单独成一行，除非右括号之后有紧密结合的语句(如：do-while，if-else if-else等)；

    ```
        //情况一：左括号放在行末，右括号放在行首
        if (x is true) {
                we do y
        }

        //情况二：左括号放在行末，右括号放在行首
        switch (action) {
        case KOBJ_ADD:
                return "add";
        case KOBJ_REMOVE:
                return "remove";
        case KOBJ_CHANGE:
                return "change";
        default:
                return NULL;
        }

        //情况三：函数的左括号应该放在行首
        int function(int x)
        {
                body of function
        }

        //情况四：右括号之后有紧密结合的语句
        do {
                body of do-loop
        } while (condition);

        //情况五：右括号之后有紧密结合的语句
        if (x == y) {
                ..
        } else if (x > y) {
                ...
        } else {
                ....
        }
    ```
- 在不降低可读性的前提下尽可能减少**空行**的数量；
    - 单行语句可以完成任务时不要使用括号；
    - 其他"case"有多行的情况下，所有"case"都要使用括号；
    - 循环中超过一条语句需要使用括号；
    ```
        //情况一：单行语句可以完成任务时不要使用括号
        if (condition)
            action();

        //情况二：单行语句可以完成任务时不要使用括号
        if (condition)
            do_this();
        else
            do_that();

        //情况三：其他"case"有多行的情况下，所有"case"都要使用括号
        if (condition) {
                do_this();
                do_that();
        } else {
                otherwise();
        }

        //情况四：循环中超过一条语句需要使用括号
        while (condition) {
                if (test)
                        do_something();
        }
    ```

## 3.2. 空格

- Linux内核风格习惯在**一些**关键字之后添加一个**空格**；

- 使用方式类似函数的关键字使用不带空格的一对小括号;
- 使用方式类似函数的关键字：sizeof, typeof, alignof, __attribute__等等；

- 需要添加空格的关键子：if, switch, case, for, do, while；

- 不要在小括号内部周围添加空格(左括号右边，右括号左边)；

- 指针声明或函数返回为指针时，星号紧靠变量名或函数名，不是类型名；

- 一元操作符右边**不添加**空格；
- 自增自减一元操作符，后缀前不加空格，前缀后不加空格；
- 结构体成员操作符周围不加空格；

- 二元操作符左右添加空格；

- 三元操作符周围添加空格；

- 逗号操作符左边不添加空格，右边添加空格；
- for语法中分号左边不添加空格，右边添加空格；

- 不要在行末添加空格(某些编辑器会在新的行首添加一些空格来表示缩进，但是想保留一行空行时，这些由空格表示的缩进可能没有删除，导致看起来像是在上一行行末添加了多余的空格)；

    ```
        //情况一：需要添加空格的关键子
        //if, switch, case, for, do, while

        /情况二：使用方式类似函数的关键字使用不带空格的一对小括号
        //sizeof, typeof, alignof, __attribute__
        s = sizeof(struct file);

        //情况三：不要在小括号内部周围添加空格(左括号右边，右括号左边)
        s = sizeof( struct file );  /* 不建议采用的示例 */

        //情况四：针声明或函数返回为指针时，星号紧靠变量名或函数名，不是类型名
        char *linux_banner;
        unsigned long long memparse(char *ptr, char **retptr);
        char *match_strdup(substring_t *s);

        //情况五：一元操作符右边不添加空格
        //&  *  +  -  ~  !  sizeof  typeof  alignof  __attribute__  defined

        //情况六：自增自减一元操作符，后缀前不加空格，前缀后不加空格；
        i++;
        i--;
        --i;
        ++i;

        //情况七：结构体成员操作符周围不加空格
        student.age;
        pstudent->age;

        //情况八：二元操作符左右添加空格
        //=  +  -  <  >  *  /  %  |  &  ^  <=  >=  ==  !=

        //情况九：三元操作符周围添加空格
        //?  :

        //情况十：逗号操作符左边不添加空格，右边添加空格
        //arg1, arg2, arg3

        //情况十一：for语法中分号左边不添加空格，右边添加空格
        for (i = 0; i < Cnt; i++) {

    ```

# 4. 命名(Naming)

- C语言是一种简洁的语言，建议用`tmp`代替`VariableIsATemporaryCounter`；

- 全局变量或全局函数可以使用混合大小写的描述性名字，使用`count_active_users()`代替`cntusr()`；

- 编译器会检查函数类型，所以不建议写一个包含函数类型的名字(匈牙利命名法)；

- 局部变量名应该简洁；
    - 可以用`i`来定义一个计数器；
    - 可以用`tmp`来定义任何类型的临时变量；

<font color=rblue><br>

- 备注：
    - 列举常用的命名情况和特例！

</font>

# 5. 定义类型(Typedefs)

- 代码`vps_t a;`中的`vps_t`降低了代码的可读性，`struct virtual_container *a;`更易于理解代码，是typedef的错误使用方式；

- typedef仅有的用法：
    - 隐藏对象，封装作用(内核不建议使用封装和成员函数的思想)；

    - 抽象整数类型，避免混淆它是int型还是long型；
        - 典型应用：u8/u16/u32；

    - 用"sparse"创建用于类型检查的新类型；
        - [Link1](https://www.kernel.org/doc/html/v4.11/dev-tools/sparse.html)
        - [Link2](https://blog.csdn.net/whatday/article/details/99670228?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-3)
    
    - 某些情况下使用与标准C99相同的新型
        - 标准C99类型：uint32_t(一些人反对使用)；
        - Linux特有类型：u8/u16/u32/u64；
        - 两种类型不强制，但是选定一种之后就应该一直使用，不建议混用；

    - 用户空间的类型安全
        - 用户空间的某些结构体可能不能使用标准C99类型和Linux特有类型，而使用"__u32"这类的类型；

- 如果不满足typedef的五种用法，就不建议使用typedef；

- 指针或有可访问元素的结构体不应该使用"typedef"；

# 6. 函数(Functions)

- 一个函数只做一件事；

- 函数长度建议一到两屏幕(ISO/ANSI的屏幕尺寸是80x24);

- 函数的最大长度与该函数的复杂性和缩进程度成反比；

- 如果由于"case"太多导致的函数过长是可以理解的；

- 使用一些有描述性名称的辅助函数；

- 函数的性能至关重要时，可以使用内联；

- 函数的局部变量的数量不应该超过5-10个(人类的大脑通常可以很容易地跟踪大约7件不同的事情)；

- 用一个空行分隔函数；

- 如果函数被导出，导出宏应该紧跟在结束函数的大括号后面
    ```
        int system_is_up(void)
        {
                return system_state == SYSTEM_RUNNING;
        }
        EXPORT_SYMBOL(system_is_up);
    ```

- 在函数原型中，包含参数名称及其数据类型；

- 不要在函数原型中使用extern关键字，因为这会使行更长；

<font color=red><br>

- 疑问：
    - "不要在函数原型中使用extern关键字"怎么理解？
    - 那什么时候使用该关键字？
    - 头文件中使用可以建议吗？

</font>

# 7. 集中函数出口(Centralized exiting of functions)

- 很多人反对使用goto，但是编译器经常编译出无条件跳转指令，相当于使用goto；

- 函数有多个退出点，且多于一个退出点要执行相同的复位、清理等操作时，建议使用goto；

- goto使用的标签名应具有描述性，如释放缓存使用`out_free_buffer:`；
- 使用"GW-BASIC名称"方式("err1:"，"err2:"等)会在需要删除某个标签时造成需要重新排序的问题；

- 使用gotos的原由：
    - 无条件跳转更好理解；
    - 减少嵌套；
    - 避免修改某个函数退出点而造成错误；
    - 优化编译器的工作；
    ```
        int fun(int a)
        {
                int result = 0;
                char *buffer;

                buffer = kmalloc(SIZE, GFP_KERNEL);
                if (!buffer)
                        return -ENOMEM;

                if (condition1) {
                        while (loop1) {
                                ...
                        }
                        result = 1;
                        goto out_free_buffer;
                }
                ...
        out_free_buffer:
                kfree(buffer);
                return result;
        }
    ```

- 使用goto，常会出现称为："one err bugs"的bug用法：
    ```
        err:
                kfree(foo->bar);
                kfree(foo);
                return ret;
    ```
- bug在于可能要执行的kfree中的foo是NULL，解决方法是使用两个标签：
    ```
        err_free_bar:
                kfree(foo->bar);
        err_free_foo:
                kfree(foo);
                return ret;
    ```
- 应该模拟错误来测试所有退出路径；

<font color=red><br>

- 疑问：
    - goto语句多个标签，跳到前面的标签，且执行完标签未退出，后面的标签会不会被执行？
    - GW-BASIC 的命名方式？

</font>

# 8. 注释(Commenting)

- 注释是好习惯；

- 不要过度注释；

- 不要用注释来解释代码如何工作，最好是让代码的工作显而易见；
- 注释是解释代码做了什么，而不是如何做；

- 尽量避免在函数体内写注释，如果需要这样做，说明函数应该拆分了；
- 应该把注释写在函数开头；

- 可以做一些评论来提醒或警告代码的优点或缺点，但是不能过分；

- 注释内核API函数时，请使用内核文档格式，请参阅[kernel-doc](https://www.kernel.org/doc/html/latest/doc-guide/index.html#doc-guide)；

- 长(多行)注释的首选格式是:
    ```
        /*
        * This is the preferred style for multi-line
        * comments in the Linux kernel source code.
        * Please use it consistently.
        *
        * Description:  A column of asterisks on the left side,
        * with beginning and ending almost-blank lines.
        */
    ```

- net/和drivers/net/中的文件，长(多行)注释的首选样式略有不同:
    ```
        /* The preferred comment style for files in net/ and drivers/net
        * looks like this.
        *
        * It is nearly the same as the generally preferred comment style,
        * but there is no initial almost-blank line.
        */
    ```

- 建议对数据(基本类型或派生类型)进行注释；
- 建议每行只使用一个数据声明(多个数据声明不使用逗号)；   

<font color=red><br>

- 疑问：
    - "kernel API"指什么？

</font>

# 9. 事情搞得一团糟(You’ve made a mess of it)

- "GNU emacs"能自动对C代码排版,但是默认的排版方式不是很好；
- 可以修改.emacs文件(~/src/linux-trees)达到想要的效果：
    ```
        (defun c-lineup-arglist-tabs-only (ignored)
        "Line up argument lists by tabs, not spaces"
        (let* ((anchor (c-langelem-pos c-syntactic-element))
                (column (c-langelem-2nd-pos c-syntactic-element))
                (offset (- (1+ column) anchor))
                (steps (floor offset c-basic-offset)))
            (* (max steps 1)
            c-basic-offset)))

        (dir-locals-set-class-variables
        'linux-kernel
        '((c-mode . (
                (c-basic-offset . 8)
                (c-label-minimum-indentation . 0)
                (c-offsets-alist . (
                        (arglist-close         . c-lineup-arglist-tabs-only)
                        (arglist-cont-nonempty .
                            (c-lineup-gcc-asm-reg c-lineup-arglist-tabs-only))
                        (arglist-intro         . +)
                        (brace-list-intro      . +)
                        (c                     . c-lineup-C-comments)
                        (case-label            . 0)
                        (comment-intro         . c-lineup-comment)
                        (cpp-define-intro      . +)
                        (cpp-macro             . -1000)
                        (cpp-macro-cont        . +)
                        (defun-block-intro     . +)
                        (else-clause           . 0)
                        (func-decl-cont        . +)
                        (inclass               . +)
                        (inher-cont            . c-lineup-multi-inher)
                        (knr-argdecl-intro     . 0)
                        (label                 . -1000)
                        (statement             . 0)
                        (statement-block-intro . +)
                        (statement-case-intro  . +)
                        (statement-cont        . +)
                        (substatement          . +)
                        ))
                (indent-tabs-mode . t)
                (show-trailing-whitespace . t)
                ))))

        (dir-locals-set-directory-class
        (expand-file-name "~/src/linux-trees")
        'linux-kernel)
    ```

- 可以不使用"GNU emacs"，使用"GNU indent"；
- 使用"GNU indent"需要一些命令行选项来进行配置；
    - "-kr -i8"表示K&R，8个字符宽的缩进；
    - 或者使用 scripts/Lindent；
- indent 有很多命令行选项，可通过man手册查看；

- 可以使用clang-format工具
    - 自动快速地重新格式化代码的某些部分；
    - 检查完整的文件；
    - 发现编码样式错误、打字错误和可能的改进
    - 对#include进行排序；
    - 调整变量/宏、返回文本
    - 参考：[clang-format](https://www.kernel.org/doc/html/latest/process/clang-format.html#clangformat)

<font color=red><br>

- 疑问：
    - "GNU emacs"？
    - "GNU indent"？
    - "clang-format"？

</font>

# 10. Kconfig配置文件(Kconfig configuration files)

- Linux中的Kconfig配置文件的缩进有所不同
    - config 定义下的缩进是一个 tab；
    - help 文本是两个空格；
    ```
        config AUDIT
                bool "Auditing support"
                depends on NET
                help
                  Enable auditing infrastructure that can be used with another
                  kernel subsystem, such as SELinux (which requires this for
                  logging of avc messages output).  Does not do system-call
                  auditing without CONFIG_AUDITSYSCALL.
    ```

- 严重危险的特性(比如对某些文件系统的写支持)应该在提示字符串中突出显示这一点,
- 参见：Documentation/kbuild/kconfig-language.rst
    ```
        config ADFS_FS_RW
                bool "ADFS write support (DANGEROUS)"
                depends on ADFS_FS
                ...
    ```

<font color=red><br>

- 疑问：
    - "严重危险的特性"在说什么？

</font>

# 11. 数据结构(Data structures)

- 单线程环境下创建和销毁的，在线程之外可见的数据结构必须有引用计数；
- 内核里没有垃圾收集器，内核外垃圾收集器慢且低效；
- 引用计数可以避免死锁；
- 引用计数可以使多用户并行访问数据；
- 引用计数可以避免线程休眠唤醒(或其他情况)之后数据已销毁现象；

- 锁不是引用计数的替代品；
- 锁用于保持数据的一致性；
- 引用计数是一种内存管理技术；
- 通常锁和引用计数都需要；

- 当用户属于不同的类时，数据结构可以有两个级别的引用计数；
- 子类计数为零是才对父类计数递减；
- 多级引用计数的使用：
    - 内存管理(struct mm_struct: mm_users and mm_count)
    - 文件系统(struct super_block: s_count and s_active)

- 其他线程可以访问你的数据结构，而你没有对其进行引用计数，那么你的数据结构使用方式存在bug；

<font color=red><br>

- 疑问：
    - "用户属于不同的类时"指什么？
    - "子类引用计数和父类引用计数(二级引用和一级引用)"？

</font>

# 12. 宏，枚举与RTL(Macros, Enums and RTL)

- 宏名和枚举中的标签都要大写；
- 定义相关常量时优先使用枚举；
- 函数宏(使用宏代表定义函数)可以小写；
- 通常建议把内联函数定义为宏；
- 包含多个语句的宏应该包含在"do - while"块中；
    ```
    #define macrofun(a, b, c)                       \
            do {                                    \
                    if (a == 5)                     \
                            do_this(b, c);          \
            } while (0)
    ```

- 应该避免的情况:
    ```
        //情况一：影响控制流的宏
        //导致调用者返回到上一层
        #define FOO(x)                                  \
                do {                                    \
                        if (blah(x) < 0)                \
                                return -EBUGGERED;      \
                } while (0)

        //情况二：依赖局部变量的宏
        //容易让人困惑，小改动造成破坏后果
        #define FOO(val) bar(index, val)

        //情况三：带参数的宏当作左值
        //FOO作为内联函数会导致错误
        FOO(x) = y;

        //情况四：忘记优先级
        //使用表达式定义常量的宏必须将表达式括在括号中
        //使用参数的宏也会出现类似的问题
        #define CONSTANT 0x4000
        #define CONSTEXP (CONSTANT | 3)

        //情况五：在函数宏中定义的局部变量存在命名空间冲突:
        // ret 很容易冲突
        // __foo_ret不容易冲突
        #define FOO(x)                          \
        ({                                      \
                typeof(x) ret;                  \
                ret = calc_ret(x);              \
                (ret);                          \
        })
    ```

- C++ 手册全面地阐述了宏定义的细节；
- gcc 手册阐述了汇编语言使用的 RTL 规则；

<font color=blue><br>

- 备注：
    - RTL(Real Time Linux)

</font>

<font color=red><br>

- 疑问：
    - 为什么使用"依赖局部变量的宏"不好？上面的解释没看明白？
    - 为什么使用"带参数的宏当作左值"不好？上面的解释没看明白？
    - "使用参数的宏也会出现类似的问题"的优先级问题怎么理解？

</font>

# 13. 打印内核信息(Printing kernel messages)

- 注意内核消息的拼写，提示信息应简洁、清晰、明确，比如用do not或don`t代替dont；

- 内核信息末尾不加句号；

- 不要在圆括号中打印数字：(%d)；

- 在linux/device.h中有许多驱动模型诊断宏
- 应该使用诊断宏来确保消息匹配到正确的设备和驱动程序
- 使用正确的级别标记
    - dev_err()
    - dev_warn()
    - dev_info()
    - and so forth
- 对于没有关联特定设备的消息，使用linux/printk.h中的定义：
    - pr_notice()
    - pr_info()
    - pr_warn()
    - pr_err()
    - etc

- 编写好的调式信息不是一件简单的事情；
- 调式信息对远程故障排除有很大帮助；
- pr_XXX()函数无条件输出；
- pr_debug()和dev_dbg()默认不输出，与调试有关的函数默认不会被编译；
- 可以定义DEBUG宏或CONFIG_DYNAMIC_DEBUG宏来编译调式信息；
- 可以使用VERBOSE_DEBUG为已经开启DEBUG的用户添加dev_vdbg()消息；

- 很多子系统的makefile里有Kconfig调试选项(-DDEBUG)；
- 可以在文件里定义宏#define DEBUG；
- 当调试信息可以打印，printk(KERN_DEBUG ...) 可以用来打印调试信息；

<font color=red><br>

- 疑问：
    - 为什么内核信息末尾不加句号？
    - 驱动模型诊断宏？
    - 没有关联特定设备的消息？
    - pr_debug、dev_dbg、dev_vdbg？
    - printk(KERN_DEBUG ...)？

</font>

# 14. 内存分配(Allocating memory)

- 内核中通用的内存分配器： kmalloc(), kzalloc(), kmalloc_array(), kcalloc(), vmalloc(), and vzalloc()；
    - [内存分配器](https://www.kernel.org/doc/html/latest/core-api/memory-allocation.html#memory-allocation)

- 为结构体分配内存建议方式：`p = kmalloc(sizeof(*p), ...);`
- `sizeof(struct name)`这种分配内存的方式会破坏代码可读性，且容易产生bug(结构体变量的结构体类型改变时可能忘记修改这里的结构体名)；
- 不要在malloc之前添加强制类型转换(把空类型的指针转换为特定类型的指针)，编译器会做这个工作；

- 为数组分配内存建议方式：`p = kmalloc_array(n, sizeof(...), ...);`
- 为零数组分配内存建议方式：`p = kcalloc(n, sizeof(...), ...);`
- 以上两种形式都会检查溢出，并且溢出发生时返回一个空指针 NULL；

- 当没有剩余的__GFP_NOWARN使用时，这些通用分配函数都会在失败时发出堆栈转储，所以当返回NULL时，没有必要发出额外的失败消息；

<font color=red><br>

- 疑问：
    - 零数组？
    - __GFP_NOWARN？
    - 发生了"堆栈转储"为什么就不需要额外的失败消息了？"堆栈转储"会打印信息？

</font>

# 15. 内联之疾(The inline disease)

- 内联让程序跑得更快；
- 过多的inline关键字会使内核变大；
- 过多的内联使整个系统运行速度变慢；
    - 大内核会占用更多的CPU高速缓存；
    - 大内核会导致可用内存页缓存减少；
    - 大内核对导致更多的cache miss；
    - cache miss 时需要访问磁盘，至少5ms，占用了很多指令时间；

- 函数有三行以上的代码不建议用内联；
- 编译时常量参数导致在编译器编译之后能优化大部分代码，建议使用内联(例如kmalloc())；

- 只使用一次的静态函数不需要手动添加inline关键字，gcc编译器会自动添加；
- 不给只使用一次的静态函数添加inline关键字，可以避免该函数如果被使用两次时需要手动删除inline关键字； 

# 16. 函数返回值和名称(Function return values and names)

- 函数可以返回多种类型的值；

- 函数常见返回值是：表明函数是否成功执行
    - 可以是错误代码(0：成功，Exxx：失败)
    - 可以是布尔值(0：失败，非0：成功)
- 不建议函数返回值混合使用上述两种方式，应满足以下规则：
    - 如果函数名是动作或命令，应该返回错误代码；
    - 如果函数名是谓词(判断)，应该返回布尔值；

- 所有(export)导出函数必须遵守这一约定；
- 所有公共函数必须遵守这一约定；
- 私有(静态)函数不需要遵守，但建议遵守；

- 如果返回值表示计算的实际结果，不是表示计算是否成功，则不遵守此规则；
- 返回值表示计算结果的时候，通过返回超出范围的结果来指示失败；
- 典型例子是返回指针的函数使用NULL或ERR_PTR机制来报告失败；

<font color=red><br>

- 疑问：
    - 导出函数和公共函数的区别？
    - ERR_PTR机制？

</font>

---

# 17. 使用布尔值(Using bool)

- Linux内核bool类型是C99 _Bool类型的别名；
- bool变量可以使用的值只有：0和1；
- 隐式或显式的到bool类型的转换会自动转为：true或false；
- 不要自己构建bool类型；

- 当使用bool值的时候，应该是true和flase，不应使用0或1；
- 推荐使用bool类型作为返回值而不是int类型；

- bool的大小的对齐方式会根据编译的体系结构发生变换；
- 如果cache line和变量的尺寸比较重要时不建议使用bool；
- 对于需要对大小和对齐优化的结构体不建议使用bool；

- 如果一个结构体中有多个真假值，建议使用位字段或固定宽度类型(u8)；
- 如果一个函数参数中有多个真价值，建议使用位字段的flags；
- 否则在结构和参数中使用bool可以提高可读性；

# 18. 不要重新创建内核宏(Don’t re-invent the kernel macros)

- 头文件include/linux/kernel.h包含一些应该使用的宏；
    - 计算数组长的宏：`#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))`
    - 计算结构体中某个成员的大小：`#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))` 
    - 类型检查：`min() 和 max()`
- 多查看该文件；

# 19. 编辑器的自定义配置(Editor modelines and other cruft)

- 一些编辑器可以识别嵌入在**源文件中**的配置信息；
- 配置信息需要使用特殊的标记表示；
- 不要在源文件中包含这些配置信息，你的配置信息会影响到别人；

- emacs 可以识别的标记
    `-*- mode: c -*-`

    ```
        /*
        Local Variables:
        compile-command: "gcc -DMAGIC_DEBUG_FLAG foo.c"
        End:
        */
    ```

- vim可以解释的标记：
    `/* vim:set sw=8 noet */`

# 20. 内联汇编(Inline assembly)

- 能用C语言干的事不用汇编指令；
- 操作某些特定体系结构可能需要内联汇编；

- 建议编写辅助函数来封装内联汇编，避免重复在代码中直接使用内联汇编；
- 内联汇编也可以使用C函数的参数；

- 大型的、重要的汇编函数应该单独创建.S文件;
- 大型的、重要的汇编函数应该有对应的C头文件，且定义相应的C原型；
- 相应的C原型应添加 asmlinkage 关键字

- 有些汇编代码需要添加关键字：volatile，防止编译器优化删除；
- 对所有的汇编代码添加volatile会影响优化；

- 一条内联汇编语句里包含多条指令，每条指令使用带**引号**的方式**分行**写，除最后一行外其他行的行末添加\n\t进行缩进和对齐：
    ```
        asm ("magic %reg1, #42\n\t"
                "more_magic %reg2, %reg3"
                : /* outputs */ : /* inputs */ : /* clobbers */);
    ```

<font color=red><br>

- 疑问：
    - 内联汇编如何使用C函数的参数？
    - asmlinkage 关键字？
    - 头文件中叫声明还是定义？
    - 哪些汇编代码需要添加volatile关键字？添加该关键字的语法？
    - 上面的代码怎么理解？
</font>

# 21. 条件编译(Conditional Compilation)

- 不要在.c文件中使用条件编译命令；
- 将条件编译命令放到.h文件中；
- 在.h文件中，同样的条件编译条件只使用一次(该条件编译下的函数全部一次性放于该添加下)，不建议先放一部分再放一部分；

- 某个函数或变量可能在特定配置中未使用，可以标记为"__maybe_unused"，而不是移到预编译条件内；
- 如果一个函数或变量总是不使用，删除它；

- 在代码中，如果可能的话，使用IS_ENABLED宏将Kconfig符号转换为C布尔表达式，并在普通的C条件下使用:
    ```
        if (IS_ENABLED(CONFIG_SOMETHING)) {
                ...
        }
    ```
- 编译器会折叠预编译条件；
- 编译器会包含或排除代码块；
- 预编译不会增加代码运行时开销；
- 编译器会检查所有预编译分支下的代码正确性(语法、类型、符号引用等)；
- 如果条件满足的分支引用了条件不满足下的符号，需要在该符号周围继续使用预编译指令；

- 不管嵌套与否，每个#endif默认应添加注释：
    ```
        #ifdef CONFIG_SOMETHING
        ...
        #endif /* CONFIG_SOMETHING */
    ```

<font color=red><br>

- 疑问：
    - 如何在C代码中使用Kconfig中的符号？

</font>

# N. 附录I 引用(Appendix I :References)

The C Programming Language, Second Edition by Brian W. Kernighan and Dennis M. Ritchie. Prentice Hall, Inc., 1988. ISBN 0-13-110362-8 (paperback), 0-13-110370-9 (hardback).

The Practice of Programming by Brian W. Kernighan and Rob Pike. Addison-Wesley, Inc., 1999. ISBN 0-201-61586-X.

GNU manuals - where in compliance with K&R and this text - for cpp, gcc, gcc internals and indent, all available from http://www.gnu.org/manual/

WG14 is the international standardization working group for the programming language C, URL: http://www.open-std.org/JTC1/SC22/WG14/

Kernel process/coding-style.rst, by greg@kroah.com at OLS 2002: http://www.kroah.com/linux/talks/ols_2002_kernel_codingstyle_talk/html/






