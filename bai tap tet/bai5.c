//bài 5
#include <stdio.h>
void tGiacDac(int n){
	for(int i = n; i>0; i--){
		for(int j = 1; j<=i; j++){
			printf("* ");
		}
		printf("\n");
	}
}
void tGiacRong(int n){
	for(int i = n; i>0; i--){
		for(int j = 1; j<=i; j++){
			if(i==n||j==1||j==i) printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}
int main(){
	int n;
	puts("Nhap chieu dai canh tam giac vuong:");
	scanf("%d", &n);
	tGiacDac(n);
	tGiacRong(n);
	return 0;
}