#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


int main()
{
    int SİZE_ARRAY = 1000;
    srand(time(0));
    float a = 10;
    clock_t start_t, end_t;
    double avarageI, avarageS, avarageM = 0;
    float b ;

// 1000 boyutlu arrayler icin 
    for (int i = 0; i < 5; i++)
    {
        float arr_case1i[SİZE_ARRAY];
        float arr_case1s[SİZE_ARRAY];
        float arr_case1m[SİZE_ARRAY];
        for (int i = 0; i < SİZE_ARRAY; i++)
        {
             b = (float)rand()/(float)(RAND_MAX) * a;
                arr_case1i[i] = b;
                arr_case1s[i] = b;
                arr_case1m[i] = b;
        }
        avarageI += insertionSort(arr_case1i,SİZE_ARRAY);
        avarageS += selectionSort(arr_case1i,SİZE_ARRAY);

        start_t = clock ();
        mergeSort(arr_case1m,0,SİZE_ARRAY-1);
        end_t = clock();
        avarageM += ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;

    }
    printf("For 1K\n");
    printf("Avarage for Insertion Sort (s) : \t%lf\n",avarageI/5);
    printf("Avarage for Selection Sort (s) : \t%lf\n",avarageS/5);
    printf("Avarage for Merge Sort (s)     : \t%lf\n",avarageM/5);
    
// 10000 boyutlu arrayler icin deneme
    avarageI = 0;
    avarageS = 0;
    avarageM = 0;
    SİZE_ARRAY = 10000;

    for (int i = 0; i < 5; i++)
        {
            float arr_case2i[SİZE_ARRAY];
            float arr_case2s[SİZE_ARRAY];
            float arr_case2m[SİZE_ARRAY];
            for (int i = 0; i < SİZE_ARRAY; i++)
            {
                b = (float)rand()/(float)(RAND_MAX) * a;
                arr_case2i[i] = b;
                arr_case2s[i] = b;
                arr_case2m[i] = b;
            }
            avarageI += insertionSort(arr_case2i,SİZE_ARRAY);
            avarageS += selectionSort(arr_case2i,SİZE_ARRAY);

            start_t = clock ();
            mergeSort(arr_case2m,0,SİZE_ARRAY-1);
            end_t = clock();
            avarageM += ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
           
        }
    printf("\nFor 10K\n");
    printf("Avarage for Insertion Sort (s) : \t%lf\n",avarageI/5);
    printf("Avarage for Selection Sort (s) : \t%lf\n",avarageS/5);
    printf("Avarage for Merge Sort (s)     : \t%lf\n",avarageM/5);
    

    return 0;
}
