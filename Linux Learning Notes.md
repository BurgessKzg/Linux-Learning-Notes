[TOC]
# 1. 基础操作
&emsp;&emsp;Ubuntu子版本号只有两个，.04和.10，.04是稳定版本，.10是测试版本。主版本号单数是短期支持版，双数是长期支持版。
## 1.1. 命令
&emsp;&emsp;Shell是命令解析器，shell是Unix的解析器，Bash是Linux的解析器，由同一个人编写，Linux也称Shell解析器。它的本质是根据键入的命令调用不同的程序来执行不同操作。
### 1.1.1. more
- “more "FileName"”
- 查看文件FileName的内容，回车下行，空格翻页，“q"退出；
- 缺陷是不能返回到前面；
### 1.1.2. less
- “less "FileName"”
- 查看文件FileName的内容，回车下行，空格翻页，"Ctrl + b"翻页返回，“Ctrl + p”按行返回，"q"退出；
### 1.1.3. head
- "head FileName"，等价于“head -10 FileName”
- 默认显示文件的前十行；
### 1.1.4. tail
- "tail FileName"，等价于“tail -10 FileName”
- 默认显示文件的后十行；
### 1.1.5. pwd
...
### 1.1.6. mv
...
### 1.1.7. cp
...
### 1.1.8. sudo su
- 在Ubuntu下切换到root用户，退出用“exit”；
### 1.1.9. cd
- "cd -"：在最近使用的两个目录之间切换；
- “cd ~”：进入家目录；
- “cd ”：也是进入家目录；
### 1.1.10. ls -l
@import "Picture001_ls_-l.jpg"
- 1：文件类型；
- 2：所有者权限；
- 3：所属组权限；
- 4：其他人权限；
- 5：文件硬链接数；
- 6：所有者；
- 7：所属组；
- 8：存储空间（目录固定4096，不包含内部文件和子目录文件）；
- 9：创建日期或最后修改日期；
- 10：文件名
### 1.1.11. tree
- "tree"命令不是自带的，使用需要安装；
- 树状结构罗列目录下的所有文件；
### 1.1.12. du
- 查看目录使用情况；
- 可加选项显示，多用“-h”
### 1.1.13. df
- 查看磁盘使用情况；
- 可加选项显示，多用“-h”
### 1.1.14. wc
- 获取**文本文件**信息（行，单词，字符）；
### 1.1.15. od
- 获取**二进制文件**信息；
- “-t”指定数据的显示格式；
    - c：ASCII字符
    - d：有符号十进制
    - f：浮点数
    - o：八进制
    - u：无符号十进制
    - x：十六进制
### 1.1.16. which
- 在PATH环境变量中指定的路径中查看命令所在路径；
- “cd”命令是shell内建命令，不能使用which；
### 1.1.17. who相关
- who 显示当前真正登录系统中的用户；
- whoami；显示的是当前用户下的用户名（有效用户ID）；
- who am i：显示的是登录时的用户名，相当于who -m；
### 1.1.18. chmod
- chmod [who] [+/-/=] [mode]
    - who可选项
        - a：所有人（默认就是a）；
        - u：文件所有者；
        - g：文件所有组；
        - o：其他人；
    - mode可选项
        - r：读权限（对应数字4）；
        - w：写权限（对应数字2）；
        - x：执行权限（对应数字1）；
        - 在数字表示权限的情况下“-”代表没有权限；
        - 数字表示法也可以执行“减权限”；
### 1.1.19. chown
- 修改文件所有者
- “chown user FileName”，将文件FileName的所有者修改为user；
- “chown user:group FileName”，将文件FileName的所有者修改为user,所属组修改为group；
- linux中文件所有者并不一定属于文件所属组，所属组有操作文件的权限；
- 使用时加“sudo”
### 1.1.20. chgrp
- 修改文件所属组
- “chgrp group FileName”
- 使用时加“sudo”；
### 1.1.21. find
- “find Path -name “FileName” ”，文件名查找；
- “find Path -size +/-10M”，文件大小查找；
- "find Path -size +10k -size -100k"，大小范围查找；
- “find Path -type f/c/d/l/p”,按照文件类型查找(f代表普通文件，不是"-")；
- 通配符“*”代表多个字符；
- 通配符“?”代表一个字符；
### 1.1.22. grep
- 查找那个文件包含某个字符串；
- “grep -r  “str” Path”；
- grep查找的时候会占用一个进程，如果用ps查进程的时候，结果只有一条，那说明是没有相关进程；
### 1.1.23. mount
- "mount DevName Path";
- 挂载目录有media（自动挂载）和mnt（手动挂载）；
- 检测设备：sudo fdisk -l（查看设备文件名）
- 磁盘命名规则
    - 磁盘分类：sd(SCSI设备)、hd(Hard Disk硬盘)、fd(Floppy Disk软盘)；
    - 分区：主分区（最多四个）和扩展分区（用于创建逻辑分区，逻辑分区第一个是sdx5开始）
- 挂载应该是挂载到空目录，否则会覆盖原先内容；
### 1.1.24. umount
- “sudo umount PathName”
- 不能在要卸载的路径内执行卸载操作；
### 1.1.25. lsblk
**需要添加介绍**
### 1.1.26. 压缩和解压缩
- tar
    - tar命令是用来**打包**文件的，不能压缩；
    - “tar czvf xxx.tar.gz”，打包；
    - “tar xjvf xxx.tat.bz2 [-C Path]”，解包；
    - 参数
        - c：打包
        - x：解包
        - v：显示提示信息
        - f：指定压缩后文件名字
        - z：使用gzip压缩(.gz)
        - j：使用bzip2压缩(.bz2)
- rar
    - windows中最常使用的一种压缩格式；
    - 需要安装这个软件
    - 不需要添加后缀，压缩之后会自动添加；
    - “rar a 压缩后的文件名 被压缩的文件和目录”
    - “rar x 压缩后的文件名 \[解压的目录]”
    - rar压缩的时候可以不加参数“-r”
- zip 
    - "zip 压缩后的文件名 被压缩的文件和目录"，压缩；
    - “unzip 压缩后的文件名 [-d Path]”,解压；
    - 不需要添加后缀名，压缩之后会自动添加；
    - zip在压缩目录的时候需要添加参数“-r”；
### 1.1.27. ps
- 查看整个系统内部所运行的进程状况；
- 通过“ps aux | grep xxx”过滤要显示的进程；
- 参数：
    - a：当前系统所有用户的进程
    - u：查看进程所有者及其他信息
    - x：显示没有控制终端的进程 
### 1.1.28. kill
- “kill -l”，查看信号；
- “kill -信号(值/字符串) 进程号”，杀死进程；
### 1.1.29. top
- 相当于window的任务管理器
### 1.1.30. env
- 查看当前进程的环境变量；
- 格式“key = value;value;...”;
### 1.1.31. ifconfig
- 查看ip；
- eth0是第一块网卡；
- mac地址唯一；
### 1.1.32. ping
- 查看网络是否通；
- linux下的ping不加参数不会主动结束（"-c"）；
### 1.1.33. nslookup
- 查看域名对应的IP；
### 1.1.34. 添加用户
#### 1.1.34.1. adduser
- adduser实际上是一个脚本；
- “sudo adduser UserName”，添加用户；
- 用户名不能包含大写字母；
#### 1.1.34.2. useradd
- useradd是一个命令；
- 需要后续再设置用户密码；
- “sudo useradd -s /bin/bash -g GroupName -d 绝对Path -m UserPathName”
    - s：指定新用户登陆时shell类型；
    - g：指定所属组，组必须已经存在(groupadd命令)；
    - d：用户家目录；
    - m：家目录不存在时自动创建；
### 1.1.35. 添加用户组
- “sudo groupadd GroupName”
### 1.1.36. 删除用户
#### 1.1.36.1. deluser
- “sudo deluser UserName”
#### 1.1.36.2. userdel
- “sudo userdel -r UserName”，“-r”指把用户主目录也删除；
### 1.1.37. su
- “su UserName”，普通用户间切换
- “sudo su”，切换至root用户
- “exit”，退出切换到的用户
### 1.1.38. passwd
- 给用户设置或修改密码；
- “sudo passwd UserName”，给普通用户设置密码；
- “sudo passwd”，给root用户设置密码；
- “sudo passwd root”，给root用户设置密码；
- “passwd”，修改当前用户的密码；
- **/etc/passwd文件内可以查看有哪些用户；**
### 1.1.39. echo
- 回显数据；
- 普通数据：echo 字符串；
- 显示环境变量：echo $PATH；
- 显示上一次程序退出值："echo \$?","$"取值的意思，“？”最近一次退出程序的返回值；
### 1.1.40. alias
- 查看或设置别名
- alias：查看别名；
- “alias SrcName='DescName'”：设置别名（.bashrc可以永久有效）；
### 1.1.41. man
- 查看帮助文档
- 语法：“man n Name”，n代表man帮助文档的章节；
- “man 命令”：查看命令的帮助文档；
- “man man”：查看帮助文档本身；
    - 1：可执行程序或shell命令
    - 2：系统调用（内核提供的函数）
    - 3：库调用（程序库中提供的函数）
    - 4：特殊文件（通常位于/dev）
    - 5：文件格式和规范（如：/etc/passwd)
    - 6：游戏
    - 7：杂项
    - 8：系统管理命令
    - 9：内核例程
### 1.1.42. nm
- 查看可执行文件，静态库，动态库内部的符号（变量名、函数名等）；
### 1.1.43. file
- 查看文件类型；
### 1.1.44. strace
- "strace ExeFileName"
- 可追踪执行文件在执行中使用的系统调用有什么；
### 1.1.45. time
- "time ExeFileName"
- 可执行程序结束时统计执行时间，包括真实执行时间，内核空间执行时间，用户空间执行时间；
- 实际执行时间=内核空间执行时间+用户空间执行时间+等待时间(等待CPU、内存、屏幕等)
## 1.2. 终端
### 1.2.1. 操作
- “命令提示符”
    - “当前登陆用户”+“@”+“主机名”+“:”+“当前路径”+“$”
    - “当前登陆用户”+“@”+“主机名”+“:”+“当前路径”+“#”
    - @相当于at（在）；
    - “~”代表家目录；
    - "$"：普通用户；
    - “#”：超级用户；
### 1.2.2. 快捷键
#### 1.2.2.1. 常用
- “Ctrl + Alt +t”：打开终端；
- “Ctrl + Shift + t”：打开标签页；
- “Ctrl + d”：关闭终端；
- “Tab”：可补齐命令或路径；
- "Ctrl + l"：清屏；
- “Ctrl + r”：快速检索历史命令；在旧的历史命令上；
- “Ctrl + a”：光标移动到最前；
- “Ctrl + e”：光标移动到最后；
- "Esc + b"：移动到当前单词头；
- “Esc + f”：移动到当前单词尾；
- “Ctrl + u”：光标前的字符都删除；
- “Ctrl + w”：光标前单词删除；
- “Ctrl + k”：光标后的字符都被删除；
- “Ctrl + y”：黏贴被u,w,k删除的字符串；
- “Ctrl + t”：交换光标位置前的两个字符；
- “Esc + t”：交换光标相邻单词位置；
#### 1.2.2.2. 不常用
- “Ctrl + h”：光标删除前一个字符；
- “Ctrl + d”：光标删除后一个字符；
- “Ctrl + b”：光标按照一个字符向前移动；
- “Ctrl + f”：光标按照一个字符向后移动；
- “Ctrl + P”：一条条往旧的方向返回历史命令；
- “Ctrl + N”：一条条往新的方向返回历史命令，前提是已经
## 1.3. Vim
### 1.3.1. 配置
- 系统配置文件：/etc/vim/vimrc
- 用户配置文件：~/.vim/vimrc
### 1.3.2. 操作
- 三种工作模式：命令模式，编辑模式，末行模式；
#### 1.3.2.1. 可视模式
- 当需要删除或复制某一行中的部分内容时使用可视模式；
- 可视模式下不会复制回车换行；
- 跳到要进入可视模式的位置，按“v”进入可视模式，按“hjkl”选择内容，再按“d”或“y”删除或复制；
#### 1.3.2.2. 分屏
- sp FileName：水平分屏
- vsp FileName：垂直分屏
- Ctrl+w+w：切换屏幕
- wall：保存全部
- qall:退出全部
#### 1.3.2.3. 末行模式
- 直接键入数字跳转到对应行；
- 单行替换：先切到对应行，再进入末行模式，输入“s/SrcStr/DescStr”回车，只替换了第一个，要替换改行所有的要使用“s/SrcStr/DescStr/g”;
- 文件替换：“%s/SrcStr/DescStr/g”
- 某几行替换：“LineStart,LineEnds/SrcStr/DescStr/g”
- 执行命令：“:!命令”
- >删除从windows拷贝文件到ubuntu中多了的"^M"：
使用vi编辑末行模式替换：
:%s/^M/\r/g
用来把^M换成回车，注意的是^M要使用CTRL-V CTRL-M生成，而不是直接键入^M
### 1.3.3. 快捷键
- h
- j
- k
- l
- Ctrl+b
- Ctrl+f
- $
- 0
- dd
- ndd
- yy
- nyy
- p：粘贴到所在行的下一行
- P：粘贴到所在行（大写P）；
- G
- ngg
- gg
- x
- X
- dw
- d0
- d$或D
- u
- Ctrl+r:反撤销；
- /：查找，向下查找，(n,N切换查找到的内容)
- ?:查找，向上查找，(n,N切换查找到的内容)
- #：移到关键字，按"#"高亮该关键字，n,N切换；
- r:命令模式下单字符替换；
- >>：向右缩进
- <<：向左缩进
- shift+k:跳到关键字的man文档中(默认第一章，可在跳转前按下章节数字)；
- ZZ：命令模式下保存退出
- x或wg：末行模式下保存退出；
- %：在结构体开始和结束位置切换；
- gg=G：排版(格式化代码)，也可以line1+gg+=+line2+gg排版这个区间
## 1.4. 目录结构
- /：根目录；
- /usr：用户应用程序和文件存放目录；
- /usr/bin:普通用户使用的应用程序；
- /usr/sbin:管理员用户使用的程序和守护程序；
- /usr/src：内核源码；
- /bin：普通可执行程序目录；
- /home：存放所有普通用户的家目录；
- /boot：启动相关文件；
- /dev：设备文件；
- /etc：配置文件；
- /lib：动态链接共享库；
- /media：U盘，光驱等设备自动挂载目录；
- /mnt：用户挂载目录；
- /root：超级用户主目录；
- /sbin：管理员使用的命令等；
- /proc：虚拟目录，内存映射，直接获取内存上系统信息，或在内存上直接操作；
- /sys：sysfs文件系统，直观反映内核设备树；
    - proc文件系统（进程信息）；
    - devfs文件系统（设备信息）；
    - devpts文件系统（伪终端）；
