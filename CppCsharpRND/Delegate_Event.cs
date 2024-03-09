using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpConsole
{
    class Delegate_Event
    {
        public delegate int CulculateDelegate(int a, int b);
        static public CulculateDelegate culculateDelegate;

        static int Add(int a, int b)
        {
            int add = a + b;
            Console.WriteLine($"Add | {a} + {b} = {add}");

            return add;
        }

        #region 사칙연산 함수
        static int Subtract(int a, int b)
        {
            int sub = a - b;
            Console.WriteLine($"Subtract | {a} - {b} = {sub}");

            return sub;
        }

        static int Multiply(int a, int b)
        {
            int mul = a * b;
            Console.WriteLine($"Multiply | {a} * {b} = {mul}");

            return mul;
        }

        static int Divide(int a, int b)
        {
            if (b == 0) {
                Console.WriteLine($"{b}으로 나누기는 불가능합니다. 일단 0을 반환합니다.");
                return 0;
            } 

            int div = a / b;
            Console.WriteLine($"Divide | {a} / {b} = {div}");

            return div;
        }

        static int Compare(int a, int b)
        {
            if(a > b)
            {
                Console.WriteLine($"{a}이(가) {b}보다 = {a-b}만큼 크다");
                return a;
            }
            else if(a == b)
            {
                Console.WriteLine($"{a}와(과) {b}은(는) 같다");
                return 0;
            }
            else
            {
                Console.WriteLine($"{a}이(가) {b}보다 = {b - a}만큼 작다");
                return a;
            }
        }
        #endregion

        static int Main()
        {
            culculateDelegate += Add;
            culculateDelegate += Subtract;
            culculateDelegate += Multiply;
            culculateDelegate += Divide;

            //culculateDelegate = Compare;

            culculateDelegate(400, 200);

            return 0;
        }
    }
}
