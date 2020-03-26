[TOC]

# 1. 典型协议

## 1.1. 网络接口层相关

- ARP协议
  
> &emsp;&emsp;ARP协议是正向地址解析协议（Address Resolution Protocol），通过已知的IP，寻找对应主机的MAC地址

- RARP协议
  
> &emsp;&emsp;RARP是反向地址转换协议，通过MAC地址确定IP地址。

## 1.2. 网络层相关

- IP协议
  
> &emsp;&emsp;传输控制协议(Transmission Control Protocol)**是一种面向连接的、可靠的、基于字节流的传输层通信协议

- ICMP协议
  
> &emsp;&emsp;协议是Internet控制报文协议（Internet Control Message Protocol）它是TCP/IP协议族的一个子协议，用于在IP主机、路由器之间传递控制消息

- IGMP协议
  
> &emsp;&emsp;IGMP协议是 Internet 组管理协议（Internet Group Management Protocol），是因特网协议家族中的一个组播协议。该协议运行在主机和组播路由器之间。

## 1.3. 传输层相关

- TCP协议
  
> &emsp;&emsp;TCP传输控制协议（Transmission Control Protocol）是一种面向连接的、可靠的、基于字节流的传输层通信协议。

- UDP协议
  
> &emsp;&emsp;UDP用户数据报协议（User Datagram Protocol）是OSI参考模型中一种无连接的传输层协议，提供面向事务的简单不可靠信息传送服务。

## 1.4. 应用层相关

- HTTP协议
  
> &emsp;&emsp;HTTP超文本传输协议（Hyper Text Transfer Protocol）是互联网上应用最为广泛的一种网络协议

- FTP协议
  
> &emsp;&emsp;FTP文件传输协议（File Transfer Protocol）

- SSH协议

# 2. 网络应用程序架构

## 2.1. C/S模型

### 2.1.1. 简介
> &emsp;&emsp;传统的网络应用设计模式，客户机(client)/服务器(server)模式。需要在通讯两端各自部署客户机和服务器来完成数据通信。

### 2.1.2. 优点
> - 客户端位于目标主机上可以保证性能，将数据缓存至客户端本地，从而提高数据传输效率；
> - 一般来说客户端和服务器程序由一个开发团队创作，所以他们之间所采用的协议相对灵活；
> - 可以在标准协议的基础上根据需求裁剪及定制；

### 2.1.3. 缺点
> - 由于客户端和服务器都需要有一个开发团队来完成开发,工作量将成倍提升，开发周期较长;
> - 从用户角度出发，需要将客户端安插至用户主机上，对用户主机的安全性构成威胁;

### 2.1.4. 应用
> - 传统的网络应用程序及较大型的网络应用程序都首选C/S模式进行开发:
>   - 知名的网络游戏魔兽世界
>    - 3D画面，数据量庞大，使用C/S模式可以提前在本地进行大量数据的缓存处理，从而提高观感

## 2.2. B/S模型

### 2.2.1. 简介
> &emsp;&emsp;浏览器()/服务器(server)模式。只需在一端部署服务器，而另外一端使用每台PC都默认配置的浏览器即可完成数据的传输。

### 2.2.2. 优点
> - 由于它没有独立的客户端，使用标准浏览器作为客户端，其工作开发量较小，只需开发服务器端即可；
> - 由于其采用浏览器显示数据，因此移植性非常好，不受平台限制；

### 2.2.3. 缺点
> - 由于使用第三方浏览器，因此网络应用支持受限；
> - 没有客户端放到对方主机上，缓存数据不尽如人意，从而传输数据量受到限制，应用的观感大打折扣；
> - 必须与浏览器一样，采用标准http协议进行通信，协议选择不灵活；

### 2.2.4. 应用
> - 偷菜游戏

# 3. 分层模型

## 3.1. OSI七层模型

## 3.2. TCP/IP四层模型


markdown滚动条：https://blog.csdn.net/weixin_34026276/article/details/93664191



网络中是否存在这样一个节点，它的WAN口来自两个或两个以上？
nc命令client，server有对应命令吗？
toupper
tolower

<style type="text/css"> 
.scroll 
{  
    width: 600px;/*宽度*/  
    height: 600px;/*高度*/  
    color: ;/*颜色*/  
    font-family:黑体;/*字体*/  
    padding-left: 10px;/*层内左边距*/  
    padding-right: 10px;/*层内右边距*/  
    padding-top: 10px;/*层内上边距*/  
    padding-bottom: 10px;/*层内下边距*/  
    overflow-x: scroll;/*横向滚动条(scroll:始终出现;auto:必要时出现;*/  
    overflow-y: scroll;/*竖向滚动条*/  
}  
</style>

<html>
<body>  
<div class="scroll"> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define UEVENT_BUFFER_SIZE 2048

static int init_hotplug_sock()
{
const int buffersize = 1024;
int ret;

struct sockaddr_nl snl;
bzero(&snl, sizeof(struct sockaddr_nl));
snl.nl_family = AF_NETLINK;
snl.nl_pid = getpid();
snl.nl_groups = 1;

int s = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
if (s == -1)
{
perror("socket");
return -1;
}
setsockopt(s, SOL_SOCKET, SO_RCVBUF, &buffersize, sizeof(buffersize));

ret = bind(s, (struct sockaddr *)&snl, sizeof(struct sockaddr_nl));
if (ret < 0)
{
perror("bind");
close(s);
return -1;
}

return s;
}

int main(int argc, char* argv[])
{
int hotplug_sock = init_hotplug_sock();

while(1)
{
/* Netlink message buffer */
char buf[UEVENT_BUFFER_SIZE * 2] = {0};
recv(hotplug_sock, &buf, sizeof(buf), 0);
printf("%s\n", buf);

/* USB 设备的插拔会出现字符信息，通过比较不同的信息确定特定设备的插拔，在这添加比较代码 */

}
return 0;
}
</div> 
</body> 
</html>









#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define UEVENT_BUFFER_SIZE 2048

static int init_hotplug_sock()
{
const int buffersize = 1024;
int ret;

struct sockaddr_nl snl;
bzero(&snl, sizeof(struct sockaddr_nl));
snl.nl_family = AF_NETLINK;
snl.nl_pid = getpid();
snl.nl_groups = 1;

int s = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
if (s == -1)
{
perror("socket");
return -1;
}
setsockopt(s, SOL_SOCKET, SO_RCVBUF, &buffersize, sizeof(buffersize));

ret = bind(s, (struct sockaddr *)&snl, sizeof(struct sockaddr_nl));
if (ret < 0)
{
perror("bind");
close(s);
return -1;
}

return s;
}

int main(int argc, char* argv[])
{
int hotplug_sock = init_hotplug_sock();

while(1)
{
/* Netlink message buffer */
char buf[UEVENT_BUFFER_SIZE * 2] = {0};
recv(hotplug_sock, &buf, sizeof(buf), 0);
printf("%s\n", buf);

/* USB 设备的插拔会出现字符信息，通过比较不同的信息确定特定设备的插拔，在这添加比较代码 */

}
return 0;
}
















