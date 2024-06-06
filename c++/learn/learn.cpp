#include<cstdio>
#include<cstdlib>

int main() {
	char ch[10][10];
	char click[20];
	int n;
	int num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s", ch[2 * i], ch[2 * i + 1]); 
	}
	while (scanf("%s%d", click, &num) != EOF) {
		num = num - 1;
		printf("%s-%s Clicked", ch[2 * num], ch[2 * num + 1]);
	}
}
