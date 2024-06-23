#include "pch.h"
#if AlgorithmNumber == 9
#include <vector>
#include <algorithm>

int main()
{
	vector <pair<int, string>> v;

	v.push_back(pair<int, string>(90, "박한울"));
	v.push_back(pair<int, string>(85, "이테일"));
	v.push_back(pair<int, string>(82, "나동빈"));
	v.push_back(pair<int, string>(98, "강종구"));
	v.push_back(pair<int, string>(79, "이상욱"));

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << "\n";
	}
	cout  << "==================\n";
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << "\n";
	}

	return 0;
}
#endif

/*!
알고리즘 해더를 이용한 정렬 방법입니다.
*/