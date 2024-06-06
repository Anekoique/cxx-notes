// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<string.h>
// void add(char* str1, char* str2, int flag)
// {
//     if (flag)
//         printf("-");
//     long len1 = strlen(str1);
//     long len2 = strlen(str2);
//     char* result = (char*)malloc(1000 * sizeof(char));
//     char* ptr1 = str1 + len1 - 1;
//     char* ptr2 = str2 + len2 - 1;
//     char* resPtr = result;
//     int carry = 0;
//     while(ptr1 >= str1 || ptr2 >= str2 || carry){
//         int sum = carry;
//         if(ptr1 >= str1){
//             sum += *ptr1 - '0';
//             ptr1--;
//         }
//         if (ptr2 >= str2){
//             sum += *ptr2 - '0';
//             ptr2--;
//         }
//         *resPtr = sum % 10 + '0';
//         carry = sum / 10;
//         resPtr++;
//     }
//     *resPtr = '\0';
//     char* start = result;
//     char* end = resPtr - 1;
//     while (start < end){
//         char temp = *start;
//         *start = *end;
//         *end = temp;
//         start++;
//         end--;
//     }
//     printf("%s\n", result);
//     free(result);
// }
// void minus(char* a, char* b)
// {
//     long len1 = strlen(a);
//     long len2 = strlen(b);
//     if (len1 < len2 || (len1 == len2 && strcmp(a, b) < 0)){
//         printf("-");
//         char* temp = a;
//         a = b;
//         b = temp;
//         int tmp;
//         tmp = len1;
//         len1 = len2;
//         len2 = tmp;
//     }
//     char* result = (char*)malloc(1000 * sizeof(char));
//     result[0] = '\0';
//     char* ptr1 = a + len1 - 1;
//     char* ptr2 = b + len2 - 1;
//     int borrow = 0;
//     int diff;
//     while (ptr1 >= a)
//     {
//         int digitA = *ptr1 - '0';
//         int digitB = ptr2 >= b ? *ptr2 - '0' : 0;
//         diff = digitA - digitB - borrow;
//         if (diff < 0){
//             diff += 10;
//             borrow = 1;
//         }else{
//             borrow = 0;
//         }
//         *(result + (ptr1 - a)) = diff + '0';
//         if (ptr2 >= b){
//             ptr2--;
//         }
//         ptr1--;
//     }
//     while (*result == '0' && *(result + 1) != '\0'){
//         result++;
//     }
//     if (*result == '\0')
//         printf("0\n");
//     else
//         printf("%s\n", result);
//     free(result);
// }
// int main()
// {
//     char* str1 = (char*)malloc(1000 * sizeof(char));
//     char* str2 = (char*)malloc(1000 * sizeof(char));
//     scanf("%s%s", str1, str2);
//     int flag;
//     if (*str1 == '-' && *str2 == '-')
//         flag = 1;
//     else if (*str1 == '-')
//         flag = 2;
//     else if (*str2 == '-')
//         flag = 3;
//     else
//         flag = 4;
//     switch(flag){
//         case 1:
//             add(++str1, ++str2, 1);
//             minus(str2, str1);
//             break;
//         case 2:
//             minus(str2, ++str1);
//             add(str1, str2, 1);
//             break;
//         case 3:
//             minus(str1, ++str2);
//             add(str1, str2, 0);
//             break;
//         case 4:
//             add(str1, str2, 0);
//             minus(str1, str2);
//             break;
//     }
// }
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void add(char* str1, char* str2, int flag)
{
    if (flag)
        printf("-");
    long len1 = strlen(str1);
    long len2 = strlen(str2);
    char* result = (char*)malloc(1000 * sizeof(char));
    char* ptr1 = str1 + len1 - 1;
    char* ptr2 = str2 + len2 - 1;
    char* resPtr = result;
    int carry = 0;
    while(ptr1 >= str1 || ptr2 >= str2 || carry){
        int sum = carry;
        if(ptr1 >= str1){
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
    printf("%s\n", result);
    free(result);
}
void minus(char* a, char* b)
{
    long len1 = strlen(a);
    long len2 = strlen(b);
    if (len1 < len2 || (len1 == len2 && strcmp(a, b) < 0)){
        printf("-");
        char* temp = a;
        a = b;
        b = temp;
        int tmp;
        tmp = len1;
        len1 = len2;
        len2 = tmp;
    }
    char* result = (char*)malloc(1000 * sizeof(char));
    char* current = result;
    result[0] = '\0';
    char* ptr1 = a + len1 -1;
    char* ptr2 = b + len2 - 1;
    int borrow = 0;
    int diff;
    while (ptr1 >= a)
    {
        int digitA = *ptr1 - '0';
        int digitB = ptr2 >= b ? *ptr2 - '0' : 0;
        diff = digitA - digitB - borrow;
        if (diff < 0){
            diff += 10;
            borrow = 1;
        }else{
            borrow = 0;
        }
        *(current + (ptr1 - a)) = diff + '0';
        if (ptr2 >= b){
            ptr2--;
        }
        ptr1--;
    }
    while (*current == '0' && *(current + 1) != '\0'){
        current++;
    }
    if (*current == '\0')
        printf("0\n");
    else
        printf("%s\n", current);
    free(result);
}
int main()
{
    char* str1 = (char*)malloc(1000 * sizeof(char));
    char* str2 = (char*)malloc(1000 * sizeof(char));
    scanf("%s%s", str1, str2);
    int flag;
    if (*str1 == '-' && *str2 == '-')
        flag = 1;
    else if (*str1 == '-')
        flag = 2;
    else if (*str2 == '-')
        flag = 3;
    else
        flag = 4;
    switch(flag){
        case 1:
            add(++str1, ++str2, 1);
            minus(str2, str1);
            break;
        case 2:
            minus(str2, ++str1);
            add(str1, str2, 1);
            break;
        case 3:
            minus(str1, ++str2);
            add(str1, str2, 0);
            break;
        case 4:
            add(str1, str2, 0);
            minus(str1, str2);
            break;
    }
}