#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        int row = i / n;
        int colum = i % n + 1;
        answer.push_back((row < colum) ? colum : row);
    }

    return answer;
}

int main()
{
    int n = 4;
    long long left = 7;
    long long right = 14;

    vector<int> answer = solution(n, left, right);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}