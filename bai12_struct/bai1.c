//Tạo kiểu dữ liệu phân số gồm hai thành phần mẫu số và tử số.
//Nhập và in ra màn hình 1 phân số, rút gọn phân số.
#include <stdio.h>
typedef struct phanSo{
	int tuSo;
	int mauSo;
} phanSo;
void inPhanSo(int a, int b){
	printf("%d/%d\n", a, b);
}
int UCLN(int a, int b){
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
void rutGon(int *a, int *b, int *flag){
	*flag = 1;
	while(1){
		int r = UCLN(*a, *b);
		if(r!=1 && *a!=1 && *b!=1){
			*a /= r;
			*b /= r;
			*flag = 0;
		}
		else break;
	}
}
int main(){
	int flag;
	phanSo a;
	printf("Nhap tu so: ");
	scanf("%d", &a.tuSo);
	printf("Nhap mau so: ");
	scanf("%d", &a.mauSo);
	if(a.mauSo==0){
		printf("Mau so khong hop le!"); return 0;
	}
	rutGon(&a.tuSo, &a.mauSo, &flag);
	if(flag)printf("Phan so = ");
	else printf("Phan so sau rut gon = ");
	inPhanSo(a.tuSo, a.mauSo);
	return 0;
}