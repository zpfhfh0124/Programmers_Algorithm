#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500
#define DIRECTION_MAX 4

#define Left(dir)  (dir+3)%DIRECTION_MAX
#define Right(dir) (dir+1)%DIRECTION_MAX

// 상,좌,하,우 순서
int directionX[DIRECTION_MAX] = { 0,-1,0,1 };
int directionY[DIRECTION_MAX] = { -1,0,1,0 };

bool isPassed[MAX][MAX][DIRECTION_MAX] = {false};
char charArr[MAX][MAX];

int row, col;

// direction : 0 = Up, 1 = Left, 2 = Down, 3 = Right
int DFS(vector<string> &grid, int y, int x, int direction, int len )
{
    if(isPassed[y][x][direction] == false)
    {
        isPassed[y][x][direction] = true;
        char c = grid[y][x];
        int new_dir = direction;
        int new_x, new_y = 0;
        if (c == 'L') {
            new_dir = Left(direction);
        }
        else if (c == 'R') {
            new_dir = Right(direction);
        }

        new_y = (y + directionY[new_dir] + row) % row;
        new_x = (x + directionX[new_dir] + col) % col;

        len++;
        DFS( grid, new_y, new_x, new_dir, len );
    }
    else {
        return len;
    }
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int len = 0;
    for (int y = 0; y < grid.size(); y++)
    {
        for (int x = 0; x < grid[y].size(); x++)
        {
            for (int dir = 0; dir < DIRECTION_MAX; dir++) 
            {
                int len = 0;
                int result = DFS(grid, y, x, dir, len);
                if(result > 0) answer.push_back(result);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << "[ ";
    for (auto iter = answer.begin(); iter != answer.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << "]";

    return answer;
}


int main()
{
    cout << "행의 개수 입력 : ";
    cin >> row;

    cout << "열의 개수 입력 : ";
    cin >> col;

    int cnt = 0;
    int strlen = 0;
    string row_str;
    vector<string> grid;
    while (cnt < row) 
    {
        cout << "S,R,L의 조합으로 입력 : ";
        cin >> row_str;

        if (cnt > 0) {
            if (row_str.length() != strlen) {
                continue;
            }
        }
        else {
            strlen = row_str.length();
        }

        grid.push_back(row_str);
        cnt++;
    }

    solution(grid);
}