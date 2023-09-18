#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int sum_mat[100][100]{};
    int k;

    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> k;
            sum_mat[(i % n)][j] += k;
            if (i >= n)cout << sum_mat[i % n][j] << " ";
        }
        if (i >= n)cout << endl;
    }

    return 0;
}