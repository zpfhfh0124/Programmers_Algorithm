#include <string>
#include <vector>

using namespace std;

void combination(vector<int> number, int r, int depth, int add, int& cnt)
{
    if (r == 0)
    {
        if (add == 0) cnt++;
    }
    else if (depth >= number.size()) return;
    else
    {
        combination(number, r, depth + 1, add, cnt);
        add += number[depth];
        combination(number, r - 1, depth + 1, add, cnt);
    }
}

int solution(vector<int> number) {
    int answer = 0;

    combination(number, 3, 0, 0, answer);

    return answer;
}

int solution2(vector<int> number) {
    int answer = 0;
    for (int i = 0; i < number.size(); i++) {
        for (int j = i + 1; j < number.size(); j++) {
            for (int k = j + 1; k < number.size(); k++)
                if (number[i] + number[j] + number[k] == 0) answer++;
        }
    }
    return answer;
}

int main()
{
    vector<int> number = { -2,3,0,2,-5 };
    //solution(number);
    int answer = solution2(number);
}