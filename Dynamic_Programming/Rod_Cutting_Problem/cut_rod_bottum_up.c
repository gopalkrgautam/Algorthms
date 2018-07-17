#include <stdio.h>

int Max(int a, int b){return(a>b?a:b);}

int main()
{
    int p[] = {1, 5, 8, 10, 13, 17, 17, 20, 24, 30};
    int q;
    int n = 4;
    int i, j;
    int r[n+1];

    r[0] = 0;


    for (j = 1; j <= n; j++)
    {
        q = -1;

        for(i = 1; i <= j; i++)
        {
            q = Max(q, p[i-1] + r[j-i]);
        }

        r[j] = q;
    }

    printf("The maximun obtainable price for the rod of length %d unit is : %d\n", n, q);
}