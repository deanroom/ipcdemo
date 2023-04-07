#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>

int main()
{
    auto pipe_name = "/tmp/cpp_fifo";
    // 创建命名管道
    mkfifo(pipe_name, 0666);
//
//    // 打开管道文件
//    int pipe_fd = open(pipe_name, O_RDONLY);
//
//    // 从管道中读取数据
//    char buf[1024];
//    while (true)
//    {
//        ssize_t num_bytes = read(pipe_fd, buf, sizeof(buf));
//        if (num_bytes == 0)
//        {
//            break;
//        }
//
//        std::string data(buf, num_bytes);
//        std::cout << "Process A received: " << data << std::endl;
//    }
//
//    // 关闭管道文件
//    close(pipe_fd);

    return 0;
}
