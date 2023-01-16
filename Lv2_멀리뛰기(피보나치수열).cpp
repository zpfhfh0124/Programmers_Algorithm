#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<unsigned long long> fib(n + 1, 0);
    fib[0] = 1;
    fib[1] = 1;

    if (n <= 2) return n;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;
        answer = fib[i];
    }

    return answer;
}

int main()
{
    int n = 50;
    long long answer = solution(n);
    cout << answer << endl;
}