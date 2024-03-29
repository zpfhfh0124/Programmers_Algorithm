﻿#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string inst, char delimiter)
{
    vector<string> result;
    stringstream ss(inst);
    string tmp;

    while (getline(ss, tmp, delimiter)) {
        result.push_back(tmp);
    }

    return result;
}

vector<int> set_stack(vector<string> insts)
{
    vector<int> stack;
    vector<int> print_vec;
    int n = 0;
    for (auto it = insts.begin(); it != insts.end(); it++)
    {
        string inst = *it;
        vector<string> splits = split(inst, ' ');
        if (!splits.empty() && splits.size() > 1) {
            inst = splits[0];
            n = stoi(splits[1]);
        }

        if (inst == "push")
        {
            stack.push_back(n);
        }
        else if (inst == "pop")
        {
            if (stack.empty()) print_vec.push_back(-1);
            else {
                print_vec.push_back(*(stack.end() - 1));
                stack.pop_back();
            }
        }
        else if (inst == "size")
        {
            print_vec.push_back(stack.size());
        }
        else if (inst == "empty")
        {
            if (stack.empty()) print_vec.push_back(1);
            else print_vec.push_back(0);
        }
        else if (inst == "top")
        {
            if (stack.empty()) print_vec.push_back(-1);
            else print_vec.push_back(*(stack.end() - 1));
        }
    }

    return print_vec;
}

int main()
{
    int line;
    cin >> line;
    cin.clear();

    string inst;
    vector<string> insts;

    for (int i = 0; i <= line; i++)
    {
        // 직전에 cin으로 받은 입력값이 있어서 inst 입력안받고 빈 문자열이 들어가는걸로 시작됨
        // 그래서 line 수보다 한번 더 입력을 받도록 일단 수정
        getline(cin, inst);
        insts.push_back(inst);
    }

    vector<int> result = set_stack(insts);

    for (auto it = result.begin(); it != result.end(); it++)
    {
        cout << *it << endl;
    }
}