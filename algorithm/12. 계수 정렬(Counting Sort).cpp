#include "pch.h"
#if AlgorithmNumber == 12
//O(n)

int main()
{
	int count[5];
	int myArray[30] = { 1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
					 3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
					 3, 1, 4, 3, 5, 1, 2, 1, 1, 1 };

	for (int i = 0; i < 5; i++) count[i] = 0;

	for (int i = 0; i < 30; i++)
		count[myArray[i] - 1]++;

	for (int i = 0; i < 5; i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
			{
				cout << i + 1;
			}
		}
	}


	return 0;
}
#endif
/*!
원래 배열이 가지는 값이 크지 않다면 
원래 배열이 가지는 최대값을 기준으로 새로운 배열을 만듭니다. 배열의 크기는 원래 배열이 가지는 최대값입니다.
그다음 원래 배열의 값들을 확인해서 해당 값을 새로만든 배열의 인덱스에 값을 증가시킵니다.
탐색이 끝나고 다시 출력할때,
새로만든 배열의 인덱스에서 숫자를 감소시키면서 for문과 while문을 이용해서 출력합니다.
*/