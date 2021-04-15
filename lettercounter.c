#include <stdio.h>
#include <string.h>

int main(void){

    //initializing global variables.
    char text[1024];
    int i = 0;
    char input;
    int length;
    int occurrences[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float percentage[26];

    //Taking input for text for analysis using getchar().
    while(1){
        input = getchar();
        if(input == '\n'){
            length = i;
            text[i] = '\0';
            printf("\n");
            printf("Letter Analysis Complete!\n");
            break;
        }
        else text[i] = input;
        i++;
    }

    //Counting occurrences for each letter lower and upper-case using ASCII, storing it in occurrences array.
    for(int i = 0; i < strlen(text); i++){
        for(int j = 65; j < 91; j++){
            if((int)text[i] == j || (int)text[i] == j + 32){occurrences[j - 65] += 1;}
        }
    }
    //Calculating percentage of occurence of letters and storing them in percentage array.
    for(int i = 0; i < sizeof(occurrences)/sizeof(int); i++){percentage[i] = ((float)occurrences[i]/(float)length)*100.0;}
    
    //Finding index of max and min in occurrences array and storing it in mostFreq and leastFreq respectively.
    int mostFreq = 0;
    int leastFreq = 0;

    for(int i = 0; i < sizeof(occurrences)/sizeof(int); i++){
        if(occurrences[mostFreq] < occurrences[i]){mostFreq = i;}
        if(occurrences[leastFreq] > occurrences[i]){leastFreq = i;}
    }

    //Prints formatted table.
    for(int i = 0; i < 28; i++){
        for(int j = 0; j < 40; j++){
            //Prints correctly spaced columns.
            if(i == 0){
                if(j == 0){printf("Letter"); j += strlen("Letter") - 1;}
                else if(j == 10){printf("Occurrences"); j += strlen("Occurrences") - 1;}
                else if(j == 25){printf("Percentage"); j += strlen("Percentage") - 1;}
                else{printf(" ");}
            }
            if(j == 0 && i == 1){
                printf("****************************************");
            }
            //Prints values for each column in the right spacing every new line.
            if(i > 1){
                char numAsString[15];
                if(j == 0){
                    printf("%c", i + 63);
                    sprintf(numAsString, "%d", i + 63);
                    j += strlen(numAsString) - 1;
                }
                else if(j == 11){
                    printf("%d", occurrences[i - 2]);
                    sprintf(numAsString, "%d", occurrences[i - 2]);
                    j += strlen(numAsString) - 1; 
                }
                else if(j == 26){
                    printf("%.2lf", percentage[i - 2]);
                    sprintf(numAsString, "%.2lf", percentage[i - 2]);
                    j += strlen(numAsString) - 1;    
                }
                else{printf(" ");}
            }
        }
        if(i > 1){printf(" \n");}
        else{printf("\n");}
    }

    printf("The most frequently occurring character is %c\n", (char)(mostFreq + 65));
    printf("The least frequently occuring character is %c\n", (char)(leastFreq + 65));
}
