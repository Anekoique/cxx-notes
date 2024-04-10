// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<queue>
// using namespace std;
// int main()
// {
//     vector<int> ji;
//     vector<int> ou;
//     queue<int> all;
//     int flag = 0;
//     int i = 0, j = 0;
//     int x;
//     while (cin >> x && x!= 0)
//     {
//         if(x % 2 == 0)
//             ou.push_back(x);
//         else
//             ji.push_back(x);
//     }
//     sort(ou.begin(), ou.end());
//     sort(ji.begin(), ji.end());
//     auto it = ji.begin();
//     auto it2 = ou.begin();
//     while (it != ji.end())
//     {
//         if (*it > *it2)
//         {
//             all.push(*it2);
//             it2++;
//         }
//         else
//         {
//             all.push(*it);
//             it++;
//         }
//         if(it2 == ou.end())
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if(flag)
//     {
//         while (it != ji.end()){
//             all.push(*it);
//             it++;
//         }
//     }
//     else
//     {
        
//         while (it2 != ou.end()){
//             all.push(*it2);
//             it2++;
//         }
//     }
//     for (int k = 0; k < ji.size(); k++)
//     {
//         cout << ji[k];
//         if (k!=ji.size()-1)
//             cout << "->";
//     }
//     cout << endl;
//     for (int k = 0; k < ou.size(); k++)
//     {
//         cout << ou[k];
//         if (k!=ou.size()-1)
//             cout << "->";
//     }
//     cout << endl;
//     while (!all.empty()) {
//         cout << all.front();
//         all.pop();
//         if(!all.empty())
//             cout << "->";
//     }
//     return 0;
// }

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
    int x;
    list<int> L1;
    list<int> L2;
    while(cin >> x)
    {
        if(x>0)
            L1.push_back(x);
        else
            L2.push_back(x);
    }
    sort(L1.begin(), L1.end());
    sort(L2.begin(), L2.end());
    for (int k = 0; k < L1.size(); k++)
    {
        cout << L1[k];
        if (k!=L1.size()-1)
            cout << "->";
    }
    cout << endl;
    for (int k = 0; k < L2.size(); k++)
    {
        cout << L2[k];
        if (k!=L2.size()-1)
            cout << "->";
    }
}