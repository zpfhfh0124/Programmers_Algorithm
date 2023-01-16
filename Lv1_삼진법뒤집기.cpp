#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int trit_reverse(int n)
{
    string trit_s = "";
    while (n > 0)
    {
        if (n % 3 == 2) trit_s.append("2");
        else if (n % 3 == 1) trit_s.append("1");
        else trit_s.append("0");

        n /= 3;
    }
    //reverse(trit_s.begin(), trit_s.end());

    int result = 0;
    for (int i = 1; i <= trit_s.size(); i++)
    {
        int trit = *(trit_s.end() - i) - 48;
        result += trit * pow(3, (i - 1));
    }
    return result;
}

int solution(int n) {
    int answer = 0;
    answer = trit_reverse(n);
    return answer;
}

int main()
{
    int n = 125;
    solution(n);
}