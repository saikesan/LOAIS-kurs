#include "head.h"


void save_in_file(string str, int** M, size_t n, int**max_mas, int max, int** num_reb,int max_size)
{
	ofstream f(str);
	ifstream fout("data.txt");
	int** write = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		write[i] = new int[max_size];
	}
	if (f.is_open())
	{
		f << "Матрица" << endl;
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				f << M[i][j] << ' ';
			}
			f << endl;
		}
		f << "\nНаибольшее паросочетание графа:" << endl;

		for (int i = 0; i < max_size; i++)
		{
			fout >> write[0][max_size];
			f << write[0][max_size] << "-";
			fout >> write[1][max_size];
			f << write[1][max_size] << endl;
		}

	}
	else
	{
		cout << "Ошибка: файл(сохранение)" << endl;
	}
	fout.close();
	f.close();
}

void read_from_file(string str, int** M, size_t n)
{
	ifstream f(str);
	size_t trash = NULL;
	if (f.is_open())
	{
		f >> trash;
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				f >> M[i][j];
			}
		}
	}
	else
	{
		cout << "Ошибка: файл(запись)" << endl;
	}
	f.close();

}

int** Create(size_t n)
{
	int** M = new int* [n];
	for (size_t i = 0; i < n; ++i) {
		M[i] = new int[n];
	}
	return M;
}

void Free(int** M1, size_t n, int* m1, int* m2)
{
	for (size_t i = 0; i < n; ++i) {
		delete[] M1[i];
	}
	delete[] m1;
	delete[] m2;
	delete[] M1;
}

void null(int** M1, int* m1, int* m2)
{
	M1 = NULL;
	m1 = NULL;
	m2 = NULL;
}

void Input(int** M, size_t n)
{
	int z = 1;
	for (size_t i = 0; i < n; ++i) 
	{
		M[i][i] = 0;
		for (size_t j = z; j < n; ++j) 
		{
			cout << "M[" << i << "][" << j << "] = ";
			cin >> M[i][j];
			M[j][i] = M[i][j];
		}
		z++;
	}
}

void FillRandomNumbers(int** M, size_t n)
{
	srand(time(NULL));
	int z = 1;
	for (size_t i = 0; i < n; i++)
	{
		M[i][i] = 0;
		for (size_t j = z; j < n; j++)
		{
			if (1 + rand() % 100 < 25)
			{
				M[i][j] = 1;
			}
			else
			{
				M[i][j] = 0;
			}
			M[j][i] = M[i][j];
		}
		z++;
	}
}

void Print(int** M, size_t n)
{
	for (size_t i = 0; i < n; ++i) 
	{
		for (size_t j = 0; j < n; ++j) 
		{
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void search(vector<vector<int>>::iterator i, vector<vector<int>> most_set, int max, int** A, int sled, int max_shag, int *vis, int *set, int** num_reb, int**max_mas, int n, int x, int &max_size)
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = i; j < n; j++) 
		{
			if (A[i][j] == 1) {
				max++;
			}
		}
	}

	num_reb = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		num_reb[i] = new int[max];
	}
	max_mas = matrix_inc(A, num_reb, n, &max);

	cout << "\nМатрица смежности рёбер" << endl;
	Print(max_mas, max);

	vis = new int[max];
	set = new int[max];
	for (int i = 0; i < max; i++) 
	{
		for (int j = 0; j < max; j++) 
		{
			vis[j] = 0;
		}
		vis[i] = 1;
		set[sled] = i;
		sled = most(i, max_mas, vis, set, &max, &max_shag, i, sled, most_set, &x);
		sled = 0;
	}

	ofstream fout;
	fout.open("data.txt");

	cout << "\nНаибольшее паросочетание графа:" << endl;

	i = most_set.begin();

	for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) 
	{
		cout << num_reb[1][(*j)] + 1 << "-" << num_reb[2][(*j)] + 1 << "; ";
		fout << num_reb[1][(*j)] + 1 << " " << num_reb[2][(*j)] + 1 << endl;
		max_size++;
	}
	
	fout.close();
	cout << "\nНомера рёбер: ";
	for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) 
	{
		cout << *j + 1 << "; ";
	}
	cout << endl;

	for (int i = 0; i < max; i++)
		delete[] max_mas[i];
	delete[] max_mas;
	max_mas = NULL;

	for (int i = 0; i < 3; i++)
		delete[] num_reb[i];
	delete[] num_reb;
	num_reb = NULL;
}

int** matrix_inc(int** mass, int** num_reb, int count, int* num) 
{
	int** mass_edge=new int*[*num];
	for (int i = 0; i < *num; i++) 
	{
		mass_edge[i] = new int[*num];
	}
	for (int i = 0; i < *num; i++) {
		for (int j = 0; j < *num; j++) {
			mass_edge[i][j] = 0;
		}
	}
	cout << "\nКоординаты рёбер\n";
	int iter = 0;
	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (mass[i][j] == 1) {
				num_reb[0][iter] = iter;
				num_reb[1][iter] = i;
				num_reb[2][iter] = j;
				iter++;

				cout << " " << iter << " " << i << " " << j << " \n";
			}

		}

	}

	for (int i = 0; i < *num; i++) 
	{
		for (int j = i + 1; j < *num; j++) 
		{
			if ((num_reb[1][i] == num_reb[1][j]) || (num_reb[1][i] == num_reb[2][j]) || (num_reb[2][i] == num_reb[1][j]) || (num_reb[2][i] == num_reb[2][j])) 
			{
				mass_edge[i][j] = 1;
				mass_edge[j][i] = 1;
			}
		}
	}
	return mass_edge;
}

int most(int i, int** mass, int* vis, int* set, int* num, int* most_step, int start, int sled, vector<vector<int>>& most_set, int* vec_iter) 
{
	for (i = 0; i < *num; i++) {
		if (mass[start][i] == 0 && vis[i] == 0) 
		{ 
			int schet = 0;
			for (int j = 0; j < sled + 1; j++) 
			{
				if (mass[set[j]][i] == 0) 
				{  
					schet++;  
				}
			}
			if (schet == sled + 1)
			{  
				sled++;
				set[sled] = i;
				vis[i] = 1;
			}
		}
	}
	if (sled > *most_step) 
	{
		most_set.clear();
		*vec_iter = 0;
		most_set.push_back(vector<int>());
		for (int i = 0; i < sled + 1; i++) 
		{
			most_set[*vec_iter].push_back(set[i]);
		}
		*most_step = sled;
	}
	vis[set[sled]] = 0;
	sled--;
	return sled;
}