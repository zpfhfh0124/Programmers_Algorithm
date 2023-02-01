#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int max_p = *max_element(priorities.begin(), priorities.end());

    queue<int> q_priorities;
    for (auto p : priorities) {
        q_priorities.push(p);
    }



    return answer;
}