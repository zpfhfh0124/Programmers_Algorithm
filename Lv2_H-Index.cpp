#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = -1;

    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] <= i) {
            answer = i;
            break;
        }
    }

    answer = (answer == -1) ? citations.size() : answer;

    return answer;
}

int main()
{
    vector<int> citations = { 8, 3, 7, 0, 2 };
    int result = solution(citations);
    cout << result << endl;
}