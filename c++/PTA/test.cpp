#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	int n;
	string ptr1, ptr2;
	vector<string> vec1, vec2;
	while (scanf("%d", &n) && n != 0){
		for (int i = 0; i < n / 2; i++) {
			cin >> ptr1;
			cin >> ptr2;
			vec1.push_back(ptr1);
			vec2.push_back(ptr2);
		}
		if (n % 2 == 1) {
			cin >> ptr1;
			vec1.push_back(ptr1);
		}
		vector<string>::const_iterator i1, i2;
		for (i1 = vec1.begin(); i1 != vec1.end(); i1++) {
			cout << *i1 << endl;
		}
		for (i2 = vec2.begin(); i2 != vec2.end(); i2++) {
			cout << *i2 << endl;
		}
		vec1.clear();
		vec2.clear();
	}
}
