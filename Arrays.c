#include "Arrays.h"
#include <stdio.h>

void swap(int* i , int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
    void insertion_sort(int* arr , int len){
        for (int i =0 ; i < len ; ++i) {
            int value = *(arr + i);
            int j = i;
            while (j > 0 && *(arr+j-1) >= value){
                 j--;
             }
            shift_element(arr+j , i-j);
            *(arr+j) = value;
        }
    }

void shift_element(int *arr, int i) {
    for (int k = 1; k < i; k++) {
        swap(arr, arr + k);
    }
    *(arr + i) = *arr;
}




