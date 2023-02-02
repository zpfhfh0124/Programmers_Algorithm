#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> a1 { 1,2,3,4,5 };
    vector<int> a2 { 2,1,2,3,2,4,2,5 };
    vector<int> a3 { 3,3,1,1,2,2,4,4,5,5 };

    int ra1 = 0;
    int ra2 = 0;
    int ra3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == a1[i % a1.size()]) ra1++;
        if (answers[i] == a2[i % a2.size()]) ra2++;
        if (answers[i] == a3[i % a3.size()]) ra3++;
    }

    vector<int> temp;
    temp.push_back(ra1);
    temp.push_back(ra2);
    temp.push_back(ra3);

    int max = *max_element(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == max) answer.push_back(i+1);
    }

    return answer;
}