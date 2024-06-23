#include "pch.h"
#if AlgorithmNumber == 37
#if Tutorial == 1
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

// �׻� ó�� �湮�ϴ� ��常 ����˴ϴ�. ��, N�� ����
int dfs(int x)
{
	d[x] = ++id; // ��帶�� ������ ��ȣ�� �����ϴ�.
	s.push(x); // ���ÿ� �ڱ� �ڽ��� �ֽ��ϴ�.

	int result = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// ���� �湮���� ���� �̿� ����� ��� 
		if (d[y] == 0) result = min(result, dfs(y));
		// �湮�� ������ ���� ó�� ���� �̿� ����� ��� 
		else if (!finished[y]) result = min(result, d[y]);
	}

	// �θ� ��尡 �ڱ� �ڽ��� ��� SCC�� �����մϴ�.
	if (result == d[x])
	{
		vector<int> scc;
		while (true)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	// �ڽ��� �θ� ���� ��ȯ�մϴ�. 
	return result;
}

int main()
{
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 0) dfs(i);
	}
	cout << SCC.size() << '\n';
	sort(SCC.begin(), SCC.end());
	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}
#endif
#if Tutorial == 2
#include <iostream>
#include <vector>
#include <stack>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX];

int dfs(int x)
{
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x])
	{
		vector<int> scc;
		while (true)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1;
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
		{
			if (d[i] == 0) dfs(i);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				int y = a[i][j];
				if (group[i] != group[y])
					inDegree[group[y]] = true;
			}
		}
		int result = 0;
		for (int i = 1; i <= SCC.size(); i++)
		{
			if (!inDegree[i]) result++;
		}
		cout << result << '\n';
	}
	return 0;
}
#endif
#if Tutorial == 3
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX];
vector<int> result;

int dfs(int x)
{
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x])
	{
		vector<int> scc;
		while (true)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1;
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		result.clear();
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			a[x + 1].push_back(y + 1);
		}
		for (int i = 1; i <= n; i++)
		{
			if (d[i] == 0) dfs(i);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				int y = a[i][j];
				if (group[i] != group[y])
					inDegree[group[y]] = true;
			}
		}
		int count = 0;
		for (int i = 0; i < SCC.size(); i++)
		{
			if (!inDegree[i + 1])
			{
				count++;
				for (int j = 0; j < SCC[i].size(); j++)
				{
					result.push_back(SCC[i][j] - 1);
				}
			}
		}
		sort(result.begin(), result.end());
		if (count != 1)
		{
			cout << "Confused\n\n";
		}
		else
		{
			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i] << "\n";
			}
			cout << "\n";
		}
	}
	return 0;
}
#endif
#endif