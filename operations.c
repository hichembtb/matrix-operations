#include <stdio.h>
#include "shared_var.c"
#include "functions.c"

// operation sur matrice ( remplire afficher , transposer , trace)
void operation_matrice()
{

    printf("Entrez le nombre de lignes pour la matrice A : ");
    scanf("%d", &mLignes);

    printf("Entrez le nombre de colonnes pour la matrice A : ");
    scanf("%d", &mColonne);

    printf("\nremplire la matrice A : \n");
    // appel de la funct remplire la matrice
    remplireMatr(mLignes, mColonne, matrice);

    // afficher la matrice
    printf("\nLa matrice A : \n");
    // appel de la funct afficher  la matrice
    afficherMatr(mLignes, mColonne, matrice);

    // creation et affichage de la transposer pour la matrice
    printf("\nLa transposition de la matrice A est : \n");
    creerAfficherTransp(mLignes, mColonne, matrice);

    // calculant la trace
    calcTrace(mLignes, mColonne, matrice);

    spacer();
}
// operation sur matrice et vecteur
void operation_matr_vect()
{

    nmbrLC("A");
    printf("\nremplire la matrice A : \n");
    // appel de la funct remplire la matrice
    remplireMatr(mLignes, mColonne, matrice);

    nmbrLVect("V");

    augAndProdVect();
}
// operation matrice sur matrice
void operation_matr_matr()
{

    printf("Entrez le nombre de lignes pour la matrice A : ");
    scanf("%d", &mLignes);

    printf("Entrez le nombre de colonnes pour la matrice A : ");
    scanf("%d", &mColonne);

    printf("\nremplire la matrice A : \n");
    // appel de la funct remplire la matrice
    remplireMatr(mLignes, mColonne, matrice);

    printf("\nEntrez le nombre de lignes pour la matrice B : ");
    scanf("%d", &mBLignes);

    printf("Entrez le nombre de colonnes pour la matrice B : ");
    scanf("%d", &mBColonne);

    printf("\nremplire la matrice B : \n");
    // appel de la funct remplire la matrice B
    remplireMatr(mBLignes, mBColonne, matriceB);

    printf("\nle produit des deux Matrice est la matrice : \n");
    prodMatr(mLignes, mColonne, mBLignes, mBColonne, matrice, matriceB);
}