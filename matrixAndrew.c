#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#define rows 5
#define cols 5

// Part 1
void fillMatrix(int matrix[rows][cols]){
	time_t t;
	srand(time(&t));
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			int number=(rand()%99+1);
			matrix[i][j]=number;
		}
	}
}
// Part 2
void printMatrix(int matrix[rows][cols]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
		printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
// Part 3
void transposeMatrix(int matrix[rows][cols]){
	for(int i=0;i<5;i++){
		for(int j=i;j<5;j++){
			int *x=(*(matrix+i)+j);
			int *y=(*(matrix+j)+i);
			int tmp=*(*(matrix+i)+j);
			*x=*(*(matrix+j)+i);
			*y=tmp;
		}
	}
}
// Part 4
void multiplyMatrix(int m1[2][rows], int m2[rows][cols], int resultMatrix[rows][cols]){
	for(int a=0;a<5;a++){
		int total=0;
		for(int b=0;b<5;b++){
			total+=(*(*m1+b)*(*(*(m2+b)+a)));
		}
		*(*resultMatrix+a)=total;
	}
	for(int a=0;a<5;a++){
		int total=0;
		for(int b=0;b<5;b++){
			total+=(*(*(m1+1)+b)*(*(*(m2+b)+a)));
		}
		*(*(resultMatrix+1)+a)=total;
	}
	for(int i=2;i<5;i++){
		for(int j=0;j<5;j++){
			*(*(resultMatrix+i)+j)=0;
		}
	}
}
int main(){
	int matrix[rows][cols];
	fillMatrix(matrix);
	printMatrix(matrix);
	transposeMatrix(matrix);
	printMatrix(matrix);
	int matrix2[2][cols]={{0,1,2,3,4},{5,6,7,8,9}};
	int matrixResult[rows][cols];
	multiplyMatrix(matrix2,matrix,matrixResult);
	printMatrix(matrixResult);
	return 0;
}