#include "pch.h"
#if AlgorithmNumber == 11
//n * log n

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };


int main()
{
	// ���� ��ü Ʈ�� ������ �ִ� �� ������ �ٲߴϴ�.
	for (int i = 1; i < number; i++)
	{
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	// ũ�⸦ �ٿ����� �ݺ������� ���� ����
	for (int i = number - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			if (c < i - 1 && heap[c] < heap[c + 1])
			{
				c++;
			}
			if (c < i && heap[root] < heap[c])
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}

	for (int i = 0; i < number; i++)
		cout << heap[i] << "\n";


	return 0;
}
#endif

/*!
����Ʈ������ ���� �ִ����� ����ϴ�. �ִ����̶� �ֻ�ܺ��� ū���ڸ� ���ʷ� ��ġ��ŵ�ϴ�.
�״��� �� �������� ���� ��Ʈ ���� �ڸ��� �ٲߴϴ�.
�ڽ� ���2���� ���Ͽ� ū �ڽĳ�带 �����մϴ�.
�״��� ��Ʈ�� ���Ͽ� ��Ʈ�� �۴ٸ� �ڽ��� ���� �ڸ��� �ٲߴϴ�.
�ڸ��� �ٲ� �ڽ���ġ�� ��Ʈ�� ��� �� ��忡�� �ٽ� ���� ū �ڽ� ���� ��Ʈ�� ��带 ���Ͽ� �ڽ��� ũ�ٸ� ��带 �ٲߴϴ�.
for������ �� ������ �ڽ��� ó���� �Ϸ�Ǹ� ���ڸ� �ٿ� ���� �ڽ��� ���ڸ� �� ���� ��Ʈ�� �ڸ��� �ٲߴϴ�.
���� �ڽĳ���� ���Ͽ� ū �ڽĳ��� �۾��� ��Ʈ�� �ڸ��� �ٲߴϴ�.
��� �̷������� ������ �ݺ��ϰԵ˴ϴ�.

*/