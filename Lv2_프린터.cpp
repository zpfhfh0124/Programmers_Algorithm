#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> task; // index, priority
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        task.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!task.empty())
    {
        auto cur_task = task.front();
        task.pop();
        if (pq.top() == cur_task.second)
        {
            pq.pop();
            answer++;
            if (cur_task.first == location) break;
        }
        else 
        {
            task.push(cur_task);
        }
    }

    return answer;
}

int main()
{
    vector<int> priorities = { 2,1,3,2 };
    int location = 2;

    int result = solution(priorities, location);
    cout << result << endl;
}