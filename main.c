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


int **Transposition(int **Mx, size_t row, size_t column){
    if(Mx == NULL){return NULL;}
    int **Result = CreateMatrix(column,row);
    if(Result == NULL){return NULL;}
    for (size_t i = 0; i < row; i++){
        if (Mx[i] != NULL){
            for (size_t j = 0; j < column; j++){
                Result[j][i] = Mx[i][j];
            }
        }}
    return Result;
}
int main()
{
  //int row1 = 2, column1 = 4; - работает штатно все функции выполнены


  //int row1 = 0, column1 = 4; - работатет штатно сообщаем пользователю что ошибка с размерами


  //int row1 = 5, column1 = 4;- работает штатно => транспонирования выполнена

  //int row1 = 10, column1 = 22; // - проверка работы матрицы с большими размерами

  //int row1 = 1, column1 = 5; // - даны 2 матриц вектора работает штатно: транспонирования превращает вектор-столбец
// в вектор-строку и наоборот

  int row1 = 4, column1 = 4;//- работает штатно все функции выполнены для заданных вектор-строк,транспонирования дает вектор-столбец

  if (row1<=0 || column1 <= 0 ){printf("Error with size"); return 0;}
  int start = 5;
  int end = 100;
  int **A = CreateMatrix(row1, column1);
  if (!A){printf("Error with mx");FreeMx(&A,row1); return 0;}

  srand(time(0));
  generateRandomMas(A,row1,column1,start,end);
  //generateRandomMas(NULL,row1,column1,start,end);


  free(A[0]);
  A[0] = NULL;// - функция транспонирования отрабатывает штатно



  PrintMx(A,row1,column1);
  int **C = Transposition(A,row1,column1);
  if (C){
      printf("------------------------\n");
      printf("Transposition\n");
      PrintMx(C,column1,row1);
      FreeMx(&C,column1);}
  else{
      printf("------------------------\n");
      printf("Error with Transposition\n");}
  FreeMx(&A,row1);
  return 0;
}
