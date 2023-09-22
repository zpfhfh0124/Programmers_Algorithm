#include <iostream>
#include <vector>

using namespace std;

#define K 1
#define Q 1
#define L 2
#define B 2
#define N 2
#define P 8

vector<int> sample = { K,Q,L,B,N,P };

vector<int> setPieces(vector<int> pieces)
{
    int max = pieces.size();
    vector<int> result(max);
    int add = 0;
    for (int i = 0; i < max; i++)
    {
        add = sample[i] - pieces[i];
        result[i] = add;
    }

    return result;
}

int main() {
    const int max = sample.size();
    vector<int> pieces(max);
    int p;
    for (int i = 0; i < max; i++)
    {
        cin >> p;
        pieces[i] = p;
    }

    vector<int> result = setPieces(pieces);
    for (auto it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}