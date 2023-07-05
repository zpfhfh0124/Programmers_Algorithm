#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> sums;
vector<int> elements;

void sum(int len)
{
    for (int i = 0; i < elements.size(); i++)
    {
        int idx = 0;
        int sum = 0;
        for (int j = i; j < i + len; j++) {
            if (j >= elements.size()) idx = j % elements.size();
            else idx = j;
            sum += elements[idx];
        }
        sums.insert(sum);
    }
}

int solution() {
    int answer = 0;
    int max = elements.size();
    
    for (int i = 1; i <= max; i++)
    {
        sum(i);
    }

    answer = sums.size();

    return answer;
}

int main()
{
    elements = { 7,9,1,1,4 };
    int result = solution();

    cout << result << endl;
}