- /tmp：存放临时文件；
- /var:日志目录；
- /opt：软件安装目录；
- /lost+found：系统非法关机时使用，用户无法操作；
## 1.5. 文件
### 1.5.1. 普通文件
- 白色
- “-”
### 1.5.2. 目录
- 蓝色
- “d”
- 目录必须有执行权限才能进入
### 1.5.3. 设备文件
- 黄色
#### 1.5.3.1. 字符设备文件
- “c”
#### 1.5.3.2. 块设备文件
- "b"
#### 1.5.3.3. 管道
- "p"
### 1.5.4. 链接文件
- 青色
- "l"
#### 1.5.4.1. 软链接
- 软连接是另一个链接文件（ls -l时不同inode）；
- 软连接可以跨文件系统；
- 软链接可以链接不存在的文件，访问时同时创建；
- 软链接可以链接目录；
- “ln -s”创建软链接；
- 删除软链接对源文件和硬链接无影响；
- 删除源文件，软链接失效；
- 需要使用绝对路径创建软链接，这样的软链接可移动，相对路径的软链接只能在当前路径使用；
#### 1.5.4.2. 硬链接
- 硬链接是源文件的别名（ls -i时inode相同），不占用磁盘空间;
- 硬链接不可以跨文件系统；
- 硬链接不可以链接不存在的文件；
- 硬链接不可以链接目录；
- “ln”默认创建硬链接；
- 删除硬链接对源文件和软链接无影响；
- 删除源文件，硬链接无影响；
- 所有硬链接和源源文件删除才能真正删除文件；
- 硬链接不需要绝对路径；
### 1.5.5 socket文件
- “s”
### 1.5.6. 可执行文件
- 绿色
### 1.5.7. 其他文件
- 灰色
## 1.6. 软件安装
### 1.6.1. 在线安装
#### 1.6.1.1. apt-get
- 安装：sudo apt-get install SoftwareName -- 在线下载安装；
- 移除：sudo apt-get remove SoftwareName
- 更新：sudo apt-get update -- 更新**软件列表**(软件列表放的是软件的名字和下载地址，可以指定服务器来更新软件列表)；
- 清理所有软件安装包: sudo apt-get clean（实际清理的是: /var/cache/apt/archives 目录下的 .deb 文件）；
#### 1.6.1.2. aptitude
- 安装：sudo aptitude install SoftwareName
- 重新安装：sudo aptitude reinstall SoftwareName
- 更新：sudo apt-get update
- 移除：sudo aptitude remove SoftwareName
- 显示状态：sudo aptitude show SoftwareName
### 1.6.2. deb包安装
- 安装：sudo dpkg -i xxx.deb
- 删除：sudo dpkg -r xxx
### 1.6.3. 源码安装
- 1. 解压缩源代码包
- 2. 进入到安装目录：cd dir
- 3. 检测文件是否缺失，创建Makefile，检测编译环境： ./configure
- 4. 编译源码，生成库和可执行程序：make
- 5. 把库和可执行程序，安装到系统目录下：sudo make install
- 6. 删除和卸载软件：sudo make distclean
- 7. 上述安装步骤并不是绝对的，应该先查看附带的 README 文件
## 1.7。 vsftpd（ftp服务器）
### 1.7.1. 安装
- “sudo apt-get install vsftpd”；
- 客户端，服务器都会被安装；
- ftp服务会随开机自动启动；
### 1.7.2. 配置
- 配置文件：/etc/vsftpd.conf；
- 配置选项：
    - “write_enable=YES”指定是否拥有写权限
    - “anon_root=/home/burgesskzg/MyFtp”指定匿名用户ftp根目录，原先默认目录（/srv/ftp）失效；
    - “anonymous_enable=YES”指定是否允许使用匿名用户；
    - “anon_upload_enable=YES”指定匿名用户是否有上传权限；
    - “anon_mkdir_write_enable=YES”指定是否允许匿名用户创建目录；
### 1.7.3. 重启
- 修改配置文件之后需要重启服务器；
- “sudo service vsftpd restart”；
### 1.7.4. 客户端登陆
#### 1.7.4.1. 实名用户登陆
- 登陆指令：“ftp 服务器IP->回车->服务器用户名->回车->服务器登陆密码”
- 缺点：
    - 用户可以访问任意目录，破坏服务器；
    - 登陆密码泄露，不安全；
#### 1.7.4.2. 匿名用户登陆
- 登陆指令：“ftp 服务器IP->回车->anonymous->回车”
- 匿名用户登陆不需要密码，直接回车；
- 匿名账号固定为：anonymous；
- 匿名用户只能访问指定目录，指定目录配置方法如下：
    - “sudo mkdir /home/burgesskzg/MyFtp/anonyDir”,在ftp根目录下创建匿名用户的指定目录；
    - "sudo chown ftp:nogroup /home/burgesskzg/MyFtp/anonyDir”修改指定目录的用户为<font color=red>ftp用户</font>，组为空组（nogroup代表空组）；
    - “chmod 777 anonyDir”，修改指定目录的权限，否则无法访问；
### 1.7.4. 上传下载
- “put FileName”上传文件；
- “get FileName”下载文件；
- ftp自带客户端不能传输目录（可以打包后传输）；
### 1.7.5. 退出
- quit，bye，exit都可以退出；
### 1.7.6. lftp客户端
- 该客户端可以上传下载目录；
#### 1.7.6.1. 安装
- sudo apt-get install lftp
#### 1.7.6.2. 登陆
- 实名登陆：“lftp UserName@服务器IP->回车->服务器密码”
- 匿名登陆：“lftp 服务器IP->回车->login”
#### 1.7.6.3.上传下载
 - put：上传文件
 - get：下载文件
 - mput：上传多个文件
 - mget：下载多个文件
 - “mirror –R”：上传整个目录及其子目录
 - mirror：下载整个目录及其子目录
### 1.7.7. 疑问
1. 服务器实名用户怎么指定？
2. ftp服务器怎么给客户指定用户名和密码？密码怎么设置为临时密码，过一段时间就自动过期？
3. 在普通用户下安装ftp服务器，那普通用户和ftp用户的关系？
## 1.8. NFS服务器
&emsp;&emsp;网络文件系统，网络中的计算机可以共享文件，类似windows中的共享文件夹。
### 1.8.1. 安装
- sudo apt-get install nfs-kernel-server
### 1.8.2. 配置
- 先创建共享目录；
- 修改配置文件，添加“共享目录路径 * (rw,sync)”,"*"代表IP地址，这样写是因为有些服务器可能不支持;
    - ro：只读
    - rw：读写
    - sync：文件同步到磁盘，不在内存中长久缓存；
    - async：与sync相反；
    - no_root_squash：登入NFS主机，使用共享目录时相当于目录的拥有者。root用户对于这个目录具有root权限，不安全，不建议使用；
    - root_squash：登入NFS主机，使用共享目录时相当于目录的拥有者。root用户使用共享目录权限被压缩为匿名使用者，它的UID和GID都会变成nobody；
    - all_squash：所有用户的身份都会被压缩成为匿名使用者（nobody）；
- 重启服务器：“sudo service nfs-kernel-server restart”；
### 1.8.3. 客户端访问
- 客户端时通过挂载的方式访问目录的；
- “mount 服务器IP:共享目录路径 /mnt”，“mnt”是挂载到本地的路径，可以修改；
- 接下来就可以在本地/mnt路径下访问NFS服务器共享路径下的文件了
## 1.9. SSH服务器
### 1.9.1. 安装
- 安装：“sudo atp-get install openssh-server”
- 查看：“sudo aptitude show openssh-server”
### 1.9.2. 登陆
- “ssh UserName@服务器IP”；
- 登陆过程确认的时候只能写“yes”或“no”，不能用“y”和“n”代替；
### 1.9.3. 退出
- logout
### 1.9.4 scp命令
- scp命令是超级拷贝的意思；
- 使用之前openssh-server服务器必须已经安装；
- “scp -r DescUserName@DescHostIP:/DescFile绝对路径 /本地路径”，确认的时候只能输入“yes”；
- “-r”递归拷贝，拷贝目录的时候使用；
## 1.10. 关机重启操作
### 1.10.1. poweroff

### 1.10.2. reboot

### 1.10.3. shutdown
#### 1.10.3.1. 参数
- “-t 秒数”: 设定切换runlevel之前的时间（警告和删除延迟时间）；
- “-k”: 只发送警告信息, 不真关机；
- “-r”: 重启；
- “-h”: shutdown之后关机；
- “-n”: 不经过init进程,shutdown指令直接关机(不建议使用)；
- “-f”: 重新开机时, 跳过fsck指令,不检查档案系统；
- “-F”: 重新开机时, 强迫做fsck检查；
- “-c”: 取消正在shutdown的动作，必须切换至其它tty才能执行此命令；
#### 1.10.3.2. 举例
- “shutdown -r now”：立刻重新开机；
- “shutdown -h now”：立刻关机；
- “shutdown -k now "str"”：发出警告讯息, 不真关机；
- “shutdown -t5 -r now”：立刻重新开机,在警告和删除processes之间,延迟5秒钟；
- “shutdown -h 15:66 "str"” 15:66关机；
- “shutdown -r 10 "str"”：10分钟后关机；
- “shutdown now”：切换至**单人操作模式**；
## 1.11. gcc
### 1.11.1. 编译过程
> 1. 预编译&emsp;“-E ”&emsp;“.c>.i”&emsp;&emsp;"cpp预处理器"
> 2. 编译&emsp;&emsp;"-S "&emsp;".i>.s"&emsp;&emsp;“gcc编译器”
> 3. 汇编&emsp;&emsp;"-c "&emsp;".s>.o"&emsp;&emsp;“as汇编器”
> 4. 链接&emsp;&emsp;&emsp;&emsp;&emsp;".o>exe"&emsp;“ld连接器” 
### 1.11.2. gcc参数
- "-E"：
- "-S"：
- "-c"：
- "-o"：
- "-I"：指定头文件路径，“gcc -I 头文件目录”
- "-L"：指定库的目录
- "-l"：指定库的名字(需要掐头去尾,lib和.a和.so需要去掉)
- "-D"：指定宏，“gcc -D 宏名”
- "-O"：指定是否优化程序，"gcc -O 1"，可取0~3;
- "-Wall":指定在编译的时候输出警告信息；
- "-g"：指定在可执行程序中添加调试信息；
## 1.12. 静态库
### 1.12.1. 命名规则
- 命名规则：“lib+库名+.a”；
### 1.12.2. 制作
> 1. 生成对应的.o文件（使用gcc参数“-c”）；
> 2. 将生成的.o文件打包：“ar rcs 静态库全名 所有的.o文件”；
    - ar工具不包含在gcc中；
    - r指将文件插入静态库中
    - c指创建静态库（不管库是否存在）
    - s指写入一个目标文件索引到库中，或者更新一个存在的目标文件索引
> 3. 发布，需要将库和头文件一起打包给客户；
### 1.12.3. 使用
- "nm 静态库全名/可执行文件"：可以查看库中符号(变量和函数等);
- "gcc main.c /lib/libName.a -I/include -o app"
- "gcc main.c -L /lib -l Name -I include -o app"，-l选项包括的是库的本名，非全名；
### 1.12.4. 优缺点
#### 1.12.4.1. 优点
- 可执行程序执行速度快；
- 库被链接到可执行程序中，不需要发布库；
#### 1.12.4.2. 缺点
- 库被链接到可执行程序中导致可执行程序变大；
- 静态库发生变化，程序必须重新编译；
## 1.13. 动态库
### 1.13.1. 命名规则
- 命名规则：“lib+库名+.so”；
### 1.13.1. 制作
> 1. 编译与地址无关的.o文件（gcc使用参数“-fPIC”和“-c”）；
> 2. 将生成的.o文件打包：“gcc -shared -o libName.so -I include 所有要加入到库中的.o文件”；
> 3. 发布，需要将库和头文件一起打包给客户；
### 1.13.2. 使用
- "gcc main.c /lib/libName.so -I/include -o app"
- "gcc main.c -L /lib -l Name -I include -o app"，-l选项包括的是库的本名，非全名；
- 如何指定共享库（动态库）的存放路径：
    - “ldd AppName”可以查看可执行文件在执行的时候依赖的所有动态库；
    - **动态链接器**会自动帮助我们调用需要的动态库，它会根据环境变量**XXX**中的路径来查找；
    - 方法一：将动态库放到根目录下的/lib下也可以访问，但是为了方式同名覆盖系统库，所以不建议这样操作；
    - 方法二：配置环境变量LD_LIBRARY_PATH（“export LD_LIBRARY_PATH=LibPath”），该路径在默认路径之前查找，但是这是临时设置，不能永久使用；
    - 方法三（不常用）：将方法二的语法写到家目录的.bashrc文件里(要放绝对路径)，配置完需要重启终端；
    - 方法四(推荐方法)：
        - 1. 找到动态链接器的配置文件：/etc/ld.so.conf；
        - 2. 动态库的路径写到配置文件中；
        - 3. 执行更新操作：“sudo ldconfig ”,加"-v"参数可查看信息输出；
