#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    vector<int> ji;
    vector<int> ou;
    queue<int> all;
    int flag = 0;
    int i = 0, j = 0;
    int x;
    while (cin >> x && x!= 0)
    {
        if(x % 2 == 0)
            ou.push_back(x);
        else
            ji.push_back(x);
    }
    sort(ou.begin(), ou.end());
    sort(ji.begin(), ji.end());
    auto it = ji.begin();
    auto it2 = ou.begin();
    while (it != ji.end())
    {
        if (*it > *it2)
        {
            all.push(*it2);
            it2++;
        }
        else
        {
            all.push(*it);
            it++;
        }
        if(it2 == ou.end())
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        while (it != ji.end()){
            all.push(*it);
            it++;
        }
    }
    else
    {
        
        while (it2 != ou.end()){
            all.push(*it2);
            it2++;
        }
    }
    for (int k = 0; k < ji.size(); k++)
    {
        cout << ji[k];
        if (k!=ji.size()-1)
            cout << "->";
    }
    cout << endl;
    for (int k = 0; k < ou.size(); k++)
    {
        cout << ou[k];
        if (k!=ou.size()-1)
            cout << "->";
    }
    cout << endl;
    while (!all.empty()) {
        cout << all.front();
        all.pop();
        if(!all.empty())
            cout << "->";
    }
    return 0;
}