//Implementation of 'Rod-Cutting' probelm in C
//From CLRS psudo-code
#include <stdio.h>
int Max(int a, int b){return(a>b?a:b);} //Function to get the maximum of the two given inputs
int cut_rod(int p[], int n);

int main()
{
    int p[] = {1, 5, 8, 9, 10, 17, 20, 24, 30}, n = 4;  //Here P is the Array containing price of rod-pieces of length 1 t0 10
                                                        //and n is the size of the given length is unit
    
    printf("The maximum revenue obtainable by a rod of %d unit length is : %d", n, cut_rod(p, n));
    return 0;
}

int cut_rod(int p[], int n)
{
    int i, q;

    if(n == 0)
        return 0;
    q = -9;  // q should be iniatialised a negetive number to compare further with the obtainable price for maximizing the revenue

    for(i = 1; i <= n; i++)
        q = Max(q, (p[i-1] + cut_rod(p, n-i)));

    return q;
}