### 1.13.3. 优缺点
#### 1.13.3.1. 优点
- 可执行程序小；
- 动态库更新不需要重新编译可执行程序；
#### 1.13.3.2. 缺点
- 执行速度相对于静态库会慢点，但差距不大；
- 发布可执行程序或更新动态库的时候需要发送动态库；
## 1.14. GDB调试
&emsp;&emsp;如果要使用gdb调试，在编译可执行程序的时候需要加选项“-g”，生成的可执行文件会比不加"-g"的要大。
- 进入gdb：“gdb 带有调试信息的可执行程序”；
- 按“l”（小些L）在gdb里查看程序的源代码；
- 按“l FileName:10”指查看文件FileName的第10行；
- 按“l FileName:FuncName”指查看文件FileName中的函数FuncName;
- 第一次查看之后，第二次继续按“l”可以往下看，第三次之后按回车就可以往下看了；
- 先查看文件，然后输入"break Line"或“b Line”打**普通断点**；
- “b Line if i==10”打**条件断点**，表示在行line上如果i等于10就进入断点；
- “i b”或"i break"或"info b"或“info break”查看断点；
- 断点打好之后按“start”开始执行，start只会执行一步，按“n”是继续执行一步，按“c”执行到断点(continue)；
- "s"进入函数体内部，再按“l”可查看函数体里的代码，也可按“b”打断点；
- 在断点停下的时候可以按“p/print var”来查看变量var的值，“ptype var”查看变量类型；
- “dispaly var”可以追踪变量的值；
- “info display”获取追踪变量的编号；
- “undispaly 追踪变量编号”删除追踪变量；
- “u”跳出当前循环，类似程序中的continue；
- “finish”跳出函数，执行之前需要去掉函数内的断点，否则出不去；
- “d 断点编号”或“del/delete 断点编号”删除断点；
- 在for循环的时候可以执行“set var i=10”代表程序已经执行到i=10；
- “quit”退出；
- “run”和“r”也是开始执行程序；
- “b”后也可以跟函数名；
- “n”不进入函数体；
## 1.15. makefile
### 1.15.1. 命名
- makefile：所有字母小写；
- Makefile：第一个字母大写；
- 直接 make （使用makefile文件）
- make -f mm (指定一个名字不为makefile的文件)
### 1.15.2. 规则
- 三要素：目标，依赖，命令(前面必须有tab)；
- 原则(命令前面必须有tab)：
    > 目标：依赖
    > &emsp;&emsp;命令
- 子目标和最终目标的关系：第一条目标中目标是终极目标，子目标为终极目标的依赖服务；
- 链接的时候占用的时间并不长，主要是编译占用时间（all指定生成的最终目标为app）；
### 1.15.3. 原理 
- 根据依赖的时间和目标的最后修改时间来决定是否重新编译；
### 1.15.4. 变量
- “obj = main.o add.o sub.o”,给变量（自定义的变量）赋值方式参考这行；
- 取变量的值：“$(obj)”;  
- 模式规则：“%.o:%.c”中的%用于匹配之间目标的依赖；
- makefile中有自己维护的变量(所有字母大写)，可以修改；
    - CC = gcc
    - CFLAGS：编译的时候使用的参数 –Wall –g -c
    - CPPFLAGS = -I
    - LDFLAGS ：链接库使用的选项 –L -l
- makefile中包含一些**自动变量**，自动变量只能在规则中的命令中使用；
    - "$<"：规则中的第一个依赖；
    - "$@"：规则中的目标；
    - "$^"：规则中的所有依赖； 
