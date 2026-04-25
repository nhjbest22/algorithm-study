#include <stdio.h>
int main (void)
{
    int a, b ;
    double result ;
    scanf ("%d %d", &a, &b);
    result = (double)a / b ;
    printf ("%.9f\n",result);
    return 0;
}