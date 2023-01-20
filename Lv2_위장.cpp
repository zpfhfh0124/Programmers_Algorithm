#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1; 
    
    map<string, int> map_clothes;

    for (auto it = clothes.begin(); it != clothes.end(); it++) {
        map_clothes[(*it)[1]]++;
    }

    // n차 다항식 ( n = 종류 개수 ) 의 계수들의 합
    for (auto it = map_clothes.begin(); it != map_clothes.end(); it++) {
        answer *= (*it).second + 1;
    }

    return answer-1;
}

int main()
{
    // value, key
    vector<vector<string>> clothes = { {"crow_mask", "face"},
                                       {"blue_sunglasses", "face"},
                                       {"smoky_makeup", "face"} };

    int result = solution(clothes);
    cout << result << endl;
}