#include<cstdio>

class schedule {
	int year, month, day, hour, minute, second;
public:
	schedule(int y, int m, int d, int h, int min, int s) : year(y), month(m), day(d), minute(min), s(second){};
}

int main() {
	int num = 0;
	int par[6] = {0};
	int maxpar[6] = {0}, flag = 0;
	while (scanf("%d %d/%d/%d %d:%d:%d", &num, &par[0], &par[1], &par[2], &par[3], &par[4], &par[5]) != EOF) {
		for (int i = 0; i < 6; i++) {
			if (par[i] < maxpar[i]) {
				for (int j = 0; j < 6; j++) {
					flag = num;
					maxpar[j] = par[j]
				}
				break;
			}
			
		}
	}
	printf("The urgent schedule is No.%d: %d/%d/%d %d:%d:%d", flag, par[0], par[1], par[2], par[3], par[4], par[5]);
}
