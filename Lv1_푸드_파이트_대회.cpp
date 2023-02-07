#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string str;
    for (int i = 0; i <= food.size() * 2; i++)
    {
        if (i < food.size()) {
            for (int j = 0; j < food[i] / 2; j++) str.append(to_string(i));
        }
    }

    answer = str;
    reverse(str.begin(), str.end());
    answer.append("0");
    answer.append(str);

    return answer;
}