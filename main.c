#include <stdio.h>
#include "Arrays.h"
#include "Strings.h"

#define LINE 256
#define WORD 30

# define len 50
int main() {
    int arr[len];
    for (int i = 0; i < len ; ++i) {
        scanf("%d" , arr+i);
    }
    insertion_sort(arr , len);
    for (int k = 0; k < len-1  ; k++) {
        printf("%d," , *(arr+k));
    }
    printf("%d" , *(arr+len-1));

    return 0;
}
