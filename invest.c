#include <stdio.h>
#include <string.h>

int main(void){

    double startBalance;
    int years;
    double interestRate;
    double contribution;
    double interest;
    double endBalance;

    do{
        printf("Enter initial investment amount: ");
        scanf("%lf", &startBalance);
        if(startBalance < 0){
            printf("Initial investment cannot be negative.\n");
        }
    } while(startBalance < 0);

    do{
        printf("Enter total years: ");
        scanf("%d", &years);
        if(years <= 0){
            printf("Years must be greater than zero.\n");
        }
    }while(years <= 0);

    do{
        printf("Enter a return rate: ");
        scanf("%lf", &interestRate);
        if(interestRate < 0){
            printf("Rate cannot be negative.\n");
        }
    } while(interestRate < 0);

    do{
        printf("Enter additional contribution per year: ");
        scanf("%lf", &contribution);
        if(contribution < 0){
            printf("Contribution cannot be negative.\n");
        }
    } while(contribution < 0);

    for(int j = 0; j < (2+years); j++){
        for(int i = 0; i < 70; i++){
            if(j == 0){
                if(i == 0){printf("Year"); i += strlen("Year") - 1;}
                else if(i == 10){printf("Start Balance"); i += strlen("Start Balance") - 1;}
                else if(i == 30){printf("Interest"); i += strlen("Interest") - 1;}
                else if(i == 50){printf("End Balance"); i += strlen("End Balance") - 1;}
                else{printf(" ");}
            }
            else if(j == 1){
                printf("*");
            }
            else if(j > 1){
                char doubleAsString[20];
                if(i == 0){
                    printf("%d", (j-1));
                    sprintf(doubleAsString, "%d", (j-1));
                    i += strlen(doubleAsString) - 1;
                }
                else if(i == 10){
                    printf("%.2lf", startBalance);
                    sprintf(doubleAsString, "%.2lf", startBalance);
                    i += strlen(doubleAsString) - 1;
                }
                else if(i == 30){
                    interest = startBalance * (interestRate/100.0);
                    printf("%.2lf", interest);
                    sprintf(doubleAsString, "%.2lf", interest);
                    i += strlen(doubleAsString) - 1;
                }
                else if(i == 50){
                    endBalance = startBalance+interest;
                    printf("%.2lf", endBalance);
                    sprintf(doubleAsString, "%.2lf", endBalance);
                    i += strlen(doubleAsString) - 1;
                }
                else{printf(" ");}
            }
        }
        printf(".\n");
        if(j > 1){
            startBalance += interest + contribution;
        }
    }
    
}

int spacesLeft(int bound, int spacesTaken){
    return bound-spacesTaken;
}