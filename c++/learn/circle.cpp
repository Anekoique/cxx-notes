#include<iostream>
#define pi 3.14
using namespace std;
class circle
{
public:
    void SetR(int x);
    double SetS(int x);
    double SetC(int x);
private:
    double R, S, C;
};
void circle::SetR(int x)
{
    R = x;
    cout << "The R is " << R <<endl;
}
double circle::SetS(int x)
{
    S = pi * x * x;
    cout << "The S is " << S << endl;
    return S;
}
double circle::SetC(int x)
{
    C = 2 * pi * x;
    cout << "The C is " << C << endl;
    return C;
}

int main()
{
    circle circle1;
    int r;
    cout << "请输入圆的半径： " << endl;
    cin >> r;
    circle1.SetR(r);
    circle1.SetC(r);
    circle1.SetS(r);
    return 0;
}