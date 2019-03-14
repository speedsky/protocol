# protocol
TCP，UDP协议的示例
## Windows下的socket程序和Linux思路相同，细节处区别如下：

1. Windows下的socket程序依赖`Winsock.dll`或`ws2_32.dll`，必须提前加载。DLL有两种加载方式。

1. Linux使用“文件描述符”的概念，而Windows使用“文件句柄”的概念；Linux不区分socket文件和普通文件，而Windows区分；Linux下socket
函数的返回值为`int`类型，而Windows下为`SOCKET`类型，也就是句柄。

1. Linux下使用`read()/write()`函数读写，而Windows下使用`recv()/send()`函数发送和接收

1. 关闭socket时，Linux使用`close()`函数，而Windows使用`closesocket()`函数。