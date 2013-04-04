// CSharpServer.cs
// compile with: /target:library
// post-build command: regasm CSharpServer.dll /tlb:CSharpServer.tlb

using System;
using System.Runtime.InteropServices;
namespace CSharpServer
{
   // Since the .NET Framework interface and coclass have to behave as 
   // COM objects, we have to give them guids.
   [Guid("DBE0E8C4-1C61-41f3-B6A4-4E2F353D3D05")]
   public interface IManagedInterface
   {
      int mathIsFun(string x, string y);
   }

   [Guid("C6659361-1625-4746-931C-36014B146679")]
   public class InterfaceImplementation : IManagedInterface
   {
      public int mathIsFun(string x, string y)
      {
	     long numberX = Int64.Parse(x);
		 long numberY = Int64.Parse(y);
		 
		 int sum = (int)numberX + (int)numberY;
		 int difference = (int)numberX - (int)numberY;
		 
         Console.WriteLine("ADDITION:    {0} + {1} = {2}", numberX, numberY, sum);
		 Console.WriteLine("SUBTRACTION: {0} - {1} = {2}", numberX, numberY, difference);
		 
         return 33;
      }
   }
}