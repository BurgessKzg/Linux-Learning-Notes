udev是一种工具，动态更新设备文件；
设备文件目录：通常在/dev/;
udev提供监视接口；
udev依赖sysfs文件系统；
udev运行在用户空间；

udev作用：动态创建和删除设备文件，遍历sysfs设备文件，hotplug(利用netlink)；

使用udev需要安装libudev库，程序中包含"libudev.h"，编译时加"-ludev"；

安装libudev : sudo apt-get install libudev-dev

sysfs完成创建删除一个设备之后，会通过netlink的方式发送uevent通知udevd；

可以使用命令"udevadm"(usr/bin/udevadm)与udev交互;
info 查询sysfs或者udev的数据库
trigger 从内核请求events
settle 查看udev事件队列，如果所有的events已处理则退出
control 修改udev后台的内部状态信息
monitor 监控内核的uevents
hwdb 处理硬件数据库索引
test

udev 必须内核中的sysfs和tmpfs支持，sysfs 为udev 提供设备入口和uevent 通道，tmpfs 为udev 设备文件提供存放空间。
sysfs挂载在/sys上；

udev 是通过对内核产生的设备文件修改，或增加别名的方式来达到自定义设备文件的目的。但是，udev 是用户模式程序，其不会更改内核行为。也就是说，内核仍然会创建sda，sdb等设备文件，而udev可根据设备的唯一信息来区分不同的设备，并产生新的设备文件（或链接）。而在用户的应用中，只要使用新产生的设备文件即可。


systemd和udevd进程关系？systemctl命令可对udev做什么处理？

udev配置文件：/etc/udev/udev.conf
udev规则文件：/etc/udev/rules.d/*

规则文件的作用：
    关键字：键-值对，匹配键，赋值键，操作符
    udev手册；
    将设备节点从默认名称重命名为其他名称
    通过创建到默认设备节点的符号链接，为设备节点提供一个可选/持久性名称，udev为/dev/disk目录中的存储设备提供开箱即用的持久性命名(ls -lR /dev/disk)；
    根据程序的输出来命名设备节点
    更改设备节点的权限和所有权
    在创建或删除设备节点时启动脚本(通常在连接或断开设备时)
    重命名网络接口
    对于不存在特定设备的设备节点的问题，编写规则不是一种变通方法。即使没有匹配的规则，udev也会用内核提供的默认名称创建设备节点(内核和udev各自创建一个？)。
    默认的udev规则存储在/etc/udev/rules.d/50-udev.rules中，不应该将规则直接写入这个文件;
    udev会读取一系列规则文件,来确定如何命名设备以及执行哪些附加操作，文件保存在/etc/ udv /rules中它们都必须有.rules后缀
    文件/etc/udev/rules.d/按词法顺序解析，在某些情况下，解析规则的顺序很重要，/etc/udev/rules.d/10-local.rules上创建一个文件取代默认值；
    规则不能跨多行，不要在您的规则中插入任何换行符，否则视为两行，且不能按预期工作；
    #为注释
    一个设备可以由多个规则匹配，规则可在不同文件，创建多个替代名称；
    规则由一系列键-值对构成，键-值对由逗号分隔，匹配键是用来识别规则所作用的设备的条件。当规则中的所有匹配键都对应于正在处理的设备时，将应用该规则并调用赋值键的操作。每个规则应该由至少一个匹配键和至少一个赋值键组成。
常用匹配键：
    KERNEL
    KERNELS：子，父
    SUBSYSTEM：父
    驱动程序：父
    ATTR{}：依据sysfs匹配
    ATTRS：子，父
    ENV{}==：

常用赋值键：
    NAME：(与符号链接的区别？)设备节点名字，如果没有该赋值键，则使用默认名称(默认名称等于内核名称)
    SYMLINK:(符号链接)：尝试用操作符"+="(SYMLINK+="DVR_USB_DISK")；
    GOTO：
    LABEL：
    IMPORT{}：
    RUN：RUN运行时设备节点已经建立，运行长时间程序建议分离；
    PROGRAM：PROGRAM运行时设备节点还未建立
    ENV{}=：
字符串替换：
    %k:只在指定路径出现
    %n:既在指定路径出现，还在源路径出现；
    %N:
    %c或%c{N}或%c{N+}：执行外部函数的输出；
字符串匹配：
    *：匹配多个字符；
    ?：匹配单个字符；
    []:匹配方括号中的字符，可以是范围；

控制权限和所有权：
    GROUP：指定所有组
    OWNER：指定所有者
    MODE：指定读写执行权限
附加选项：
    OPTIONS：
        last_rule：以后的规则不起作用
        ignore_device：
        all_partitions：

sysfs:
    顶级设备路径具有相应设备节点的实际设备,是包含一个dev文件的sysfs目录("find /sys -name dev")

udevinfo



/***************************************************/
struct timeval
struct timezone
gettimeofday()
/***************************************************/
printf("%-6s[%llu.%06u] %-8s %s (%s)\n",
fprintf()
/***************************************************/
struct sigaction
sigemptyset()
sigaction()
/***************************************************/
fd_set readfds
FD_ZERO()
FD_SET()
FD_ISSET()
select()
/***************************************************/
struct udev
udev_new()
udev_ref()
udev_unref()
/***************************************************/
struct udev_device
udev_device_get_action()
udev_device_get_devpath()
udev_device_get_subsystem()
udev_device_get_properties_list_entry()
udev_device_unref()
/***************************************************/
struct udev_list_entry
udev_list_entry_foreach()
udev_list_entry_get_name()
udev_list_entry_get_value()
/***************************************************/
struct udev_monitor
udev_monitor_new_from_netlink()
udev_monitor_enable_receiving()
udev_monitor_get_fd()
udev_monitor_receive_device()
udev_monitor_unref()











如果多个线程都对udev的监视窗口监控，当事件发生的时候是每个线程都能收到还是只有一个线程能收到事件？








