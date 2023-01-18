#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string message;
    getline(cin, message);

    vector<int> ascii;
    string binary_str;

    for (int i = 0; i < message.size(); i++)
    {
        // 아스키 코드 변환 저장
        ascii.push_back(int(message[i]));

        int mod = ascii[i];
        string bin = "";
        while (mod != 0)
        {
            if (mod % 2 == 1) {
                bin.append("1");
            }
            else {
                bin.append("0");
            }
            mod /= 2;
        }

        if (bin.length() == 6) bin.append("0");

        reverse(bin.begin(), bin.end());
        binary_str.append(bin);
    }

    cout << binary_str << endl;

    string answer;
    char prev_bit = ' ';
    int cnt = 0;

    for (auto bit : binary_str)
    {
        if (bit != prev_bit && cnt > 0)
        {
            if (prev_bit == '1') answer.append("0 ");
            else answer.append("00 ");

            answer.append(cnt, '0');
            answer.append(" ");
            cnt = 0;
        }
        ++cnt;
        prev_bit = bit;
    }

    if (prev_bit == '1') answer.append("0 ");
    else answer.append("00 ");

    answer.append(cnt, '0');

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << answer << endl;
}