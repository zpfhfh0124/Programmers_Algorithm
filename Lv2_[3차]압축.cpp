#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dic;

vector<int> solution(string msg) {
    vector<int> answer;

    for (int i = 0; i <= 26; i++) {
        char ch = i + 64;
        string str(1, ch);
        dic.push_back(str);
    }

    string str = "";
    for (int w = 0; w < msg.size();)
    {
        int idx = -1;
        str += msg[w];
        auto it = find(dic.begin(), dic.end(), str);
        
        if (it == dic.end())
        {
            dic.push_back(str);
            str.clear();
        }
        else {
            idx = it - dic.begin();
            if ( find( dic.begin(), dic.end(), str+msg[w+1] ) == dic.end() ) answer.push_back(idx);
            w++;
        }
    }

    return answer;
}

int main() 
{
    string msg = "TOBEORNOTTOBEORTOBEORNOT";

    vector<int> results = solution(msg);

    for (int i : results)
    {
        cout << i << " ";
    }
}