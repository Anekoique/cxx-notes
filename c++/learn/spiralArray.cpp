#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
/*int main()
{ 
    int n;
    cin >> n;
    int* A;
    A = new int[n * n];
    memset(A, 0x00, sizeof (int)*n*n);

    int iRow,iCol;
    enum DIRECTION {DOWN, LEFT, UP, RIGHT};
    DIRECTION dir = DOWN;
    iRow = 0;
    iCol = n-1;
    for (int k = 1; k <= n * n; ++k)
    {
        A[iRow * n + iCol] = k;
        switch(dir)
        {
            case DOWN:
                if (iRow < n - 1 && A[(iRow + 1) * n + iCol] == 0)
                {
                    iRow++;
                }else
                {
                    dir = LEFT;
                    iCol--;
                }
                break;
            case LEFT:
                if (iCol > 0 && A[iRow * n + iCol - 1] == 0)
                {
                    iCol--;
                }else{
                    dir = UP;
                    iRow--;
                }
                break;
            case UP:
                if (iRow > 0 && A[(iRow - 1) * n + iCol] == 0)
                {
                    iRow--;
                }else{
                    dir = RIGHT;
                    iCol++;
                }
                break;
            case RIGHT:
                if (iCol < n - 1 && A[iRow * n + iCol + 1] == 0)
                {
                    iCol++;
                }else{
                    dir = DOWN;
                    iRow++;
                }
                break;
        }
    }
    for (iRow = 0; iRow < n; iRow++)
    {
        for (iCol = 0; iCol < n; iCol++)
        {
            cout.width(4);
            cout << A[iRow * n + iCol];
        }
        cout << endl;
    }
    delete [] A;
}*/
/*int main()
{
    int n;
    cin >> n;
    int* A;
    A = new int[n * n];
    memset(A, 0x00, sizeof (int)*n*n);

    int iRow,iCol;
    iRow = 0;iCol = 0;
    enum DIRECTION {DOWN = 0, RIGHT, UP, LEFT};
    DIRECTION dir = DOWN;
    for (int k = 1; k <= n * n; k++){
        A[iRow * n + iCol] = k;
        switch(dir){
            case DOWN:
                if (iRow < n - 1 && A[(iRow + 1) * n + iCol] == 0){
                    iRow++;
                }else{
                    dir = RIGHT;
                    iCol++;
                }
                break;
            case RIGHT:
                if (iCol < n - 1 && A[iRow * n + iCol + 1] == 0)
                {
                    iCol++;
                }else{
                    dir = UP;
                    iRow--;
                }
                break;
            case UP:
                if (iRow > 0 && A[(iRow - 1) * n + iCol] == 0)
                {
                    iRow--;
                }else{
                    dir = LEFT;
                    iCol--;
                }
                break;
            case LEFT:
                if (iCol > 0 && A[iRow * n + iCol - 1] == 0)
                {
                    iCol--;
                }else{
                    dir = DOWN;
                    iRow++;
                }
                break;;
        }
    }
    for (iRow = 0; iRow < n; iRow++){
        for(iCol = 0; iCol < n; iCol++){
            cout.width(4);
            cout << A[iRow * n + iCol];
        }
        cout<<endl;
    }
    delete [] A;
    return 0;
}*/
/*int main()
{
    int n;
    cin >> n;
    vector<int> A(n*n, 0);

    int iRow, iCol;
    enum DIRECTION {DOWN, LEFT, UP, RIGHT};
    DIRECTION dir = DOWN;
    iRow = 0;
    iCol = n - 1;
    for (int k = 1; k <= n * n; ++k)
    {
        A[iRow * n + iCol] = k;
        switch (dir)
        {
            case DOWN:
                if (iRow < n - 1 && A[(iRow + 1) * n + iCol] == 0)
                {
                    iRow++;
                }else
                {
                    dir = LEFT;
                    iCol--;
                }
                break;
            case LEFT:
                if (iCol > 0 && A[iRow * n + iCol - 1] == 0)
                {
                    iCol--;
                }else{
                    dir = UP;
                    iRow--;
                }
                break;
            case UP:
                if (iRow > 0 && A[(iRow - 1) * n + iCol] == 0)
                {
                    iRow--;
                }else{
                    dir = RIGHT;
                    iCol++;
                }
                break;
            case RIGHT:
                if (iCol < n - 1 && A[iRow * n + iCol + 1] == 0)
                {
                    iCol++;
                }else{
                    dir = DOWN;
                    iRow++;
                }
                break;
        }
    }
    for (iRow = 0; iRow < n; iRow++)
    {
        for (iCol = 0; iCol < n; iCol++)
        {
            cout.width(4);
            cout << A[iRow * n + iCol];
        }
        cout << endl;
    }
}*/
int main()
{
    int n;
    cin >> n;
    vector<int> A(n*n, 0);

    int iRow, iCol;
    enum DIRECTION {DOWN, LEFT, UP, RIGHT};
    DIRECTION dir = LEFT;
    iRow = 0;
    iCol = n - 1;
    for (int k = 1; k <= n * n; ++k)
    {
        A[iRow * n + iCol] = k;
        switch (dir)
        {
            case DOWN:
                if (iRow < n - 1 && A[(iRow + 1) * n + iCol] == 0)
                {
                    iRow++;
                }else
                {
                    dir = RIGHT;
                    iCol--;
                }
                break;
            case LEFT:
                if (iCol > 0 && A[iRow * n + iCol - 1] == 0)
                {
                    iCol--;
                }else{
                    dir = DOWN;
                    iRow--;
                }
                break;
            case UP:
                if (iRow > 0 && A[(iRow - 1) * n + iCol] == 0)
                {
                    iRow--;
                }else{
                    dir = LEFT;
                    iCol++;
                }
                break;
            case RIGHT:
                if (iCol < n - 1 && A[iRow * n + iCol + 1] == 0)
                {
                    iCol++;
                }else{
                    dir = UP;
                    iRow++;
                }
                break;
        }
    }
    for (iRow = 0; iRow < n; iRow++)
    {
        for (iCol = 0; iCol < n; iCol++)
        {
            cout.width(4);
            cout << A[iRow * n + iCol];
        }
        cout << endl;
    }
}