#include <iostream>

struct Student
{
	char name[20];
	char surname[20];
	char fathername[20];
	int recordNumber;
	int marks[5];
	float avgMarks;
};

void ReadFile(const char* filename, Student mas[], int numberStudent)
{
	FILE* file;
	if (fopen_s(&file, filename, "r") != NULL)
	{
		printf("Не удалось открыть файл %s", filename);
		exit(1);
	}

	for (int i = 0; i < numberStudent; i++)
	{
		fscanf_s(file, "%s%s%s%d%d%d%d%d%d", &mas[i].surname, 20, &mas[i].name, 20, &mas[i].fathername, 20, &mas[i].recordNumber,
			&mas[i].marks[0], &mas[i].marks[1], &mas[i].marks[2], &mas[i].marks[3], &mas[i].marks[4]);
		mas[i].avgMarks = float(mas[i].marks[0] + mas[i].marks[1] + mas[i].marks[2] + mas[i].marks[3] + mas[i].marks[4]) / 5;
	}

	fclose(file);
}

int SelectSorting()
{
	int choose;
	do {
		printf("Выберите сортировку:\n1 - по фамилии\n2 - по среднему баллу\n3 - Вывести учеников, у которых средний балл от 3.5 до 4.5\nВыбор:");
		scanf_s("%d", &choose);
	} while (choose > 3 || choose < 1);
	return choose;
}

void SortSurname(Student mas[], int numberStudent)
{
	for (int i = 0; i < numberStudent - 1; i++)
		for (int j = 0; j < numberStudent - i - 1; j++)
		{
			switch (strcmp(mas[j].surname, mas[j + 1].surname))
			{
			case 1:
				Student tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
				break;
			case 0:
				if (strcmp(mas[j].name, mas[j + 1].name) > 0)
				{
					Student tmp = mas[j];
					mas[j] = mas[j + 1];
					mas[j + 1] = tmp;
				}
				break;
			}
		}
}

void SortAvgMarks(Student mas[], int numberStudent)
{
	for (int i = 0; i < numberStudent - 1; i++)
		for (int j = 0; j < numberStudent - i - 1; j++)
			if (mas[j].avgMarks < mas[j + 1].avgMarks)
			{
				Student tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
}

void PrintStudent(Student mas[], int numberStudent)
{
	for (int i = 0; i < numberStudent; i++)
		printf("%s\t%s\t%s\t%d\t%d %d %d %d %d | %.1f\n", mas[i].surname, mas[i].name, mas[i].fathername, mas[i].recordNumber,
			mas[i].marks[0], mas[i].marks[1], mas[i].marks[2], mas[i].marks[3], mas[i].marks[4], mas[i].avgMarks);
	printf("\n");
}

void printAvgMarks(Student mas[], int numberStudent)
{
	for (int i = 0; i < numberStudent; i++)
		if (mas[i].avgMarks >= 3.5 && mas[i].avgMarks <= 4.5)
			printf("%s\t%s\t%s\t%d\t%d %d %d %d %d | %.1f\n", mas[i].surname, mas[i].name, mas[i].fathername, mas[i].recordNumber,
				mas[i].marks[0], mas[i].marks[1], mas[i].marks[2], mas[i].marks[3], mas[i].marks[4], mas[i].avgMarks);
}

int main()
{
	system("chcp 1251"); system("cls");

	const int numberStudent = 10;
	Student mas[numberStudent];

	char filename[] = "1.txt";

	ReadFile(filename, mas, numberStudent);
	PrintStudent(mas, numberStudent);

	switch (SelectSorting())
	{
	case 1:
		SortSurname(mas, numberStudent);
		printf("\n");
		PrintStudent(mas, numberStudent);
		break;
	case 2:
		SortAvgMarks(mas, numberStudent);
		printf("\n");
		PrintStudent(mas, numberStudent);
		break;
	case 3:
		printf("\n");
		printAvgMarks(mas, numberStudent);
		break;
	}

	return 0;
}