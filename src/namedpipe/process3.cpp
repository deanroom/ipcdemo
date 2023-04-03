#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main()
{
    // 创建 Unix 域套接字
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);

    if (sock == -1)
    {
        std::cerr << "Failed to create socket!" << std::endl;
        return 1;
    }

    // 连接到服务端的套接字
    sockaddr_un serverAddr;
    serverAddr.sun_family = AF_UNIX;
    strcpy(serverAddr.sun_path, "/Users/jerryding/src/mypipe");

    if (connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "Failed to connect to the server socket!" << std::endl;
        close(sock);
        return 1;
    }

    // 向服务端发送数据
    const char* message = "Hello from C++ on Linux!";
    int bytesSent = send(sock, message, strlen(message), 0);

    if (bytesSent == -1)
    {
        std::cerr << "Failed to send message to server!" << std::endl;
        close(sock);
        return 1;
    }

    std::cout << "Message sent to server: " << message << std::endl;

    // 关闭套接字
    close(sock);

    return 0;
}
