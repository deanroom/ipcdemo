using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Win32.SafeHandles;

class Program
{
    // 声明 C 库函数
    [DllImport("libc", EntryPoint = "mkfifo", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern int mkfifo(string pathname, int mode);

    [DllImport("libc", EntryPoint = "open", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern SafeFileHandle open(string pathname, int flags);

    [DllImport("libc", EntryPoint = "read", SetLastError = true)]
    private static extern int read(int fd, byte[] buf, int count);

    static async Task Main(string[] args)
    {
        string fifoPath = "/tmp/myfifo3";

        if (!File.Exists(fifoPath))
        {
            int fifoMode = 0666; // 要创建的管道的权限
            // 创建命名管道
            int result = mkfifo(fifoPath, fifoMode);

            if (result == 0)
            {
                Console.WriteLine("命名管道已成功创建！");
            }
            else
            {
                int error = Marshal.GetLastPInvokeError();
                //var message = Marshal.GetLastPInvokeErrorMessage();
                Console.WriteLine($"创建命名管道时发生错误，错误代码：{error}");
                return;
            }
        }
        await using var stream = new FileStream(fifoPath,FileMode.Open,FileAccess.Read,FileShare.ReadWrite);
        using var reader = new StreamReader(stream);
        while (true)
        {
            Console.WriteLine(reader.ReadLine());
            Thread.Sleep(1000);
        }

    }
}