### 1.15.5. 函数
&emsp;&emsp;makefile中的所有函数都是有返回值的，使用的时候主要目的也是获取函数返回值。
#### 1.15.5.1. "wildcard"
- 获取某个目录下的某种格式的所有文件；
- “src=$(wildcard ./*.c)”代表获取当前目录下的所有.c文件；
#### 1.15.5.2. "patsubst"
- patsubst是一个匹配替换函数；
- “obj=$(patsubst ./\%.c, ./\%.o, \$(src))”,将src中的所有的.c文件替换称.o文件；
### 1.15.6. 伪目标
- 为了防止目标和目录里的文件重名，需要使用伪目标；
- 语法：
> .PHONY:clean
> clean:
> &emsp;&emsp;rm *.o -f
> - rm添加-f选项是为了防止文件已经被删除后再删除时报错；
> - makefile中命令前面可以加“-”，表示如果命令执行失败时忽略继续向下执行；
## 1.16. C库函数（文件IO）
- 文件IO使用的是**文件指针**（FILE* fp）
- 文件结构体中主要包含三个成员
    - 文件描述符-索引到对应磁盘文件；
    - 文件内读写指针；
    - I/O缓存区
- 文件IO操作的时候使用缓存区，默认8k大小，所以需要特殊处理才能将数据写入磁盘：
    - 刷新缓存区（fflush函数）；
    - 缓存区满；
    - 正常关闭文件
        - fclose；
        - main函数return；
        - main函数exit；
- 标准C库函数printf本质上调用的是文件IO，而文件IO调用的是linux的write函数，**write函数属于用户空间**，它会触发进入内核空间，调用系统调用sys_write：
## 1.17. 文件描述符
- linux中有虚拟地址空间的概念，32位系统是4G，0\~3G是用户空间，3~4G是内核空间；
- 虚拟地址空间本质是<font color=red>在硬盘上的</font>,但是并不是说虚拟4G就直接占用4G硬盘，而是用多少就占用多少；
- 进程控制块（PCB）在内核区，PCB内部维护文件描述符；
- 文件描述符本质是一个数组，大小是1024；
- 文件描述符0代表标准输入；
- 文件描述符1代表标准输出；
- 文件描述符2代表标准错误；
## 1.18. 系统函数
&emsp;&emsp;系统函数在man文档的第二章。
### 1.18.1. open
- “int open(const char *pathname, int flags)”
- “int open(const char *pathname, int flags, mode_t mode)”
    - patename：文件路径，可以是相对或绝对路径；
    - flags：打开方式；
        - O_RDONLY：只读打开，必选，互斥三选一
        - O_WRONLY：只写打开，必选，互斥三选一
        - O_RDWR：可读可写打开，必选，互斥三选一
        - O_APPEND：表示追加，新的内容放到文件末尾，不覆盖原先内容，可选；
        - O_CREAT：若文件不存在则创建，需要提供mode参数来配置文件权限，另有umask掩码存在；
        - O_EXCL：和O_CREAT共用，表示文件已存在则报错返回；
        - O_TRUNC：如果文件已存在，则将其长度截断为0字节；
        - O_NONBLOCK 设置文件为非阻塞状态
- 文件权限由open的mode参数和当前进程的umask掩码共同决定
- 文件存在判断使用O_EXCL和O_CREAT；
- 文件截断O_TRUNC(就是将文件大小设置为0，清空文件内容)；
- 设置文件为<font color=red>非阻塞状态：O_NONBLOCK</font>；
- 报错情况：
    - 打开文件不存在 
    - 以写方式打开只读文件(打开文件没有对应权限)
    - 以<font color=red>只写方式打开目录</font>;
### 1.18.2. close
- "int close(int fd)",fd为open函数的返回值；
- 返回值：
    - 0：正常关闭
    - 1：关闭出错，看errno；- 
### 1.18.3. read
- “ssize_t read(int fd, void *buf, size_t count)”
- 从打开的设备或文件中读取数据；
- 返回值：
    - \>0：读出的字节数
    - =0：文件读取完毕
    - -1：错误，看errno；
### 1.18.4. write
- “ssize_t write(int fd, const void *buf, size_t count)”
- 向打开的设备或文件中写数据；
- 返回值：
  - \>=0：写入文件的字节数
  - -1：错误，看errno
### 1.18.5. lseek
- “off_t lseek(int fd, off_t offset, int whence)”
- whence参数：
  - SEEK_SET：从文件头向后偏移，StartPos+offset = 0+offset = offset;
  - SEEK_CUR：从当前位置向后偏移,CurrPos+offset,offset可正可负； 
  - SEEK_END：从文件尾部向后偏移，文件长度+offset，offset可正可负；
- lseek函数作用：
    > 1. 获取文件的大小；
        - len = lseek(fd,0,SEEK_END);
    > 2. 移动文件指针；
    > 3. 文件拓展；
        - lseek(fd,20000,SEEK_END);//20000大于文件原长度；
        - write(fd,"t",1);//需要写一下才能真正拓展；

- 文件拓展的使用场景：加入是多线/进程下载一个10G大小的文件，可以使用文件拓展先占好空间，然后每个线程给指定位置下载数据就行了；
### 1.18.6. 系统函数VS库函数
<font color=red>如何判断一个函数是系统函数还是库函数?</font>
&emsp;&emsp;答：1-该函数是否访问内核数据;2-该函数是否访问外部硬件资源，只要二者有一就是系统函数，否则是库函数。

## 1.19. 文件操作函数
### 1.19.1 stat,lstat,fstat
- 获取文件属性（从inode上获取）
- 用stat可以实现命令“ls -l”的功能；
- stat函数会“穿透追踪”文件，lstat不会穿透追踪，lstat遇到软链接，读取的就是软链接的文件的大小；
- vi编辑器也会穿透操作；
- "ls -l"和"rm"指令不会穿透操作；
- fstat是在文件打开之后操作的，传入的是文件描述符；
```C
struct stat {
    dev_t         st_dev;       //文件的设备编号
    ino_t         st_ino;       //节点
    mode_t        st_mode;      //文件的类型和存取的权限
    nlink_t       st_nlink;     //连到该文件的硬连接数目，刚建立的文件值为1
    uid_t         st_uid;       //用户ID
    gid_t         st_gid;       //组ID
    dev_t         st_rdev;      //(设备类型)若此文件为设备文件，则为其设备编号
    off_t         st_size;      //文件字节数(文件大小)
    blksize_t     st_blksize;   //块大小(文件系统的I/O 缓冲区大小)
    blkcnt_t      st_blocks;    //块数
    time_t        st_atime;     //最后一次访问时间
    time_t        st_mtime;     //最后一次修改时间
    time_t        st_ctime;     //最后一次改变时间(指属性)
};
```
- st_mode
@import "Picture002_st_mode.png"
### 1.19.2. access
- 测试指定文件是否拥有某种权限
- “int access(const char *pathname, int mode)”
- mode参数：
  - R_OK：是否有读权限
  - W_OK：是否有写权限
  - X_OK：是否有执行权限
  - F_OK：测试一个文件是否存在
- 返回值：
  - 0：所有欲查核的权限都通过了检查
  - -1：权限被禁止
### 1.19.3. chmod
- 改变文件的权限 
- "int chmod( const char *filename, int pmode )",pmode必须是一个8进制数
### 1.19.4. chown
- 改变文件的所有者
- “int chown(const char *path, uid_t owner, gid_t group)”
### 1.19.5. rename
- 文件重命名，<font color=red>是否可移动文件？</font>
- 头文件：stdio.h
- "int rename(const char *oldpath, const char *newpath)"
### 1.19.6. link相关
#### 1.19.6.1. link
- 创建一个硬链接
- “int link(const char *oldpath, const char *newpath)”
#### 1.19.6.2. symlink
- 作用：创建一个软连接
#### 1.19.6.3. readlink
- 作用：读软连接对应的文件名，不是读内容
#### 1.19.6.4. unlink
- 作用：
  - 删除一个文件的目录项并减少它的链接数，若成功则返回0，否则返回-1，错误原因存于errno。
  - 如果想通过调用这个函数来成功删除文件，你就必须拥有这个文件的所属目录的写和执行权限。
- 使用：
  - 1. 如果是符号链接，删除符号链接
  - 2. 如果是硬链接，硬链接数减1，当减为0时，释放数据块和inode
  - 3. 如果文件硬链接数为0，但有进程已打开该文件，并持有文件描述符，则等该进程关闭该文件时，kernel才真正去删除该文件(利用该特性创建临时文件，先open或creat创建一个文件，马上unlink此文件)
### 1.19.7. truncate
- 将参数path 指定的文件大小改为参数length 指定的大小。如果原来的文件大小比参数length大，则超过的部分会被删去。
- "int truncate(const char *path, off_t length)"
### 1.19.8. dup
- 文件描述符复制，使得多个文件描述符指向同一个文件；
- “int dup(int oldfd)”，返回值是新的文件描述符；
- 返回值是文件描述符表中没有被占用的最小的文件描述符；
- 虽然有两个文件描述符，但是文件指针只有一个，可以同时写文件；
### 1.19.9. dup2
- 文件描述符复制，使得多个文件描述符指向同一个文件；
- “int dup(int oldfd,int newfd)”
    - 如果newfd之前已被打开，则该函数会先关闭newfd然后将oldfd的的内容(非文件描述符值)再复制给newfd；
    - 如果newfd没有打开，直接复制；
    - 返回值是oldfd的文件描述符值；
### 1.19.10. fcntl
- 改变已经打开的文件的属性；
- 头文件：fcntl.h
- “int fcntl（int fd, int cmd）”
- “int fcntl（int fd, int cmd, long arg）”
- “int fcntl（int fd, int cmd, struct flock *lock）”
- 功能：
  - 复制一个现有的描述符，cmd：F_DUPFD
  - 获得／设置文件描述符标记，cmd：F_SETFD，F_GETFD
  - 获得／设置异步I/O所有权，cmd：F_GETOWN，F_SETOWN
  - 获得／设置记录锁，cmd：F_GETLK，F_SETLK，F_SETLKW
  - 获得／设置文件状态标记，cmd：F_GETFL，F_SETFL
    - F_SETFL
      - O_APPEND
      - O_NONBLOCK
    - F_GETFL
      - O_RDONLY
      - O_WRONLY
      - O_RDWR
      - O_EXEC：执行方式打开
      - O_SEARCH：搜索打开目录
      - O_APPEND
      - O_NONBLOCK

## 1.20. 目录操作
### 1.20.1 chdir
- 修改当前进程的路径
- "int chdir(const char *path)"
### 1.20.2. getwd
- 获取当前进程工作目录
- "char *getcwd(char *buf, size_t size)"
### 1.20.3. mkdir
- 创建目录
- "int mkdir(const char *pathname, mode_t mode)"
- 创建的目录需要有执行权限，否则无法进入目录
### 1.20.4. rmdir
- 删除一个空目录
- "int rmdir(const char *pathname)"
### 1.20.5. opendir
- 打开一个目录
- "DIR *opendir(const char *name)"
- 返回值：
  - DIR结构指针，该结构是一个内部结构，保存所打开的目录信息，作用类似于FILE结构
  - 函数出错返回 NULL
### 1.20.6. readdir
- 读目录
- "struct dirent *readdir(DIR *dirp)"
- -D_BSD_SOURCE,编译时添加宏定义
- 返回值：返回一条记录项
    ```C
    struct dirent
    {
        ino_t  d_ino;// 此目录进入点的inode     
        ff_t   d_off;// 目录文件开头至此目录进入点的位移
        signed short int d_reclen; //d_name 的长度,不包含NULL 字符
        unsigned char d_type;//d_name所指的文件类型 
        har    d_name[256];//文件名
    };    
    ```
- d_type:
    - DT_BLK - 块设备
    - DT_CHR - 字符设备
    - DT_DIR - 目录
    - DT_LNK - 软连接
    - DT_FIFO - 管道
    - DT_REG - 普通文件
    - DT_SOCK - 套接字
    - DT_UNKNOWN - 未知

### 1.20.7. closedir
- 关闭目录

## 1.21. errno
### 1.21.1. 定义
- errno是一个全局变量；
- 标准C库函数可对其进行修改（Linux系统函数也可以）
- 类型是：int
- 作用：记录系统的最后一次错误代码
    - 每个errno值对应着以字符串表示的错误类型
    - 当调用"某些"函数出错时，该函数会重新设置 errno 的值
### 1.21.2. 宏定义
- 第 1 - 34 个错误定义：/usr/include/asm-generic/errno-base.h
- 第 35 - 133 个错误定义：/usr/include/asm-generic/errno.h
### 1.21.3. perror
- 头文件：stdio.h
- “void perror(const char *s)”；
- 作用：
  - 用来将上一个函数发生错误的原因输出到标准设备(stderr)，此错误原因依照全局变量errno 的值来决定要输出的字符串。
  - 参数 s 所指的字符串会先打印出,后面再加上错误原因字符串
## 1.22. 疑问
1. 为什么要修改文件的所有者或所属组？
2. tty设备，pts设备怎么理解？（字符终端，桌面终端和设备终端）
3. free命令简介
4. linux怎么安全关机？
5. export和source的区别？
6. 文件IO和系统IO的区别？
7. C库函数和系统函数的区别？
8. 理解递归的思想，语法中在什么条件下才能使用递归；
9. FILE和文件描述符和进程控制块PCB和inode的关系？
10. cpu 为什么要使用虚拟地址空间与物理地址空间映射？解决了什么样的问题？
    > 答：
        1. 方便编译器和操作系统安排程序的地址分布（程序可以使用一系列相邻的虚拟地址来访问物理内存中不相邻的大内存缓冲区）；
        2. 方便进程之间隔离（不同进程使用的虚拟地址彼此隔离。一个进程中的代码无法更改正在由另一进程使用的物理内存）；
		1. 方便OS使用你那可怜的内存（程序可以使用一系列虚拟地址来访问大于可用物理内存的内存缓冲区。当物理内存的供应量变小时，内存管理器会将物理内存页（通常大小为 4 KB）保存到磁盘文件。数据或代码页会根据需要在物理内存与磁盘之间移动）。
## 1.23. 附录
strtol函数将“数字字符串”转换成数字；
sprintf函数

# 2. 系统操作
## 2.1 命令
### 2.1.1. ulimit
- "ulimit -a"：查看进程资源限制；
## 2.2. 进程
### 2.2.1. 概念
|名称|概念|位置|资源|
|:----:|:----:|:----:|:----:|
|程序|编译好的二进制文件|磁盘上|不占系统资源|
|进程|运行的程序|内存里|占用系统资源|
- **进程**：抽象概念，与操作系统原理紧密关联，是运行时的程序，在内存中执行，占用系统资源；
- **系统资源**：CPU、内存、文件描述符、设备、锁等；
### 2.2.2. 并发
- 程序设计有单道程序设计和多道程序设计之分；
- 并发：从宏观上看多个程序同时执行，微观看程序还是串行执行；
### 2.2.3. CPU
- CPU内部基本组成模块：指令预取器，指令译码器，算数逻辑单元，寄存器堆和MMU等；
- 算数逻辑单元(ALU)只能执行"+"和"<<"运算，其他运算都是这种运算模拟出来的；
### 2.2.4. 存储介质
- 网络存储->硬盘->内存->cache(缓存)->寄存器；
- 上面的存储介质从左到右，容量越来越低，存取速度越来越快，价格越来越高；
### 2.2.5. MMU
- 作用：
  - 虚拟内存地址到物理内存地址的映射；
  - 修改内存访问级别(linux内核内存访问级别两种：用户空间和内核空间)；
### 2.2.6. 进程控制块(PCB)
- linux内核中，每个进程都有一个进程控制块来维护进程信息；
- 进程控制块本质上是一个结构体：task_struct;
- 结构体定义位置：/usr/src/linux-headers-4.15.0-88/include/linux/sched.h;
- PCB主要成员：
  - 进程ID；
  - 进程状态(初始化，就绪，运行，挂起，停止)；
  - CPU寄存器(进程切换时需要保护和恢复);
  - 虚拟地址空间信息；
  - 控制终端信息；
  - 当前工作目录(chdir函数改变该值);
  - umask掩码；
  - 文件描述符表(包含多个指向FILE结构体的指针);
  - 信号相关信息；
  - 用户ID和组ID；
  - 会话和进程组(会话概念大于进程组)；
  - 进程资源上限；
## 2.3. 环境变量
### 2.3.1. 概念
- 操作系统中用来指定操作系统运行环境的一些参数(定义进程的运行环境)；
### 2.3.2. 格式
- "name=value1:value2:..."，"="两边不允许有空格；
- 本质是字符串；
- name一般由大写字母和下划线构成；
### 2.3.3. 存储
- char* []数组；
- 数组名：environ
- 内部存储字符串，NULL结尾；
- 引用(声明)方式："extern char** environ";
- 文件：environ.c
### 2.3.4. 加载
- 加载位置和命令行参数一致接近内核空间的用户空间；
### 2.3.5. 常见环境变量
#### 2.3.5.1. PATH
- 可执行文件的搜索路径；
- "echo $PATH"在shell中查看该值的方式；
- 新版本的工作目录一般往PATH前面放(shell解析器查找规则是从左往右依次查找)
#### 2.3.5.2. SHELL
- 当前shell，通常是/bin/bash;
#### 2.3.5.3. TERM
- 当前终端
#### 2.3.5.4. LANG
- 当前语言(决定了字符编码以及时间、货币等信息的显示格式);
#### 2.3.5.5. HOME
- 当前用户主目录路径(很多程序需要在主目录下保存配置文件，使得每个用户在运行该程序时都有自己的一套配置);
### 2.3.6. 命令
#### 2.3.6.1. echo
- "echo $ABC"
- 显示环境变量ABC的值
#### 2.3.6.2. export
- "export ABC="AABBCC""
- 设置一个新环境变量ABC，值为AABBCC；
- 临时有效
#### 2.3.6.3. 修改
- "ABC="QQWWEE""
- 修改ABC的值为QQWWEE
#### 2.3.6.4. env
- 显示所有的环境变量
#### 2.3.6.5. set
- 显示所有本地定义的shell环境变量；
#### 2.3.6.6. unset
- "unset ABC"
- 清除环境变量
#### 2.3.6.7. readonly
- "readonly ABC"
- 设置环境变量只读；
### 2.3.7. 函数
#### 2.3.7.1. getenv()
- "char *getenv(const char *name)"
- 获取环境变量值
- 返回值：成功返回变量值，失败返回NULL；
#### 2.3.7.2. setenv()
- "int setenv(const char *name, const char *value, int overwrite)"
- 设置环境变量的值
- 成功返回0，失败返回-1；
- overwrite
  - 非零：覆盖原有值
  - 0：不覆盖，多用于设置新环境变量；
#### 2.3.7.3. unsetenv()
- "int unsetenv(const char *name)"
- 删除环境变量
- 返回值：成功返回0，失败返回-1；
- name不存在返回成功，name为“name=”情况返回-1；
## 2.4. 进程控制
### 2.4.1. fork
- "pid_t fork(void)"
- pid_t是有符号整形(为了兼容-1),0不是有效的ID，最小有效进程ID是1(init进程)；
- 创建一个子进程
- 返回值：
  - 失败返回"-1"
  - 父进程返回子进程ID
  - 子进程返回0
- 这里需要注意的是，不是fork函数返回值有两个，而是fork之后fork函数在父子进程中各有一个，各自返回自己的；
- fork之后父进程先执行还是子进程先执行不确定，取决于内核所使用的调度算法；
### 2.4.2. 进程共享
#### 2.4.2.1. 父子进程相同之处
- 全局变量、.data、.text、栈、堆、环境变量、用户ID、宿主目录、进程工作目录、信号处理方式...
#### 2.4.2.2. 父子进程不同之处
- 进程ID、fork返回值、父进程ID、进程运行时间、闹钟(定时器)、未决信号集
- 父子进程间遵循**读时共享写时复制**的原则
#### 2.4.2.3. 父子进程共享之处
- 文件描述符(打开文件的结构体)、mmap建立的映射区
### 2.4.3. 多进程gdb调试
- gdb只能跟踪一个进程,可以在fork函数**调用之前**通过指令设置gdb跟踪父进程还是子进程，默认跟踪父进程；
  - set follow-fork-mode child 设置gdb在fork之后跟踪子进程
  - set follow-fork-mode parent 设置gdb在fork之后跟踪父进程
### 2.4.4. getpid
- "pid_t getpid(void)"
- 获取当前进程ID
### 2.4.5. getppid
- "pid_t getppid(void)"
- 获取当前进程的父进程ID
### 2.4.6. getuid
- "uid_t getuid(void)"
- 获取当前进程**实际**用户ID
### 2.4.7. geteuid
- "uid_t geteuid(void)"
- 获取当前进程**有效**用户ID
### 2.4.8. getgid
- "gid_t getgid(void)"
- 获取当前进程**使用**用户组ID
### 2.4.9. getegid
- "gid_t getegid(void)"
- 获取当前进程**有效**用户组ID
### 2.4.10. 循环创建多个子进程
```C
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv,char* argc[])
{
	unsigned int i,cnt;
	pid_t pid = 0;

	if(argv < 2)
	{
		printf("请传入创建子进程个数参数！\n");
		exit(-1);
	}
	printf("进程开始!\n");
	
	cnt = strtol(argc[1],NULL,10);
	printf("要创建的子进程个数为：%d\n",cnt);
	for(i=0;i<cnt;i++)
	{
		pid = fork();

		if(-1 == pid)
		{
			perror("创建子进程出错！\n");
			exit(-1);
		}
		if(0 == pid)
		{
			break;
		}
	}
	
	sleep(i);

	if(i<cnt)
	{
		
		printf("我是第%d个子进程\n",i+1);
	}else
	{
		printf("我是父进程！\n");
	}

	return 0;
}
```
执行效果如下：
```
burgesskzg@BkUb:~/testDir/fork$ ./a.out 5
进程开始!
要创建的子进程个数为：5
我是第1个子进程
我是第2个子进程
我是第3个子进程
我是第4个子进程
我是第5个子进程
我是父进程！
```
## 2.5. exec系列函数
- fork之后，经常要调用exec系列函数，调用一种exec函数后，进程的用户空间代码和数据完全被新程序替换，并从新程序的启动例程开始执行；
- 调用exec不创建新进程，所以调用exec前后该进程的id不改变 ；
- exec函数一旦调用成功即执行新程序，不返回,只有失败才返回，错误值-1,所以通常直接在exec函数调用后直接调用perror()和exit()，无需if判断;
- 只有execve是真正的系统调用，其它五个函数最终都调用execve，execve在man手册第2节，其它函数在man手册第3节
- 可执行文件可以是二进制文件，也可以是Linux下可执行脚本
> l:(list) 命令行参数列表
> p:(path) 搜素file时使用path变量
> v:(vector) 使用命令行参数数组
> e:(environment) 使用环境变量数组,不使用进程原有的环境变量，设置新加载程序运行的环境变量

### 2.5.1. execl
- "int execl(const char *path, const char *arg, ...)"
- 加载一个进程，通过“路径+程序名”来加载
- 参数：
  - path为绝对路径+程序；
  - argv[0]必须和可执行程序名一样！；
  - argv[1]之后才为新进程的命令行参数；
  - 最后一个参数必须为NULL；
- 该函数可以用来加载一个自定义的程序；
- eg:execl("/bin/ls","ls","-a","-l",NULL);
### 2.5.2. execlp
- "int execlp(const char *file, const char *arg, ...)"
- 借助环境变量PATH来加载一个进程，当PATH中所有目录搜索后没有参数1(file)则出错返回；
- 参数：
  - file为可执行程序名；
  - argv[0]必须和可执行程序名一样！；
  - argv[1]之后才为新进程的命令行参数；
  - 最后有一个参数必须为NULL；
- 该函数通常用来调用系统程序，如：ls、cp等；
- eg:execl("ls","ls","-a","-l",NULL);
### 2.5.3. execle
- "int execle(const char *path, const char *arg, ..., char *const envp[])"
- 在envp[]中指定当前进程所使用的环境变量替换掉该进程继承的所有环境变量
### 2.5.4. execv
- "int execv(const char *path, char *const argv[])"
- 将所有参数构造成指针数组传递
### 2.5.5. execvp
- "int execvp(const char *file, char *const argv[])"
- 将所有参数构造成指针数组传递
### 2.5.6. execve
- "int execve(const char *path, char *const argv[], char *const envp[])"
- 在envp[]中指定当前进程所使用的环境变量替换掉该进程继承的所有环境变量
- 将所有参数构造成指针数组传递
### 2.5.7. other
- 在使用exec函数族时，一定要加上错误判断语句。因为exec很容易执行失败，其中最常见的原因有：
    - 找不到文件或路径，此时errno被设置为ENOENT；
    - 数组argv和envp忘记用NULL结束，此时errno被设置为EFAULT；
    - 没有对应可执行文件的运行权限，此时errno被设置为EACCES； 
- exec后新进程保持原进程以下特征：
    - 环境变量（使用了execle、execve函数则不继承环境变量）；
    - 进程ID和父进程ID；
    - 实际用户ID和实际组ID； 
    - 附加组ID；
    - 进程组ID；
    - 会话ID；
    - 控制终端；
    - 当前工作目录；
    - 根目录；
    - 文件权限屏蔽字；
    - 文件锁；
    - 进程信号屏蔽；
    - 未决信号；
    - 资源限制；
    - tms_utime、tms_stime、tms_cutime以及tms_ustime值;
- 对打开文件的处理与每个描述符的exec关闭标志值有关，进程中每个文件描述符有一个exec关闭标志（FD_CLOEXEC），若此标志设置，则在执行exec时关闭该描述符，否则该描述符仍打开。除非特地用fcntl设置了该标志，否则系统的默认操作是在exec后仍保持这种描述符打开，利用这一点可以实现I/O重定向 
```C
char *const Para[] ={"ls", "-l", "-a", NULL}; 
char *const Enir[] ={"PATH=/bin:/usr/bin", "TERM=console", NULL}; 
execl("/bin/ls", "ls", "-l", "-a", NULL); 
execv("/bin/ls", Para); 
execle("/bin/ls", "ls", "-l", "-a", NULL, Enir); 
execve("/bin/ls", Para, Enir); 
execlp("ls", "ls", "-l", "-a", NULL); 
execvp("ls", Para);
```
- <font color=red>"extern char **environ;"</font>什么作用？
## 2.6. 进程回收
### 2.6.1. 僵尸进程
- 子进程结束，父进程还未回收，子进程残留资源(PCB)还在内核中，这个时候的子进程为僵尸进程；
- 僵尸进程不能使用kill命令终止；
- <font color=red>用什么方法回收僵尸进程？</font>
### 2.6.2. 孤儿进程
- 父进程比子进程早结束，这个时候子进程变为孤儿进程，它的父进程变为init进程；
### 2.6.3. wait
- 进程终止时，操作系统的隐式回收机制：1.关闭所有文件描述符 2. 释放用户空间分配的内存，子进程结束，会在内核中保留PCB，PCB中保留退出状态
  - 正常退出保留返回值；
  - 异常退出保留信号值(linux中所有的进程异常终止都是因为收到了某个信号！);
- 父进程可以调用wait或waitpid获取子进程结束状态；
- shell可以使用"$?"获取最近一个进程结束状态；
- wait函数有三个功能：
  - 阻塞父进程；
  - 回收子进程残留资源；
  - 获取子进程退出状态；
  - "pid_t wait(int *status)"
  - 返回值：
    - 成功返回清理的子进程ID；
    - "-1"，没有需要清理的子进程时返回该值；
  - 借助宏函数来进一步判断进程终止的具体原因：
    - WIFEXITED(status)为真：进程正常结束，再使用WEXITSTATUS(status)获取返回值；
    - WIFSIGNALED(status)为真：进程异常终止，再使用WTERMSIG(status)获取使进程终止的信号**编号**；
    - WIFSTOPPED(status)：进程处于暂停状态，再使用WSTOPSIG(status)获取使进程暂停的信号的**编号**；
    - WIFCONTINUED(status)：进程暂停后又继续运行；
### 2.6.4. waitpid
- "pid_t waitpid(pid_t pid, int *status, in options)"
- 清理指定的PID**子进程**；
- 参数
  - pid
    - ">0"：回收指定PID的进程(必须是子进程)；
    - "-1"：回收任意子进程(一次回收一个)；
    - "0"：回收和当前进程一个组的所有**子进程**(一次回收一个)；
    - "<-1"：回收指定进程组内的<font color=red>所有</font>子进程(一次回收多个？);
  - options
    - "0"：阻塞等待，等同于wait；
    - "WNOHANG"：不阻塞等待，轮询处理；
- 返回值：
  - "PID"：返回回收的子进程的PID；
  - "-1"：没有子进程需要回收了？
  - "0"：当参数options为"WNOHANG"时，没有子进程结束时返回0；
### 2.6.5. waitpid使用疑问
---
- waitpid可以回收非血缘关系进程吗？
```C
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argv,char* argc[])
{
	unsigned int i;
	pid_t pid = 0;

	pid = fork();
	if(-1 == pid)
	{
		perror("创建子进程出错！\n");
		exit(-1);
	}else if(0 == pid)
	{
		printf("子进程任务!\n");
		while(-1);
		printf("子进程任务结束!\n");
	}else
	{
		printf("父进程回收非血缘进程!\n");
		if(-1 == waitpid(5455,NULL,0))
		{
			perror("回收非血缘进程失败!\n");
		}

		waitpid(pid,NULL,0);
	}

	return 0;
}
```
结果如下：
```
父进程回收非血缘进程!
回收非血缘进程失败!
: No child processes
子进程任务!
```
---
- 当pid的值为0时，每调用一个waitpid一次，回收一个同组子进程还是多个一起回收？
```C
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	unsigned int i;
	pid_t pid = 0,retPid = 0;
	pid_t pidArr[5] = {0};

	for(i=0;i<5;i++)
	{
		pid = fork();

		if(-1 == pid)
		{
			perror("创建子进程出错！\n");
			exit(-1);
		}else if(0 == pid)
		{
			break;
		}else
		{
			pidArr[i] = pid;
		}
	}

	if(i<5)
	{
		printf("第%d个子进程在这里循环!\n",i);
		while(1);
	}else
	{
		for(i=0;i<5;i++)
		{
			printf("第%d个子进程的PID是:%d\n",i,pidArr[i]);
		}
		for(i=0;i<5;i++);
		{
			retPid = waitpid(0,NULL,0);
			printf("子进程%d被回收!\n",retPid);

		}
	}

	return 0;
}
```
当程序执行后，用"ps ajx"查看进程组为6365：
```
  6365   6366   6365  97805 pts/0      6365 R+    1000   0:05 ./WaitPidTest
  6365   6367   6365  97805 pts/0      6365 R+    1000   0:05 ./WaitPidTest
  6365   6368   6365  97805 pts/0      6365 R+    1000   0:05 ./WaitPidTest
  6365   6369   6365  97805 pts/0      6365 R+    1000   0:05 ./WaitPidTest
  6365   6370   6365  97805 pts/0      6365 R+    1000   0:05 ./WaitPidTest
```
在别的终端用"kill -9 6366 6367"一次杀死多个子进程，结果如下：
```
第0个子进程的PID是:6366
第1个子进程的PID是:6367
第2个子进程的PID是:6368
第3个子进程的PID是:6369
第4个子进程的PID是:6370
第0个子进程在这里循环!
第1个子进程在这里循环!
第3个子进程在这里循环!
第2个子进程在这里循环!
第4个子进程在这里循环!
子进程6366被回收!
```
测试发现，如果每次只kill一个子进程，则有几个子进程waitpid执行几次，但当一次kill多个子进程，则只回收一个，<font color=red>父进程直接结束,未kill的子进程称为孤儿进程，需要后续查明原因？</font>

---
### 2.6.6. 疑问
- 执行了exec函数的子进程需要回收吗
-exit参数不能超过128？
- 子进程暂停导致的wait返回还需要再wait吗？
- while的判断条件必须大于0？-1也不行？
- 子进程和父进程共享文件描述符，而一个进程终止时会关闭所有文件描述符，那父进程还要使用描述符怎么办？
## 2.7. IPC(进程间通信)
&emsp;&emsp;Linux中进程地址空间相互独立，进程有不同的用户地址空间，进程的全局变量只能在本进程使用，进程之间不能相互访问，要交换数据必须通过内核，内核提供的这种机制称为进程间通信(IPC)。
&emsp;&emsp;在进程间完成数据传递要借助操作系统,方法有：文件、管道、信号、共享内存、消息队列、套接字、命名管道等，但随着计算机的发展，一些方法被弃用，现常用方法有：管道、信号、共享映射区和本地套接字。
- 管道(使用最简单)
- 信号(开销最小)
- 共享映射区(无血缘关系)
- 本地套接字(最稳定)
### 2.7.1. 管道
#### 2.7.1.1. 管道(pipe)
- 创建：
  - "int pipe(int pipefd[2])"
  - 成功返回0，失败返回-1并置errno；
  - pipefd是传出参数，函数调用成功返回两个已经打开的文件描述符，fd[0]代表读，fd[1]代表写，后续需要手动关闭；
  - 先调用pipe，在调用fork实现进程通信；
- 常见情况(阻塞I/O操作，不设置O_NONBLOCK)：
  - 读管道：
    - 管道有数据：
      - 返回实际读到的字节数；
    - 管道无数据：
      - 写端没有全部关闭，阻塞等待(让出CPU)；
      - 写端全部关闭，返回0(类似读到文件尾部)；
  - 写管道：
    - 管道读端没有全部关闭：
      - 管道未满，返回写入的实际字节数；
      - 管道已满，阻塞(让出CPU)
    - 管道读端全部关闭：
      - 进程收到SIGPIPE信号，如果没有该信号的处理函数，进程将异常终止；
- 特点：
  - 使用简单；
  - 实现原理：可以是内核缓冲区，也可以是环形队列；
  - 管道是是一个伪文件；
  - 管道由两个文件描述符引用，一个表示读端，一个表示写端，规定数据从管道的写端流入管道，从读端流出；
  - 有了有名管道(fifo)之后管道又被叫为无名管道(pipe);
  - 管道默认大小为4k(ulimit –a或fpathconf函数)；
  - 必须是有共同祖先进程(父子和兄弟进程间)的进程间才能通信；
- 缺点：
  - 写端不能读，读端不能写；
  - 数据不可反复读；
  - 双向半双工机制导致只能在一个方向传输，建立两个管道实现双向通信；
  - 必须在血缘进程之间通信；

#### 2.7.1.2. 命名管道(fifo)
- 可以在非血缘关系进程间通信；
- fifo是基础文件，进程可以read/write这个文件；
- 创建方式:
  - 命令方式："mkfifo fifoName"
  - 函数方式："int mkfifo(const char *pathname,  mode_t mode)"
#### 2.7.1.3. 疑问
- 管道共同祖先具体指什么，两个不同父进程的孙子进程之间可以通信吗？
- 怎么看管道的读端或写端被全部关闭？
- fd[0]代表读，fd[1]代表写，可以返回来吗？
### 2.7.2. 共享内存映射
#### 2.7.2.1. 概念
- 内存映射指磁盘文件与内存空间中的缓冲区映射，当从缓冲区中取数据，就相当于读文件中的相应字节，将数据写入缓冲区，相当于将字节写入文件，这样，就可不适用read和write函数，使用指针完成I/O操作。
#### 2.7.2.2. mmap函数
- "void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)",成功返回创建的映射区首地址,失败返回MAP_FAILED宏；
  - addr：建立映射区的首地址，Linux内核指定，直接传递NULL；
  - length：映射区大小；
  - prot：映射区权限，PROT_READ、PROT_WRITE、PROT_READ|PROT_WRITE等；
  - flags：设定更新物理区域、设置共享、创建匿名映射区等标志
    - MAP_SHARED：将映射区的操作反映到物理设备（磁盘）上，对于父子进程建立map时，该值表示父子进程共享映射区(父子进程共享打开的文件和mmap建立的MAP_SHARED映射区；
    - MAP_PRIVATE：映射区的修改不会反映到物理设备，对于父子进程建立map时，该值表示父子进程各自独占映射区；
  - fd：建立映射区的文件描述符
  - offset：映射文件的偏移，必须是4k的倍数,因为映射区是MMU帮助创建，页大小最小4k；
#### 2.7.2.3. 使用mmap注意事项
- 创建映射区隐含一次对文件的读操作；
- 使用MAP_SHARED要求映射区的权限小于等于文件打开的权限，MAP_PRIVATE无所谓；
- 映射区的释放与文件关闭无关，映射建立成功文件即可关闭；
- 映射文件大小为0时不能创建映射区，对于open时使用O_CREATE新建文件，需要扩展(ftruncate或lseek)文件大小。mmap报总线错误多是由于共享文件存储空间大小引起；
- munmap传入的地址一定是mmap的返回地址，不建议直接对该指针++操作；
- 文件偏移量必须为4K的整数倍；
- mmap创建映射区出错概率非常高，一定要检查返回值，确保映射区成功建立再进行后续操作
- 无血缘关系的进程间也可以使用mmap来完成通信，需要使用MAP_SHARED;
#### 2.7.2.4. munmap函数
- "int munmap(void *addr, size_t length)"，成功返回0，失败返回-1；
#### 2.7.2.5. 匿名映射
- 匿名映射：通常建立映射区要open一个文件，然后unlink和close，linux可以直接使用匿名映射来代替；
  - "int *p = mmap(NULL, 10, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0)",fd写-1；
  - MAP_ANONYMOUS和MAP_ANON两个宏是Linux特有
  - 类Unix系统使用"fd = open("/dev/zero", O_RDWR)"创建匿名映射，当然，linux中也可以这样实现。
#### 2.7.2.6. 疑问
- 先使用map，然后fork之后，父子进程都调用munmap不会出现失败的情况，为什么？
- 文件描述符关闭了，但映射区选择MAP_SHARED，还会将结果写到文件里吗？
### 2.7.3. 信号
&emsp;&emsp;POSIX.1对可靠信号例程进行了标准化。
&emsp;&emsp;进程控制块PCB包含信号的阻塞信号集和未决信号集。

#### 2.7.3.1. 特点
- 操作简单
- 满足条件才发送
- 不能携带大量信息；
- 机制类似软件中断，有很大的延时性，但是用户感受不到；
- 信号有内核检测，内核发送，内核调用处理函数；
- 四要素：
  - 编号
    - 1 ~ 31常规信号
    - 34 ~ 64实时信号
    - "kill -l"查看信号
  - 名称，本质是宏，建议使用名称，不要使用编号，好兼容不同平台；
  - 事件，每个信号代表不同事件；
  - 默认处理动作(term,ignore,core,stop,continue)
  - 信号处理方式：
    - 执行默认动作(默认动作有上面提到的五种)；
    - 忽略(先执行，执行的动作是忽略)
    - 捕捉(执行自定义函数)
#### 2.7.3.2. 信号产生
1. 按键产生
  - "Ctrl + C"：SIGINT信号，编号2
  - "Ctrl + \\"：SIGQUIT信号，编号3
  - "Ctrl + Z"：SIGTSTP信号，编号20
2. 硬件异常
  - SIGSEGV：非法访问内存，编号11，段错误
  - SIGBUS：总线错误，编号7
  - SIGFPE：除0操作产生，浮点数例外，编号8 
3. kill命令
  - "kill -信号编号/信号名称 进程ID"
  - kill函数调用时遇到"ID非法，信号非法，普通用户杀init进程等权级问题"时会失败；
4. 函数
  - kill函数，成功返回0,失败返回-1
    - 参数pid
      - ">0"：指定进程
      - "=0"：同组进程
      - "=-1"：有权限发送的所有进程
      - "<-1"：指定进程组
  - raise函数，给当前进程发送指定信号
  - abort函数，给当前进程发送SIGABRT信号；
5. 系统调用
  - alarm函数
    - 每个进程有且只有一个定时器
    - 参数单位为秒
    - 函数返回剩余秒数
    - alarm(0)表示取消定时，不是定时0秒
  - setitimer函数
    - 参数which：
      - ITIMER_REAL：自然定时，14号信号SIGALRM
      - ITIMER_VIRTUAL：程序在用户空间定时，26号信号SIGVTALRM
      - ITIMER_PROF：运行定时(内核+用户，无等待),27号信号SIGPROF
    - 函数精度是微秒；
#### 2.7.3.3. 信号集
- man 7 signal查看信号
- sigset_t类型是位图
- 作用于自定义信号集的函数
  - sigemptyset()：将某个信号集位都清0	
  - sigfillset()：将某个信号集位都置1
  - sigaddset()：将某个信号加入信号集
  - sigdelset()：将某个信号清出信号集
  - sigismember()：判断某个信号是否在信号集中
- 作用于信号屏蔽字(阻塞信号集)的函数
  - sigprocmask()：屏蔽、解除屏蔽信号屏蔽字中的某些信号
    - 参数how
      - SIG_BLOCK：设置set中信号屏蔽
      - SIG_UNBLOCK：解除set中信号屏蔽
      - SIG_SETMASK：用set替换当前屏蔽字
- 作用于未决信号集的函数
  - sigpending()：获取未决信号集
#### 2.7.3.4. 信号捕捉
- signal()，返回捕捉函数句柄
- sigaction()
  - 捕捉函数执行期间由sa_mask指定屏蔽字
  - 默认sa_flags=0，捕捉函数执行期间，被捕捉的本信号自动屏蔽  
  - 常规信号不支持排队，多次产生只记一次
  - 参数sa_handler：
    - 捕捉函数名
    - SIG_IGN表忽略
    - SIG_DFL表执行默认动作
  - sa_sigaction：指定带参数的信号捕捉函数
  - sa_mask:捕捉函数执行期间屏蔽字
  - sa_flags:
    - 0：默认动作，屏蔽本信号；
    - SA_DEFER:不自动屏蔽本信号
    - SA_SIGINFO：选用sa_sigaction来指定捕捉函数
    - SA_INTERRURT：系统调用被信号中断后，不重启
    - SA_RESTART：自动重启
#### 2.7.3.5. 竞态条件(时序竞态)
- 进程在执行时由于竞争原因，导致在多次执行时的时序不一样；
- pause函数：
  - 该函数造成进程主动挂起，等待信号唤醒，进程将处于阻塞状态，主动放弃cpu，直到有信号递达将其唤醒，信号处理函数执行完之后该函数才返回；
  - 返回值只有-1(不是错误发生)，并设置errno为EINTR；
  - 返回情况：
    - 1. 如果信号的默认处理动作是终止进程，则进程终止，pause函数没有机会返回
    - 2. 如果信号的默认处理动作是忽略，**进程继续处于挂起状态，pause函数不返回**
    - 3. 如果信号被捕捉，则信号处理函数处理之后pause返回-1，errno设置为EINTR，表示"被信号中断";
    - 4. pause收到的信号如果被屏蔽，那么pause就不能被唤醒;
  - alarm函数和pause函数可以实现sleep函数，但是存在时序竞态的问题，用sigsuspend解决；
- "int sigsuspend(const sigset_t *mask)"用于解决pause函数的时序竞态问题；
  - sigsuspend函数调用期间，进程信号屏蔽字由其参数mask确定；
  - 将某个信号从临时信号屏蔽字mask中删除，这样在调用sigsuspend时将解除对该信号的屏蔽，然后挂起等待，当sigsuspend返回时，进程的信号屏蔽字恢复为原来的值。如果原来对该信号是屏蔽态，sigsuspend函数返回后仍然屏蔽该信号
- 竞态条件跟系统负载紧密相关，体现出信号的不可靠性，系统负载越严重，信号不可靠性越强；
- 不可靠由其实现原理所致，信号通过软件方式(每次系统调用结束后，或中断处理处理结束后，需通过扫描PCB中的未决信号集，来判断是否应处理某个信号)
- 这种情况只能在编写程序过程中提早预见，主动规避，而无法通过gdb程序调试等其他手段弥补
#### 2.7.3.6. 全局变量异步I/O
- 通过加锁、解锁来解决该问题
#### 2.7.3.7. 可重入函数和不可重入函数
- 一个函数在被调用执行期间由于某种时序又被重复调用，称之为“重入”
- 定义可重入函数，函数内不能含有全局变量及static变量，不能使用malloc、free;
- 信号捕捉函数应设计为可重入函数;
- 信号处理程序可以调用的可重入函数可参阅man 7 signal
- 没有包含在上述列表中的函数大多是不可重入的，其原因为
  - 用静态数据结构
  - 调用了malloc或free
  - <font color=red>标准I/O函数</font>
#### 2.7.3.8. SIGCHLD
##### 2.7.3.8.1. 产生条件
- 子进程结束；
- 子进程收到SIGSTOP；
- 子进程收到SIGCONT(总之就是子进程状态改变)；
##### 2.7.3.8.2. 动作
- 默认动作是忽略；
- 可以捕捉该信号，在信号处理函数中回收子进程，(wait或waitpid)的结果是正确结束，不是信号打断！
- 多子进程回收情况建议在信号处理函数中使用while来回收一组，避免僵尸进程；
- "pid_t waitpid(pid_t pid, int *status, int options)"
  - options
    - WNOHANG:没有子进程结束，立即返回
    - WUNTRACED:如果子进程由于被停止产生的SIGCHLD，waitpid则立即返回
    - WCONTINUED:如果子进程由于被SIGCONT唤醒而产生的SIGCHLD，waitpid则立即返回
  - 获取status
    - WIFEXITED(status):子进程正常exit终止，返回真
      - WEXITSTATUS(status)返回子进程正常退出值
    - WIFSIGNALED(status):子进程被信号终止，返回真
      - WTERMSIG(status)返回终止子进程的信号值
    - WIFSTOPPED(status)子进程被停止，返回真
      - WSTOPSIG(status)返回停止子进程的信号值
    - WIFCONTINUED(status)
#### 2.7.3.9. 信号传参
##### 2.7.3.9.1. sigqueue
- "int sigqueue(pid_t pid, int sig, const union sigval value)",成功返回0,失败返回-1并设置errno
```C
union sigval 
{
  int   sival_int;
  void *sival_ptr;
};
```
- 向指定进程发送指定信号的同时，携带数据
- 如传地址，需注意不同进程之间虚拟地址空间各自独立，将当前进程地址传递给另一进程没有实际意义，多用于将自己进程传参，实现回调；
##### 2.7.3.9.2. sigaction
- "int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)"
```C
struct sigaction 
{
void     (*sa_handler)(int);
void     (*sa_sigaction)(int, siginfo_t *, void *);
sigset_t   sa_mask;
int       sa_flags;
};
```
- 当注册信号捕捉函数使用sa_sigaction可获取更多信息。但此时的sa_flags必须指定为SA_SIGINFO。siginfo_t可以携带各种与信号相关的数据
#### 2.7.3.10. 中断系统调用
- 系统调用可分为两类：慢速系统调用和其他系统调用
- 慢速系统调用：会使进程永远阻塞，在阻塞期间收到一个信号，该系统调用被中断,不再继续执行(早期)，也可以设定系统调用是否重启。如，read、write、pause、wait、waitpid等
- 其他系统调用：getpid、getppid、fork等
- pause的行为
  - 想中断pause，信号不能被屏蔽
  - 信号的处理方式必须是捕捉 (默认、忽略都不可以）
  - 中断后返回-1， 设置errno为EINTR(表“被信号中断”)
  - 可修改struct sigaction的sa_flags参数来设置被信号中断后系统调用是否重启
    - SA_INTERRURT不重启
    - SA_RESTART重启
    - SA_NODEFER在执行捕捉函数期间，不希望自动阻塞该信号(除非sa_mask中包含该信号)
#### 2.7.3.x. 注意
- 内核回调执行捕捉函数结束之后会调用系统调用sysreturn先返回内核；
- SIGKILL和SIGSTOP信号不允许屏蔽、忽略和捕捉，只能执行默认动作。
- 自然定时器法：指与进程状态无关，进程挂起不影响计时；
- 信号被捕捉的执行函数虽然是内核采用回调机制调用的，但是这个函数在执行期间还是在用户空间！
- 不存在0号信号
- 有些信号由于平台不同导致有多个编号，所以建议使用的时候使用名称，便于兼容； 
- root用户可以发送信号给任意用户，普通用户只能给自己创建的进程发送信号，给其他普通用户也不能发送信号；
- 子进程继承了父进程的信号屏蔽字和信号处理动作，但子进程没有继承未决信号集
- 应该在fork之前，阻塞SIGCHLD信号。注册完捕捉函数后解除阻塞
#### 2.7.3.x. 疑问
- 利用sigaddset设置9和19号信号，未决信号集不被信号屏蔽字影响，那信号屏蔽字对应位设置了吗？
- 怎么获取信号屏蔽字(阻塞信号集)的状态，只能获取未决信号集来判断吗？
- 32 33信号作用？
- 常规信号和实时信号区别？
- 屏蔽了信号之后，信号到来，如果不解除屏蔽，那进程是阻塞吗？
- 有时间验证pause不同的返回情况；
- 如果使用"kill -9 -进程组ID"来杀死进程组，那父进程还来得急回收子进程吗？
### 2.7.4. 守护进程
#### 2.7.4.1. 终端
- 进程的控制终端，控制终端的信息保存在PCB中，fork会复制PCB中的信息，因此子进程的也会有该终端，默认情况下（没有重定向）每个进程的标准输入、标准输出和标准错误输出都指向控制终端；
- 类型
  - Alt + Ctrl + F1、F2、F3、F4、F5、F6	字符终端
  - Alt + F7：图形终端
  - SSH、Telnet等：网络终端(Xshell)
  - pts (pseudo terminal slave) 指伪终端
- 进程可以通过一个特殊的设备文件/dev/tty访问它的控制终端，每个终端设备都对应一个不同的设备文件，/dev/tty提供了一个通用的接口，一个进程要访问它的控制终端既可以通过/dev/tty也可以通过该终端设备所对应的设备文件来访问；
- ttyname函数可以由文件描述符查出对应的文件名，该文件描述符必须指向一个终端设备而不能是任意文件；
  - "char *ttyname(int fd)",成功：终端名；失败：NULL，设置errno;
- 终端启动流程：
  - init --> fork --> exec --> getty --> 用户输入帐号 --> login --> 输入密码 --> exec --> bash
- **线路规程(line discipline)**像一个过滤器，对于某些特殊字符并不是让它直接通过，而是做特殊处理
- 虚拟终端或串口终端的数目是有限的，虚拟终端(字符控制终端)一般就是/dev/tty1∼/dev/tty6六个，串口终端的数目也不超过串口的数目
- 网络终端或图形终端窗口的数目却是不受限制的，它们通过伪终端（Pseudo TTY）实现的
- 一套伪终端由一个主设备（PTY Master）和一个从设备（PTY Slave）组成。主设备在概念上相当于键盘和显示器，只不过它不是真正的硬件而是一个内核模块，操作它的也不是用户而是另外一个进程。从设备和上面介绍的/dev/tty1这样的终端设备模块类似，只不过它的底层驱动程序不是访问硬件而是访问主设备。网络终端或图形终端窗口的Shell进程以及它启动的其它进程都会认为自己的控制终端是伪终端从设备，例如/dev/pts/0、/dev/pts/1等。
#### 2.7.4.2. 进程组
- 进程组，也称之为作业，代表一个或多个进程的集合，每个进程都属于一个进程组
- 操作系统设计的进程组的概念，是为了简化对多个进程的管理
- 当父进程，创建子进程的时候，默认子进程与父进程属于同一进程组。进程组ID==第一个进程ID(组长进程)。所以，组长进程标识：其进程组ID==其进程ID
- 使用kill -SIGKILL -进程组ID(负的)来将整个进程组内的进程全部杀死
- 组长进程可以创建一个进程组，创建该进程组中的进程，然后终止。只要进程组中有一个进程存在，进程组就存在，与组长进程是否终止无关，进程组生存期：进程组创建到最后一个进程离开(终止或转移到另一个进程组)
- 一个进程可以为自己或子进程或有权限的进程设置进程组ID
- pid_t getpgrp(void); 总是返回调用者的进程组ID
- pid_t getpgid(pid_t pid);	 成功：0；失败：-1，设置errno
  - 获取指定进程的进程组ID
  - 如果pid = 0，那么该函数作用和getpgrp一样
- int setpgid(pid_t pid, pid_t pgid); 	成功：0；失败：-1，设置errno
  - 改变进程默认所属的进程组。通常可用来加入一个现有的进程组或创建一个新进程组
  - <font color=red>如改变子进程为新的组，应fork后，exec前</font>
  - 权级问题。非root进程只能改变自己创建的子进程，或有权限操作的进程

#### 2.7.4.3. 会话
- 创建一个会话需要注意以下6点注意事项：
  - 调用进程不能是进程组组长，该进程变成新会话首进程(session header)
  - 该进程成为一个新进程组的组长进程。
  - 需有root权限(ubuntu不需要)
  - 新会话丢弃原有的控制终端，该会话没有控制终端
  - 该调用进程是组长进程，则出错返回
  - 建立新会话时，先调用fork, 父进程终止，子进程调用setsid
- pid_t getsid(pid_t pid); 成功：返回调用进程的会话ID；失败：-1，设置errno
  - 获取进程所属的会话ID
  - pid为0表示察看当前进程session ID
- ps ajx命令查看系统中的进程。
  - 参数a表示不仅列当前用户的进程，也列出所有其他用户的进程，
  - 参数x表示不仅列有控制终端的进程，也列出所有无控制终端的进程，
  - 参数j表示列出与作业控制相关的信息
- 组长进程不能成为新会话首进程，新会话首进程必定会成为组长进程
- pid_t setsid(void);  成功：返回调用进程的会话ID；失败：-1，设置errno
  - 创建一个会话，并以自己的ID设置进程组ID，同时也是新会话的ID
  - 调用了setsid函数的进程，既是新的会长，也是新的组长

#### 2.7.4.4. 守护进程
- Daemon(精灵)进程，是Linux中的后台服务进程，通常独立于控制终端并且周期性地执行某种任务或等待处理某些发生的事件。一般采用以d结尾的名字。
- 不受用户登录、注销的影响，一直在运行着
- 创建守护进程，最关键的一步是调用setsid函数创建一个新的Session，并成为Session Leader
- 创建守护进程模型
  - 1. 创建子进程，父进程退出,所有工作在子进程中进行形式上脱离了控制终端
  - 2. 在子进程中创建新会话,setsid()函数使子进程完全独立出来，脱离控制
  - 3. 改变当前目录为根目录,chdir()函数,防止占用可卸载的文件系统也可以换成其它路径
  - 4. 重设文件权限掩码,umask()函数,防止继承的文件创建屏蔽字拒绝某些权限,	增加守护进程灵活性
  - 5. 关闭文件描述符,继承的打开文件不会用到，浪费系统资源，无法卸载
  - 6. 开始执行守护进程核心工作
  - 7. 守护进程退出处理程序模型
#### 2.7.4.5. 疑问
- 为什么". .bashrc"会重新加载.bashrc文件？"."代表什么？ 
- 利用ttyname(0)查看标准输入的控制终端，在文字终端是/dev/tty3但是在图形下是/dev/pst/2，为什么？
- 子进程必须在exec执行之前调用setpgid改变组ID吗？
- 每次fork，子进程的组ID不等于父进程的组ID？比如bash执行程序时？
- 创建会话的进程它的进程组ID会改变？
## 2.8. 线程
### 2.8.1. 概念
- 轻量级的进程，有线程号和线程ID之分；
- 有自己的PCB，但是和其他线程共享地址空间，线程是最小的执行单位，进程是最小的资源分配单位；
### 2.8.2. 原理
- 线程和进程在底层都调用clone()函数；
- 线程有自己的PCB，但是同一个线程组里的线程PCB指向相同的三级页表(linux内核不区分线程和进程，只在用户空间区分)；
- 创建线程的进程在线程创建之后自身也编程一个线程；
- 线程可看作是寄存器和栈的集合；
- 线程是最小执行单位，进程是最小分配资源单位(Linux内核中，其他OS不一定)
- "ps -Lf [pid]"可以产看线程号(LWP)
### 2.8.3. 资源
- 共享资源
  - 文件描述符表
  - 信号处理方式
  - 工作目录
  - 用户ID和组ID
  - 内存地址空间(.bss段、.text段、.data段、heap堆和共享库)
  - 线程间共享全局变量，进程不共享全局变量，只能借助mmap；
- 非共享资源
  - 线程ID
  - 处理器现场和栈指针(内核栈)
  - 独立的栈空间(用户空间栈)
  - errno变量
  - 信号屏蔽字
  - 调度优先级
### 2.8.4. 优缺点
- 优点
  - 提高程序并发性
  - 数据共享方便
  - 开销小
- 缺点
  - 对信号支持不好
  - 库函数，不稳定
  - 编写困难，不支持GDB调式
### 2.8.5. 控制原语
#### 2.8.5.1. pthread_self
- "pthread_t pthread_self(void)",没有失败的情况，返回调用该函数的线程的ID；
  - pthread_t在linux中是无符号整数(%lu)；
  - 线程ID是进程内部的识别标志，和线程号LWP不同，两个进程间的线程ID允许相同；
  - <font color=red>不应使用全局变量 pthread_t tid在子线程中通过pthread_create传出参数来获取线程ID，而应使用pthread_self</font>
#### 2.8.5.2. pthread_create
- "int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)",成功返回0，失败直接返回错误号！
  - thread：传出参数，保存系统为我们分配好的线程ID；
  - attr：通常传NULL表示使用线程默认属性，若想使用具体属性也可以修改该参数；
  - start_routine：函数指针，指向线程主函数(线程体)，该函数运行结束，则线程结束；
  - arg：线程主函数执行期间所使用的参数
#### 2.8.5.3. pthread_exit
- "void pthread_exit(void *retval)",retval表示线程退出状态，通常传NULL;
  - 将单个线程退出,线程中，禁止使用exit函数，会导致进程内所有线程全部退出;
  - pthread_exit或者return返回的指针所指向的内存单元必须是全局的或者是用malloc分配的，不能在线程函数的栈上分配，因为当其它线程得到这个返回指针时线程函数已经退出了
#### 2.8.5.4. pthread_join
- "int pthread_join(pthread_t thread, void **retval)",成功返回0，失败直接返回错误号！
  - thread：线程ID
  - retval：存储线程结束状态
  - 调用该函数的线程将挂起等待，直到ID为thread的线程终止；
    - 如果thread线程通过return返回，retval所指向的单元里存放的是thread线程函数的返回值；
    - 如果thread线程被别的线程调用pthread_cancel异常终止掉，retval所指向的单元里存放的是常数PTHREAD_CANCELED
    - 如果thread线程是自己调用pthread_exit终止的，retval所指向的单元存放的是传给pthread_exit的参数；
    - 如果对thread线程的终止状态不感兴趣，可以传NULL给retval参数
#### 2.8.5.5. pthread_detach
- "int pthread_detach(pthread_t thread)",成功返回0，失败直接返回错误号！
  - 实现线程分离(线程主动与主控线程断开关系。线程结束后，其退出状态不由其他线程获取，而直接自己自动释放。网络、多线程服务器常用)
  - 也可使用 pthread_create函数参2(线程属性)来设置线程分离
#### 2.8.5.6. pthread_cancel
- "int pthread_cancel(pthread_t thread)"，成功返回0，失败直接返回错误号！
  - 杀死(取消)线程
  - 线程的取消并不是实时的，而有一定的延时。需要等待线程到达某个取消点(检查点)
  - 取消点：是线程检查是否被取消，并按请求进行动作的一个位置，通常是一些系统调用creat，open，pause，close，read，write..... 执行命令man 7 pthreads可以查看具备这些取消点的系统调用列表
  - 如线程中没有取消点，可以通过调用pthread_testcancel函数自行设置一个取消点
  - 被取消的线程退出值定义在Linux的pthread库中。常数PTHREAD_CANCELED的值是-1。可在头文件pthread.h中找到它的定义：#define PTHREAD_CANCELED ((void *) -1)。因此当我们对一个已经被取消的线程使用pthread_join回收时，得到的返回值为-1
  - 终止某个线程而不终止整个进程，有三种方法
    - 从线程主函数return。这种方法对主控线程不适用，从main函数return相当于调用exit;
    - 	一个线程可以调用pthread_cancel终止同一进程中的另一个线程;
    - 线程可以调用pthread_exit终止自己。
#### 2.8.5.7. pthread_equal
- "int pthread_equal(pthread_t t1, pthread_t t2)"
- 比较两个线程ID是否相等
#### 2.8.5.8. 对比
| 进程 | 线程 |
|:---:|:---:|
|fork|pthread_create|
|exit|pthread_exit|
|wait|pthread_join|
|kill|phtread_cancel|
|gitpid|pthread_self|
### 2.8.6. 线程属性
#### 2.8.6.1. 结构体
typedef struct
{
  &emsp;&emsp;int 					etachstate; 	//线程的分离状态
  &emsp;&emsp;int 					schedpolicy; 	//线程调度策略
  &emsp;&emsp;struct sched_param	schedparam; 	//线程的调度参数
  &emsp;&emsp;int 					inheritsched; 	//线程的继承性
  &emsp;&emsp;int 					scope; 		//线程的作用域
  &emsp;&emsp;size_t 				guardsize; 	//线程栈末尾的警戒缓冲区大小
  &emsp;&emsp;int					stackaddr_set; //线程的栈设置
  &emsp;&emsp;void* 				stackaddr; 	//线程栈的位置
  &emsp;&emsp;size_t 				stacksize; 	//线程栈的大小
} pthread_attr_t;
- 属性值不能直接设置，须使用相关函数进行操作，初始化的函数为pthread_attr_init，这个函数必须在pthread_create函数之前调用。之后须用pthread_attr_destroy函数来释放资源
- 默认的属性为非绑定、非分离、缺省的堆栈、与父进程同样级别的优先级
#### 2.8.6.2. 属性初始化
- "int pthread_attr_init(pthread_attr_t *attr)",成功返回0，失败直接返回错误号！
- 初始化线程属性
- 应先初始化线程属性，再pthread_create创建线程
#### 2.8.6.3. 属性销毁
- "int pthread_attr_destroy(pthread_attr_t *attr)",成功返回0，失败直接返回错误号！
- 销毁线程属性所占用的资源
#### 2.8.6.4. 分离状态设置
- "int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate)",设置线程属性为分离或非分离状态，
- "int pthread_attr_getdetachstate(pthread_attr_t *attr, int *detachstate)",获取线程的分离状态；
- PTHREAD_CREATE_DETACHED：分离线程
- PTHREAD _CREATE_JOINABLE：非分离线程
- 非分离状态：线程的默认属性是非分离状态，这种情况下，原有的线程等待创建的线程结束。只有当pthread_join()函数返回时，创建的线程才算终止，才能释放自己占用的系统资源
- 分离状态：分离线程没有被其他的线程所等待，自己运行结束了，线程也就终止了，马上释放系统资源
- 注意，如果设置一个线程为分离线程，而这个线程运行又非常快，它很可能在pthread_create函数返回之前就终止了，它终止以后就可能将线程号和系统资源移交给其他的线程使用，这样调用pthread_create的线程就得到了错误的线程号。要避免这种情况可以采取一定的同步措施，最简单的方法之一是可以在被创建的线程里调用pthread_cond_timedwait函数，让这个线程等待一会儿，留出足够的时间让函数pthread_create返回。设置一段等待时间，是在多线程编程里常用的方法。但是注意不要使用诸如wait()之类的函数，它们是使整个进程睡眠，并不能解决线程同步的问题
#### 2.8.6.5. 栈地址设置
- "int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr, size_t stacksize)",成功返回0，失败直接返回错误号！
- "int pthread_attr_getstack(pthread_attr_t *attr, void **stackaddr, size_t *stacksize)",成功返回0，失败直接返回错误号！
- 当进程栈地址空间不够用时，指定新建线程使用由malloc分配的空间作为自己的栈空间
- POSIX.1定义了两个常量_POSIX_THREAD_ATTR_STACKADDR 和_POSIX_THREAD_ATTR_STACKSIZE检测系统是否支持栈属性。也可以给sysconf函数传递_SC_THREAD_ATTR_STACKADDR或 _SC_THREAD_ATTR_STACKSIZE来进行检测
#### 2.8.6.6. 栈大小设置
- "int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize)",成功返回0，失败直接返回错误号！
- "int pthread_attr_getstacksize(pthread_attr_t *attr, size_t *stacksize)",成功返回0，失败直接返回错误号！
- 当系统中有很多线程时，可能需要减小每个线程栈的默认大小，防止进程的地址空间不够用，当线程调用的函数会分配很大的局部变量或者函数调用层次很深时，可能需要增大线程栈的默认大小。
#### 2.8.6.7. NPTL
- NPTL实现机制(POSIX)，Native POSIX Thread Library
- 察看当前pthread库版本getconf GNU_LIBPTHREAD_VERSION
- 使用线程库时gcc指定 –lpthread
#### 2.8.7. 注意事项
- 主线程退出其他线程不退出，主线程应调用pthread_exit
- 避免僵尸线程
  - pthread_join
  - pthread_detach
  - pthread_create指定分离属性
- malloc和mmap申请的内存可以被其他线程释放
- 应避免在多线程模型中调用fork除非，马上exec，子进程中只有调用fork的线程存在，其他线程在子进程中均pthread_exit
- 信号的复杂语义很难和多线程共存，应避免在多线程引入信号机制
- 线程ID和LWP(线程号)不一样，线程号是内核用来分配时间片的依据，而线程ID是进程在内部用来区分不同线程时使用！
- 线程创建的时候不能使用指针传递，要使用值传递(立马拷贝)，值传递，在64位其实不影响！小类型变大类型再变回来不会有影响！
- 当创建线程的时候如果创建线程的函数会用jion等待子线程的时候，可以用指针传参，这时候主线程函数的所有内容还存在，获取该地址的内容也不会出错。但是如果不需要等待子线程结束而直接向下运行的时候，传参就有可能出现问题，就是创建线程的函数执行完成后，其所占的空间会被释放而值被改变，而创建的线程此时会根据参数地址去取其值，但是此空间已经被改变，所以再取内容会出错。
- pthread_self函数没有失败的情况！
- pthread_detach线程分离，进程没有与之对应的函数，不是execl的对应，线程里执行exec函数会造成整个进程(多个线程)损坏(待验证)，所以线程中多用system函数(先建子进程，再执行命令)；
- 对分离的线程回收函数返回值错误码22，表示不能对分离的线程回收；
- 对一个已经回收了的线程再回收，函数返回值是3；
- 调用pthread_cancel杀死一个线程，对该线程回收时，函数返回值是"-1"；
- pthread_cancel函数不是实时的，有延时，需要线程被取消的线程到达某个取消点，如果只有一个while(1)循环，里面没有任何操作，线程是无法杀死的，pthread_testcancel手动添加取消点；
## 2.9. 线程同步
### 2.9.1. 概念
- 线程同步，指一个线程发出某一功能调用时，在没有得到结果之前，该调用不返回。同时其它线程为保证数据一致性，不能调用该功能。
- "同步"是为了避免数据混乱，解决与时间有关的错误，不仅线程间需要同步，进程间、信号间等都需要同步机制(多个控制流共同操作一个共享资源的情况都需要同步);
### 2.9.2. 同步原因
- 资源共享（独享资源则不会）
- 调度随机（意味着数据访问会出现竞争）
- 线程间缺乏必要的同步机制
- 以上三点中，前两点不能改变，只能从第三点着手解决，使多个线程在访问共享资源的时候，出现互斥；
### 2.9.3. 互斥量
- mutex：互斥量、互斥锁
- 每个线程在对资源操作前都尝试先加锁，成功加锁才能操作，操作结束解锁
- 当A线程对某个全局变量加锁访问，B在访问前尝试加锁，拿不到锁，B阻塞。C线程不去加锁，而直接访问该全局变量，依然能够访问，但会出现数据混乱，互斥锁实质上是操作系统提供的一把“建议锁”（又称“协同锁”），建议程序中有多线程访问共享资源的时候使用该机制。但，并没有强制限定，即使有了mutex，如果有线程不按规则来访问数据，依然会造成数据混乱
- 函数：
  - pthread_mutex_init函数，初值1
	- pthread_mutex_destroy函数
	- pthread_mutex_lock函数
	- pthread_mutex_trylock函数
	- pthread_mutex_unlock函数
	- 成功返回0，失败直接返回错误号！
	- pthread_mutex_t 类型，其本质是一个结构体。为简化理解，应用时可忽略其实现细节，简单当成整数看待
	- pthread_mutex_t mutex; 变量mutex只有两种取值1、0
	- restrict关键字：只用于限制指针，告诉编译器，所有修改该指针指向内存中内容的操作，只能通过本指针完成。不能通过除本指针以外的其他变量或指针修改
- 如果互斥锁 mutex 是静态分配的（定义在全局，或加了static关键字修饰），可以直接使用宏进行初始化。e.g.  pthead_mutex_t muetx = PTHREAD_MUTEX_INITIALIZER；2.	动态初始化：局部变量应采用动态初始化。e.g.  pthread_mutex_init(&mutex, NULL)
- lock尝试加锁，如果加锁不成功，线程阻塞，阻塞到持有该互斥量的其他线程解锁为止。
- unlock主动解锁函数，同时将阻塞在该锁上的所有线程全部**唤醒**，至于哪个线程先被唤醒，取决于优先级、调度。默认：先阻塞、先唤醒。
- trylock加锁失败直接返回错误号（如：EBUSY），不阻塞
- 在访问共享资源前加锁，访问结束后立即解锁。锁的“粒度”应越小越好
- 死锁
  - 线程试图对同一个互斥量A加锁两次
  - 线程1拥有A锁，请求获得B锁；线程2拥有B锁，请求获得A锁
- 避免死锁的方法：
  - 当得不到所有所需资源时，放弃已经获得的资源，等待。
  - 保证资源的获取顺序，要求每个线程获取资源的顺序一致。如：A获取顺序1、2、3；B顺序应也是1、2、3。若B为3、2、1则易出现死锁现象
### 2.9.4. 读写锁
- 与互斥量类似，但读写锁允许更高的并行性。其特性为：写独占，读共享
- 一把读写锁具备三种状态
  - 读模式下加锁状态 (读锁)
  - 写模式下加锁状态 (写锁)
  - 不加锁状态
- 特性
  - 读写锁是“写模式加锁”时， 解锁前，所有对该锁加锁的线程都会被阻塞
  - 读写锁是“读模式加锁”时， 如果线程以读模式对其加锁会成功；如果线程以写模式加锁会阻塞
  - 读写锁是“读模式加锁”时， 既有试图以写模式加锁的线程，也有试图以读模式加锁的线程。那么读写锁会阻塞随后的读模式锁请求。优先满足写模式锁。读锁、写锁并行阻塞，写锁优先级高
  - 读写锁非常适合于对数据结构读的次数远大于写的情况
- 函数
  - pthread_rwlock_init函数
	- pthread_rwlock_destroy函数
	- pthread_rwlock_rdlock函数  
	- pthread_rwlock_wrlock函数
	- pthread_rwlock_tryrdlock函数
	- pthread_rwlock_trywrlock函数
	- pthread_rwlock_unlock函数
  - 成功返回0，失败直接返回错误号！
  - pthread_rwlock_t类型	用于定义一个读写锁变量
### 2.9.5. 条件变量
- 条件变量本身不是锁！但它也可以造成线程阻塞。通常与互斥锁配合使用。给多线程提供一个会合的场所
- 函数
  - pthread_cond_init函数
	- pthread_cond_destroy函数
	- pthread_cond_wait函数
	- pthread_cond_timedwait函数
	- pthread_cond_signal函数
	- pthread_cond_broadcast函数
	- 成功返回0，失败直接返回错误号！
	- pthread_cond_t类型	用于定义条件变量
	- 可以使用静态初始化的方法，初始化条件变量：pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
- pthread_cond_wait函数，阻塞等待一个条件变量
  - 阻塞等待条件变量cond满足，释放已掌握的互斥锁(这两部是原子操作)；
  - 当被唤醒，pthread_cond_wait函数返回时，解除阻塞并重新申请获取互斥锁(但会出现没有抢上资源的问题，建议while判断)；
- pthread_cond_timedwait函数，限时等待一个条件变量
  - 参数三看man sem_timedwait函数，查看struct timespec结构体
  - 形参abstime：绝对时间(time(NULL)返回的就是绝对时间。而alarm(1)是相对时间，相对当前时间定时1秒)
    - time_t cur = time(NULL); 获取当前时间。
    - struct timespec t;	定义timespec 结构体变量t
		- t.tv_sec = cur+1; 定时1秒
- 相较于mutex而言，条件变量可以减少竞争
- 如直接使用mutex，除了生产者、消费者之间要竞争互斥量以外，消费者之间也需要竞争互斥量，但如果汇聚（链表）中没有数据，消费者之间竞争互斥锁是无意义的。有了条件变量机制以后，只有生产者完成生产，才会引起消费者之间的竞争。提高了程序效率
### 2.9.6. 信号量
- 由于互斥锁的粒度比较大，如果我们希望在多个线程间对某一对象的部分数据进行共享，使用互斥锁是没有办法实现的，只能将整个数据对象锁住。这样虽然达到了多线程操作共享数据时保证数据正确性的目的，却无形中导致线程的并发性下降。线程从并行执行，变成了串行执行。与直接使用单进程无异
- 信号量，是相对折中的一种处理方式，既能保证同步，数据不混乱，又能提高线程并发
- 函数
  - sem_init函数，参数pshared取0用于线程间；取非0（一般为1）用于进程间
	- sem_destroy函数
	- sem_wait函数
	- sem_trywait函数	
	- sem_timedwait函数	
	- sem_post函数
  - 成功返回0，失败返回-1同时设置errno；
  - sem_t类型，本质仍是结构体。但应用期间可简单看作为整数，忽略实现细节
- 由于sem_t的实现对用户隐藏，所以所谓的++、--操作只能通过函数来实现，而不能直接++、--符号；
- 信号量的初值，决定了占用信号量的线程的个数？
### 2.9.7. 进程间同步
#### 2.9.7.1. 互斥量
- 进程间也可以使用互斥锁，来达到同步的目的。但应在pthread_mutex_init初始化之前，修改其属性为进程间共享
- pthread_mutexattr_t mattr类型：用于定义mutex锁的**属性**
- pthread_mutexattr_init函数：初始化一个mutex属性对象
- pthread_mutexattr_destroy函数：销毁mutex属性对象 (而非销毁锁)
- pthread_mutexattr_setpshared函数：修改mutex属性
  - 线程锁：PTHREAD_PROCESS_PRIVATE (mutex的默认属性即为线程锁，进程间私有)
  - 进程锁：PTHREAD_PROCESS_SHARED
#### 2.9.7.2. 文件锁
- 借助 fcntl函数来实现锁机制。	操作文件的进程没有获得锁时，可以打开，但无法执行read、write操作
- "int fcntl(int fd, int cmd, ... /* arg */ )"
- 参数二cmd：
  - F_SETLK (struct flock *)	设置文件锁（trylock）
  - F_SETLKW (struct flock *) 设置文件锁（lock）W --> wait
  - F_GETLK (struct flock *)	获取文件锁
