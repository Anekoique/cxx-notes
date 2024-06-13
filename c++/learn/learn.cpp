//#include<cstdio>
//#include<iostream>
//#include<cstdlib>
//
//struct job
//{
//	char name[40];
//	double salary;
//	int floor;
//};
//
//template <typename T>
//void swap(T &a, T &b) {
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//template <class T>
//void swap(T *a, T *b, int n) {
//	T temp;
//	for (int i = 0; i < n; i++) {
//		temp = a[i];
//		a[i] = b[i];
//		b[i] = temp;
//	}	
//}
//
//template <> void swap<job>(job &a, job &b) {
//	double t1;
//	int t2;
//	t1 = a.salary;
//	a.salary = b.salary;
//	b.salary = t1;
//	t2 = a.floor;
//	a.floor = b.floor;
//	b.floor = t2;
//}
//
//int main() {
//	int a = 1, b = 2;
//	swap(a ,b);
//	std::cout << a << ' ' << b << std::endl;
//}
//

#include<iostream>
class math {
	int a;
	static int A;
public:
	math(int x = 1) : a(x){};
	explicit math(double x);
	int add(int x, int y) {
		return a + x + y;
	}
	math operator+(int x) {
		math A;
		A.a = x + a;
		return A;
	}
	friend math operator+(int x, const math & X);
	friend std::ostream &  operator<<(std::ostream & os, const math & X);	
	int geta() const {return a;}
	// int getA() const {return A;}
};

math::math(double x) {
	a = (int)x;
}

math operator+(int x, const math & X) {
	math A;
	A.a = x + X.a;
    return A;	
}

std::ostream & operator<<(std::ostream & os, const math & X) {
	os << X.a;
	return os;
}

int main() {
	math a(1);
	math b = 2 + a;
	math c = a + 2;
	std::cout << b.geta() << std::endl;
	std::cout << c.geta() << std::endl;
	std::cout << a << std::endl;
	// std::cout << a.getA() << std::endl;
	math A;
	A = (math)16.6;
	std::cout << A.geta() << std::endl;
}

