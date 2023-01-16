#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> stack_Parentheses(0);
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == '(') stack_Parentheses.push_back(*it);
        else if (*it == ')') {
            if(!stack_Parentheses.empty())stack_Parentheses.pop_back();
            else {
                answer = false;
                break;
            }
        }
        else {
            answer = false;
            break;
        }
    }

    if (!stack_Parentheses.empty()) answer = false;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "answer : " <<  answer << endl;

    return answer;
}

int main()
{
    string s;
    cout << "괄호 입력 : ";
    cin >> s;

    solution(s);
}