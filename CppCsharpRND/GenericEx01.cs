using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpConsole
{
    class GenericEx01
    {
        static void CopyArray<T>(T[] source, T[] target)
        {
            for(int i = 0; i < source.Length; i++)
            {
                target[i] = source[i];
            }
        }

        static void Main(string[] args)
        {
            int[] source = { 1, 2, 3, 4, 5 };
            int[] target = new int[source.Length];

            CopyArray<int>(source, target);

            foreach (int element in target)
            {
                Console.WriteLine(element);
            }

            string[] sourceString = { "안젤리카", "아카테스", "벨로나", "빌트레드", "씨발" };
            string[] targetString = new string[sourceString.Length];

            CopyArray<string>(sourceString, targetString);

            foreach (var item in targetString)
            {
                Console.WriteLine(item);
            }
        }
    }
}
