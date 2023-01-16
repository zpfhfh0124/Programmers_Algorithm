#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == ' ') {
            answer.append(" ");
            cnt = 0;
            continue;
        }

        string c = " ";
        if (cnt % 2 == 0) c = toupper(*it);
        else c = tolower(*it);
        
        answer.append(c);
        cnt++;
    }

    return answer;
}

int main()
{
    string s = "try hello world";
    solution(s);
}