#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
class String
{
public:
	char* str;
	String() : str(new char[1])
	{
		str[0] = 0;
	}
 
	// 构造函数
	String(const char* s)
	{
		cout << "调用构造函数" << endl;
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy_s(str, len, s);
	}
 
	// 复制构造函数
	String(const String & s)
	{
		cout << "调用复制构造函数" << endl;
		int len = strlen(s.str) + 1;
		str = new char[len];
		strcpy_s(str, len, s.str);
	}
 
	// 复制赋值运算符
	String & operator = (const String & s)
	{
		cout << "调用复制赋值运算符" << endl;
		if (str != s.str)
		{
			delete[] str;
			int len = strlen(s.str) + 1;
			str = new char[len];
			strcpy_s(str, len, s.str);
		}
		return *this;
	}
 
	// 移动构造函数
	// 和复制构造函数的区别在于，其参数是右值引用
	String(String && s) : str(s.str)
	{
		cout << "调用移动构造函数" << endl;
		s.str = new char[1];
		s.str[0] = 0;
	}
 
	// 移动赋值运算符
	// 和复制赋值运算符的区别在于，其参数是右值引用
	String & operator = (String && s)
	{
		cout << "调用移动赋值运算符" << endl;
		if (str != s.str)
		{
			// 在移动赋值运算符函数中没有执行深复制操作，
			// 而是直接将对象的 str 指向了参数 s 的成员变量 str 指向的地方，
			// 然后修改 s.str 让它指向别处，以免 s.str 原来指向的空间被释放两次。
			str = s.str;
			s.str = new char[1];
			s.str[0] = 0;
		}
		return *this;
	}
 
	// 析构函数
	~String()
	{
		delete[] str;
	}
};
 
template <class T>
void MoveSwap(T & a, T & b)
{
	T tmp = move(a);  //std::move(a) 为右值，这里会调用移动构造函数
	a = move(b);  //move(b) 为右值，因此这里会调用移动赋值运算符
	b = move(tmp);  //move(tmp) 为右值，因此这里会调用移动赋值运算符
}
 
template <class T>
void Swap(T & a, T & b) 
{
	T tmp = a;  //调用复制构造函数
	a = b;  //调用复制赋值运算符
	b = tmp;  //调用复制赋值运算符
}
 
int main()
{
	String s;
	// 如果没有定义移动赋值运算符，则会导致复制赋值运算符被调用，引发深复制操作。
	s = String("this");  //调用移动赋值运算符
	cout << "print " << s.str << endl;
	String s1 = "hello", s2 = "world";
	//MoveSwap(s1, s2);  //调用一次移动构造函数和两次移动赋值运算符
	Swap(s1, s2);//调用一次复制构造函数，两次复制赋值运算符
	cout << "print " << s2.str << endl;
	return 0;
}
