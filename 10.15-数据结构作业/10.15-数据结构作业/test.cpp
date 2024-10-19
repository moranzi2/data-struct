#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void test(int n)
{
	int i;
	i = n;
	printf("%d\n", i--);
	if (i > 1)
		return test(i);
	else
		return;
}
bool isValid(char* s) {
    struct SL {
        int* a;
        int top;
        int capacity;
    }b;
    b.a = (int*)malloc(sizeof(int) * 10000);
    b.top = -1;
    b.capacity = 10000;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            b.a[b.top + 1] = 1;
            b.top++;
        }
        if (s[i] == '{')
        {
            b.a[b.top + 1] = 2;
            b.top++;
        }
        if (s[i] == '[')
        {
            b.a[b.top + 1] = 3;
            b.top++;
        }
        if (s[i] == ')')
        {
            if (b.top == -1)
                return false;
            if (b.a[b.top] != 1)
                return false;
            b.top--;
        }
        if (s[i] == '}')
        {
            if (b.top == -1)
                return false;
            if (b.a[b.top] != 2)
                return false;
            b.top--;
        }
        if (s[i] == ']')
        {
            if (b.top == -1)
                return false;
            if (b.a[b.top] != 3)
                return false;
            b.top--;
        }
        i++;
    }
    if (b.top == -1)
        return true;
    else
        return false;
}
int Min(int a, int b)
{
    return a > b ? b : a;
}
int minPathSum(int grid[3][3], int gridSize, int gridColSize) {//––∫Õ¡–
    int grids[3][3];
    grids[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++)
    {
        grids[i][0] = grids[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < gridColSize; i++)
    {
        grids[0][i] = grids[0][i] + grid[0][i];
    }
    for (int i = 1; i < gridSize; i++)
    {
        for (int j = 1; j < gridColSize; j++)
        {
            grids[i][j] = Min(grids[i][j - 1], grids[i - 1][j]) + grid[i][j];
        }
    }
    return grids[gridSize - 1][gridColSize - 1];
}
int main()
{
	test(10);
    char a[10] = { '{' ,'}','(','[',']',')'};
    char b[10] = { '(','{',')', '}', '[', ']' };
    printf("%d\n", isValid(a));
    printf("%d\n", isValid(b));
   /* int grid[3][3] = {1,3,1,1,5,1,4,2,1};
    minPathSum(grid, 3, 3);*/
}