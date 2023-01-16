#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> map_duplicate;
    bool isPass = true;
    for (int i = 0; i < words.size(); i++)
    {
        isPass = true;
        if (i > 0 && words[i - 1].back() != words[i].front()) isPass = false;
        if (!map_duplicate.empty() && map_duplicate.find(words[i]) != map_duplicate.end()) isPass = false;
        if (words[i].length() <= 1) isPass = false;

        if (!isPass) {
            answer = { i % n + 1, i / n + 1 };
            break;
        }

        map_duplicate.insert(make_pair(words[i], i));
    }
   
    if (isPass) answer = { 0,0 };

    return answer;
}

int main()
{
    int n = 2;
    vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
    auto answer = solution(n, words);

    cout << "[" << answer[0] << "," << answer[1] << "]";
}