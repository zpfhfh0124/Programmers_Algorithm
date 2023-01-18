#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;



    return answer;
}

int main()
{
    const int row = 4;
    const int colum = 4;

    int idx = 0;
    int curr_row = 0;
    int curr_colum = 0;
    vector<vector<int>> board(row, vector<int>(colum));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << i << "행 " << j << "열 : ";
            cin >> idx;
            board[i][j] = idx;
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < board[i].size(); j++)
        {
            if (j == board[i].size() - 1) cout << board[i][j];
            else cout << board[i][j] << ",";
        }
        if (i == board.size() - 1) cout << "]" << endl;
        else cout << "],";
    }

    bool isValid = false;
    while (!isValid)
    {
        cout << "현재 행 입력 :";
        cin >> curr_row;        
        cout << "현재 열 입력 :";
        cin >> curr_colum;
        isValid = (curr_row < row&& curr_colum < colum) ? true : false;
    }

    int result = solution(board, curr_row, curr_colum);
}