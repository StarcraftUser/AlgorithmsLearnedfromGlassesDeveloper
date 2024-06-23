#include "pch.h"

#if AlgorithmNumber == 1

int main()
{
	int min, index, temp;
	int myarray[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (int i = 0; i < 10; i++)
	{
		min = 10000;
		for (int j = i; j < 10; j++)
		{
			if (min > myarray[j])
			{
				min = myarray[j];
				index = j;
			}
		}
		temp = myarray[i];
		myarray[i] = myarray[index];
		myarray[index] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myarray[i] << '\t';
	}
	return 0;
}

#endif