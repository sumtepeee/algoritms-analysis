/*
 * sort.c
 *
 *  Created on: 29 march  2024
 *      Author: Sumeyye
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "sort.h"

#define MAX_SATIR_UZUNLUK 1000

double bubbleSort(float *arr,int lent) {
    clock_t start_t , end_t;
    start_t = clock ();

    int copy;
    int swap = 1;
    while (swap == 1)
    {
        swap = 0;
        for (int i = 0; i < lent-1; i++)
        { 
            if (arr[i] > arr[i+1])
            {
                copy = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = copy;
                swap = 1;
            }   
            
        }
    }
    end_t = clock ();
    double total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    return total_t;
}

double selectionSort(float *arr,int n) {
    clock_t start_t , end_t;
    start_t = clock ();

    int min_index,i,j;
    float temp;

    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1 ; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                temp = arr[j];
                arr[j] = arr[min_index];
                arr[min_index] = temp;
            }   
        }   
    } 
    end_t = clock ();
    double total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    return total_t;
}

double insertionSort(float *arr,int lent) {
    clock_t start_t , end_t;
    start_t = clock ();

    float temp;
    int i,j;

    for (i = 1; i < lent ; i++)
    {
        temp = arr[i];
        j = i-1;
        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = temp; 
    }
    end_t = clock ();
    double total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    return total_t;
}

double shellSort(float *arr,int lent,int h) {
    if (h==1)
    {
        clock_t start_t , end_t;
        start_t = clock ();
        int j;
        float temp;
        for (int interval = lent/2; interval > 0; interval/=2) // h = 500 olarak seçiyoruz 
        {
            for (int i = interval; i < lent; i++)
            {
                temp = arr[i];
                j=i;
                while (j >= interval && arr[j-interval] > temp)
                { 
                    arr[j] = arr[j-interval];
                    j = j-interval;
                }
                arr[j] = temp; 
            }  
        }
    end_t = clock ();
    double total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    return total_t;
    }
    else if (h==2)
    {
        clock_t start_t , end_t;
        start_t = clock ();
        int j;
        float temp;
        for (int interval = lent/3; interval > 0; interval/=3) // h = 500 olarak seçiyoruz 
        {
            for (int i = interval; i < lent; i++)
            {
                temp = arr[i];
                j=i;
                while (j >= interval && arr[j-interval] > temp)
                { 
                    arr[j] = arr[j-interval];
                    j = j-interval;
                }
                arr[j] = temp; 
            }  
        }
    end_t = clock ();
    double total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    return total_t;
    } 
    return EXIT_FAILURE;
}

void mergeSort(float *arr, int start , int end){
    if (end <= start)
    {
        return;
    }
    int middle = start + (end-start)/2;
    mergeSort (arr, start , middle );
    mergeSort (arr, middle +1, end);
    merge (arr, start , middle , end);
    
}

void merge (float *arr, int start,int middle, int end){
    float temp[end+1];
    int i = start, j = middle+1;

    for (int k = start; k <= end; k++)
    {
        temp[k] = arr[k];
    }
    for (int k = start; k <= end; k++)
    {
       if (i>middle)
       {
        arr[k] = temp[j++];
       }
       else if (j>end)
       {
        arr[k] = temp[i++];
       }
       else if (temp[j]<temp[i])
       {
        arr[k] = temp[j++];
       }
       else
       {
        arr[k] = temp[i++];
       } 
    }
}

// ayırma işlemini yapıyoruz
void quickSort (float *arr, int start , int end){
    int pivot;  // partition indice i
    if ((end - start) >=0)
    {
        pivot = partition(arr,start,end);
        quickSort (arr,start ,pivot -1);
        quickSort (arr,pivot+1, end);
    }
}

int partition(float *arr, int start, int end) {
    float pivotValue = arr[end];
    int pivotIndex = start;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivotValue) {
            float temp = arr[i];
            arr[i] = arr[pivotIndex];
            arr[pivotIndex] = temp;
            pivotIndex++;
        }
    }

    float temp = arr[pivotIndex];
    arr[pivotIndex] = arr[end];
    arr[end] = temp;

    return pivotIndex;
}

void quickSortRandom (float *arr, int start , int end){
    int pivot;  // partition indice i
    if ((end - start) >=0)
    {
        pivot = partitionRandom(arr,start,end);
        quickSortRandom (arr,start ,pivot -1);
        quickSortRandom (arr,pivot+1, end);
    }
}

int partitionRandom(float *arr, int start, int end) {
    // Rastgele pivot seçimi
    srand(time(NULL));  // Seed'i güncelliyoruz
    int randomIndex = start + rand() % (end - start + 1);
    float temp = arr[randomIndex];
    arr[randomIndex] = arr[end];
    arr[end] = temp;

    float pivotValue = arr[end];
    int pivotIndex = start;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivotValue) {
            temp = arr[i];
            arr[i] = arr[pivotIndex];
            arr[pivotIndex] = temp;
            pivotIndex++;
        }
    }

    temp = arr[pivotIndex];
    arr[pivotIndex] = arr[end];
    arr[end] = temp;

    return pivotIndex;
}
