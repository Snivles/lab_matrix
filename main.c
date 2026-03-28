#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int **CreateMatrix(size_t row, size_t column){
    int **dmas = (int **)calloc(row, sizeof(int *));
    if (dmas == NULL){
        return NULL;
    }


    for (size_t i = 0; i < row; i++) {
        dmas[i] = (int *)calloc(column, sizeof(int));
        if (dmas[i] == NULL){
            for (size_t j = 0; j < i; j++) free(dmas[j]);
            free(dmas);
            return NULL;
        }
    }
    return dmas;
  return NULL;}


void PrintMx(int **Mx, size_t row, size_t column)
{
    if (Mx == NULL) return;
    for (size_t ix = 0; ix < row; ix++) {
        if (Mx[ix]) {
            for (size_t jx = 0; jx < column; jx++) {
                printf("%4d ", Mx[ix][jx]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}

void generateRandomMas(int **Mx, size_t row , size_t column, int start , int end){
  if (Mx == NULL) return;
  if( start > end){
    int flag = end;
    end = start;
    start = flag;
}
  if(start <= end && (start >=0 && end>=0)){
  for (size_t i = 0; i < row; i++)
    for (size_t j = 0; j < column; j++)
        if(Mx[i] != NULL){
        Mx[i][j] = rand() % (end-start+1)+start;}
  }
}



int main()
{
    printf("Hello World!\n");
    return 0;
}
