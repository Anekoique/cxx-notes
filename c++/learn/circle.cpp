#include<iostream>
#include<vector>
#include<stdio.h>
#define pi 3.14

using namespace std;

// class circle
// {
// public:
//     void SetR(int x);
//     double SetS(int x);
//     double SetC(int x);
// private:
//     double R, S, C;
// };
// void circle::SetR(int x)
// {
//     R = x;
//     cout << "The R is " << R <<endl;
// }
// double circle::SetS(int x)
// {
//     S = pi * x * x;
//     cout << "The S is " << S << endl;
//     return S;
// }
// double circle::SetC(int x)
// {
//     C = 2 * pi * x;
//     cout << "The C is " << C << endl;
//     return C;
// }

// int main()
// {
//     circle circle1;
//     int r;
//     cout << "请输入圆的半径： " << endl;
//     cin >> r;
//     circle1.SetR(r);
//     circle1.SetC(r);
//     circle1.SetS(r);
//     return 0;
// }

// class Rectangle
// {
// public:
//     int Rec_S(int x1, int y1, int x2, int y2)
//     {
//         return (y1 - y2) * (x2 - x1);
//     }
//     Rectangle();
//     ~Rectangle();
// private:
//     int x1, x2, y1, y2;
// };
// Rectangle::Rectangle(void)
// {
//     cout << "The position of the point is (x1, y1), (x2, y2)" << endl;
// }
// Rectangle::~Rectangle(void)
// {
//     cout << "The rectangle is deleted " << endl;
// }
// int main()
// {
//     Rectangle rec;
//     int x1,x2,y1,y2;
//     cin >> x1 >> y1 >> x2 >> y2;
//     cout << rec.Rec_S(x1, y1, x2, y2) << endl;
//     return 0;
// }

// class Circle
// {
// private:
//     int R, S, C;
// public:
//     Circle(int r)
//     {
//         R = r;
//         S = pi * R * R;
//         C = 2 * pi * R;
//     }
//     int get_S()
//     {
//         return S;
//     }
//     int get_C()
//     {
//         return C;
//     }
// };
// int main()
// {
//     int r;
//     cout << "the R of the swimming pool is " << endl;
//     cin >> r;
//     Circle cir1(r), cir2(r + 3);
//     cout << "the price of the guodao is " << (cir2.get_S() - cir1.get_S()) * 30 << endl;
//     cout << "the price of the zhalan is " << cir2.get_C() * 35 << endl;
//     return 0;
// }

class Complex
{
private:
    float R, I;
public:
    Complex(float r = 0, float i = 0):R(r), I(i){}
    float get_R()
    {
        return R;
    }
    float get_I()
    {
        return I;
    }
    void add(Complex c){
        R = R + c.get_R();
        I = I + c.get_I();
    }
    void show(){
        cout << R << " + " << I << "i" << endl;
    }
};
int main()
{
    Complex c1(2, 2);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
    return 0;
}