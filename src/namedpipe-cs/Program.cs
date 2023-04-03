using System;
using System.IO;
using System.IO.Pipes;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static async Task Main(string[] args)
    {
        // 创建 Unix 域套接字
        Socket serverSocket = new Socket(AddressFamily.Unix, SocketType.Stream, ProtocolType.Unspecified);
        EndPoint endPoint = new UnixDomainSocketEndPoint("/Users/jerryding/src/mypipe");

        // 绑定到本地地址并监听连接请求
        serverSocket.Bind(endPoint);
        serverSocket.Listen(10);

        Console.WriteLine("Server listening on Unix domain socket: /tmp/mysocket");

        // 接受客户端连接并处理请求
        while (true)
        {
            Socket clientSocket = await serverSocket.AcceptAsync();

            Console.WriteLine("Client connected.");

            // 读取客户端发送的消息
            byte[] buffer = new byte[1024];
            int bytesRead = await clientSocket.ReceiveAsync(buffer, SocketFlags.None);

            Console.WriteLine("Message received from client: {0}", Encoding.ASCII.GetString(buffer, 0, bytesRead));

            // 向客户端发送响应
            string response = "Hello from C# on Linux!";
            byte[] responseBytes = Encoding.ASCII.GetBytes(response);
            await clientSocket.SendAsync(responseBytes, SocketFlags.None);

            Console.WriteLine("Response sent to client.");

            // 关闭客户端套接字
            clientSocket.Shutdown(SocketShutdown.Both);
            clientSocket.Close();
        }

        // 关闭服务端套接字
        serverSocket.Close();
    }
}
