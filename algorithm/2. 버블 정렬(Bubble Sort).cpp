#include "pch.h"

#if AlgorithmNumber == 2

int main()
{
	int temp;
	int myarray[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (myarray[j] > myarray[j + 1])
			{
				temp = myarray[j];
				myarray[j] = myarray[j + 1];
				myarray[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myarray[i] << '\t';
	}
	return 0;
}

#endif