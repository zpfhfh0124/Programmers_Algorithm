using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpConsole
{
    class GenericClassEx01<T>
    {
        private T[] array;

        public GenericClassEx01()
        {
            array = new T[3];
        }

        public T this[int index]
        {
            get { return array[index]; }
            set 
            { 
                if(index >= array.Length)
                {
                    Array.Resize<T>(ref array, index+1);
                    Console.WriteLine($"배열 크기 조절 : {array.Length}");
                }
                array[index] = value;
            }
        }

        public int Length
        {
            get { return array.Length; }
        }
    }

    class GenericClassMainApp
    {
        static void Main(string[] args)
        {
            GenericClassEx01<string> str_generic = new GenericClassEx01<string>();
            str_generic[0] = "兵庫県";
            str_generic[1] = "神戸市";
            str_generic[2] = "東灘区";
            str_generic[3] = "本山北町";
            str_generic[4] = "1丁目";

            for(int i = 0; i < str_generic.Length; i++)
            {
                Console.WriteLine(str_generic[i]);
            }

            Console.WriteLine();

            GenericClassEx01<int> int_generic = new GenericClassEx01<int>();
            int_generic[0] = 0;
            int_generic[1] = 1;
            int_generic[2] = 2;
            int_generic[3] = 3;
            int_generic[4] = 4;

            for(int i = 0; i < int_generic.Length; i++)
            {
                Console.WriteLine(int_generic[i]);
            }
        }
    }
}