- 参数三
   struct flock {
              ...
              short l_type;    	锁的类型：F_RDLCK 、F_WRLCK 、F_UNLCK
              short l_whence;  	偏移位置：SEEK_SET、SEEK_CUR、SEEK_END 
              off_t l_start;   		起始偏移：1000
              off_t l_len;     		长度：0表示整个文件加锁
              pid_t l_pid;     	持有该锁的进程ID：(F_GETLK only)
              ...
         };
- 依然遵循“读共享、写独占”特性。但！如若进程不加锁直接操作文件，依然可访问成功，但数据势必会出现混乱
## 2.10. 提示
- 使用互斥量来加锁解锁时，粒度(共享资源处加锁，不要多加)越小越好！
- 条件变量：在需要获取的资源没有的情况才调用wait！另外，就算被唤醒了，但可能由于等待的线程较多而不一定能抢上资源，所以应该用while而不是if判断资源的是否没有！
- 可以利用一个互斥量(互斥锁)和一个条件变量实现生产者消费者模型！
- 可以利用两个信号量和一个队列实现生产者消费者模型！
- IPC:管道(有名和无名)、信号，共享映射区、本地套接字等；
- 线程同步：互斥量(互斥锁pthread_mutex)、读写锁(pthread_rwlock)、条件变量(pthread_cond)、信号量(sem)
- 进程同步：信号量(sem)、互斥量(pthread_mutex，需要借助mmap实现在进程间访问)、文件锁
## 2.11.疑问：
- return和exit和pthread_exit的区别，在没有线  程的代码中和有线程的代码中的使用注意事项？

