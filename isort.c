#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define size 50

int shift_element(int* arr, int i){

for(int k = i; k >= 0; k--){
*(arr + k + 1) = *(arr + k);
}

return 0;
}

int insertion_sort(int* arr, int len){
    int key, j;
    for (int i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
    arr[j + 1] = key;
}
    return 0;
}

int main(){
    int arr[size] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int temp = 0;
    for(int i = 0; i < size; i++){
        scanf("%d",&temp);
        *(arr + i) = temp;
    }

    insertion_sort(arr,size);
    printf("%d",*arr);

    for(int i = 1; i < size; i++){
        printf(",%d",*(arr + i));
    }
    printf("\n");
return 0;
}