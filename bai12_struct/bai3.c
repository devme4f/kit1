/*
3. Tạo kiểu dữ liệu nhân viên bao gồm tên, số giờ làm, lương, trong đó lương = số giờ *10000.
Nhập và in danh sánh có n nhân viên (n nhập từ bàn phím), sau đó tính tổng tiền cần để trả lương cho toàn bộ nhân viên
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct dulieuNV{
	char tenNV[30];
	float gioLam;
	float luong;
} dulieuNV;
void nhapDaTa(dulieuNV *nhanVien, int size){
	for(int i = 0; i<size; i++){
		printf("Nhap ten nhan vien: ");
		fflush(stdin);
		gets(nhanVien[i].tenNV);
		printf("Nhap so gio lam viec: ");
		scanf("%f", &nhanVien[i].gioLam);
		nhanVien[i].luong = nhanVien[i].gioLam * 10000;
	}
}
void xuatData(dulieuNV *nhanVien, int size){
	printf("\nDANH SACH NHAN VIEN:\n\n");
	printf("\tTen Nhan Vien \t\t Luong\n");
	float tongLuong;
	for(int i = 0; i<size; i++){
		printf("%25s \t %.2fvnd\n", nhanVien[i].tenNV, nhanVien[i].luong);
		tongLuong += nhanVien[i].luong;
	}
	printf("\n\nTONG TIEN LUONG CAN TRA: %.3fvnd\n", tongLuong);
}
int main(){
	int size;
	printf("Nhap so luong nhan vien: ");
	scanf("%d", &size);
	dulieuNV *nhanVien = (dulieuNV*)malloc(size * sizeof(dulieuNV));
	nhapDaTa(nhanVien, size);
	xuatData(nhanVien, size);
	return 0;
}
