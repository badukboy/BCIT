using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Service1Console.TestWeb;

namespace WebServiceTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Service1 webservice = new Service1();
            Console.WriteLine(webservice.anotherSimpleMethod(4, 3));
            Console.ReadKey();
        }
    }
}
