#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a)
    {
        int mod = n % a;
        n = (n / a) * b + mod;
        answer += n - mod;
    }

    return answer;
}

int main()
{
    int a = 3;
    int b = 2;
    int n = 10;
    solution(a, b, n);
}