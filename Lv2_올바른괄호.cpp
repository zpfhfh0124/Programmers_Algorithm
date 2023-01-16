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

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "answer : " <<  answer << endl;

    return answer;
}

int main()
{
    string s;
    cout << "��ȣ �Է� : ";
    cin >> s;

    solution(s);
}