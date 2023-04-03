#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    // 打开管道文件
    // int pipe_fd = open("/Users/jerryding/src/mypipe", O_WRONLY);

    // // 向管道中写入数据
    // std::string data = "Hello from process B!";
    // write(pipe_fd, data.c_str(), data.size());

    // // 关闭管道文件
    // close(pipe_fd);

    // return 0;

    //mkfifo("/Users/jerryding/src/mypipe", 0666);

    // 打开命名管道
    int pipeHandle = open("/Users/jerryding/src/mypipe", O_WRONLY);

    if (pipeHandle == -1)
    {
        std::cerr << "Failed to connect to the named pipe!" << std::endl;
        return 1;
    }

    // 向管道中写入数据
    std::string message = "Hello from C++ on Linux!";
    write(pipeHandle, message.c_str(), message.length());

    // 关闭管道
    close(pipeHandle);

}
