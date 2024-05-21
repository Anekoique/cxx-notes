#include<iostream>

using namespace std;

class cDate {
    int year, month, day;
public: 
    cDate (int y, int m, int d): year(y), month(m), day(d) {};
    cDate& operator++();
    cDate operator++(int);
    cDate& operator+(long days) const;
    cDate& operator-(long days) const;
    long operator-(const cDate& d) const;
    static int isLeapYear(int y);
    friend ostream& operator<<(ostream& os, const cDate& d);
};

int cDate::isLeapYear(int y) {
	if (y%4 == 0 && y%100 != 0 || y%400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

cDate& operator++() {
	int list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 10, 31};
	if (lsLeapYear)
		list[1]++;
	if (day == list[month]) {
		day = 1;
		if (month == 12) {
			month = 1;
			year++;
		} else {
			month++;
		}
	} else {
		day++;
	}
	return *this;
}

cDate operator+(long days) {
}
int main()
{

}

