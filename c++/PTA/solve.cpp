#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void input(vector<pair<int, int>>& vec)
{
    int num1, num2;
    string str;
    while (cin >> str)
    {
        size_t pos = str.find(',');
        num1 = stoi(str.substr(0, pos));
        num2 = stoi(str.substr(pos + 1));
        if (num1 == 0 && num2 == 0) break;
        vec.push_back(make_pair(num1, num2));
    }
}

void output(vector<pair<int, int>>& vec)
{
    for (auto elem : vec)
    {
        if (elem.first == 0) continue;
        cout << elem.first << ',' << elem.second << ' ';
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    vector<pair<int, int>> a, b, c;
    input(a);
    input(b);
    sort(a.begin(), a.end(), compare);
    sort(b.begin(), b.end(), compare);

    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < a.size() && ptr2 < b.size())
    {
        if (a[ptr1].second < b[ptr2].second) {
            c.push_back(a[ptr1]);
            ptr1++;
        }
        else if (a[ptr1].second > b[ptr2].second) {
            c.push_back(b[ptr2]);
            ptr2++;
        }
        else {
            c.push_back(make_pair(a[ptr1].first + b[ptr2].first, a[ptr1].second));
            ptr1++;
            ptr2++;
        }
    }
    while (ptr1 < a.size()) {
        c.push_back(a[ptr1]);
        ptr1++;
    }
    while (ptr2 < b.size()) {
        c.push_back(b[ptr2]);
        ptr2++;
    }

    output(c);
}
