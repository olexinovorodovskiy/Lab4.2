#include <stdio.h>
#include <stdlib.h>

void printmatrix (int **A, int **B, int row, int col);
void max_min (int **A, int row, int max, int min);
void transposition (int **B, int row, int col, int **T);
void multiply (int **A, int **B, int row, int col, int **Mult);
void sorting (int **A, int row, int col, int sort);
void summ (int **A, int **B, int row, int col, int sumA, int sumB);
//-----------------------------------------------------------------------
int main()
{
 int method_fill, method_task;
 int row, col;
 int max, min, sort, sumA, sumB;
 srand(time(NULL));
    printf(" A is square, B is rectangular");
    printf("\n Enter the desired number of rows and columns in the matrix A and rows in the matrix B\n\t ");
    scanf (" %d", &row);
    printf("\n Enter the desired number of columns in the matrix B\n\t ");
    scanf (" %d", &col);
    do{
    printf("\n Choose how to fill the matrix");
    printf("\n 1: manually\t2: randomly \t3: automatically\n\t");
        scanf (" %d", &method_fill);
        if (method_fill <=0 || method_fill > 3)
        {
            printf("/nThere is no such method");
            printf("/nTry again/n");
        }
    }while (method_fill <= 0 || method_fill > 3);
     int** A = NULL;
    A = (int**)malloc(row*sizeof(int));
    for(int i=0; i<row; i++)
    {
        A[i] = (int*)malloc(row*sizeof(int));
    }

    int **B=NULL;
    B=(int**) malloc(col * sizeof(int));
    int **Mult=NULL;
    Mult=(int**) malloc(col * sizeof(int));
    int **T=NULL;
    T=(int**) malloc(row * sizeof(int));

    for(int i=0; i<col; i++)
    {
        B[i] = (int**)malloc(row*sizeof(int));
        Mult[i] = (int**)malloc(row*sizeof(int));
        T[i] = (int**)malloc(row*sizeof(int));
    }
    if (method_fill==1)
    {
        for(int i=0; i<row; i++)
            {
                for(int j=0;j<row;j++)
                    {
                        printf("Enter value for A[%d][%d]: ", i, j);
                        scanf("%d", &A[i][j]);
                    }
            }
        for(int i=0; i<row; i++)
            {
                for(int j=0;j<col;j++)
                    {
                        printf("Enter value for B[%d][%d]: ", i, j);
                        scanf("%d", &A[i][j]);
                    }
            }
    }
    else if (method_fill==2)
    {
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<row;j++)
            {
                A[i][j]= rand()%20;
            }
        }
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                B[i][j]= rand()%20;
            }
        }
    }
    else
    {
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<row;j++)
            {
                A[i][j]= i+j;
            }
        }
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                B[i][j]= i+j;
            }
        }
    }

    system("cls");
    printmatrix (A, B, row, col);


    printf(" Choose follow-up?");
    printf("\n 1: Search for the MAX and MIN of matrix A");
    printf("\n 2: Transponate matrix B");
    printf("\n 3: Multiply the matrix A by matrix B");
    printf("\n 4: Sort matrix A in ascending");
    printf("\n 5: Sum of the rows of A and columns of B\n\t");


    do
    {
        scanf (" %d", &method_task);
    }while (method_task!=1 && method_task!=2 && method_task!=3 && method_task!=4 && method_task!=5);

   switch (method_task){
    case 1:
        max_min(A, row, max, min);
        break;

    case 2:
        transposition (B, row, col, T);
        break;

    case 3:
        multiply (A, B, row, col, Mult);
        break;

    case 4:
        sorting (A, row, col, sort);
        break;

    case 5:
        summ (A, B, row, col, sumA, sumB);
        break;
    }
    for (int i=0;i<row;i++)
    {
        free(A[i]);
    }
    free(A);
    for(int i=0;i<col;i++)
    {
        free(B[i]);
        free(Mult[i]);
        free(T[i]);
    }
    free(B);
    free(Mult);
    free(T);
    return 0;
}
//-----------------------------------------------------------------------
void printmatrix (int **A, int **B, int row, int col)
{
    for(int i=0; i<row; i++)
        {
            for(int j=0;j<row;j++)
                {
                    printf("%3d ", A[i][j]);
                }
            printf("\n");
        }
    printf("\n");
    for(int i=0; i<row; i++)
        {
            for(int j=0;j<col;j++)
                {
                    printf("%3d ", B[i][j]);
                }
            printf("\n");
        }
    printf("\n");
}
//-----------------------------------------------------------------------
void max_min (int **A, int row, int max, int min)
{
    max=A[0][0];
    min=A[0][0];
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                if (A[i][j] > max)
                    {
                        max = A[i][j];
                    }
            }
        }
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                if (A[i][j] < min)
                    {
                        min = A[i][j];
                    }
            }
        }
    printf(" MAX value of A: MAX = %d\n", max);
    printf(" MIN value of A: MIN = %d\n", min);
}
//-----------------------------------------------------------------------
void transposition (int **B, int row, int col, int **T)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            {
                T[j][i] = B[i][j];
            }
    }
    printf("\nTransponated B = \n");
  for (int i=0; i<col; i++)
        {
            for (int j=0; j<row; j++)
                {
                    printf("%d ", T[i][j]);
                }
            printf("\n");
        }
}
//-----------------------------------------------------------------------
void multiply (int **A, int **B, int row, int col, int **Mult)
{

   for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
               Mult[i][j]= 0;
            }
        }
   for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                for (int k=0; k<row; k++)
                {
                   Mult[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    printf("\n A*B = \n");
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    printf("%d\t",Mult[i][j]);
                }
            printf("\n");
        }
}
//-----------------------------------------------------------------------
void sorting (int **A, int row, int col, int sort)
{
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<row; j++)
            {
            int mini = A[i][j];

            int x = i;
            int y = j;

            int z = j;

            for (int k = i; k < row; k++)
                {
                    for (z; z < row; z++)
                    {
                        if (A[k][z] < mini)
                        {
                          mini = A[k][z];
                          x = k;
                          y = z;
                        }
                    }
                z = 0;
                }
            int temp = A[i][j];
            A[i][j] = A[x][y];
            A[x][y] = temp;
            }
        }
    printf("\n Sorted A = \n");
    for (int i=0;i<row;i++)
        {
            for (int j=0;j<row;j++)
                {
                    printf("%d ", A[i][j]);
                }
            printf("\n");
        }

}
//-----------------------------------------------------------------------
void summ (int **A, int **B, int row, int col, int sumA, int sumB)
{

    for(int i=0;i<row;i++)
        {
            sumA=0;
            for(int j=0;j<row;j++)
                {
                    sumA += A[i][j];
                }
            printf("\n Sum of a row %d of A = %d",i++,sumA);
        }
    printf("\n");

    for(int j=0;j<col;j++)
    {
        sumB=0;
        for(int i=0;i<row;i++)
            {
                sumB += B[i][j];
            }
        printf("\n Sum of a column %d of B = %d",j++,sumB);
    }
    printf("\n");
}
