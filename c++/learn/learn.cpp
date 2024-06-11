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
public:
	math(int x = 1) : a(x){};
	int add(int x, int y) {
		return a + x + y;
	}
	math operator+(int x) {
		math A;
		A.a = a + x;
		return A;
	}
	int geta() {
		return a;
	}
};
int main() {
	math a(1);
	math b = a + 2;
	std::cout << b.geta();
}
