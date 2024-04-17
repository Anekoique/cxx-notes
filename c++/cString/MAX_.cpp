#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char* str1 = (char*)malloc(1000 * sizeof(char));
    char* str2 = (char*)malloc(1000 * sizeof(char));
    scanf("%s%s", str1, str2);
    long len1 = strlen(str1);
    long len2 = strlen(str2);

    char* result = (char*)malloc((len1+2)*sizeof(char));
    char* ptr1 = str1 + len1 - 1;
    char* ptr2 = str2 + len2 - 1;
    char* resPtr = result;
    int carry = 0;
    while (ptr1 >= str1 || ptr2 >= str2 || carry)
    {
        int sum = carry;
        if (ptr1 >= str1){
            sum += *ptr1 - '0';
            ptr1--;
        }
        if (ptr2 >= str2){
            sum += *ptr2 - '0';
            ptr2--;
        }
        *resPtr = sum % 10 + '0';
        carry = sum / 10;
        resPtr++;
    }
    *resPtr = '\0';
    char* start = result;
    char* end = resPtr - 1;
    while (start < end){
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("%s+%s=%s\n", str1, str2, result);
    printf("%s-%s=",str1, str2);
    char* result2 = (char*)malloc((len1+2) * sizeof(char));
    char* resPtr2 = result2;
    str1+=len1-1;
    str2+=len2-1;
    while(len2){
        if(*str1-*str2<0)
        {
            *resPtr2 = *str1 - *str2 + 10 + '0';
            resPtr2++;
            str1--;
            *str1 -= 1;
            str2--;
        }else{
            *resPtr2 = *str1 - *str2 + '0';
            resPtr2++;
            str1--;
            str2--;
        }
        len2--;
        len1--;
    }
    if(len1 == len2 && *(resPtr2-1) == '0'){
        printf("0");
        return 0;
    }
    while(len1)
    {
        *resPtr2 = *str1;
        resPtr2++;
        str1--;
        len1--;
    }
    start = result2;
    end = resPtr2 - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("%s", result2);
}