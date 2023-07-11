#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 자카드 유사도
int jaccard(vector<string> str1_vec, vector<string> str2_vec) {

    if (str1_vec.empty() && str2_vec.empty()) return 65536;

    vector<string> vec_union;
    vec_union.resize(str1_vec.size() + str2_vec.size());
    vector<string> vec_inter;
    vec_inter.resize(str1_vec.size() + str2_vec.size());

    sort(str1_vec.begin(), str1_vec.end());
    sort(str2_vec.begin(), str2_vec.end());

    auto union_it = set_union(str1_vec.begin(), str1_vec.end(), str2_vec.begin(), str2_vec.end(), vec_union.begin());
    vec_union.erase(union_it, vec_union.end());
    auto inter_it = set_intersection(str1_vec.begin(), str1_vec.end(), str2_vec.begin(), str2_vec.end(), vec_inter.begin());
    vec_inter.erase(inter_it, vec_inter.end());

    float rate = ((float)vec_inter.size() / (float)vec_union.size());
    int result = rate * 65536;
    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
   
    for (int i = 0; i < str1.size(); i++) str1[i] = toupper(str1[i]);
    for (int i = 0; i < str2.size(); i++) str2[i] = toupper(str2[i]);
    
    vector<string> str1_vector;
    vector<string> str2_vector;
    string newStr = "";

    for (int i = 0; i < str1.size() - 1; i++)
    {
        newStr.clear();
        if (isalpha(str1[i]) == 0 || isalpha(str1[i + 1]) == 0) continue;
        newStr = str1[i];
        newStr.append(str1, i + 1, 1);
        str1_vector.push_back(newStr);
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        newStr.clear();
        if (isalpha(str2[i]) == 0 || isalpha(str2[i + 1]) == 0) continue;
        newStr = str2[i];
        newStr.append(str2, i + 1, 1);
        str2_vector.push_back(newStr);
    }

    answer = jaccard(str1_vector, str2_vector);
    return answer;
}

int main()
{
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";

    int answer = solution(str1, str2);

    cout << answer << endl;
}