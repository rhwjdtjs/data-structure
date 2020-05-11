/*
�ۼ���: 20194032 ������
�ۼ���: 2020�� 5�� 11��
���α׷���: ����� ���� �� ���� ����ϴ� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>
void matrix_add(int **matrix_A, int **matrix_B, int **matrix_C, int ROWS);
void matrix_sub(int **matrix_A, int **matrix_B, int **matrix_C, int ROWS);
void matrix_mul(int **matrix_A, int **matrix_B, int **matrix_C, int ROWS, int COLS);
void matrix_print(int **matrix, int ROWS, int COLS);
int main()
{
	int i,j;
	int **matrix_A,**matrix_B,**matrix_C;
	int ROWS,COLS;
	FILE *fp;
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		return 0;
	}
	

	while(!feof(fp))
	{
		fscanf(fp,"%d %d",&ROWS,&COLS);
		matrix_A=(int **)malloc(sizeof(int *)*ROWS);
		for(i=0; i<ROWS; i++)
			matrix_A[i]=(int *)malloc(sizeof(int)*COLS);
		for(i=0; i<ROWS; i++)
		{
			for(j=0; j<COLS; j++)
				fscanf(fp,"%d",&matrix_A[i][j]);
		}
		fscanf(fp,"%d %d",&ROWS,&COLS);
		matrix_B=(int **)malloc(sizeof(int *)*ROWS);
		for(i=0; i<ROWS; i++)
			matrix_B[i]=(int *)malloc(sizeof(int)*COLS);
		for(i=0; i<ROWS; i++)
		{
			for(j=0; j<COLS; j++)
				fscanf(fp,"%d",&matrix_B[i][j]);
		}
	}
	printf("������ A\n");
	matrix_print(matrix_A,ROWS,COLS);
	printf("\n");
	printf("������ B\n");
	matrix_print(matrix_B,ROWS,COLS);
	printf("\n");
	matrix_C=(int **)malloc(sizeof(int *)*ROWS);
	for(i=0; i<ROWS; i++)
		matrix_C[i]=(int *)malloc(sizeof(int)*COLS);

	printf("A ��İ� B����� ��\n");
	matrix_add(matrix_A,matrix_B,matrix_C,ROWS);
	matrix_print(matrix_C,ROWS,COLS);

	printf("A ��İ� B����� ��\n");
	matrix_sub(matrix_A,matrix_B,matrix_C,ROWS);
	matrix_print(matrix_C,ROWS,COLS);
	printf("A ��İ� B����� ��\n");
	matrix_mul(matrix_A,matrix_B,matrix_C,ROWS,COLS);
	matrix_print(matrix_C,ROWS,COLS);
	for(i = 0; i < ROWS; i++)
		free(matrix_A[i]);
	free(matrix_A);
	for (i = 0; i < ROWS; i++)
		free(matrix_B[i]);
	free(matrix_B);
	for (i = 0; i < ROWS; i++)
		free(matrix_C[i]);
	free(matrix_C);
	fclose(fp);
}
void matrix_add(int **matrix_A, int **matrix_B, int **matrix_C, int ROWS)
{
	int i,j;
	for(i=0; i<ROWS; i++)
		for(j=0; j<ROWS; j++)
			matrix_C[i][j]=matrix_A[i][j]+matrix_B[i][j];
}
void matrix_sub(int **matrix_A, int **matrix_B, int **matrix_C, int ROWS)
{
	int i,j;
	for(i=0; i<ROWS; i++)
		for(j=0; j<ROWS; j++)
			matrix_C[i][j]=matrix_A[i][j]-matrix_B[i][j];
}
void matrix_mul(int **matrix_A, int **matrix_B, int **matrix_C, int ROWS, int COLS)
{
	int i,j,k;
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			matrix_C[i][j]=0;
			for(k=0; k<ROWS; k++)
				matrix_C[i][j]+=matrix_A[i][k]*matrix_B[k][j];
		}
	}
}
void matrix_print(int **matrix, int ROWS, int COLS)
{
	int i,j;
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			if(j==COLS-1)
				printf(" %d ",matrix[i][j]);
			else
				printf(" %d ",matrix[i][j]);
		}
		printf("\n");
	}
}