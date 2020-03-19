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
udev规则文件：
    用户自定义目录：/etc/udev/rules.d/*
    UDEV默认规则文件目录：/lib/udev/rules.d(安霸CV22平台在/usr/lib/udev/rules.d下也发现相同文件且一一关联)
    UDEVD运行时动态添加的规则目录：/run/udev/rules.d(在安霸CV22平台下没有该子目录，可见该子目录非必须)

在/lib/udev/rules.d目录下有一个"60-persistent-storage.rules"规则文件，该规则文件会根据存储设备的自身信息在/dev/disk/目录下创建存储设备的设备文件的链接文件，刚开始看在/dev/disk/by-label/目录下有一个对SD卡的链接，看了这个规则文件一直以为"ENV{ID_FS_LABEL_ENC}=="?*", SYMLINK+="disk/by-label/$env{ID_FS_LABEL_ENC}""中的ID_FS_LABEL_ENC指的是环境变量，后来才知道，这个是存储设备自身的信息，再格式化的时候可以给设备创建label信息；
在安霸CV22平台给sd卡创建一个label(假设叫SD_DISK)的方法：
mkfs.vfat -v -n SD_DISK /dev/mmcblk1p1  ，不过需要注意的是该指令会格式化SD卡，注意备份SD中文件！
应该是有只设置标签不格式化的指令，后续在究...
但是这种方法是针对单一SD卡的LABEL方式链接，客户手里面的SD卡不能格式化之后给建立LABEL，想到的办法还是针对平台来实现：
可以在/etc/udev/rules.d/目录下专门建一个SD的规则文件，其中一行匹配内容如下：
KERNELS=="*e0005000*" , ACTION=="add", SYMLINK+="DVR_SD_DISK" ，这里根据硬件设计中SD卡槽对应的SD控制器寄存器基址为e0005000来创建链接。该平台有两个SD卡控制器，SD0可以做eMMC boot使用，所有一般SD1用来驱动SD卡，如果两个控制器都做SD卡驱动，可再设计。

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
结构体udev：保存从配置文件读取的默认值
struct udev {
 int refcount;
 void (*log_fn)(struct udev *udev,
         int priority, const char *file, int line, const char *fn,
         const char *format, va_list args);
 void *userdata;
 char *sys_path;
 char *dev_path;
 char *rules_path;
 char *run_config_path;
 char *run_path;
 struct udev_list_node properties_list;
 int log_priority;
};
udev_new() :创建udev library context,udev library context采用引用记数机制，创建默认记数为1;
udev_ref()：增加引用记数
udev_unref()：减少引用记数，如果引用记数为0，则释放内部资源
/***************************************************/
结构体udev_list_entry：设备链表入口
struct udev_list_entry {
 struct udev_list_node node;
 struct udev *udev;
 struct udev_list_node *list;
 char *name;
 char *value;
 int num;
};
udev_list_entry_foreach()
udev_list_entry_get_name()
udev_list_entry_get_value()
/***************************************************/
结构体udev_device：udev设备链表
struct udev_device {
 struct udev *udev;
 struct udev_device *parent_device;
 char *syspath;
 const char *devpath;
 char *sysname;
 const char *sysnum;
 char *devnode;
 mode_t devnode_mode;
 char *subsystem;
 char *devtype;
 char *driver;
 char *action;
 char *devpath_old;
 char *knodename;
 char *id_filename;
 char **envp;
 char *monitor_buf;
 size_t monitor_buf_len;
 struct udev_list_node devlinks_list;
 struct udev_list_node properties_list;
 struct udev_list_node sysattr_value_list;
 struct udev_list_node sysattr_list;
 struct udev_list_node tags_list;
 unsigned long long int seqnum;
 unsigned long long int usec_initialized;
 int timeout;
 int devlink_priority;
 int refcount;
 dev_t devnum;
 int ifindex;
 int watch_handle;
 int maj, min;
 bool parent_set;
 bool subsystem_set;
 bool devtype_set;
 bool devlinks_uptodate;
 bool envp_uptodate;
 bool tags_uptodate;
 bool driver_set;
 bool info_loaded;
 bool db_loaded;
 bool uevent_loaded;
 bool is_initialized;
 bool sysattr_list_read;
 bool db_persist;
};
udev_device_get_action()
udev_device_get_devpath()
udev_device_get_subsystem()
udev_device_get_properties_list_entry()
udev_device_unref()
/***************************************************/
结构体udev_monitor：udev设备事件源
struct udev_monitor {
 struct udev *udev;
 int refcount;
 int sock;
 struct sockaddr_nl snl;
 struct sockaddr_nl snl_trusted_sender;
 struct sockaddr_nl snl_destination;
 struct sockaddr_un sun;
 socklen_t addrlen;
 struct udev_list_node filter_subsystem_list;
 struct udev_list_node filter_tag_list;
 bool bound;
};
udev_monitor_new_from_netlink()
udev_monitor_enable_receiving()
udev_monitor_get_fd()
udev_monitor_receive_device()
udev_monitor_unref()
/***************************************************/
结构体udev_enumerate：查找和排序sys设备
struct udev_enumerate {
 struct udev *udev;
 int refcount;
 struct udev_list_node sysattr_match_list;
 struct udev_list_node sysattr_nomatch_list;
 struct udev_list_node subsystem_match_list;
 struct udev_list_node subsystem_nomatch_list;
 struct udev_list_node sysname_match_list;
 struct udev_list_node properties_match_list;
 struct udev_list_node tags_match_list;
 struct udev_device *parent_match;
 struct udev_list_node devices_list;
 struct syspath *devices;
 unsigned int devices_cur;
 unsigned int devices_max;
 bool devices_uptodate:1;
 bool match_is_initialized;
};
udev_enumrate_new()：创建一个枚举器，用于扫描系统已接设备
udev_enumrate_ref()：增加引用记数
udev_enumrate_unref：减少引用记数
udev_enumrate_add_match/nomatch_xxx
/***************************************************/
结构体udev_queue：存取当前活动事件
struct udev_queue {
 struct udev *udev;
 int refcount;
 struct udev_list_node queue_list;
 struct udev_list_node failed_list;
};
/***************************************************/



https://blog.csdn.net/u012247418/article/details/80555556


http://www.360doc.com/content/18/0830/22/2245786_782535165.shtml





NETLINK：一种特殊类型的socket，专门用于内核空间与用户空间的异步通信。
如果多个线程都对udev的监视窗口监控，当事件发生的时候是每个线程都能收到还是只有一个线程能收到事件？
外部硬件设备在/dev目录下对应的设备文件是由谁创建的？是驱动自己建的还是udev建的？








