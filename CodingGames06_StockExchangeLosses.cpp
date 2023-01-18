#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   /* int n;
    cin >> n; cin.ignore();*/
    vector<int> prices = {3,2,10,7,15,14};
    int n = prices.size();
    //for (int i = 0; i < n; i++) {
    //    int v;
    //    cin >> v; cin.ignore();
    //    prices.push_back(v);
    //}

    int max_loss = 0;
    int highest_price = 0;

    for (int price : prices)
    {
        if (price > highest_price) highest_price = price;
        if (price - highest_price < max_loss) max_loss = price - highest_price;
    }

    cout << max_loss << endl;
}