#include<iostream>
#include<vector>
using namespace std;
/*int main()
{
    int n, i ,j;
    cin >> n;
    vector<int> A(n * n, 0);
    //1
    int point = n * n / 2 + 1;
    int mid = n / 2 + 1;
    for (i = 0, j = point; i < n; i++)
        A[i * n + mid] = 1 + i * 6;
    //2
    for (i = 0, j = n; j > 0; j--, i++)
        A[i * n + j] = point + n / 2;
    //3

}*/
int main()
{
    int n, i ,j;
    cin >> n;
    vector<int> A(n * n, 0);
    int mid = n / 2;
    int k = 1; i = 0; j = mid;
    A[i * n + j] = k++;
    while (k <= n * n)
    {
        int x = i, y = j;
        i--; j++;
        if (i < 0)
            i = n - 1;
        if (j > n - 1)
            j = 0;
        if(A[i * n + j] != 0)
        {
            A[(x + 1) * n + y] = k++;
            i = x + 1; j = y;
        }
        else
        {
            A[i * n + j] = k++;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++){
            cout.width(4);
            cout << A[i * n + j];
        }
        cout << endl;
    }
    return 0;
}
