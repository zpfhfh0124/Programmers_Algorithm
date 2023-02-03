#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q_idx;
    for (int i = 0; i < progresses.size(); i++) q_idx.push(i);

    int day = 0;
    while (!q_idx.empty()) {
        int remain_pg = 100 - progresses[q_idx.front()];
        int remain_day = remain_pg / speeds[q_idx.front()];
        if (remain_pg % speeds[q_idx.front()] > 0) remain_day += 1;

        if (!answer.empty() && day >= remain_day) {
            answer.back()++;
        }
        else {
            answer.push_back(1);
        }

        // 다음 남은 시간이 이전 시간보다 클 경우에만 갱신
        day = (day < remain_day) ? remain_day : day;
        q_idx.pop();
    }

    return answer;
}

int main()
{
    vector<int> progresses = { 93, 30, 55, 60 };
    vector<int> speeds = { 1, 30, 5, 40 };
    vector<int> result = solution(progresses, speeds);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}