#include "pch.h"

#if AlgorithmNumber == 8
#include <algorithm>

bool compare(int a, int b)
{
	return a > b;
}

class Student
{
public:
	string name;
	int score;
	Student(string name, int score) :name(name), score(score) {}
	// ���� ������ "������ ���� ����"
	bool operator < (Student& student)
	{
		return this->score < student.score;
	}
};

int main()
{
	int a[10] = { 9, 3, 5, 4, 1, 10, 8, 6, 7, 2 };
	sort(a, a + 10, compare);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << " =========================== \n";

	Student students[] =
	{
		Student("������", 90),
		Student("�̻��", 93),
		Student("���ѿ�", 97),
		Student("������", 87),
		Student("������", 92),
	};
	sort(students, students + 5);

	for (int i = 0; i < 5; i++)
	{
		cout << students[i].name << "\n";
	}
	return 0;
}
#endif
/*!
�˰��� �ش��� �̿��� ���� ����Դϴ�.
*/