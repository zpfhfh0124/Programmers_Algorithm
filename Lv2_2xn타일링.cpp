#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 60000;
const int MOD = 1000000007;
int F[MAX];

// 가로2 세로1 직사각형 타일
// 가로 n 세로 1인 바닥 채우는 경우의 수
// 2(n-1)의 개수 + 2(n-2)의 개수
// 점화식
int solution(int n) {

    F[1] = 1;
    F[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        F[i] = F[i - 2] + F[i - 1];
        F[i] %= MOD;
    }

    return F[n];
}

int main()
{
    int n;
    int result;
    cin >> n;
    result = solution(n);
    cout << result;
}