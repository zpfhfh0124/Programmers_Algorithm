#include <iostream>
#include <vector>

using namespace std;

int max_len(vector<int> nums, int i, int j)
{
    int sum = accumulate(nums.begin() + k, nus,begin() + j, 0);
    int min = i;
    int max = j;
    while(sum != 0 && max - min > 0)
    {
        if(max >= j)
        {
            min++;
            
            ac
        }
    }
    
    return (j - i + 1);
}

int main() {
    int n;
    cin >> n;
    
    int k;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        nums.push_back(k);
    }
    
    int m;
    cin >> m;
    
    int i,j;
    for(int i = 0; i < m; i++)
    {
        cin >> i >> j;
    }
    
    return 0;
}