//bài 3
#include <stdio.h>
void menu(){
	printf("1. In phan so a/b:\n");
	printf("2. Rut gon phan so` \n");
	printf("3. In ra so thap phan \n");
	printf("Any. Ket thuc \n");
}
int eUCLN(int a, int b){ // số chia hết cho cả a, b (!=0) chứ ko hẳn là ước
	int m, n;
	if(a>b){
		m = a;
		n = b;
	}
	else{
		m = b;
		n = a;
	}
	while(m%n!=0){
		int r = m%n;
		m = n;
		n = r;
	}
	return n;
}
void rutGon(int a, int b){
	while(1){
		int r = eUCLN(a, b);
		if(eUCLN(a, b)!=1&&a!=1&&b!=1){
			a /= r;
			b /= r;
		}
		else{
			printf("%d/%d", a, b);
			break;
		}
	}
}
int main(){
	int a, b, choice;
	puts("Nhap a, b(!=0):");
	scanf("%d%d", &a, &b);
	if(b==0) return 0;
	menu();
	while(choice!=4){
		puts("\nNhap lua chon:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if(a==0) printf("0");
				else printf("%d/%d", a, b);
				break;
			case 2:
				if(a==0) printf("0");
				else rutGon(a, b);
				break;
			case 3:
				if(a==0) printf("0");
				else printf("%f", (float)a/(float)b);
				break;
			default :
				choice = 4;
				break;

		}
	}
	return 0;
}