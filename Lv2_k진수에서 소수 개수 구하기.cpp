#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n을 k진법으로 변환
string kBin(int n, int k)
{
    if (k == 10) return to_string(n);

    string n_to_k = "";
    int mod = 0;
    while (n > 0) 
    {
        mod = n % k;
        n /= k;
        n_to_k.append(to_string(mod));
    }
    reverse(n_to_k.begin(), n_to_k.end());
    return n_to_k;
}

// 소수 판별식
bool isPrimeNum(long n)
{
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string n_to_k = kBin(n, k);
    n_to_k.append("0");
    string cur_str = "";
    vector<long> nums;
    for (int i = 0; i < n_to_k.size(); i++)
    {
        if (n_to_k[i] == '0') {
            if(!cur_str.empty()) nums.push_back(stol(cur_str));
            cur_str.clear();
        }
        else {
            cur_str.append( n_to_k, i, 1);
        }
    }

    for (long num : nums)
    {
        if (isPrimeNum(num)) answer++;
    }

    return answer;
}

int main()
{
    int n = 110011;
    int k = 10;
    int result = solution(n, k);

    cout << result << endl;
}