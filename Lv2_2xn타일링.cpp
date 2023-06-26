#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 60000;
const int MOD = 1000000007;
int F[MAX];

// ����2 ����1 ���簢�� Ÿ��
// ���� n ���� 1�� �ٴ� ä��� ����� ��
// 2(n-1)�� ���� + 2(n-2)�� ����
// ��ȭ��
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