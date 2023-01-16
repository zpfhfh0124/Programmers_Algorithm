#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    int answer = 0;
    string members = "ACFJMNRT";
   
    do 
    {
        bool isVaild = true;
        for (int i = 0; i < n; i++)
        {
            int member1_idx = 0;
            int member2_idx = 0;
            
            for (int j = 0; j < members.length(); j++) 
            {
                if(members[j] == data[i][0]) member1_idx = j;
                if(members[j] == data[i][2]) member2_idx = j;
            }

            char compare_char = data[i][3];
            int distance = max(member1_idx - member2_idx, member2_idx - member1_idx) - 1;
            switch (compare_char)
            {
                case '<':
                    isVaild = (distance < data[i][4] - '0');
                break;
                case '>':
                    isVaild = (distance > data[i][4] - '0');
                break;
                case '=':
                    isVaild = (distance == data[i][4] - '0');
                break;
                default :

                break;
            };

            if (isVaild == false) break;
        }
        if (isVaild) answer++;
    } while (next_permutation(members.begin(), members.end()));

    return answer;
}

int main()
{
    int n = 0;
    cout << "���� : ";
    cin >> n;
    vector<string> data(n);
    for (int i = 0; i < n; i++)
    {
        cout << i << "��° ���ǽ� �Է� : ";
        cin >> data[i];
    }

    int result = solution(n, data);

    cout << result;
}