#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 4

int main(){

  int i,j,k;
  int mat1[n][n], mat2[n][n], mul[n][n];

//    les elements de la premiere matrice
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            mat1[i][j] = rand() % 10;
        }
    }

//     les elements de la deuxieme matrice
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            mat2[i][j] = rand() % 10;
        }
    }

//      fonction calcule de temps mis

  double debut = clock();
  printf("Multiplication du matrice = \n");
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      mul[i][j]=0;
      for(k = 0; k < n; k++)
      {
        mul[i][j] += mat1[i][k] * mat2[k][j];
      }}
  }
  double fin = clock();

  //Afficher le resultat
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      printf("%d\t",mul[i][j]);
    }
    printf("\n");
  }

  printf("le temps d'execution est de %f\n",fin-debut);
  return 0;
}
