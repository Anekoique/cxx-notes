#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> lst;
    int x;
    while (cin >> x)
    {
        if (x > 0)
            lst.push_front(x);
        else
            lst.push_back(x);
        if (cin.get() == '\n')
            break;
    }
    cout << "size = " << lst.size() << endl;
    cout << "front = " << lst.front() << endl;
    cout << "back = " << lst.back() << endl;
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << '\t';
    } 
    cout << endl;
    return 0;
}