- 线程下给用于返回的局部变量(结构体变量)malloc回来的空间在哪回收？  
  (方法一，creat的时候将malloc好的空间传进去，线程内取空间做返回使用；方法二，join线程定义一级指针，取地址变二级指针传进线程，线程malloc出一级指针，然后返回一级指针即可)

- 线程回收有没有不阻塞的方法，要不然太浪费？

- 使用读写锁的时候应该也会有死锁的问题出现把？

- 信号量初始化的时候为零，可不可以通过post多次++sem，怎么限制一个信号量可以被几个线程使用？

- 哲学家吃饭问题？

## 疑问
1. 嵌入式开发中，MMU的映射表谁来设置填写？
2. 命令行参数是什么？boot给kernel传递的又是什么？
3. UTF-8代表简体中文；
4. 用户空间的程序与设备通信的方法：
  - 通过ioperm获取操作IO端口的权限，然后用inb/inw/ inl/ outb/outw/outl等函数，避开设备驱动程序，直接去操作IO端口？
  - 用ioctl函数去操作/dev目录下对应的设备，这是设备驱动程序提供的接口。像键盘、鼠标和触摸屏等输入设备一般都是这样做的？
  - 用write/read/mmap去操作/dev目录下对应的设备，这也是设备驱动程序提供的接口。像framebuffer等都是这样做的？
