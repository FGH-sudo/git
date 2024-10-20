#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main() {
int sock;
int ret=0;
sock=socket(AF_INET,SOCK_STREAM,0);    //创建套接字（socket），AF_INET表示使用ipv4协议，sock_stream表示使用TCP连接，0为使用默认TCP协议
  
  
//初始化结构体变量
struct sockaddr_in server_addr;   //用struct构建sockaddr_in类型结构体变量，声明为server_addr，储存地址
memset(&server_addr,0,sizeof(server_addr));       //初始化结构体server_addr，将其所有元素初始化为0，sizeof函数用于确定结构体变量占据字节的大小
server_addr.sin_family=AF_INET;   //地址族为IPV4
server_addr.sin_port=htons(601);   //sin_port表示端口号，用htons函数将主机字节序转化为网络字节序（16位）
server_addr.sin_addr.s_addr=htonl(INADDR_ANY);    //htonl函数将主机字节序转化为网络字节序（32位），INADDR_ANY是宏，代表本机的回环地址（0.0.0.0）
  
  
ret=bind(sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
//上面的代码中，bind函数用于将套接字与指定的ip地址和端口号绑定，由于函数要求接受通用的struct sockaddr*指针，所以将具体的sockaddr_in强转化
if(ret!=0) {
    printf("绑定失败\n");
    exit(EXIT_FAILURE);     //EXIT_FAILURE是头文件stdlib.h定义的一个宏，表示程序异常退出
}    //对返回值进行判定，0为成功
  
  
ret=listen(sock,128);    //128表示监听连接的最大数量
if(ret!=0) {
    printf("监听失败\n");
    exit(EXIT_FAILURE);
}    //对返回值进行判定，0为成功
  
  
printf("等待客户端连接\n");
  
while(1){   //设置while循环，在客户端退出后等待其他客户端连接
int client_sock;
char client_ip[64];   //ip地址缓冲区大小为64位
struct sockaddr_in client_addr;
socklen_t client_len=sizeof(client_addr);    //socklen_t是一个数据类型，和int长度相同，这里声明了变量client_len,并将client_addr占据的字节数赋值给它
memset(&client_addr,0,sizeof(client_addr));
    //创建客户端套接字，定义储存客户端地址的结构体并初始化
client_sock=accept(sock,(struct sockaddr*)&client_addr,&client_len);     //用accept函数接收客户端ip地址与端口号
if (client_sock<0)  {
    printf("接收失败\n");
    exit(EXIT_FAILURE);
}
  
printf("客户端ip：%s,端口号：%d\n",//%s为字符串转换说明
    inet_ntop(client_sock,&client_addr.sin_addr,client_ip,sizeof(client_ip)),   //将客户端的网络地址信息转换位可读的字符串，inet_ntop对ipv4和ipv6都适用
    ntohs(client_addr.sin_port)    //将端口号从网络字节序转化为主机字节序
    );    //说明已成功接收客户端连接请求
  
  
while(1){
    char buf[64];//生成64位的缓冲区，储存读取的信息
    int len;
    len=read(client_sock,buf,sizeof(buf)-1);//-1是为了确保缓冲区留有一个字节储存字符串的终止符\0
    if(len<0){
        printf("读取失败\n");
        exit(EXIT_FAILURE);
    }
buf[len]='\0';     //表示缓冲区内在读取的信息的最后添加终止符\0，buf中前“len”个字符为有效内容
if (memcmp(buf,"exit",4)==0){     //memcmp函数用于比较两块内存区域的内容，比较4个字节，若相同则返回0
    close(client_sock);
    printf("连接断开");
    break;    //输入exit退出连接
}
printf("接收消息：%s\n",buf);
send(client_sock,buf,len,0);    //回复客户端消息
}
  
}
close(sock);
return 0;
  
}  