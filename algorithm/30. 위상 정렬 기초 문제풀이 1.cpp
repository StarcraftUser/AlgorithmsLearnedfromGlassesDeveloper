#include "pch.h"
#if AlgorithmNumber == 30
#if Tutorial == 1
#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int n, inDegree[MAX], result[MAX];
vector<int> a[MAX];

void topologySort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < a[x].size(); j++)
		{
			int y = a[x][j];
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << " ";
	}
}

int main()
{
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		inDegree[y]++;
	}
	topologySort();
}
#endif
#if Tutorial == 2
#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int n, inDegree[MAX], bulidtime[MAX], result[MAX];
vector<int> a[MAX];

void topologySort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			result[i] = bulidtime[i];
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			result[y] = max(result[y], result[x] + bulidtime[y]);
			if (--inDegree[y] == 0) q.push(y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << '\n';
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> bulidtime[i];
		while (true)
		{
			int x;
			cin >> x;
			if (x == -1) break;
			inDegree[i]++;
			a[x].push_back(i);
		}
	}
	topologySort();
}
#endif
#endif