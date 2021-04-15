#include <stdio.h>
#include <stdlib.h>

int main(void){
    //Takes user input for array size and stores it.
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    //Dynamically allocates space for an array given the size.
    double *array;
    array = malloc(size * sizeof(double));
    
    //Takes user input for array element values one by one.
    for(int i = 0; i < size; i++){
        printf("Enter element %d: ", i);
        scanf("%lf", &array[i]);
    }
    
    //Prints unsorted array with 2 decimal digits of precision.
    printf("\nUnsorted array:\n");    
    for(int i = 0; i < size; i++){
        printf("%.2lf ", array[i]);
    }
    printf("\n");
    
    /*
    Uses insertion sort to sort values from highest to lowest.
    Starting from the second element, compares to element preceding current element.
    While the preceding element is lesser, the current element is swapped with every preceding element until it
    is lesser than its preceding element or if it is now the first element.
    */
    int i = 1;
    while(i < size){
        int j = i;
        while(j > 0 && array[j - 1] < array[j]){
            double placeHolder = array[j];
            array[j] = array[j - 1];
            array[j - 1] = placeHolder;
            j -= 1;
        }
        i += 1;
    }

    //Prints sorted array with 2 decimal digits of precision.
    printf("Sorted array:\n");
    for(int i = 0; i < size; i++){
        printf("%.2lf ", array[i]);
    }

    //Dynamically allocated memory is freed.
    free(array);
}
    