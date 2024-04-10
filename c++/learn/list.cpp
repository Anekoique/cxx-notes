#include<iostream>
#include<list>
#include<algorithm>
#include<cstdio>
using namespace std;

// int main()
// {
//     list<int> lst;
//     int x;
//     while (cin >> x)
//     {
//         if (x > 0)
//             lst.push_front(x);
//         else
//             lst.push_back(x);
//         if (cin.get() == '\n')
//             break;
//     }
//     cout << "size = " << lst.size() << endl;
//     cout << "front = " << lst.front() << endl;
//     cout << "back = " << lst.back() << endl;
//     list<int>::iterator it;
//     for (it = lst.begin(); it != lst.end(); it++)
//     {
//         cout << *it << '\t';
//     } 
//     cout << endl;
//     return 0;
// }

int main()
{
    list<int> L1, L2, L3;
    list<int>::iterator it;
    int x;
    while (cin >> x && x != 0)
    {
        if (x % 2 == 0){;
            L2.push_back(x);
            L3.push_back(x);
        }
        else{
            L1.push_back(x);
            L3.push_back(x);
        }
    }
    L1.sort();
    L2.sort();
    L3.sort();
    it = L1.begin();
    for (size_t i = 0; i < L1.size(); i++)
    {
        cout << *it;
        it++;
        if (it != L1.end())
            cout << "->";
    }
    cout << endl;
    it = L2.begin();
    for (size_t i = 0; i < L2.size(); i++)
    {
        cout << *it;
        it++;
        if (it != L2.end())
            cout << "->";
    }
    cout << endl;
    it =  L3.begin();
    for (size_t i = 0; i < L3.size(); i++)
    {
        cout << *it;
        it++;
        if (it != L3.end())
            cout << "->";
    }
    cout << endl;
}

// #include<iostream>
// #include<cstdio>
// #include<list>
// #include<algorithm>
// using namespace std;
int main()
{
    int x;
    list<int> L1;
    list<int> L2;
    list<int>::iterator it;
    while(cin>>x)
    {
        if(x>0)
            L1.push_back(x);
        else
            L2.push_back(x);
    }
    L1.sort();
    L2.sort();
    it = L1.begin();
    for (size_t i = 0; i < L1.size(); i++)
    {
        cout << *it;
        it++;
        if (it != L1.end())
            cout << "->";
    }
    cout << endl;
    it = L2.begin();
    for (size_t i = 0; i < L2.size(); i++)
    {
        cout << *it;
        it++;
        if (it != L2.end())
            cout << "->";
    }
}