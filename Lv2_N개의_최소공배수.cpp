#include <string>
#include <vector>

using namespace std;

#define lcm(a, b) { a*b/gcd(a,b) };

int gcd(int a, int b)
{
    int temp = 0;
    if (a < b)
    {
        temp = b;
        b = a;
        a = temp;
    }

    while (b > 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int solution(vector<int> arr) {
    int lcm = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        lcm = lcm(arr[i], lcm);
    }

    return lcm;
}

int main()
{
    vector<int> arr = { 2,6,8,14 };
    solution(arr);
}