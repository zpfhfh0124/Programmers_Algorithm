#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> enable_wards = { "aya", "ye", "woo", "ma" };

bool ward_check(string ward)
{
    string temp_str = "";
    bool isSpeakable = true;

    for (int i = 0; i < ward.size(); i++)
    {
        if (ward.substr(i, enable_wards[0].size()) == enable_wards[0]) i += enable_wards[0].size() - 1;
        else if (ward.substr(i, enable_wards[1].size()) == enable_wards[1]) i += enable_wards[1].size() - 1;
        else if (ward.substr(i, enable_wards[2].size()) == enable_wards[2]) i += enable_wards[2].size() - 1;
        else if (ward.substr(i, enable_wards[3].size()) == enable_wards[3]) i += enable_wards[3].size() - 1;
        else isSpeakable = false;
    }

    /*for (int i = 0; i < enable_wards.size(); i++)
    {
        temp_str = ward.substr(0, enable_wards[i].size());
        if (temp_str == enable_wards[i])
        {
            ward = ward.erase(0, enable_wards[i].size());
        }
    }*/
        
    //isSpeakable = (ward.size() > 0) ? false : true;
    return isSpeakable;
}

int solution(vector<string> babbling) {
    int answer = 0;

    for (auto ward : babbling)
    {
        if (ward_check(ward)) answer++;
    }

    return answer;
}

int main()
{
    vector<string> v_input_str;
    string input_str = "";
    
    while (input_str != "0")
    {
        cout << "문자열 입력. (0 입력 : 문자열 입력 종료) ";
        cin >> input_str;

        if (input_str == "0") break;
        
        v_input_str.push_back(input_str);
    }
    

    int answer = solution(v_input_str);
    cout << endl;
    cout << " 결과 : " << answer;
}