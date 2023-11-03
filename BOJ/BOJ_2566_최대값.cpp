#include <iostream>

#define LINE_MAX 9

using namespace std;

int main()
{
    int max = 0;
    int col = 0;
    int row = 0;

    int n = 0;
    for (int i = 1; i <= LINE_MAX; i++)
    {
        for (int j = 1; j <= LINE_MAX; j++)
        {
            cin >> n;
            if (max <= n) {
                max = n;
                col = i;
                row = j;
            }
        }
    }

    cout << max << endl;
    cout << col << " " << row;
}