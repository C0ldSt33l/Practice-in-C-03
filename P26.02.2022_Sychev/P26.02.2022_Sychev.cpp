#include<iostream>
#include<time.h>


// ������� � ���������� ��������� ��� 1-�� �������
const int MAX = 100;

void scanArraySize(int& rows, int& cols) // ��������� ������ �������
{
	printf("������� ������ ������� (m � n <= 100)\n");

	do
	{
		printf("m = "); scanf_s("%d", &rows);
		printf("n = "); scanf_s("%d", &cols);

		if (rows < 1 || rows > 100 || cols < 1 || cols > 100)
			printf("������� ������������ ������� �������. ��������� ����\n");
	} while (rows < 1 || rows > 100 || cols < 1 || cols > 100);
}

void fillArrayByRandomFloat(float arr[][MAX], int rows, int cols) // ��������� ������� ���������� ������������� �������
{
	srand(time(0));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = (float)rand() / (RAND_MAX + 1) * 80 - 50;
}

void printArray(float arr[][MAX], int rows, int cols) // ������� ������� �� �����
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("|%7.3f", arr[i][j]);
		printf("|\n");
	}
}

void findMaxAbsElOfArray(float arr[][MAX], int rows, int cols, float& maxel) // ������� ������� � ���������� ������� � �������
{
	float maxabs = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (fabs(arr[i][j]) > maxabs)
			{
				maxabs = abs(arr[i][j]);
				maxel = arr[i][j];
			}
}

void divideAllElsOnMaxEl(float arr[][MAX], int rows, int cols, float max) // ����� ������ ������� ������� �� ���������� �� ���
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] /= max;
}

// 1-�� �������
void taskOne()
{
	float array[MAX][MAX], max_abs_el;
	int m, n;

	// ��������� ������ �������, ��������� ���������� ������������� ������� � ������� �� �����
	scanArraySize(m, n);
	fillArrayByRandomFloat(array, m, n);
	printArray(array, m, n);

	// ������� ������������ �� ������ ������� � ������� ��� �� �����
	findMaxAbsElOfArray(array, m, n, max_abs_el);
	printf("���������� �� ������ ������� �������: %.3f\n", max_abs_el);

	// ����� ��� �������� �� ������������ �� ������ � ������� ������������ �������
	divideAllElsOnMaxEl(array, m, n, max_abs_el);
	printArray(array, m, n);
}

// ������� ��� 2-�� �������
void checkX(double& x) // ��������� �������� ������������ ����� x
{
	printf("������� ������������ ����� x � ��������� [-1.007, 1.007]:\n");

	do
	{
		printf("x = "); scanf_s("%lf", &x);

		if (x < -1.007 or x > 1.007)
			printf("������� ������������ �����. ��������� ����\n");
	} while (x < -1.007 or x > 1.007);
}

// 2-�� �������
void taskTwo()
{
	double x, f, e = 0.00001, sum;
	int k = 1;

	checkX(x);

	x = x * x;
	f = sum = -1 * x / 6; // ����������� 1-�� �������

	printf("%d. %.10lf\n", k, f);
	printf("sum = %.10lf\n", sum);

	for (k = 2; k < 12; k++) // ����������� 2-11 �������� � �� �����
	{
		f *= (3 * x / (k + 3) - x);
		printf("%d. %.10lf\n", k, f);
		sum += f;
		printf("sum = %.10lf\n", sum);
	}

	do // ��������� ���������� ��������, ������� ����� ��������� � ������� ��������������� �������
	{
		f *= (3 * x / (k + 3) - x);
		printf("%d. %.10lf\n", k, f);
		sum += f;
		printf("sum = %.10lf\n", sum);
		k++;
	} while (abs(f) >= e);

	printf("����������� k: %d\n����� ���� = %.10lf", k - 2, sum - f); // ������� ����� ������� �������� � ����� ��������� �� k
}

// ������� ��� 3-�� �������
void checkE(double& x, double& e) // ��������� �������� ����� e
{
	printf("������� x � e (e > 0):\n");
	printf("x = "); scanf_s("%lf", &x);
	
	do
	{
		printf("e = "); scanf_s("%lf", &e);

		if (e <= 0)
			printf("������� ������������ �����. ��������� ����\n");
	} while (e <= 0);
}

void printCurrentElementAndCurrentSum(int elementnumber, double element, double sum) // ������� �� ����� ������� ������� (� ��� �������) � ������� ����� ���������
{
	printf("%d. %.3lf\n", elementnumber, element);
	printf("sum = %.3lf\n", sum);
}

// 3-� �������
void taskThree()
{
	double f, e, x, sum;
	int n = 1;

	checkE(x, e);

	f = sum = x / 24; // ������� 1-�� ������� ����

	printCurrentElementAndCurrentSum(n, f, sum);

	if (f < e) // ��������� ������ �� 1-�� ������ ����� e
		printf("Final sum = 0");
	else
	{
		do
		{
			n++;
			f *= (-1 * x / (n + 4));
			sum += f;

			printCurrentElementAndCurrentSum(n, f, sum);
		} while (f >= e);

		printf("Final sum = %.3lf\n", sum - f); // ������� �� ����� ����� ���������
	}
}

// ����� �������
void taskSelect(int& way)
{
	printf("�������� ����� �������:\n");
	printf("1 - ������� ����� 10 (���� Praktika_2_3)\n");
	printf("2 - ������� ����� 19 (���� Praktika_2_3)\n");
	printf("3 - ������� ����� 19 (���� Praktika_3_3)\n");

	do // �������� ������ �������
	{
		scanf_s("%d", &way);

		if (way > 3 || way < 1)
			printf("������� ������������ �����. ��������� �������\n");
	} while (way > 3 || way < 1);
	
	switch (way)
	{
	case 1: // ������� ����� 10 (���� Praktika_2_3)
		taskOne();

		break;
	case 2: // ������� ����� 19 (���� Praktika_2_3)
		taskTwo();

		break;
	case 3: // ������� ����� 19 (���� Praktika_3_3)
		taskThree();

		break;
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	int way;

	taskSelect(way);

	return 0;
}