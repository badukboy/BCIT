using System;
using System.Runtime.InteropServices;
namespace ANamespace
{

    public interface ASignatures
    {
        int getNumberX
        {
            get; 
        }

        int getNumberY
        {
            get;
        }
    }

    [ClassInterface(ClassInterfaceType.AutoDual)]
    public class AClass : ASignatures
    {
        int numberX;
        int numberY;

        public int getNumberX
        {
            get
            {
                return numberX;
            }
        }
        public int getNumberY
        {
            get
            {
                return numberY;
            }
        }
        public void setNumberX(int x)
        {
            this.numberX = x;
        }
        public void setNumberY(int y)
        {
            this.numberY = y;
        }
    }
}