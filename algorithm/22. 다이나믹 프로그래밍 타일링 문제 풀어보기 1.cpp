#include "pch.h"
#if AlgorithmNumber == 22
#if Tutorial == 1
int d[1001];

int dp(int x)
{
	if (x == 1)return 1;
	if (x == 2)return 2;
	if (d[x] != 0)return d[x];
	return d[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}

int main()
{
	int number;
	cin >> number;

	cout << dp(number) << "\n";
	return 0;
}
#endif
#if Tutorial == 2
//11727¹ø ¹®Á¦
int d[1001];

int dp(int x)
{
	if (x == 1)return 1;
	if (x == 2)return 3;
	if (d[x] != 0)return d[x];
	return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
}

int main()
{
	int number;
	cin >> number;

	cout << dp(number) << "\n";
	return 0;
}
#endif
#endif