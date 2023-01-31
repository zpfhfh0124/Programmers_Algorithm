#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    int len = p.length();

    for (int i = 0; i < t.length(); i++)
    {
        string tp = t.substr(i, len);
        if (tp.length() < len) continue;
        long int ltp = stol(tp);
        long int lp = stol(p);
        if (ltp <= lp) answer++;
    }

    return answer;
}

int main()
{
    string t = "3141592";
    string p = "271";

    int result = solution(t, p);

    cout << result;
}