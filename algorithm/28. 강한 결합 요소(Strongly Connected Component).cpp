#include "pch.h"
#if AlgorithmNumber == 28
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001


int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

// DFS는 총 정점의 갯수만큼 실행됩니다. 
int dfs(int x) {
	d[x] = ++id; // 노드마다 고유한 번호를 할당 
	s.push(x); // 스택에 자기 자신을 삽입 

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y)); // 방문하지 않은 이웃 
		else if (!finished[y]) parent = min(parent, d[y]); // 처리중인 이웃 
	}

	if (parent == d[x])
	{
		// 부모노드가 자기 자신인 경우 
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	// 자신의 부모 값을 반환합니다. 
	return parent;
}

int main()
{
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 0) dfs(i);
	}
	cout << "SCC의 갯수: " << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); i++)
	{
		cout << i + 1 << "번째 SCC: ";
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif