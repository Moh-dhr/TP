
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define n 8

int main(int argc, char** argv){

        int taille,i,j,k;

        MPI_Init(NULL, NULL);
        static double totaltime,t1,t2;

        int world_size;
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        int world_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

                taille = n/world_size;



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
    }// la diffusion de la matrice 1

         for(i = 0; i < n; i++)
        {
            MPI_Bcast(&mat2[i] , n*n ,MPI_INT , 0 , MPI_CO>
        }

      // le partages de lignes de matrice 1 entre les diff>
       for(i = 0; i < world_size; i++)
        {
                for(j = 0; j < n; j++)
        {
            MPI_Send(&mat1[j] , n*taille ,MPI_INT , 0 , 0 >
            taille++;
        }
        }
//Reception
                MPI_Recv(&mat2[j] , n*taille ,MPI_INT , 0 >

        // Multiplication
        t1 = MPI_Wtime();
        for(i = 0; i < n; i++){
                for(j = 0; j < n; j++){
                        mul[i][j]=0;
                        }
                }

        for(i = 0; i < n; i++){
                for(j = 0; j < n; j++){
                        for(k = 0; k < n; k++){
                                mul[i][j] += mat1[i][k] * >
      }
    }
  }
  t2 = MPI_Wtime();
  //envoi des resultats
  MPI_Send(&mul[i][j] , n*n ,MPI_INT , 0 , 0 , MPI_COMM_WO>
// le maitre affiche
        if(world_rank == 0){

                for(i = 0; i < n; i++)
        {
    for(j = 0; j < n; j++)
    {
      printf("%d\t",mul[i][j]);
    }
    printf("\n");
        }
        totaltime = t2-t1;
        printf("le temps d'execution est de %f \n", totalt>

        }
        return 0;
        MPI_Finalize();

        }
