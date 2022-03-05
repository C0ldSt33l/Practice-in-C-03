#include<iostream>
#include<time.h>


// Функции и глобальная переменна для 1-го задания
const int MAX = 100;

void scanArraySize(int& rows, int& cols) // Сканируем размер матрицы
{
	printf("Введите рамеры матрицы (m и n <= 100)\n");

	do
	{
		printf("m = "); scanf_s("%d", &rows);
		printf("n = "); scanf_s("%d", &cols);

		if (rows < 1 || rows > 100 || cols < 1 || cols > 100)
			printf("Введены неправильные размеры матрицы. Повторите ввод\n");
	} while (rows < 1 || rows > 100 || cols < 1 || cols > 100);
}

void fillArrayByRandomFloat(float arr[][MAX], int rows, int cols) // Заполняем матрицу случайными вещественными числами
{
	srand(time(0));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = (float)rand() / (RAND_MAX + 1) * 80 - 50;
}

void printArray(float arr[][MAX], int rows, int cols) // Выводим матрицу на экран
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("|%7.3f", arr[i][j]);
		printf("|\n");
	}
}

void findMaxAbsElOfArray(float arr[][MAX], int rows, int cols, float& maxel) // Находим элемент с наибольшим модулем в матрице
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

void divideAllElsOnMaxEl(float arr[][MAX], int rows, int cols, float max) // Делим каждый элемент матрицы на наибольший из них
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] /= max;
}

// 1-ое задание
void taskOne()
{
	float array[MAX][MAX], max_abs_el;
	int m, n;

	// Сканируем размер матрицы, заполняем случайными вещественными числами и выводим на экран
	scanArraySize(m, n);
	fillArrayByRandomFloat(array, m, n);
	printArray(array, m, n);

	// Находим максимальный по модулю элемент и выводим его на экран
	findMaxAbsElOfArray(array, m, n, max_abs_el);
	printf("Наибольший по модулю элемент матрицы: %.3f\n", max_abs_el);

	// Делим все элементы на максимальный по модулю и выводим получившуюся матрицу
	divideAllElsOnMaxEl(array, m, n, max_abs_el);
	printArray(array, m, n);
}

// Функция для 2-го задания
void checkX(double& x) // Проверяем вводимое вещественное число x
{
	printf("Введите вещественное число x в диапозоне [-1.007, 1.007]:\n");

	do
	{
		printf("x = "); scanf_s("%lf", &x);

		if (x < -1.007 or x > 1.007)
			printf("Введено неправильное число. Повторите ввод\n");
	} while (x < -1.007 or x > 1.007);
}

// 2-ое задание
void taskTwo()
{
	double x, f, e = 0.00001, sum;
	int k = 1;

	checkX(x);

	x = x * x;
	f = sum = -1 * x / 6; // Высчитываем 1-ей элемент

	printf("%d. %.10lf\n", k, f);
	printf("sum = %.10lf\n", sum);

	for (k = 2; k < 12; k++) // высчитываем 2-11 элементы и их сумму
	{
		f *= (3 * x / (k + 3) - x);
		printf("%d. %.10lf\n", k, f);
		sum += f;
		printf("sum = %.10lf\n", sum);
	}

	do // Вычисляем оставшиеся элементы, находим сумму элементов и элемент удовлетворяющий условию
	{
		f *= (3 * x / (k + 3) - x);
		printf("%d. %.10lf\n", k, f);
		sum += f;
		printf("sum = %.10lf\n", sum);
		k++;
	} while (abs(f) >= e);

	printf("Минимальный k: %d\nСумма ряда = %.10lf", k - 2, sum - f); // Выводим номер нужного элемента и сумму элементов до k
}

// Функции для 3-го задания
void checkE(double& x, double& e) // Проверяем вводимое число e
{
	printf("Введите x и e (e > 0):\n");
	printf("x = "); scanf_s("%lf", &x);
	
	do
	{
		printf("e = "); scanf_s("%lf", &e);

		if (e <= 0)
			printf("Введено направильное число. Повторите ввод\n");
	} while (e <= 0);
}

void printCurrentElementAndCurrentSum(int elementnumber, double element, double sum) // Выводим на экран текущий элемент (с его номером) и текущую сумму элементов
{
	printf("%d. %.3lf\n", elementnumber, element);
	printf("sum = %.3lf\n", sum);
}

// 3-е задание
void taskThree()
{
	double f, e, x, sum;
	int n = 1;

	checkE(x, e);

	f = sum = x / 24; // Считаем 1-ый элемент ряда

	printCurrentElementAndCurrentSum(n, f, sum);

	if (f < e) // Проверяем меньше ли 1-ый элемет числа e
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

		printf("Final sum = %.3lf\n", sum - f); // Выводим на экран сумму элементов
	}
}

// Выбор задания
void taskSelect(int& way)
{
	printf("Выберите номер задания:\n");
	printf("1 - задание номер 10 (файл Praktika_2_3)\n");
	printf("2 - задание номер 19 (файл Praktika_2_3)\n");
	printf("3 - задание номер 19 (файл Praktika_3_3)\n");

	do // Проверка выбора задания
	{
		scanf_s("%d", &way);

		if (way > 3 || way < 1)
			printf("Введено направильное число. Повторите попытку\n");
	} while (way > 3 || way < 1);
	
	switch (way)
	{
	case 1: // задание номер 10 (файл Praktika_2_3)
		taskOne();

		break;
	case 2: // задание номер 19 (файл Praktika_2_3)
		taskTwo();

		break;
	case 3: // задание номер 19 (файл Praktika_3_3)
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