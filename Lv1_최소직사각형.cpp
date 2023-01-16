#include <string>
#include <vector>

using namespace std;

void swap(int& w, int& h)
{
    int temp = h;
    h = w;
    w = temp;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0], sizes[i][1]);
        }

        if (w < sizes[i][0]) w = sizes[i][0];
        if (h < sizes[i][1]) h = sizes[i][1];
    }
    answer = w * h;
    return answer;
}

int main()
{
    vector<vector<int>> sizes = { {60,50},{30,70},{60,30},{80,40} };
    solution(sizes);
}