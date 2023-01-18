#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
    vector<int> v_sum;
    dp[0][0] = triangle[0][0];
    
    int answer = -1;
    
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // 좌측 최외곽
            if (j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
            // 우측 최외곽
            else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            
            if (i == triangle.size() - 1) v_sum.push_back(dp[i][j]);
        }
    }

    answer = *max_element(v_sum.begin(), v_sum.end());

    return answer;
}

int main()
{
    vector<vector<int>> triangle(5, vector<int>(5));
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            switch (i)
            {
                case 0 :
                {
                    triangle[i][j] = 7;
                }
                break;
                case 1:
                {
                    if(j==0) triangle[i][j] = 3;
                    else triangle[i][j] = 8;
                }
                break;
                case 2:
                {
                    if (j == 0) triangle[i][j] = 8;
                    else if (j == 1) triangle[i][j] = 1;
                    else triangle[i][j] = 0;
                }
                break;
                case 3:
                {
                    if (j == 0) triangle[i][j] = 2;
                    else if (j == 1) triangle[i][j] = 7;
                    else if (j == 2) triangle[i][j] = 4;
                    else triangle[i][j] = 4;
                }
                break;
                case 4:
                {
                    if (j == 0) triangle[i][j] = 4;
                    else if (j == 1) triangle[i][j] = 5;
                    else if (j == 2) triangle[i][j] = 2;
                    else if (j == 3) triangle[i][j] = 6;
                    else triangle[i][j] = 5;
                }
                break;
            }
        }
    }

    int result = solution(triangle);

    cout << result;

    return 0;
}