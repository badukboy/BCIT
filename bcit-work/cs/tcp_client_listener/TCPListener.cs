using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

class ClientHandler
{
	Socket cSocket;
	int threadCount;
	
	public ClientHandler(Socket s, int id)
	{
		cSocket = s;
		threadCount = id;
	}
	
	public void Handler()
	{
		Byte[] byteSent = new Byte[1];
		Byte[] bytesReceived = new Byte[1];
		DirectoryInfo directoryInfo;

        int bytes;
        String data = "";

        String currentByteString = "";
        char currentByteChar;
					
		while(true)
		{
            while (true)
            {
                bytes = cSocket.Receive(bytesReceived, bytesReceived.Length, 0);

                // Console.WriteLine(Encoding.ASCII.GetString(bytesReceived, 0, bytes));
                currentByteString = System.Text.Encoding.ASCII.GetString(bytesReceived, 0, bytes);
                currentByteChar = currentByteString[0];
                // Console.WriteLine(currentByteChar);

                if (currentByteChar == '\0')
                {
                    Console.WriteLine("*** DEBUG: Found null character, returning directory contents...");

                    break;
                }

                data += currentByteString;

                Console.WriteLine("*** DEBUG: Current data: " + data);
            }

			//Process the data sent by the client.
			if(data == "exit")
			{
				break;
			}

			directoryInfo = new DirectoryInfo(data);

			FileInfo[] fileArray = directoryInfo.GetFiles();
			string files = "";	
			
			foreach (FileInfo fileInfo in fileArray)
			{
				files += fileInfo.Name;
				files += "\n";
			}

			byte[] msg = System.Text.Encoding.ASCII.GetBytes(files);
			
			// Send request to the server
			cSocket.Send(msg, msg.Length, 0);
		}

		cSocket.Close();
	}
}

class MyTcpListener
{
	static void Main(string[] args)
	{
		int threadCount = 0;
	
		try
		{
			int port = 13000;
			IPAddress address = IPAddress.Parse("127.0.0.1");

			// IPAddress address = IPAddress.Parse("142.232.246.23");

			IPEndPoint ipe = new IPEndPoint(address, port);
			Socket s = new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

			s.Bind(ipe);
			s.Listen(10);
			
			while(true)
			{
				Socket cls = s.Accept();
				
				threadCount++;
				ClientHandler ch = new ClientHandler(cls, threadCount);
				Thread t = new Thread(new ThreadStart(ch.Handler));
				t.Start();
			}
			
			s.Close();
		}
		catch (SocketException e)
		{
			Console.WriteLine("Socket exception: {0}", e);
		}

		Console.Read();
	} 
}