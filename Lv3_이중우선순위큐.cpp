#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> q_tower;
    for (auto op : operations) {
        string s_num;
        for (int i = 2; i < op.size(); i++) {
            s_num.push_back(op[i]);
        }
        int num = stoi(s_num);
        
        switch (*op.begin())
        {
        case 'I' :
            q_tower.push_back(num);
            break;
        case 'D':
            if (num == -1) {
                if (!q_tower.empty()) {
                    sort(q_tower.rbegin(), q_tower.rend());
                    q_tower.pop_back();
                }
            }
            else {
                if (!q_tower.empty()) {
                    sort(q_tower.begin(), q_tower.end());
                    q_tower.pop_back();
                }
            }
            break;
        default:
            break;
        }
    }

    if (q_tower.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*max_element(q_tower.begin(), q_tower.end()));
        answer.push_back(*min_element(q_tower.begin(), q_tower.end()));
    }

    return answer;
}

int main()
{
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    vector<int> answer = solution(operations);
    for (auto a : answer) {
        cout << a << " ";
    }
}