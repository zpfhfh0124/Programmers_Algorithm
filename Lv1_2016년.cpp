#include <iostream>
#include <string>
#include <vector>
//#include <chrono>
#include <map>

using namespace std;
//using namespace std::chrono;

string solution(int a, int b) {
    
    vector<string> weekdays = { "일","월","화","수","목","금","토" };
    int prev_year_lastday_idx = 4;

    map<int, int> month_lastdays;
    month_lastdays.insert(pair(1, 31));
    month_lastdays.insert(pair(2, 29));
    month_lastdays.insert(pair(3, 31));
    month_lastdays.insert(pair(4, 30));
    month_lastdays.insert(pair(5, 31));
    month_lastdays.insert(pair(6, 30));
    month_lastdays.insert(pair(7, 31));
    month_lastdays.insert(pair(8, 31));
    month_lastdays.insert(pair(9, 30));
    month_lastdays.insert(pair(10, 31));
    month_lastdays.insert(pair(11, 30));
    month_lastdays.insert(pair(12, 31));

    int add_days = 0;
    for (int m = 1; m <= a; m++) {
        if (m == a) add_days += b;
        else add_days += month_lastdays[m];
    }

    return weekdays[(add_days + prev_year_lastday_idx) % weekdays.size()];
}

int main()
{
    int month = 12;
    int day = 31;
    string answer = solution(month, day);
    cout << answer << endl;
}