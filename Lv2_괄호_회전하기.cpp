#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<char> check(string s)
{
    stack<char> s_st;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (!s_st.empty()) {
            switch (*it)
            {
            case ')':
                if (s_st.top() == '(') s_st.pop();
                else s_st.push(*it);
                break;
            case '}':
                if (s_st.top() == '{') s_st.pop();
                else s_st.push(*it);
                break;
            case ']':
                if (s_st.top() == '[') s_st.pop();
                else s_st.push(*it);
                break;
            default:
                s_st.push(*it);
                break;
            }
        }
        else s_st.push(*it);
    }
    return s_st;
}

void shift(string &s)
{
    char front_s = ' ';
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (i == 0) {
            front_s = c;
        }
        else{
            s[i - 1] = c;
        }
    }
    s[s.size() - 1] = front_s;
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        // 괄호 스택 체크
        if(check(s).empty()) answer++;
        shift(s);
    } 

    return answer;
}

int main()
{
    string s = "[](){}";
    int result = solution(s);
    cout << result << endl;
}