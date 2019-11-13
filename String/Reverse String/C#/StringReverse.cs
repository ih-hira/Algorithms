using System.IO;
using System;

class Program
{
    static void Main()
    {
        string text = "inside code";
        char[] charArray = text.ToCharArray();
        Array.Reverse( charArray );
        string reverse =  new string( charArray );
        Console.WriteLine(reverse);
    }
}