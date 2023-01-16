#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string bin_s = "";
        int bin = arr1[i] | arr2[i];
        while (bin_s.size() < n)
        {
            if (bin % 2 == 0) bin_s.append(" ");
            else bin_s.append("#");

            bin >>= 1;
        }
        reverse(bin_s.begin(), bin_s.end());
        answer.push_back(bin_s);
    }

    return answer;
}

int main()
{
    int n = 6;
    vector<int> arr1 = { 46, 33, 33, 22, 31, 50 };
    vector<int> arr2 = { 27, 56, 19, 14, 14, 10 };

    solution(n, arr1, arr2);
}