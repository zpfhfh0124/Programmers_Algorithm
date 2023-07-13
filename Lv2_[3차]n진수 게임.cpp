#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 10진수 k -> n진수 변환 
string n_change(int n, int k)
{
    if (k == 0) return to_string(k);

    string cur = "";
    while (k > 0)
    {
        string mod_str = "";
        int mod = k % n;
        if (mod >= 10) {
            mod += 55;
            mod_str = char(mod);
        }
        else mod_str = to_string(mod);

        cur.append(mod_str);
        k /= n;
    }
    reverse(cur.begin(), cur.end());
    return cur;
}

// 자리수 i일 때, 각 자리수 별 개수 -> n * (n-1)^(i-1)
// --> 한 자리 단위로 펼치면 i * n * (n-1)^(i-1) 개
// 필요한 최소 각 자리의 개수 : t * m
string solution(int n, int t, int m, int p) {
    string answer = "";

    string n_serial = "";
    for (int i = 0; i <= t * m; i++)
    {
        n_serial.append(n_change(n, i));
    }

    for (int i = 0; i < t * m; i++)
    {
        // p번째 차례에만 삽입
        if (p - 1 == i % m && answer.size() < t) {
            answer.append(n_serial, i, 1);
        }
    }

    return answer;
}

int main()
{
    int n = 16;
    int t = 16;
    int m = 2;
    int p = 1;

    string result = solution(n, t, m, p);
    cout << result << endl;
}