5. system()函数和exec系列函数的区别？
6. 哪些函数必须要调用chdir之后才能执行成功？
  - stat?
  - scandir?
7. snprintf和printf和put等？scanf、fgets、fprintf等的使用？
8. printf函数中怎么匹配，%d,%u等各代表什么？
9. 0、1、2和stdin,stdout,stderr，和FILE_STDIN等都是文件描述符？
10. stat函数传入路径不存在会怎么办？
11. select和epoll函数
12. 挂起会失去CPU吗(pause函数和sigsuspend函数)？挂起和阻塞的区别？
13. 出现段错误怎么处理？
    答：带"-g"编译，用gdb打开可执行程序，run，停止的位置就是段错误出现的位置。
14. 什么是段错误，浮点数例外，总线错误等？
15. 标准IO和文件IO的区别？
16. 时序竞态、全局变量的异步IO和可重入不可重入函数的使用技巧和如何避免？
17. POSIX.1和BSD和System V的区别？

## 备注
- /dev/zero和/dev/null一个读一个写，大小无限；
- I/O操作是最能拖慢执行效率的操作，优化程序时可以最先从这里下手；
- 所有的系统调用都是原子操作！- 
- 可以用malloc申请0字节大小的空间，且可以释放！

## 模块
---

总结以下时间
time()函数
timespace结构体
timeval结构体；
time_t 类型 
绝对时间(pthread_cond_timedwait,sem_timedwait)，相对时间(setitimer())
sleep
struct timeval time_start, time_end;
gettimeofday(&time_start, nullptr);
  AM_SYSTEM(cmd);
