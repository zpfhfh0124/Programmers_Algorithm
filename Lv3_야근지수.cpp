#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q_works;
    
    for (auto w : works) q_works.push(w);

    for (int i = n; i > 0; i--) {
        if (q_works.empty()) continue;
        int max = q_works.top();
        answer += pow(max, 2);
        q_works.pop();
        if(max > 1) q_works.push(max - 1);
    }

    return answer;
}

int main()
{
    vector<int> works = { 1,1 };
    int n = 3;
    int result = solution(n, works);
    cout << result;
}