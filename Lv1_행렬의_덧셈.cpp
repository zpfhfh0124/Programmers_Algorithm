#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> answer_in;
        for (int j = 0; j < arr1[0].size(); j++)
        {
            answer_in.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(answer_in);
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1 = { {1,2}, {2,3} };
    vector<vector<int>> arr2 = { {4,6}, {7,9} };
}