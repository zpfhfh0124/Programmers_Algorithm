#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

int solution(string s) {
    map<int, string> map_nums;
    map_nums.insert(pair<int, string>(0, "zero"));
    map_nums.insert(pair<int, string>(1, "one"));
    map_nums.insert(pair<int, string>(2, "two"));
    map_nums.insert(pair<int, string>(3, "three"));
    map_nums.insert(pair<int, string>(4, "four"));
    map_nums.insert(pair<int, string>(5, "five"));
    map_nums.insert(pair<int, string>(6, "six"));
    map_nums.insert(pair<int, string>(7, "seven"));
    map_nums.insert(pair<int, string>(8, "eight"));
    map_nums.insert(pair<int, string>(9, "nine"));

    string num_s = "";
    string split_s = "";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (!isdigit(*it)) split_s += *it;
        else num_s += *it;

        for (int i = 0; i < map_nums.size(); i++)
        {
            if (split_s == map_nums[i])
            {
                num_s += to_string(i);
                split_s.clear();
            }
        }
    }

    return stoi(num_s);
}

int main()
{
    string s = "one4seveneight";
    solution(s);
}