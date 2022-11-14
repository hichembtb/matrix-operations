#include<stdio.h>
#include<stdlib.h>
#include "shared_var.c"
#include "operations.c"
//
void main()
{

    // demander
    question();
    printf("reponse : ");
    scanf("%d", &reponse);
    
    switch (reponse)
    {
    case 1:
        operation_matrice();
        system("pause");
        break;
    case 2:
        operation_matr_vect();
        system("pause");
        break;
    case 3:
        operation_matr_matr();
        system("pause");
        break;

    default:
        printf("selectioner un nombre correct\n");
        spacer();
        spacer();
        main();
        break;
    }
}