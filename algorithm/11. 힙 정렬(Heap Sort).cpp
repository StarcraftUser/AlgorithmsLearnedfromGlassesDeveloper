#include "pch.h"
#if AlgorithmNumber == 11
//n * log n

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };


int main()
{
	// 먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다.
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
	// 크기를 줄여가며 반복적으로 힙을 구성
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
이진트리에서 먼저 최대힙을 만듭니다. 최대힙이란 최상단부터 큰숫자를 차례로 배치시킵니다.
그다음 맨 마지막의 노드와 루트 노드와 자리를 바꿉니다.
자식 노드2개를 비교하여 큰 자식노드를 선택합니다.
그다음 루트와 비교하여 루트가 작다면 자식의 노드와 자리를 바꿉니다.
자리를 바꾼 자식위치를 루트로 잡고 그 노드에서 다시 값이 큰 자식 노드와 루트의 노드를 비교하여 자식이 크다면 노드를 바꿉니다.
for문에서 맨 마지막 자식의 처리가 완료되면 숫자를 줄여 다음 자식의 숫자를 맨 앞의 루트와 자리를 바꿉니다.
역시 자식노드들과 비교하여 큰 자식노드와 작아진 루트와 자리를 바꿉니다.
계속 이런식으로 정렬을 반복하게됩니다.

*/