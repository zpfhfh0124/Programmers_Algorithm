#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>

using namespace std;

vector<string> split(string sentence, char separator)
{
    vector<string> result(0);
    stringstream ss(sentence);
    string temp;

    while (getline(ss, temp, separator))
    {
        result.push_back(temp);
    }

   

    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    // id_list의 인덱스 저장용 map
    map<string, int> m_id_idx;

    // id, report_id로 한 쌍을 만들어서 accused, reporters 형식의 key, value의 map을 생성
    // value가 set이기 때문에 하나의 key에 여러 value를 삽입하는 것이 가능
    map<string, set<string>> m_report;

    // 각 id를 id_list의 index 순으로 map에 저장
    for (int i = 0; i < id_list.size(); i++) {
        m_id_idx[id_list[i]] = i;
    }

    for (auto it = report.begin(); it != report.end(); it++)
    {
        // 신고자, 피신고자의 문자열을 공백(" ") 단위로 split
        vector<string> v_report_case = split(*it, ' ');
        string reporter = v_report_case.front();
        string accused = v_report_case.back();

        m_report[accused].insert(reporter);
    }

    vector<int> answer(id_list.size(), 0);
    for (auto it : m_report)
    {
        if (it.second.size() >= k) {
            for (auto it_value : it.second) {
                answer[m_id_idx[it_value]]++;
            }
        }
    }

    return answer;
}


int main()
{
    vector<string> _id_list;
    cout << "문자열 단위로 id를 입력하세요. 입력을 종료하려면 0을 입력" << endl;
    
    string input_str;
    while ( _id_list.size() <= 1000 )
    {
        cin >> input_str;
        
        if (input_str == "0")
        {
            if (_id_list.size() >= 2) {
                break;
            }
            else {
                continue;
            }
        }

        _id_list.push_back(input_str);

       
    }

    vector<string> _report_list;
    string input_reporter;
    string input_accused;
    int cnt = 0;
    while ( _report_list.size() <= 200000 ) 
    {
        cnt++;
        cout << cnt << "번째 신고자를 입력하세요. 종료하면 0을 입력" << endl;
        cin >> input_reporter;

        // 종료 로직
        if (input_reporter == "0")
        {
            if (_report_list.size() >= 1)
            {
                cout << "입력 종료" << endl;
                break;
            }
            else 
            {
                cnt--;
                continue;
            }
        }

        cout << "피신고자를 입력하세요." << endl;
        cin >> input_accused;

        bool isContain = false;
        for (auto it_id = _id_list.begin(); it_id != _id_list.end(); it_id++)
        {
            if (input_reporter == *it_id)
            {
                isContain = true;
            }
        }

        if (!isContain) continue;

        for (auto it_id = _id_list.begin(); it_id != _id_list.end(); it_id++)
        {
            if (input_accused == *it_id)
            {
                isContain = true;
            }
        }

        string report_set = input_reporter + " " + input_accused;
        
        if (isContain) _report_list.push_back(report_set);

    }

    int k = 0;
    cout << "신고 기준 회수 : ";
    cin >> k;

    auto result = solution(_id_list, _report_list, k);

    for (auto it = result.begin(); it != result.end(); it++) 
    {
        cout << *it << " ";
    }

    return 0;
}
