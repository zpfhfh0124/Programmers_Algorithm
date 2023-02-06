#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int mat[1000000];
    for (int i = 2; i <= n; i++) mat[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (mat[i] == 0) continue;

        for (int j = 2*i; j <= n; j+=i)
        {
            mat[j] = 0;
        }
    }

    for (int i = 2; i <= n; i++) if (mat[i] != 0) answer++;

    return answer;
}