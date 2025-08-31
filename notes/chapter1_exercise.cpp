
#include <stdio.h>

// A function to remove all odd numbers from an ordered array. The array
//should remain ordered. Would it be easier to write this function if the array
//were unordered?
int removeOdd(int *arr, int size) {
    int *write = arr;
    int *read = arr;
    int *end = arr + size;
    int count = 0;
    while(read < end) {
        if (*read % 2 == 0){
            *write = *read;
            write++;
            count++;
        }
        read++;
    }
    return count;
}
//implement strlen
int strlen(char *str){
    
    char *p = str;
    while(*p){
        p++;
    }
    return p - str;
}

int main() {
    // Demonstrate removeOdd
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeOdd(arr, size);
    printf("Array after removing odd numbers: ");
    for (int i = 0; i < newSize; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Demonstrate strlen
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    char *newLine = str;
    while(*newLine){
        if(*newLine == '\n'){
            *newLine = '\0';
            break;
        }
        newLine++;
    }
    printf("Length: %d\n", strlen(str));
}
