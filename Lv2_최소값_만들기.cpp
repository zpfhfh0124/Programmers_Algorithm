#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    answer = inner_product(A.begin(), A.end(), B.begin(), 0);

    //sort(A.begin(), A.end());   // 오름차순
    //sort(B.rbegin(), B.rend()); // 내림차순
    //
    //for (int i = 0; i < A.size(); i++)
    //{
    //    answer += A[i] * B[i];
    //}

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}

int main()
{
    int len = 0;
    cout << "배열 길이 : ";
    cin >> len;
    vector<int> A(len);
    vector<int> B(len);
    for (int i = 0; i < len; i++)
    {
        cout << "A 배열의 " << i << "번째 : ";
        cin >> A[i];
        cout << "B 배열의 " << i << "번째 : ";
        cin >> B[i];
    }

    solution(A, B);
    return 0;
}