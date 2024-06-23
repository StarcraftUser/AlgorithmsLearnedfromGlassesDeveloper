#include "pch.h"
#if AlgorithmNumber == 21
#if Tutorial == 1

__int64 dp(__int64 x)
{
	if (x == 1)return 1;
	if (x == 2)return 1;

	return dp(x - 1) + dp(x - 2);
}

int main()
{
	cout << dp(50) << endl;
	return 0;
}
#endif

#if Tutorial == 2
__int64 d[100];
__int64 dp(__int64 x)
{
	if (x == 1)return 1;
	if (x == 2)return 1;
	if (d[x] != 0)return d[x];
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main()
{
	cout << dp(50) << endl;
	return 0;
}
#endif
#endif