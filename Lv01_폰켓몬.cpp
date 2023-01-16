#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int select_amount = nums.size() / 2;

    // Key : 종류번호, Value : 배열 Index
    map<int, vector<int>> pokemons;
    
    for (int i = 0; i < nums.size(); i++)
    {
        pokemons.insert(make_pair(nums[i], i));
    }

    if (pokemons.size() >= select_amount) answer = select_amount;
    else answer = pokemons.size();

    return answer;
}

int main()
{
    vector<int> nums;
    nums = { 3,3,3,2,2,4 };
    
    int answer = solution(nums);
    
    cout << answer << endl;
}