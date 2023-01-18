#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx = 0;
    sort(people.begin(), people.end()); // 오름차순 정렬    
    while (idx < people.size())
    {
        int remain = limit - *(people.end() - 1);
        if (remain >= people[idx])
        {
            people[idx] = 0;
            idx++;
        }       
        if(!people.empty()) people.pop_back();
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> people = { 70, 80, 50 };
    int limit = 100;
    solution(people, limit);
}