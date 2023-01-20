#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> p_ii;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> map_tuple;
    int digit_cnt = 0;
    int num = 0;
    for (auto c = s.end() - 1; c != s.begin(); c--)
    {
        if (isdigit(*c) != 0) {
            num += (*c - '0')* pow(10, digit_cnt);
            digit_cnt++;
        }
        else {
            if (digit_cnt > 0) {
                map_tuple[num]++;
                num = 0;
                digit_cnt = 0;
            }
        }
    }

    vector<p_ii> vec_tuple(map_tuple.begin(), map_tuple.end());
    
    sort(vec_tuple.begin(), vec_tuple.end(), [](p_ii a, p_ii b) {
        return a.second > b.second;
    });

    for (auto t : vec_tuple) {
        answer.push_back(t.first);
    }

    return answer;
}

int main()
{
    string s = "{{20,111},{111}}";
    solution(s);
}