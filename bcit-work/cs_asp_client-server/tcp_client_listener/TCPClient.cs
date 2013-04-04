using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace TCPClient
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                int port = 13000;
                int bytes;
                Byte[] bytesSent = new Byte[1];
                Byte[] bytesReceived = new Byte[1];
                string request;

                IPAddress address = IPAddress.Parse("127.0.0.1");

                IPEndPoint ipe = new IPEndPoint(address, port);
                Socket s = new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
                
                Console.WriteLine("Attempting to connect...");
                s.Connect(ipe);

                if (s.Connected)
                {
                    Console.WriteLine("Connected to socket!\n");

					while(true)
					{
                        Console.Write("Enter a directory: ");
						request = Console.ReadLine();
						
						if(request == "exit")
						{
							break;
						}

                        request += "x";
                        request = request.Remove(request.Length - 1, 1) + '\0';
						
						bytesSent = Encoding.ASCII.GetBytes(request);

						s.Send(bytesSent, bytesSent.Length, 0);

                        while (true)
                        {
                            bytes = s.Receive(bytesReceived, bytesReceived.Length, 0);
                            Console.Write(Encoding.ASCII.GetString(bytesReceived, 0, bytes));
                        }
					}

                    s.Close();
                }
            }
            catch (ArgumentNullException e)
            {
                Console.WriteLine("Argument Null Exception: {0}", e);

            }
            catch (SocketException e)
            {
                Console.WriteLine("SocketException: {0}", e);
            }

            Console.Read();
        }


    }
}