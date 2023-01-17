#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int miss = 5;
    int hit = 1;

    deque<string> cache;
    for (auto it = cities.begin(); it != cities.end(); it++)
    {
        string lowerstr_it = "";
        for (char c : *it) {
            lowerstr_it += tolower(c);
        }

        auto find_cache = find(cache.begin(), cache.end(), lowerstr_it);
        if (find_cache == cache.end()) {
            if (cache.size() < cacheSize) {
                cache.push_back(lowerstr_it);
            }
            else {
                if(!cache.empty()) cache.pop_front();
                if(cacheSize > 0) cache.push_back(lowerstr_it);
            }

            answer += miss;
        }
        else { 
            cache.erase(find_cache);
            cache.push_back(lowerstr_it);
            answer += hit; 
        }   
    }

    return answer;
}

int main()
{
    vector<string> cities = { "Jeju", "Pangyo", "NewYork", "newyork" };
    int cacheSize = 2;

    int result = solution(cacheSize, cities);
    cout << result << endl;
}