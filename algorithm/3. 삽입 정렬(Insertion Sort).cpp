#include "pch.h"

#if AlgorithmNumber == 3

int main()
{
	int j, temp;
	int myarray[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (int i = 0; i < 9; i++)
	{
		j = i;
		while (myarray[j] > myarray[j + 1])
		{
			temp = myarray[j];
			myarray[j] = myarray[j + 1];
			myarray[j + 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myarray[i] << '\t';
	}
	return 0;
}

#endif