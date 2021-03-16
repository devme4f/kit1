//4. Nhập 1 dãy n số nguyên (0<n<30), in ra màn hình các số chẵn và vị trí số chẵn đó trong dãy
#include <stdio.h>
#include <stdlib.h>
void nhap(int *row, int size){
	printf("Nhap cac phan tu:\n");
	for(int i = 0; i<size; i++) scanf("%d", &row[i]);
}
void inChan(int *row, int size){
	for(int i = 0; i<size; i++){
		if(row[i]%2==0){
			printf("Vi tri %d: ", i+1);
			printf("%d\n", row[i]);
		}
	}
}
int main(){
	int size;
	printf("Nhap chieu dai day so nguyen: ");
	scanf("%d", &size);
	if(size<=0 || size>=30) return 0;
	int *row = (int*)malloc(size * sizeof(int));
	nhap(row, size);
	inChan(row, size);
	return 0;
}