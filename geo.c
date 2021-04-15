#include <stdio.h>
#include <math.h>

double squareArea(double l){return l*l;}
double sphereVolume(double r){return (4.0/3.0)*(M_PI)*(pow(r, 3));}
double saCube(double l){return l*l*6;}

int main(void){
    
    int choice;

    do{
        printf("1. Compute the area of a square\n2. Compute the volume of a sphere\n3. Compute the surface area of a cube\n4. Quit\n");
        printf("Enter an option: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
            {
                double length;

                printf("Enter side length (cm):\n");
                scanf("%lf", &length);

                printf("The area of the square is %.2lf (cm).\n", squareArea(length));
                break;
            }

            case 2:
            {
                double radius;

                printf("Enter radius (cm):\n");
                scanf("%lf", &radius);
                
                printf("The volume of the sphere is %.2lf (cm).\n", sphereVolume(radius));
                break;
            }

            case 3:
            {
                double length;

                printf("Enter side length (cm):\n");
                scanf("%lf", &length);

                printf("The surface area of the cube is %.2lf(cm).\n", saCube(length));
                break;
            }
        }

    } while(choice != 4);
    printf("Goodbye!\n");
}