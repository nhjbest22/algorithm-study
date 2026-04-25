#pragma warning(disable : 4996)
#include <stdio.h>
long long GCD(long long x, long long y)
{
	long long n;
	if (y != 0)
	{
		n = x % y;
		return GCD(y, n);
	}
	return x;
}
int main()
{
	long long num_1, num_2,result;
	scanf("%lld %lld", &num_1, &num_2);
	result = GCD(num_1, num_2);
	for (long long a = 0; a < result ; a++)
	{
		printf("1");
	}
	return 0;
}