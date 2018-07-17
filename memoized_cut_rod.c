//C-Implementation of 'Rod Ctuttng' problem using Dynamic Peogramming
#include <stdio.h>

int Max(int a, int b){return(a>b?a:b);}

int memoized_cut_rod(int p[], int n);
int memoized_cut_rod_aux(int p[], int n, int r[]);

int memoized_cut_rod(int p[], int n)
{
    int r[n+1];
    int i;
    r[0] = 0;
    for(i = 1; i <= n; i++)
    {
        r[i] = -999;
    }
    return(memoized_cut_rod_aux(p, n, r));
}

int memoized_cut_rod_aux(int p[], int n, int r[])
{
    int i, q;

    if( r[n] >= 0)
        return (r[n]);

    if( n==0)
        q = r[0];
    
    else
    {
        q = -999;
        for( i = 1; i <= n; i++)  
            q = Max(q, p[i-1] + memoized_cut_rod_aux(p, n-i, r));
    }
    return q;
}

int main()
{
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 4;
    printf("The maximun obtainable price for the rod of length %d unit is : %d\n", n, memoized_cut_rod(p, n));
    
    return 0;
}

