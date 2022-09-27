#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
#include <clocale>
#include <fstream>


using namespace std;


int** Create(size_t n);

void save_in_file(string str, int** M, size_t n, int** max_mas, int max, int** num_reb, int max_size);

void read_from_file(string str, int** M, size_t n);

void Free(int** M1, size_t n, int* m1, int* m2);

void Input(int** M, size_t n);

void FillRandomNumbers(int** matrix, size_t n);

void Print(int** M, size_t n);

void menu();

void search(vector<vector<int>>::iterator i, vector<vector<int>> most_set, int max, int** A, int sled, int max_shag, int* vis, int* set, int** num_reb, int** max_mas, int n, int x, int &max_size);

int** matrix_inc(int** mass, int** num_reb, int count, int* num);

int most(int i, int** mass, int* vis, int* set, int* num, int* most_step, int start, int sled, vector<vector<int>>& most_set, int* vec_iter);

void null(int** M1, int* m1, int* m2);
