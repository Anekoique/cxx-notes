#include<cstdio>
#include<cstring>
#include<cstdlib>

int main()
{
    char* str1 = (char*)malloc(1000 * sizeof(char));
    char* str2 = (char*)malloc(1000 * sizeof(char));
    char str1_[1000];
    str1_[0] = *str1;
    scanf("%s%s", str1, str2);
    printf("%s", str1_);
}