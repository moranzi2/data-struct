#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int uniquePaths(int m, int n) {
    int a[105][105] = {0};
    
    if (m == 1 || n == 1)
    {
        return 1;
    }
    
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (i == 1)
                ++a[i][j];
            if (j == 1)
                ++a[i][j];
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    return a[m - 1][n - 1];
}
int main()
{
    uniquePaths(3, 7);
}