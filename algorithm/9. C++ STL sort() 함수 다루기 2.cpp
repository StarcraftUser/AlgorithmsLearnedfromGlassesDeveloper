#include "pch.h"
#if AlgorithmNumber == 9
#include <vector>
#include <algorithm>

int main()
{
	vector <pair<int, string>> v;

	v.push_back(pair<int, string>(90, "���ѿ�"));
	v.push_back(pair<int, string>(85, "������"));
	v.push_back(pair<int, string>(82, "������"));
	v.push_back(pair<int, string>(98, "������"));
	v.push_back(pair<int, string>(79, "�̻��"));

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
�˰��� �ش��� �̿��� ���� ����Դϴ�.
*/