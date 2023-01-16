#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int target, int &answer, int count = 0, int sum = 0)
{
    if (count == numbers.size() - 1)
    {
        if (target == sum + numbers[count]) answer++;
        if (target == sum - numbers[count]) answer++;

        return;
    }

    DFS(numbers, target, answer, count + 1, sum + numbers[count]);
    DFS(numbers, target, answer, count + 1, sum - numbers[count]);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers, target, answer);

    return answer;
}

int main()
{
    vector<int> ex = { 1,1,1,1,1 };
    cout << solution(ex, 3);
}