#include "pch.h"
#if AlgorithmNumber == 15
#include <queue>

int main()
{
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();

	while (!q.empty())
	{
		cout << q.front() << "\n";
		q.pop();
	}
	return 0;
}
#endif