//bài 4 -_-
#include <stdio.h>

int main(){
	int n;
	puts("Nhap n(>0):");
	scanf("%d", &n);
	if(n<1) return 0;
	printf("Cac uoc cua %d la:\n", n);
		for(int i = 1; i<=n; i++){
			if(n%i==0) printf("%d ", i);
		}
	return 0;
}