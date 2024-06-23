#include "pch.h"

#if AlgorithmNumber == 14
#include <stack>

int main()
{
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();

	while (!s.empty())
	{
		cout << s.top() << "\n";
		s.pop();
	}
	return 0;
}
#endif