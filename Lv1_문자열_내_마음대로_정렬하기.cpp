#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    for (auto str : strings){
        answer.push_back(str);
    }

    sort(answer.begin(), answer.end(),[n](string& s1, string& s2) {
        return (s1[n] == s2[n]) ? s1 < s2 : s1[n] < s2[n];
    });

    return answer;
}

int main()
{
    vector<string> strings = { "sun", "bed", "car" };
    int n = 1;
    solution(strings, n);
}