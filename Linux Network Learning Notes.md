[TOC]

# 1. 典型协议

## 1.1. 网络接口层相关

- ARP协议
    > ARP协议是正向地址解析协议（Address Resolution Protocol），通过已知的IP，寻找对应主机的MAC地址

- RARP协议
    > RARP是反向地址转换协议，通过MAC地址确定IP地址。

## 1.2. 网络层相关

- IP协议
    > 传输控制协议(Transmission Control Protocol)**是一种面向连接的、可靠的、基于字节流的传输层通信协议

- ICMP协议
    > 协议是Internet控制报文协议（Internet Control Message Protocol）它是TCP/IP协议族的一个子协议，用于在IP主机、路由器之间传递控制消息

- IGMP协议
    > IGMP协议是 Internet 组管理协议（Internet Group Management Protocol），是因特网协议家族中的一个组播协议。该协议运行在主机和组播路由器之间。

## 1.3. 传输层相关

- TCP协议
    > TCP传输控制协议（Transmission Control Protocol）是一种面向连接的、可靠的、基于字节流的传输层通信协议。

- UDP协议
    > UDP用户数据报协议（User Datagram Protocol）是OSI参考模型中一种无连接的传输层协议，提供面向事务的简单不可靠信息传送服务。

## 1.4. 应用层相关

- HTTP协议
    > HTTP超文本传输协议（Hyper Text Transfer Protocol）是互联网上应用最为广泛的一种网络协议

- FTP协议
    > FTP文件传输协议（File Transfer Protocol）

- SSH协议

# 2. 网络应用程序架构

## 2.1. C/S模型

### 2.1.1. 简介
> 传统的网络应用设计模式，客户机(client)/服务器(server)模式。需要在通讯两端各自部署客户机和服务器来完成数据通信。
### 2.1.2. 优点

### 2.1.3. 缺点

### 2.1.4. 应用

## 2.2. B/S模型

### 2.2.1. 简介
> 浏览器()/服务器(server)模式。只需在一端部署服务器，而另外一端使用每台PC都默认配置的浏览器即可完成数据的传输。

### 2.2.2. 优点

### 2.2.3. 缺点

### 2.2.4. 应用

```

```