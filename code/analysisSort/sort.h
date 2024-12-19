#ifndef SORT_H_
#define SORT_H_


double bubbleSort(float *arr, int lent);

double selectionSort(float *arr, int n);

double insertionSort(float *arr, int lent);

double shellSort(float *arr, int lent,int h);

void mergeSort(float *arr, int start, int end);

void merge (float *arr, int start,int middle, int end);

void quickSort (float *arr, int start, int end);

int partition ( float *arr, int start, int end);

void quickSortRandom (float *arr, int start, int end);

int partitionRandom ( float *arr, int start, int end);


#endif /* SORT_H_ */ 