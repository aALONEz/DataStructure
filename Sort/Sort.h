#pragma once
#include <stdio.h>

typedef int SortType;

void QuickSort(SortType* arr, int left, int right);
void SelectSort(SortType* arr, int size);
void HeapSort(SortType* arr, int size);
void ShellSort(SortType* arr, int size);
void BubbleSort(SortType* arr, int size);
void InsertSort(SortType* arr, int size);
void PrintArr(SortType* arr, int size);
