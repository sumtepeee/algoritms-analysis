/*
 * sort.c
 *
 *  Created on: 07 april  2024
 *      Author: Sumeyye
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "sort.h"   

#define MAX_SATIR_UZUNLUK 1000 // Bir satırın maksimum uzunluğunu belirleyin

int main(int argc, char const *argv[]) {
  clock_t start_t , end_t;
 FILE *dosya;
    char satir[MAX_SATIR_UZUNLUK];
    float sayi_dizisi[MAX_SATIR_UZUNLUK]; // 1000 sayıyı tutabilecek bir dizi oluşturuyoruz
    int eleman_sayisi = 0;

    dosya = fopen("1Kints.txt", "r");
    if (dosya == NULL) {
        perror("Dosya acilirken hata olustu");
        return 1;
    }

    // Dosyadan satır okuyup sayıları diziye ekleyelim
    while (fgets(satir, MAX_SATIR_UZUNLUK, dosya) != NULL) {
        // Satırı integer'a çevirip diziye ekleyelim
        sayi_dizisi[eleman_sayisi] = atof(satir);
        eleman_sayisi++;

        // Dizi kapasitesi aşıldığında hata verelim
        if (eleman_sayisi > MAX_SATIR_UZUNLUK) {
            fprintf(stderr, "Dizi kapasitesi asildi!\n");
            break;
        }
    }

    fclose(dosya);

    float array_bubble[MAX_SATIR_UZUNLUK],array_selection[MAX_SATIR_UZUNLUK],
    array_insertion[MAX_SATIR_UZUNLUK],array_shell1[MAX_SATIR_UZUNLUK],array_shell2[MAX_SATIR_UZUNLUK],
    array_merge[MAX_SATIR_UZUNLUK],array_quick[MAX_SATIR_UZUNLUK],array_quickrandom[MAX_SATIR_UZUNLUK];

    for (int i = 0; i < MAX_SATIR_UZUNLUK; i++)
    {
      array_bubble[i] = sayi_dizisi[i];
      array_selection[i] = sayi_dizisi[i];
      array_insertion[i] = sayi_dizisi[i];
      array_shell1[i] = sayi_dizisi[i];
      array_shell2[i] = sayi_dizisi[i];
      array_merge[i] = sayi_dizisi[i];
      array_quick[i] = sayi_dizisi[i];
      array_quickrandom[i] = sayi_dizisi[i];
    }
    

    printf("Algorithme\t\tTepms d'execution(s)\n");
    printf("Bubble Sort\t\t%lf\n",bubbleSort(array_bubble,MAX_SATIR_UZUNLUK));
    printf("Selection Sort\t\t%lf\n",selectionSort(array_selection,MAX_SATIR_UZUNLUK));
    printf("Insertion Sort\t\t%lf\n",insertionSort(array_insertion,MAX_SATIR_UZUNLUK));
    printf("Shell Sort with h1\t%lf\n",shellSort(array_shell1,MAX_SATIR_UZUNLUK,1));
    printf("Shell Sort with h2\t%lf\n",shellSort(array_shell2,MAX_SATIR_UZUNLUK,2));

    start_t = clock ();
    mergeSort(array_merge,0,MAX_SATIR_UZUNLUK-1);
    end_t = clock ();
    double total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    printf("Merge Sort\t\t%lf\n",total_t);
    
    start_t = clock ();
    quickSort(array_quick,0,MAX_SATIR_UZUNLUK-1);
    end_t = clock ();
    total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    printf("Quick Sort standard \t%lf\n",total_t);

    start_t = clock ();
    quickSortRandom(array_quickrandom,0,MAX_SATIR_UZUNLUK-1);
    end_t = clock ();
    total_t = ( double )( end_t - start_t ) / CLOCKS_PER_SEC ;
    printf("Quick Sort aleatoir\t%lf\n",total_t);

    return 0;
}

