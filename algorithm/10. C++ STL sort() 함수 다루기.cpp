#include "pch.h"
#if AlgorithmNumber == 10
#include <vector>
#include <algorithm>

bool compare(pair<string, pair<int, int>> a,
	pair<string, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
}

int main()
{
	vector <pair<string, pair<int, int>>> v;

	v.push_back(pair<string, pair<int, int>>("나동빈", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("이태일", pair<int, int>(97, 19930518)));
	v.push_back(pair<string, pair<int, int>>("박한울", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("이상구", pair<int, int>(90, 19921207)));
	v.push_back(pair<string, pair<int, int>>("강종구", pair<int, int>(88, 19900302)));

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << "\n";
	}
	cout << "==================\n";
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << "\n";
	}

	return 0;
}
#endif

/*!
알고리즘 해더와 compare 함수를 이용한 정렬 방법입니다.
*/