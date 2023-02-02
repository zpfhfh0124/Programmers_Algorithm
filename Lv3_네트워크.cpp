#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checked[200] = {false};

void dfs(int current, int n, vector<vector<int>> computers) {
    checked[current] = true;
    for (int i = 0; i < n; i++) {
        if(!checked[i] && computers[current][i] == 1) dfs(i, n, computers);
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!checked[i]) {
            dfs(i, n, computers);
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> computers = { {1,1,0}, {1,1,0}, {0,0,1} };
    int result = solution(n, computers);
    cout << result << endl;
}