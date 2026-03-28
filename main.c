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
  //int row1 = 2, column1 = 4;
  //int row2 = 2, column2 = 4; - работает штатно все функции выполнены


  //int row1 = 2, column1 = 4;
  //int row2 = 0, column2 = 4; - работатет штатно сообщаем пользователю что ошибка с размерами


  //int row1 = 5, column1 = 4;
  //int row2 = 2, column2 = 4; - работает штатно тк размеры матрицы различны(не кв матрица) => суммы быть не может а транспозиция выполнена

  //int row1 = 10, column1 = 22;
  //int row2 = 10, column2 = 22; // - проверка работы матрицы с большими размерами

  //int row1 = 1, column1 = 5;
  //int row2 = 5, column2 = 1; // - даны 2 матриц вектора работает штатно: суммы нет тк размеры не соответ , транспозиция превращает вектор-столбец
// в вектор-строку и наоборот

  int row1 = 3, column1 = 3;
  int row2 = 3, column2 = 3; //- работает штатно все функции выполнены для заданных вектор-строк (сумма тоже является вектор-строкой),
//транспозиция дает вектор-столбец

  if (row1<=0 || row2 <= 0 || column1 <= 0 || column2 <= 0){printf("Error with size"); return 0;}
  int start = 5;
  int end = 100;
  int **A = CreateMatrix(row1, column1);
  int **B = CreateMatrix(row2, column2);
  if (!A || !B){printf("Error with mx");FreeMx(&A,row1);FreeMx(&B,row2); return 0;}

  srand(time(0));
  generateRandomMas(A,row1,column1,start,end);
  //generateRandomMas(NULL,row1,column1,start,end);

  generateRandomMas(B,row2,column2,start,end);
  //generateRandomMas(NULL,row2,column2,start,end);


  free(A[1]);
  A[1] = NULL;// - функция транспозиции отрабатывает штатно, СУММУ РАССМОТРЕТЬ !!!(P.s. Сумма теперть тоже работает)

  free(B[2]);
  B[2] = NULL;//- функция транспозиции отрабатывает штатно, СУММУ РАССМОТРЕТЬ !!!(P.s. Сумма теперть тоже работает)

  int **C = Sum_Mx(A, row1, column1, B, row2, column2);
  //int **C = Sum_Mx(NULL, row1, column1, B, row2, column2);
  //int **C = Sum_Mx(NULL, row1, column1, NULL, row2, column2);
  PrintMx(A,row1,column1);
  printf("------------------------\n");
  PrintMx(B,row2,column2);
  if(C){
      printf("------------------------\n");
      printf("Sum\n");
      PrintMx(C,row2,column2);
      FreeMx(&C,row1);}
  else{
      printf("------------------------\n");
      printf("Error with sum\n");}
  FreeMx(&A,row1);
  FreeMx(&B,row2);
  return 0;
}
