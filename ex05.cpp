#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    answer = inner_product(A.begin(), A.end(), B.begin(), 0);

    //sort(A.begin(), A.end());   // ��������
    //sort(B.rbegin(), B.rend()); // ��������
    //
    //for (int i = 0; i < A.size(); i++)
    //{
    //    answer += A[i] * B[i];
    //}

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << answer << endl;

    return answer;
}

int main()
{
    int len = 0;
    cout << "�迭 ���� : ";
    cin >> len;
    vector<int> A(len);
    vector<int> B(len);
    for (int i = 0; i < len; i++)
    {
        cout << "A �迭�� " << i << "��° : ";
        cin >> A[i];
        cout << "B �迭�� " << i << "��° : ";
        cin >> B[i];
    }

    solution(A, B);
    return 0;
}