#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Pos
{
    int y;
    int x;
};

// n : 행 / m : 열 [y][x]
int n, m;

const int MAX = 100;
bool isVisited[MAX][MAX] = {false};
int dist[MAX][MAX] = {0};

// 상 좌 하 우
const int DIR_MAX = 4;
int directionX[DIR_MAX] = { 0, -1, 0, 1 };
int directionY[DIR_MAX] = { -1, 0, 1, 0 };

queue<Pos> q_pos;
int solution(vector<vector<int>> maps)
{
    int answer = 0;

    n = maps.size();
    m = maps[0].size();
    isVisited[0][0] = true;
    dist[0][0] = 1;

    Pos pos = Pos{ 0, 0 };
    q_pos.push(pos);

    while (!q_pos.empty())
    {
        pos = (q_pos.front());
        q_pos.pop();
        
        int cur_x = pos.x;
        int cur_y = pos.y;

        // 4방향 탐색 (상 -> 좌 -> 하 -> 우)
        for (int i = 0; i < DIR_MAX; i++)
        {
            int next_x = cur_x + directionX[i];
            int next_y = cur_y + directionY[i];

            // 맵 범위 내인지 체크
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
            // 벽 체크
            if (maps[next_y][next_x] == 0) continue;
            // 이미 체크된 곳
            if (isVisited[next_y][next_x]) continue;

            // 체크 끝나고 갈 수 있는 곳이면...
            q_pos.push(Pos{ next_y, next_x });
            isVisited[next_y][next_x] = true;
            dist[next_y][next_x] = dist[cur_y][cur_x] + 1;
        }
    }

    // 도착지 체크
    if (!isVisited[n - 1][m - 1]) answer = -1;
    else answer = dist[n - 1][m - 1];
   
    return answer;
}

int main()
{
    vector<vector<int>> maps = { {1,0,1,1,1 }, { 1,0,1,0,1 }, { 1,0,1,1,1 }, { 1,1,1,0,1 }, { 0,0,0,0,1 } };
    cout << solution(maps);

}