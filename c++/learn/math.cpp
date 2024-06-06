// #include<cstdio>
// int measure(int x, int y) {
// 	int z = y;
// 	while (x % y != 0) {
// 		z = x % y;
// 		x = y;
// 		y = z;
// 	}
// 	return z;
// }
// int beishu(int x, int y) {
// 	int z = measure(x, y);
// 	return x * y / z;
// }
// class math {
// public:
// 	int zi, mu;
// 	int flag;
//     math(int zi=1, int mu=1) {
// 		if (zi != 0) {
// 			int x = measure(zi, mu);
// 			if (mu == 1) {
// 				this->zi = zi;
// 				this->mu = 1;
// 				flag = 0;
// 			} else if (x != 1) {
// 				zi = zi / x;
// 				mu = mu / x;
// 				flag = 1;
// 			} else {
// 				this->zi = zi;
// 				this->mu = mu;
// 				flag = 2;
// 			}
// 		} else {
// 			this->zi = zi;
// 			this->mu = mu;
// 		}
//     }
// 	void show() {
// 		if (!flag) printf("%d\n", zi);
// 		else printf("%d/%d\n", zi, mu);
// 	}
// 	void show2() {
// 		if (!flag) printf("%d\t", zi);
// 		else printf("%d/%d\t", zi, mu);
// 	}
// 	void newmath() {
// 		int x = measure(this->zi, this->mu);
// 		if (this->mu == 1) {
// 			this->mu = 1;
// 			this->flag = 0;
// 		} else if (x != 1 || x != -1) {
// 			this->zi = this->zi / x;
// 			this->mu = this->mu / x;
// 			if (this->mu == 1) {
// 				this->mu = 1;
// 				this->flag = 0;
// 			} else
// 				this->flag = 1;
// 		} else {
// 			this->flag = 2;
// 		}
// 		if (this->mu < 0) {
// 			this->mu = -this->mu;
// 			this->zi = -this->zi;
// 		}
// 	}
// };


// math operator+(const math& a, const math& b) {
// 	math m;
// 	if (!a.flag && !b.flag) {
// 		m.mu = 1;
// 		m.zi = a.zi + b.zi;
// 	}
// 	else if (!a.flag && b.flag) {
// 		m.mu = b.mu;
// 		m.zi = b.mu * a.zi + b.zi;
// 	}
// 	else if (a.flag && !b.flag) {
// 		m.mu = a.mu;
// 		m.zi = a.zi + a.mu * b.zi;
// 	}
// 	else {
// 		m.mu = beishu(a.mu, b.mu);
// 		m.zi = m.mu / a.mu * a.zi + m.mu / b.mu * b.zi;
// 	}
// 	m.newmath();
// 	return m;
// }
// math operator-(const math& a, const math& b) {
// 	math m;
// 	if (!a.flag && !b.flag) {
// 		m.mu = 1;
// 		m.zi = a.zi - b.zi;
// 	}
// 	else if (!a.flag && b.flag) {
// 		m.mu = b.mu;
// 		m.zi = b.mu * a.zi - b.zi;
// 	}
// 	else if (a.flag && !b.flag) {
// 		m.mu = a.mu;
// 		m.zi = a.zi - a.mu * b.zi;
// 	}
// 	else {
// 		m.mu = beishu(a.mu, b.mu);
// 		m.zi = m.mu / a.mu * a.zi - m.mu / b.mu * b.zi;
		
// 	}
// 	m.newmath();
// 	return m;
// }
// math operator*(const math& a, const math& b) {
// 	math m;
// 	if (!a.flag && !b.flag) {
// 		m.mu = 1;
// 		m.zi = a.zi * b.zi;
// 	} else if (!a.flag && b.flag) {
// 		m.mu = b.mu;
// 		m.zi = a.zi * m.zi;
// 	} else if (a.flag && !b.flag) {
// 		m.mu = a.mu;
// 		m.zi = b.zi * a.zi;
// 	} else {
// 		m.mu = a.mu * b.mu;
// 		m.zi = a.zi * b.zi;
// 	}
// 	m.newmath();
// 	return m;
// }
// math operator/(const math& a, const math& b) {
// 	math m;
// 	if (!a.flag && !b.flag) {
// 		m.mu = 1;
// 		m.zi = a.zi / b.zi;
// 	} else if (!a.flag && b.flag) {
// 		m.mu = b.zi;
// 		m.zi = b.mu / a.zi;
		
// 	}
// 	else if (a.flag && !b.flag) {
// 		m.mu = a.mu;
// 		m.zi = a.zi;
// 		m.mu *= b.zi;
// 	}
// 	else {
// 		m.mu = a.mu * b.zi;
// 		m.zi = a.zi * b.mu;
// 	}
// 	m.newmath();
// 	return m;
// }

