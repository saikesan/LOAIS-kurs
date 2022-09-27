#include "head.h"

void menu()
{
	vector<vector<int>>::iterator i;
	vector<vector<int>> most_set;
	ifstream f;

	int max = 0, sled = 0, max_shag = -1, x = 0, max_size=0;
	int* vis=NULL, * set=NULL;
	int** num_reb = NULL, ** max_mas = NULL;
	int exit_key = 0, k = 0;
	int** A = NULL;
	string str;
	size_t n = NULL;

	while (exit_key != 1)
	{
		exit_key = 0;
		cout << "Меню" << endl << "1. Создать Матрицу" << endl << "2. Выход" << endl;
		cin >> k;
		system("cls");

		switch (k)
		{
		case 1:

			while ((exit_key != 2) && (exit_key != 1) && (exit_key != 3) && (exit_key != 5))
			{
				cout << "Ввести размер" << endl << "1.Размер" << endl << "2.Из файла(без указания размера)" << endl << "3.Выход" << endl << "4.В начало" << endl;
				cin >> k;
				system("cls");
				switch (k)
				{
				case 1:
					cout << "Размер= " << endl;
					cin >> n;
					A = Create(n);
					system("cls");
					exit_key = 2;
					break;
				case 2:
					cout << "Имя файла" << endl;
					cin >> str;
					f.open(str);
					f >> n;
					A = Create(n);
					read_from_file(str, A, n);
					f.close();
					system("cls");
					exit_key = 3;
					break;
				case 3:
					cout << "Bye" << endl;
					exit_key = 1;
					break;
				case 4:
					Free(A, n, vis, set);
					null(A, vis, set);
					exit_key = 5;
				}
			}
			while ((exit_key != 1) && (exit_key != 3) && (exit_key != 5))
			{
				cout << "Заполнить" << endl << "1.Вручную" << endl << "2.Авто" << endl << "3.Выход" << endl << "4.В начало" << endl;
				cin >> k;
				system("cls");
				switch (k)
				{
				case 1:
					Input(A, n);
					exit_key = 3;
					break;
				case 2:
					FillRandomNumbers(A, n);
					exit_key = 3;
					break;
				case 3:
					cout << "Bye" << endl;
					exit_key = 1;
					break;
				case 4:
					Free(A, n, vis, set);
					null(A, vis, set);
					exit_key = 5;
				}

			}
			while ((exit_key != 1) && (exit_key != 4) && (exit_key != 5))
			{
				cout << "Работа с матрицей" << endl << "1.Отрисовать" << endl << "2.Поиск н.п." << endl << "3.Выход" << endl << "4.В начало" << endl;
				cin >> k;
				system("cls");
				switch (k)
				{
				case 1:
					cout << "Матрица:" << endl;
					Print(A, n);
					break;
				case 2:
					system("cls");
					cout << "Матрица:" << endl;
					Print(A, n);
					search(i, most_set, max, A, sled, max_shag, vis, set, num_reb, max_mas, n, x, max_size);
					exit_key = 4;
					break;
				case 3:
					system("cls");
					cout << "Bye" << endl;
					exit_key = 1;
					break;
				case 4:
					Free(A, n, vis, set);
					null(A, vis, set);
					exit_key = 5;
					break;
				}
			}
			while ((exit_key != 1) && (exit_key != 5))
			{
				cout << "1.Сохранить" << endl << "2.Выход" << endl << "3.В начало" << endl;
				cin >> k;
				system("cls");
				switch (k)
				{
				case 1:
					cout << "Имя файла: ";
					cin >> str;
					cout << "Сохранено!" << endl;
					save_in_file(str, A, n, max_mas, max, num_reb, max_size);
					break;
				case 2:
					system("cls");
					cout << "Bye" << endl;
					exit_key = 1;
					break;
				case 3:
					Free(A, n, vis, set);
					null(A, vis, set);
					exit_key = 5;
				}
			}
			break;
		case 2:
			cout << "Bye" << endl;
			exit_key = 1;
		}
	}
}
