#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    // arr1[i].size == arr2.size()
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> row;
        for (int j = 0; j < arr2[0].size(); j++) {
            int addition = 0;
            for (int k = 0; k < arr1[i].size(); k++) {
                addition += arr1[i][k] * arr2[k][j];
            }
            row.push_back(addition);
        }
        answer.push_back(row);
    }
    return answer;
}

int main()
{
    vector<vector<int>> arr1 = { { 1, 4 }, { 3, 2 }, { 4, 1 } } /*{ {2,3,2}, {4,2,4}, {3,1,4} }*/;
    vector<vector<int>> arr2 = { { 3, 3 }, { 3, 3 } } /*{ {5,4,3}, {2,4,1}, {3,1,1} }*/;

    solution(arr1, arr2);
}