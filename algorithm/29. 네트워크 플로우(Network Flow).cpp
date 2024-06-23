//너비우선탐색(BFS)를 사용합니다.
#include "pch.h"
#if AlgorithmNumber == 29
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100
#define INF (INT32_MAX / 2)

int n = 6/*정점의 개수*/, result/*결과적으로 구할 최대 유량을 저장하는 변수*/;
int c[MAX][MAX]/*용량을 담아줄 변수*/, f[MAX][MAX]/*현재 흐르고 있는 값을 담아주는 변수*/, d[MAX]/*현재 노드를 방문을 했는지를 저장 및 확인하는 변수*/;
vector<int> a[MAX];

void maxFlow(int start, int end)
{
	while (true)
	{
		fill(d, d + MAX, -1);//모드 정점은 방문하지 않는 상태 -1로 초기화합니다.
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++)
			{
				int y = a[x][i];
				// 방문하지 않은 노드 중에 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1)
				{
					q.push(y);
					d[y] = x; // 경로를 기억합니다.
					if (y == end)break;//도착지에 도달을 한 경우

				}
			}
		}
		// 모든 경로를 찾은 뒤에 탈출합니다. 
		if (d[end] == -1)break;
		int flow = INF;
		for (int i = end; i != start; i = d[i])
		{
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		// 최소 유량만큼 추가합니다.
		for (int i = end; i != start; i = d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
			cout << i << "\t" << d[i] << "\t" << f[d[i]][i] << "\t" << f[i][d[i]] << endl;
		}
		result += flow;
	}
}

int main()
{
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	cout << result << endl;
	return 0;
}
#endif