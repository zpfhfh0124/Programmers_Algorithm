#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFront = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') {
            isFront = true;
            continue;
        }
        else {
            isFront = false;
        }

        if (isFront) {
            s[i] = toupper(s[i]);
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    answer.append(s);

    return answer;
}

int main() 
{
    string s = "";
    cout << "문자열을 입력하세요." << endl;
    cin >> s;
    string result = solution(s);
    cout << result << endl;

    return 0;
}
