#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> bin;
    int len = 0;
    int remainder = 0;
    int zero_cnt = 0;
    int bin_cnt = 0;
    string temp_s = "";
    while (s != "1")
    {
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it == '0')
            {
                zero_cnt++;
            }
        }

        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        len = s.length();
        remainder = 0;
        while (len > 0)
        {
            remainder = len % 2;
            len = len / 2;
            bin.push_back(remainder);
        }

        reverse(bin.begin(), bin.end());
        temp_s.clear();
        for (auto it = bin.begin(); it != bin.end(); it++)
        {
            temp_s.append(to_string(*it));
        }
        bin_cnt++;
        s = temp_s;
        bin.clear();
    }
   
    answer.push_back(bin_cnt);
    answer.push_back(zero_cnt);

    return answer;
}

int main()
{
    string bin_str;
    cin >> bin_str;
    auto v_result = solution(bin_str);
    
    for (auto it = v_result.begin(); it != v_result.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}