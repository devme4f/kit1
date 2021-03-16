//3. Nhập vào từ bàn phím mảng số nguyên m*m (m là số nguyên dương nhập vào từ bàn phím).
// Đổi chỗ 2 hàng bất kì trong mảng
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
void swap(int **matrix, int size){
	int a, b;
	printf("Nhap 2 hang muon doi cho: ");
	scanf("%d%d", &a, &b);
	a--; b--;
	int *temp = (int*)malloc(size * sizeof(int));
	for(int i = 0; i<size; i++){
		*(temp + i) = matrix[a][i];
		matrix[a][i] = matrix[b][i];
		matrix[b][i] = temp[i];
	}
}
void xuat(int **matrix, int size){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int size;
	printf("Nhap kich thuong ma tran vuong: ");
	scanf("%d", &size);
	if(size<1) return 0;
	int **matrix = (int**)malloc(size * sizeof(int));
	for(int i = 0; i<size; i++){
		matrix[i] = (int*)malloc(size * sizeof(int));
	}
	nhap(matrix, size);
	swap(matrix, size);
	xuat(matrix, size);
	return 0;
}