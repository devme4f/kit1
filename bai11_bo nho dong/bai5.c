//5. Nhập 1 dãy số thực không quá 50 phần tử, đưa ra màn hình tổng các số dương trong dãy.
//Xóa tất cả các số âm có trong dãy
#include <stdlib.h>
#include <stdio.h>
void nhap(int *row, int size){
	printf("Nhap cac phan tu:\n");
	for(int i = 0; i<size; i++) scanf("%d", &row[i]);
}
void xoaAm(int *row, int *size){
	for(int i = 0; i<*size; i++){
		if(row[i]<0){
			for(int j = i; j<*size; j++){
				row[j] = row[j+1];
			}
			i--;
			*size -= 1;
		}
	}
}
void xuat(int *row, int size){
	for(int i = 0; i<size; i++){
		printf("%d ", row[i]);
	}
}
int tong(int *row, int size){
	int s = 0;
	for(int i = 0; i<size; i++){
		s += row[i];
	}
	return s;
}
int main(){
	int size;
	printf("Nhap chieu dai day so: ");
	scanf("%d", &size);
	if(size<=0 || size>=50) return 0;
	int *row = (int*)malloc(size * sizeof(int));
	nhap(row, size);
	xoaAm(row, &size);
	xuat(row, size);
	printf("\nTong so duong: %d\n", tong(row, size));
	return 0;
}