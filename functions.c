#include <stdio.h>
#include "shared_var.c"
#define max 10
// funct separer avec etoile
void spacer()
{
    for (i = 0; i < 10; i++)
    {
        printf("*");
    }
    printf("\n");
}
// question de demarage
void question()
{
    printf("faire quoi ? :\n");
    printf(" 1 : TRANSPOSER , TRACE d\'une matrice.\n");
    printf(" 2 : PRODUIT d\'une matrice avec un vecteur + AUGMENTATION.\n");
    printf(" 3 : PRODUIT , ADDITION de deux matrice .\n");
}

void nmbrLC(char nomMat[max])
{
    // nomMatpour donner le nom de la matrice en appelant la fonction
    printf("Entrez le nombre de lignes pour la matrice %s : ", nomMat);
    scanf("%d", &mLignes);

    printf("Entrez le nombre de colonnes pour la matrice %s : ", nomMat);
    scanf("%d", &mColonne);
}
void nmbrLVect(char nomMat[max])
{
    printf("\nentrer le nombre de ligne du vecteur V : ");
    scanf("%d", &vLignes);
}
/*LES FUNCTIONS MATRICE*/
// funct remplire une matrice
void remplireMatr(int mLignes, int mColonne, int matrice[max][max])
{
    for (i = 0; i < mLignes; i++)
    {
        for (j = 0; j < mColonne; j++)
        {

            printf("element : [%d][%d] : ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
}
// funct afficher une matrice
void afficherMatr(int mLignes, int mColonne, int matrice[max][max])
{
    for (i = 0; i < mLignes; i++)
    {
        for (j = 0; j < mColonne; j++)
        {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}
// funct creer et afficher la transposer d'une matrice
void creerAfficherTransp(int mLignes, int mColonne, int matrice[max][max])
{
    int transpose[10][10];
    for (i = 0; i < mLignes; i++)
    {
        for (j = 0; j < mColonne; j++)
        {
            transpose[j][i] = matrice[i][j];
        }
    }
    // affichage
    for (i = 0; i < mColonne; i++)
    {
        for (j = 0; j < mLignes; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
}
// funct calculer la trace d'une matrice
void calcTrace(int mLignes, int mColonne, int matrice[max][max])
{
    int trace = 0;
    if (mLignes == mColonne)
    {

        printf("\nle diagonal : \n");
        for (i = 0; i < mLignes; i++)
        {
            // calculant la trace
            trace = trace + matrice[i][i];

            printf("%d\t \n", matrice[i][i]);
        }
        // afficher la trace
        printf("\nla trace = %d \n", trace);
    }
    else
    {
        printf(" REMARQUE : la matrice n'est pas carre pour calculer la trace \n");
    }
}
/*FIN LES FUNCTIONS MATRICE*/

/*LES FUNCTIONS VECTEUR*/
// funct remplire le vecteur
void remplVect(int vLignes, int vecteur[max])
{
    for (i = 0; i < vLignes; i++)
    {
        printf("Vecteur[%d] : ", i);
        scanf("%d", &vecteur[i]);
    }
}
// funct afficher le vecteur
void afficherVect(int vLignes, int vecteur[max])
{
    for (i = 0; i < vLignes; i++)
    {
        printf("\t%d\n", vecteur[i]);
    }
}
/*FIN LES FUNCTIONS VECTEUR*/

/*LES FUNCTIONS MATRICE VECTEUR*/
// Funct produit de matrice et un vecteur
void prodMatrVect(int mLignes, int mColonne, int vLignes, int matrice[max][max], int vecteur[max])
{
    if (mColonne == vLignes)
    {

        int resVecteur[10];
        //   initializer la matrice a 0
        for (i = 0; i < mLignes; ++i)
        {
            resVecteur[i] = 0;
        }
        // Multiplucation de matrice par un vecteur
        for (i = 0; i < mLignes; i++)
            for (j = 0; j < mColonne; j++)
            {
                resVecteur[i] += matrice[i][j] * vecteur[j];
            }

        for (i = 0; i < mLignes; ++i)

        {
            printf("\t%d \n", resVecteur[i]);
        }
    }
    else
    {
        printf("multiplication impossible car \n nombre de colonnes de la matrice n'egale pas \n nombre de ligne du vecteur\n");
    }
}

/*FIN LES FUNCTIONS MATRICE VECTEUR*/

/*LES FUNCTIONS MATRICE MATRICE*/
// Funct Produit 2 matrices
void prodMatr(int mLignes, int mColonne, int mBLignes, int mBColonne, int matrice[max][max], int matriceB[max][max])
{
    int k;
    if (mColonne == mBLignes)
    {

        int resMatr[10][10];
        //   initializer la matrice a 0
        for (i = 0; i < mLignes; i++)
            for (j = 0; j <= mColonne; j++)
            {
                resMatr[i][j] = 0;
            }
        // Multiplucation de matrice par un vecteur
        for (i = 0; i < mLignes; i++)
            for (j = 0; j < mBColonne; j++)
                for (k = 0; k < mColonne; k++)
                {
                    resMatr[i][j] += matrice[i][k] * matriceB[k][j];
                }
        for (i = 0; i < mLignes; ++i)
            for (j = 0; j < mBColonne; ++j)
            {
                printf("\t%d ", resMatr[i][j]);
                if (j == mBColonne - 1)
                    printf("\n\n");
            }
    }
    else
    {
        printf("multiplication impossible car \n nombre de colonnes de la matrice n'egale pas \n nombre de ligne du deuxieme matrice\n");
    }
}
// Addition de deux matrice
void matrAdd(int mLignes, int mColonne, int mBLignes, int mBColonne, int matrice[max][max], int matriceB[max][max])
{

    int addMatr[max][max];
    if ((mLignes == mBLignes) && (mColonne == mBColonne))
    {
        for (i = 0; i < mLignes; i++)
        {
            for (j = 0; j < mColonne; j++)
            {
                addMatr[i][j] = matrice[i][j] + matriceB[i][j];
                printf("%d ", addMatr[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Addition impossible ");
    }
}
/*FIN LES FUNCTIONS MATRICE MATRICE*/

// AUGMENTATION FUNCTION
// Augmenter une matrice par un vecteur
void augMatrVect(int mLignes, int mColonne, int vLignes, int matrice[max][max], int vecteur[max])
{

    if (mLignes == vLignes)
    {
        int matrAug[max][max];
        int vectAug[max][max];
        //   initializer la matriceAug a 0
        for (i = 0; i < mLignes; ++i)
            for (j = 0; j <= mColonne; j++)
            {
                matrAug[i][j] = 0;
            }

        // ajouter les valeur de la matrice donner a la matrice Aug
        for (i = 0; i < mLignes; i++)
        {
            for (j = 0; j < mColonne; j++)
            {

                matrAug[i][j] = matrice[i][j];
            }
        }
        //   initializer la vectAug a 0
        for (i = 0; i < mLignes; ++i)
            for (j = 0; j <= mColonne; j++)
            {
                vectAug[i][j] = 0;
            }
        // ajouter le vecteur a la matrice 'vectAug'
        for (i = 0; i < mLignes; i++)
        {
            for (j = mColonne; j <= mColonne; j++)
            {

                vectAug[i][j] = vecteur[i];
            }
        }

        matrAdd(mLignes, mColonne + 1, mLignes, mColonne + 1, matrAug, vectAug);
        // Afficher la matrice vectAug (optionelle)
        // printf("VectAug : \n");
        // for (i = 0; i < mLignes; i++)
        // {
        //     for (j = 0; j <= mColonne; j++)
        //     {
        //         printf("%d\n", vectAug[i][j]);
        //     }
        // }

        // Afficher la matrice Aug (optionelle)
        // printf("matrAug : \n");
        // for (i = 0; i < mLignes; i++)
        // {
        //     for (j = 0; j <= mColonne; j++)
        //     {
        //         printf("\n%d\n", matrAug[i][j]);
        //     }
        // }
    }
    else
    {
        printf("augmentaion impossible car les lignes ne sont pas egaux\n");
    }
}

void augAndProdVect(){
    if ((mColonne == vLignes) || (mLignes == vLignes))
    {
        printf("\nremplire le Vecteur V : \n");
        remplVect(vLignes, vecteur);
        printf("\nle vecteur V : \n");
        afficherVect(vLignes, vecteur);
        if (mColonne == vLignes)
        {
            printf("\nle produit de la matrice A et le vecteur V : \n");
            prodMatrVect(mLignes, mColonne, vLignes, matrice, vecteur);
            spacer();
        }
        else
        {
            printf("multiplication impossible car \n nombre de colonnes de la matrice n'egale pas \n nombre de ligne du vecteur\n");
        }
        if (mLignes == vLignes)
        {
            printf("matrice A augmenter par le vecteur V : \n");
            augMatrVect(mLignes, mColonne, vLignes, matrice, vecteur);

            spacer();
        }
        else
        {
            printf("augmentaion impossible car les lignes ne sont pas egaux\n");
        }
    }
    else
    {
        printf("\n produit et augmentation impossible\n");
    }
}