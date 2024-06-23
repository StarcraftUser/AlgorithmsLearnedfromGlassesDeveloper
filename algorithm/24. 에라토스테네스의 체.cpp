#include "pch.h"
#if AlgorithmNumber == 24
#if Tutorial == 1
bool isPrimeNumber(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	cout << isPrimeNumber(97) << "\n";
	return 0;
}
#endif
#if Tutorial == 2
#include <math.h>

bool isPrimeNumber(int x)
{
	int end = (int)sqrt(x);
	for (int i = 2; i < end; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	cout << isPrimeNumber(97) << "\n";
	return 0;
}
#endif
#if Tutorial == 3

int number = 100000;
int a[100001];

void PrimeNumberSieve()
{
	for (int i = 1; i < number; i++)
	{
		a[i] = i;
	}
	for (int i = 2; i < number; i++)
	{
		if (a[i] == 0)continue;
		for (int j = i + i; j <= number; j += i)
		{
			a[j] = 0;
		}
	}

	for (int i = 2; i <= number; i++)
	{
		if (a[i] != 0) cout << a[i] << '\n';
	}
}

int main()
{
	PrimeNumberSieve();
	return 0;
}
#endif
#endif