// int main() {
//     int x1, y1, x2, y2;
//     scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
// 	math m1(x1, y1);
// 	math m2(x2, y2);
// 	math m3 = m1 + m2;
// 	math m4 = m1 - m2;
// 	math m5 = m1 * m2;
// 	math m6 = m1 / m2;
// 	m1.show();
// 	m2.show();
// 	m3.show2();
// 	m4.show2();
// 	m5.show2();
// 	m6.show2();
// 	return 0;
// }

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

class Rational{
public:
    Rational(int num=1,int denomi=1){ //构造函数，带默认参数
        numerator = num;
        denominator = denomi;
        normalize();
    }
    Rational operator + (Rational &s); //重载加法运算
    Rational operator - (Rational &s); //重载减法运算
    Rational operator * (Rational &s); //重载乘法运算
    Rational operator / (Rational &s); //重载除法运算

    bool operator > (Rational &s); //重载">"运算符
    bool operator < (Rational &s); //重载"<"运算符
    bool operator >= (Rational &s); //重载">="运算符
    bool operator <= (Rational &s); //重载"<="运算符
    bool operator == (Rational &s); //重载"=="运算符
   
    friend istream& operator >>(istream&,Rational&);
    friend ostream& operator <<(ostream&,Rational &); //重载输出运算符
     
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    void normalize(); //将分数化为最简式函数
private:
    int numerator; //分子
    int denominator; //分母
};


void Rational::normalize(){
    if(denominator<0){ //保证分母大于0
        numerator *= -1;
        denominator *= -1;
    }
    int a = abs(numerator);
    int b = abs(denominator);
    int gcd_ab = gcd(a,b); //求分子、分母的最大公约数
   
    //分子、分母分别除以最大公约数，得到最简式
    numerator /= gcd_ab;  
    denominator /=gcd_ab;
}

Rational Rational:: operator + (Rational &s){
    Rational t;
    t.numerator = numerator*s.denominator+denominator*s.numerator;
    t.denominator = denominator*s.denominator;
    return Rational(t.numerator,t.denominator);
}

Rational Rational::operator - (Rational &s){
    Rational t;
    t.numerator = numerator*s.denominator-denominator*s.numerator;
    t.denominator = denominator*s.denominator;
    return Rational(t.numerator,t.denominator);
}

Rational Rational::operator * (Rational &s){
    Rational t;
    t.numerator = numerator*s.numerator;
    t.denominator = denominator*s.denominator;
    return Rational(t.numerator,t.denominator);
}

Rational Rational::operator / (Rational &s){
    Rational t;
    t.numerator = numerator*s.denominator;
    t.denominator = denominator*s.numerator;
    return Rational(t.numerator,t.denominator);
}

bool Rational::operator > (Rational &s){
    if(numerator*s.denominator-denominator*s.numerator>0)
        return true;
    else
        return false;
}

bool Rational::operator < (Rational &s){
    if(numerator*s.denominator-denominator*s.numerator<0)
        return true;
    else
        return false;
}

bool Rational::operator >= (Rational &s){
    if(numerator*s.denominator-denominator*s.numerator>=0)
        return true;
    else
        return false;
}

bool Rational::operator <= (Rational &s){
    if(numerator*s.denominator-denominator*s.numerator<=0)
        return true;
    else
        return false;
}

bool Rational::operator == (Rational &s){
    if(numerator*s.denominator-denominator*s.numerator==0)
        return true;
    else
        return false;
}

istream& operator >> (istream& in,Rational &obj){
    in >> obj.numerator;
    in >> obj.denominator;
	obj.normalize();
    return in;
}
ostream& operator << (ostream& out,Rational &obj){
    if(obj.numerator==0)
        out << obj.numerator;
	else {
		if(obj.denominator==1)
			out << obj.numerator;
		else
			out << obj.numerator << '/' << obj.denominator;
	}
	return out;
}

int main(){
    Rational r1,r2;
    cin >> r1;
    cout << r1 << endl;
    cin >> r2;
    cout << r2 << endl;
   
    //测试四则运算运算符
    Rational r3 = r1+r2;
    Rational r4 = r1-r2;
    Rational r5 = r1*r2;
    Rational r6 = r1/r2;   
	cout << r3 << '\t' << r4 << '\t' << r5 << '\t' << r6 << '\t';
    // cout << "r1 + r2 = " << r3 << endl;
    // cout << "r1 - r2 = " << r4 << endl;
    // cout << "r1 * r2 = " << r5 << endl;
    // cout << "r1 / r2 = " << r6 << endl;
   
    // //测试比较运算符
    // if(r1>r2) cout << "r1大于r2" << endl;
    // if(r1<r2) cout << "r1小于r2" << endl;
    // if(r1==r2) cout << "r1等于r2" << endl;
    // if(r1<=r2) cout << "r1小于等于r2" << endl;
    // if(r1>=r2) cout << "r1大于等于r2" << endl;
    return 0;
}
