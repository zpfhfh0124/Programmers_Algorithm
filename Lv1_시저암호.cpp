#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int asciiA = 65;
    int ascii_a = 97;
    int start_ascii = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') {
            answer.append(" "); continue;
        }

        start_ascii = (s[i] < ascii_a) ? asciiA : ascii_a;
        int shift = (s[i] - start_ascii + n) % 26;
        char c = shift + start_ascii;
        answer.append(1, c);
    }

    return answer;
}

int main()
{
    string s = "z";
    int n = 1;
    solution(s, n);
}