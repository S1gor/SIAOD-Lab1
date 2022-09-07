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
		fscanf_s(file, "%s%s%s%d%d%d%d%d%d", &mas[i].surname, 20, &mas[i].name, 20, &mas[i].fathername, 20, &mas[i].recordNumber,
			&mas[i].marks[0], &mas[i].marks[1], &mas[i].marks[2], &mas[i].marks[3], &mas[i].marks[4]);

	fclose(file);
}

void PrintStudent(Student mas[], int numberStudent)
{
	for (int i = 0; i < numberStudent; i++)
		printf("%s\t%s\t%s\t%d\t%d %d %d %d %d\n", mas[i].surname, mas[i].name, mas[i].fathername, mas[i].recordNumber,
			mas[i].marks[0], mas[i].marks[1], mas[i].marks[2], mas[i].marks[3], mas[i].marks[4]);
}

void Sort(Student mas[], int numberStudent, int d)
{
	for (int i = 0; i < numberStudent; i++)
		for (int j = 0; j < numberStudent - 1; j++)
		{
			if (mas[j].surname[d] > mas[j + 1].surname[d])
			{
				Student tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
			/*if (mas[j].surname[0] == mas[j + 1].surname[0])
			{
				for (int k = 0; k < numberStudent; k++)
					for (int l = 0; l < numberStudent - 1; l++)
					{
						if (mas[l].surname[1] > mas[l + 1].surname[1])
						{
							Student tmp = mas[j];
							mas[j] = mas[j + 1];
							mas[j + 1] = tmp;
						}
					}
			}*/
		}
	/*for (int i = 0; i < numberStudent; i++)
	{
		if (mas[i].surname[d] == mas[i + 1].surname[d])
		{
			d++;
			Sort(mas, numberStudent, d);
		}
	}*/
}

int main()
{
	system("chcp 1251"); system("cls");

	const int numberStudent = 10;
	Student mas[numberStudent];

	char filename[] = "1.txt";

	ReadFile(filename, mas, numberStudent);
	
	PrintStudent(mas, numberStudent);

	int d = 0;
	Sort(mas, numberStudent, d);

	printf("\n\n\n");
	PrintStudent(mas, numberStudent);


	return 0;
}