#include <iostream>
using std::cout;
#include "stringbad.h"

void callme1(StringBad &);
void callme2(StringBad &);

int main()
{
	using std::endl;
	{
		StringBad headline1("hello world1");
		StringBad headline2("hello world2");
		StringBad sports("hello world3");
		callme1(headline1);
		callme2(headline2);
		StringBad sailor = sports;
		StringBad knot;
		knot = headline1;
		cout << "knot : " << knot << std::endl;
		StringBad * str = new StringBad;
		cout << *str;
		(*str).show();
		str->show();
		delete str;
	}
	cout << "End of main()\n";

	return 0;
}

void callme1(StringBad & rab)
{
	cout << "String passed by reference:\n";
	cout << " \"" << rab << " \"\n";
}

void callme2(StringBad & sb)
{
	cout << "String passed by value:\n";
	cout << " \"" << sb << " \"\n";
}
