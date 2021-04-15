#include <stdio.h>
#include <stdlib.h>

//typedef and struct used to create a 'new geographic position type'.
typedef struct{
    double latitude;
    double longitude;
} geoPos;

//Initializing function that prints geographic positions and one that sorts them.
void printPositions(geoPos *geoPoses, int size);
void selectionSort(geoPos *geoPoses, int size);

int main(void){
    //Creating dynamically allocated array for geographic posisitions of type geoPos and other necessary variables.
    geoPos *geoPoses = malloc(sizeof(geoPos));
    char input;
    int size = 1;

    do{
        //Declaring and taking input for longitude and latitude.
        double lat;
        double lon;
        printf("Enter latitude: ");
        scanf("%lf", &lat);
        printf("Enter longitude: ");
        scanf("%lf", &lon);
        
        //lon and lat used to create a geoPos out of and then added to geoPoses array.
        geoPos pos = {.latitude = lat, .longitude = lon};
        geoPoses[size - 1] = pos;

        //clears input buffer.
        fflush(stdin);

        //Takes input for whether user wants to continue.
        printf("Enter another geographic position (y/n): ");
        scanf("%c", &input);
        
        //If they want to continue, reallocates memory to have space for one more geoPos.
        if(input == 'n'){break;}
        size += 1;
        geoPoses = realloc(geoPoses, sizeof(geoPoses) + sizeof(geoPos));
    }while(input == 'y');

    //Prints unsorted geographical positions.
    printPositions(geoPoses, size);
    //Sorts positions starting from nothernmost.
    selectionSort(geoPoses, size);
    //Prints sorted geographical positions.
    printPositions(geoPoses, size);
    free(geoPoses);
}

//Prints geographical positions.
void printPositions(geoPos *geoPoses, int size){
    printf("\nPositions:\n");
        for(int i = 0; i < size; i++){
            printf("%lf, %lf\n", geoPoses[i].latitude, geoPoses[i].longitude);
        }
}

/*
Sorts geographical positions from nothernmost to southernmost using selection sort. At every index,
takes current element and replaces it with the greatest latitude element that comes after the
current element. Final array is sorted.
*/
void selectionSort(geoPos *geoPoses, int size){
    for(int i = 0; i < size; i++){

            int maxIndex = i;
            for(int j = (i + 1); j < size; j++){
                if(geoPoses[j].latitude > geoPoses[maxIndex].latitude){
                    maxIndex = j;
                }
            }

            geoPos placeHolder = geoPoses[maxIndex];
            geoPoses[maxIndex] = geoPoses[i];
            geoPoses[i] = placeHolder;
        }
}