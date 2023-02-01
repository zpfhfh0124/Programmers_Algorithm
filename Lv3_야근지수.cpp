#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q_works(works.begin(), works.end());
    
    while (n > 0)
    {
        int max = q_works.top();
        if (max <= 0) break;
        q_works.pop();
        q_works.push(max - 1);
        n--;
    }

    while (!q_works.empty())
    {
        int pow_work = pow(q_works.top(), 2);
        answer += pow_work;
        q_works.pop();
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