gettimeofday(&time_end, nullptr);

---

pos = str.find("\t")，pos必须定义为 string::size_type，
最好的办法是直接比较：if (str.find("\t") == string::npos) { … } 
 c++中 npos 是这样定义的：static const size_type npos = -1;
 string::size_type 由字符串配置器 allocator 定义
 (unsigned long)-1 和 (unsigned short)-1 不同，类似原因有时都是-1却返回false；

---

cat /proc/mounts得到当前系统挂载的文件系统：
 /dev/mmcblk1p1 /sdcard vfat rw,relatime,fmask=0022,dmask=0022,codepage=437,iocharset=iso8859-1,shortname=mixed,errors=remount-ro 0 0
后面的选项是什么意思？不同平台/proc/mounts的输出格式都是这样的吗？

---

#include<unistd.h>
void sync(void);
int fsync(int filedes);
int fdatasync(int filedes);
返回值：若成功则返回0,出错则返回 -1
sync 函数只是将所有修改过的块缓冲区排入写队列，然后就返回，它并不等待实际写磁盘操作结束。
通常称为 update的系统守护进程会周期性的（一般每隔30秒）调用sync函数。保证了定期冲洗内核的块缓冲区。命令 sync也调用sync函数。
fsync函数只对由文件描述符 filedes 指定的单一文件起作用，并且等待写磁盘操作结束，然后返回。
fdatasync函数类似于 fsync，但它只影响文件的数据部分。
"echo 3 > /proc/sys/vm/drop_caches":手动清除缓存cache
Buffers:被OS buffer（written to disk）住的内存.buffer用于存放要输出到disk(块设备)的数据
Cache：存放从disk上读出的数据。 Buffer和cache是为了提高IO性能并由OS管理
-buffer/cache：一个应用程序认为系统被用掉多少内存；=used-buffers-cached
+buffer/cache：一个应用程序认为系统还有多少内存； = ? + buffers+cached

---

Free命令读取的数据都是从：cat /proc/meminfo中读取的
查看进程内存使用情况：
ps aux
top
free
pmap
cat /proc/pid/smaps
cat /proc/pid/maps
cat /proc/pid/statm

---

SOC的地址空间只有4G，那它是怎么管理8G的eMMC的？
SOC的启动过程到底是什么样的？

---

使用dd指令，对磁盘进行连续写入，不使用内存缓冲区，每次写入8k的数据，总共写入20万次，产生1.6G大小的文件。
dd if=/dev/zero of=/data01/test.dbf bs=8k count=200000 conv=fdatasync

---

金步国：http://www.jinbuguo.com/
https://www.iteye.com/blog/elf8848-2088986
内核编程规范和代码风格：https://www.cnblogs.com/trav/p/10356415.html

阅读一篇DDR文档；
阅读一篇解串器文档；
阅读一篇摄像头sensor文档；
阅读一篇视频编解码文档；
阅读shell脚本编程；
阅读lua编程；

<div style="font-size: 9px; margin-left: 1cm;"> <span class='pageNumber'></span> / <span class='totalPages'></span></div><div style="font-size: 9px; margin-left: auto; margin-right: 1cm; "> <span class=“say”>BurgessKzg</span></div>


VT100终端

添加线程函数"pthread_setname_np"相关笔记