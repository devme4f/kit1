//bài 2
#include <stdio.h>
int main(){
	int k, a[100], b[100], c[100], m = 0, n = 0;
	puts("Nhap so phan tu:");
	scanf("%d", &k);
	printf("Nhap cac phan tu cua mang:");
	for(int i = 0; i<k; i++) scanf("%d", &a[i]);
	for(int i = 0; i<k; i++){
		if(a[i]>0){
			b[m] = a[i];
			m++;
		}
		else{
			c[n] = a[i];
			n++;
		}
	}
	printf("Mang A:\n");
	for(int i = 0; i<k; i++) printf("%d ", a[i]);
	printf("\nMang B:\n");
	for(int i = 0; i<m; i++) printf("%d ", b[i]);
		printf("\nMang C:\n");
	for(int i = 0; i<n; i++) printf("%d ", c[i]);
	return 0;
}