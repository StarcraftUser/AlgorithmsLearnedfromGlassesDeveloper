#include "pch.h"
#if AlgorithmNumber == 36
#if Tutorial == 1
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int>a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s;

// 매칭에 성공한 경우 true, 실패한 경우 false
bool dfs(int x)
{
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];
		// 이미 처리한 노드는 더이상 볼 필요가 없음
		if (c[t])continue;
		c[t] = true;
		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= s; j++)
		{
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);
		if (dfs(i))count++;
	}

	cout << count << '\n';
	return 0;
}
#endif
#if Tutorial == 2
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int>a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s;

// 매칭에 성공한 경우 true, 실패한 경우 false
bool dfs(int x)
{
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];
		// 이미 처리한 노드는 더이상 볼 필요가 없음
		if (c[t])continue;
		c[t] = true;
		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= s; j++)
		{
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);
		if (dfs(i))count++;
	}

	cout << count << '\n';
	return 0;
}
#endif
#if Tutorial == 3
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int>a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s;

bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];
		if (c[t])continue;
		c[t] = true;
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= s; j++)
		{
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			fill(c, c + MAX, false);
			if (dfs(i))count++;
		}
	}


	cout << count << '\n';
	return 0;
}
#endif
#if Tutorial == 4
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int>a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s, k;

bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];
		if (c[t])continue;
		c[t] = true;
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= s; j++)
		{
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);
		if (dfs(i))count++;
	}

	int extra = 0;
	for (int i = 1; i <= n && extra < k; i++)
	{
		fill(c, c + MAX, false);
		if (dfs(i))extra++;

	}

	cout << count + extra << '\n';
	return 0;
}
#endif
#if Tutorial == 5
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int astat[MAX][3];
int d[1001];
int c[1001];
int n;

bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;
		if (d[y] == 0 || dfs(d[y]))
		{
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> astat[i][0] >> astat[i][1] >> astat[i][2];
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (astat[i][0] == astat[j][0] && astat[i][1] == astat[j][1] && astat[i][2] == astat[j][2])
			{
				a[i].push_back(j);
			}
			else if (astat[i][0] >= astat[j][0] && astat[i][1] >= astat[j][1] && astat[i][2] >= astat[j][2])
			{
				a[i].push_back(j);
			}
			else if (astat[i][0] <= astat[j][0] && astat[i][1] <= astat[j][1] && astat[i][2] <= astat[j][2])
			{
				a[j].push_back(i);
			}
		}
	}
	int count = 0;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			fill(c, c + MAX, false);
			if (dfs(i)) count++;
		}
	}
	cout << n - count << '\n';
	return 0;
}
#endif
#endif