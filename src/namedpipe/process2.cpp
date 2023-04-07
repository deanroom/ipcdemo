#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

    auto pipe_name = "/tmp/myfifo3";

    // 打开命名管道
    int pipeHandle = open(pipe_name, O_WRONLY);

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
