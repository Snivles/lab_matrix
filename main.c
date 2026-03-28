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

void FreeMx(int ***Mx, size_t rows) {
    if (Mx == NULL || *Mx == NULL) return;

    for (size_t i = 0; i < rows; i++) {
        free((*Mx)[i]);
    }
    free(*Mx);
    *Mx = NULL;
}



int **Sum_Mx(int **Mx_A, size_t row_A, size_t column_A,int **Mx_B, size_t row_B, size_t column_B)
{
  if(row_A != row_B || column_A != column_B || Mx_A == NULL || Mx_B == NULL){return NULL;}
  int **Result = CreateMatrix(row_A, column_A);
  if (Result == NULL) {return NULL;}
  for (size_t i=0; i < row_A;i++){
      if (Mx_A[i] != NULL && Mx_B[i] != NULL){
        for (size_t j = 0; j < column_A; j++){
                int sum = Mx_A[i][j] + Mx_B[i][j];
                int a_mx = Mx_A[i][j],b_mx = Mx_B[i][j];
                if ((b_mx > 0 && a_mx > INT_MAX - b_mx) || (b_mx < 0 && a_mx < INT_MIN - b_mx)){
                  FreeMx(&Result, row_A);
                  return NULL;}
                sum = Mx_A[i][j] + Mx_B[i][j];
                Result[i][j] = sum;}}
      else if (Mx_A[i] == NULL && Mx_B[i] != NULL) {
            for (size_t j = 0; j < column_A; j++){
                Result[i][j] = Mx_B[i][j];
            }
        }
      else if (Mx_A[i] != NULL && Mx_B[i] == NULL) {
            for (size_t j = 0; j < column_A; j++){
                Result[i][j] = Mx_A[i][j];
            }
        }
}
  return Result;}

int main()
{
    printf("Hello World!\n");
    return 0;
}
