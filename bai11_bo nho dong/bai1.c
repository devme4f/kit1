//1. Nhập mảng 1 chiều n phần tử nhập từ bàn phím.Chèn số X vào vị trí thứ k trong dãy(x,k nhập từ bàn phím)
#include <stdio.h>
#include <stdlib.h>
void nhap(int *box, int n){
	printf("Nhap cac phan tu:\n");
	for(int i = 0; i<n; i++){
		scanf("%d", (box + i)); 
	}
}
void xuat(int *box, int n){
	printf("Cac phan tu cua day la:\n");
	for(int i = 0; i<n; i++){
		printf("%d ", *(box + i));
	}
}
void chen(int *box, int *n){
	*n += 1;
	realloc(box, *n * sizeof(int));
	int x, k;
	printf("Nhap so X va vi tri thu k can chen: ");
	scanf("%d%d", &x, &k);
	for(int i = *n; i>=k; i--) *(box + i) = *(box +i-1);
	*(box + k-1) = x;
}
int main(){
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	int *box = (int*)malloc(n * sizeof(int));
	nhap(box, n);
	chen(box, &n);
	xuat(box, n);
	free(box);
	return 0;
}