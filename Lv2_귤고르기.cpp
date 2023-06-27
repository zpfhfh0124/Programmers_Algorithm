#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tangerine_pair;
    for (auto it = tangerine.begin(); it != tangerine.end(); it++)
    {
        tangerine_pair[*it]++;
    }

    vector<int> counts;
    for (auto t : tangerine_pair)
    {
        counts.push_back(t.second);
    }

    sort(counts.begin(), counts.end(), greater<int>());

    for (auto c : counts)
    {
        if (k <= 0) break;

        k -= c;
        answer++;
    }

    return answer;
}

int main()
{
    int k = 2;
    vector<int> tang = { 1,1,1,1,2,2,2,3 };
    int result = solution(k, tang);
    cout << result << endl;
}