#include "pch.h"

#if AlgorithmNumber == 7
constexpr int number = 8;

//int size;
int sorted[8]; // 정렬 배열은 반드시 전역 변수로 선언 
int count = 0;

void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;
	// 작은 순서대로 배열에 삽입 
	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// 남은 데이터도 삽입 
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	// 정렬된 배열을 삽입 
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	// 이외의 경우는 크기가 1개인 경우 
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main()
{
	int array[number] = { 7, 6, 5, 8, 3, 5, 9, 1 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
#endif

/*!
먼저 배열을 반씩 모두 쪼겐다. 1개 짜리의 배열로 모두 쪼갭니다.
그 다음 2개씩 붙여서 정렬을 수행합니다.
그 다음도 역시 기존의 정렬된 배열의 2배씩 다시 작은 순서대로 정렬합니다.

*/

