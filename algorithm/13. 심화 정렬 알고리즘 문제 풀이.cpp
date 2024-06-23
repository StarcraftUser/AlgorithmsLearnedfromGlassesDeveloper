#include "pch.h"
#if AlgorithmNumber == 13
#if Tutorial == 1
#include <algorithm>

string a[20000];
int n;

bool compare(string a, string b)
{
	//���̰� ª�� ���� �켱
	if (a.length() < b.length())
	{
		return true;
	}
	else if (a.length() < b.length())
	{
		return false;
	}
	else // ���̰� �������
	{
		return a < b; // ���������� ����
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, compare);

	for (int i = 0; i < n; i++)
	{
		if (i > 0 && a[i] == a[i - 1])
		{
			continue;
		}
		else
		{
			cout << a[i] << '\n';
		}
	}
	return 0;
}
#endif

#if Tutorial == 2
#include <algorithm>
string a[20000];
int n;

int getSum(string a)
{
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++)
	{
		//������ ��쿡�� ���մϴ�.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
		{
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b)
{
	//���̰� ª�� ���� �켱
	if (a.length() < b.length())
	{
		return true;
	}
	else if (a.length() < b.length())
	{
		return false;
	}
	else // ���̰� �������
	{
		int aSum = getSum(a);
		int bSum = getSum(b);
		if (aSum != bSum)
		{
			return aSum < bSum;
		}
		else
		{
			return a < b; // ���������� ����
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, compare);

	for (int i = 0; i < n; i++)
	{
		if (i > 0 && a[i] == a[i - 1])
		{
			continue;
		}
		else
		{
			cout << a[i] << '\n';
		}
	}
	return 0;
}
#endif

#if Tutorial == 3
int n;
int a[10001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		while (a[i] != 0)
		{
			cout << i << '\n';
			a[i]--;
		}
	}
	return 0;
}
#endif
#endif