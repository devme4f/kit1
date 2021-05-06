//ax + b = 0
#include<stdio.h>
int main(){
	int a, b;
	printf("Nhap a va b: ");
	scanf("%d%d", &a, &b);
	if(a==0 && b!=0){
		printf("Phuong trinh vo nghiem!");
	}
	if(a!=0){
		printf("X = %.03f\n", -(float)b/a); //ép kiểu int thành float, giờ chưa học không biết không sao
	}
	return 0;
}
