#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAX = 100;
vector<int> all_cards;
map<int, bool> boxs = {(0,true), (1,true)};

void box_check(map<int, bool> &boxs)
{
    for (auto box : boxs) 
    {
        if (box.second == false)
        {
            box.second = true;
        }
        else {
            break;
        }
    }
}

void init_boxs(vector<int> cards)
{
    //√ ±‚»≠
    for (auto card : cards)
    {
        boxs.insert({ card,false });
    }
}

int solution(vector<int> cards) {
    int answer = 0;

    all_cards = cards;
    
    init_boxs(all_cards);



    return answer;
}

int main()
{

}