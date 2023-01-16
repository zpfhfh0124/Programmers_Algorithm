#include <string>
#include <vector>
#include <iostream>

using namespace std;

int combination(vector<int>& ingredient, int cnt);

int solution(vector<int> ingredient) {
    int answer = 0;

    answer = combination(ingredient, answer);

    return answer;
}

int combination(vector<int> &ingredient, int cnt)
{
    string sequence = "";
    for (vector<int>::iterator it = ingredient.begin(); it != ingredient.end(); it++)
    {
        sequence += to_string(*it);
        int len = sequence.length();
        if (len >= 4)
        {
            int idx = len - 4;
            string piece = sequence.substr(idx);
            if (piece == "1231")
            {
                sequence = sequence.substr(0, idx);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    vector<int> vec = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
    int result = solution(vec);
    cout << "°á°ú : " << result;
}