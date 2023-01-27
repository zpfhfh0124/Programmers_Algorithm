#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q_remain_pg;
    for (int i = 0; i < progresses.size(); i++) {
        int remain_pg = 100 - progresses[i];
        int remain_day = remain_pg / speeds[i] ;
        if (remain_pg % speeds[i] > 0) remain_day += 1;

        q_remain_pg.push(remain_day);
    }



    return answer;
}

int main()
{

}