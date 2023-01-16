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

    // id_list�� �ε��� ����� map
    map<string, int> m_id_idx;

    // id, report_id�� �� ���� ���� accused, reporters ������ key, value�� map�� ����
    // value�� set�̱� ������ �ϳ��� key�� ���� value�� �����ϴ� ���� ����
    map<string, set<string>> m_report;

    // �� id�� id_list�� index ������ map�� ����
    for (int i = 0; i < id_list.size(); i++) {
        m_id_idx[id_list[i]] = i;
    }

    for (auto it = report.begin(); it != report.end(); it++)
    {
        // �Ű���, �ǽŰ����� ���ڿ��� ����(" ") ������ split
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
    cout << "���ڿ� ������ id�� �Է��ϼ���. �Է��� �����Ϸ��� 0�� �Է�" << endl;
    
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
        cout << cnt << "��° �Ű��ڸ� �Է��ϼ���. �����ϸ� 0�� �Է�" << endl;
        cin >> input_reporter;

        // ���� ����
        if (input_reporter == "0")
        {
            if (_report_list.size() >= 1)
            {
                cout << "�Է� ����" << endl;
                break;
            }
            else 
            {
                cnt--;
                continue;
            }
        }

        cout << "�ǽŰ��ڸ� �Է��ϼ���." << endl;
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
    cout << "�Ű� ���� ȸ�� : ";
    cin >> k;

    auto result = solution(_id_list, _report_list, k);

    for (auto it = result.begin(); it != result.end(); it++) 
    {
        cout << *it << " ";
    }

    return 0;
}
