//2. Nhập vào từ bàn phím mảng số nguyên m*m (m là số nguyên dương nhập vào từ bàn phím).
// In ra giá trị lớn nhất và vị trí của nó
#include <stdio.h>
#include <stdlib.h>
void nhap(int **matrix, int size){
	printf("Nhap mang:\n");
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
}
int timMax(int **matrix, int size, int *hang, int *cot){
	int max = matrix[0][0];
	*hang = 0; *cot = 0;
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(matrix[i][j]>max){
				max = matrix[i][j];
				*hang = i;
				*cot = j;
			}
		}
	}
	return max;
}
int main(){
	int size, hang, cot;
	printf("Nhap kich thuong ma tran vuong: ");
	scanf("%d", &size);
	if(size<1) return 0;
	int **matrix = (int**)malloc(size * sizeof(int));
	for(int i = 0; i<size; i++){
		matrix[i] = (int*)malloc(size * sizeof(int));
	}
	nhap(matrix, size);
	printf("MAX = %d\n", timMax(matrix, size, &hang, &cot));
	printf("Tai:\nhang: %d\ncot: %d", hang+1, cot+1);
	return 0;
}