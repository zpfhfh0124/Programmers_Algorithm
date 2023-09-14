#include <iostream>
#include <cmath>

using namespace std;

int max(int w, int h, int n, int m)
{

    // 1행 1열부터 앉는다고 가정. 열 / (비워야 하는 자리 개수 + 1) +1을 하는건 비우고 바로 다음 자리에 한명 앉는다고 생각해야함
    return ceil((double)h / (double)(m + 1)) * ceil((double)w / (double)(n + 1));
}

int main() {
    int w, h, n, m; // W행 H열 세로 띄울 N칸, 가로 띄울 M칸 
    cin >> w >> h >> n >> m;

    int result = max(w, h, n, m);

    cout << result << endl;
    return 0;
}