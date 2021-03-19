//Tạo kiểu dữ liệu gồm tên, lớp, điểm tổng kết.
//Nhập và in d.sách có n sinh viên (n nhập từ bàn phím), sau đó sắp xếp lại tên sinh viên theo thứ tự bảng chữ cái
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct duLieuSV{
	char tenSV[30], lop[15];
	float diemTK;
} duLieuSV;
void sapXepTen(duLieuSV *sinhVien, int size){
	char tempTen[30];
	char tempLop[15];
	float tempDiem;
	for(int i = 0; i<size-1; i++){
		if(strcmp(sinhVien[i].tenSV, sinhVien[i+1].tenSV) > 0){
			strcpy(tempTen, sinhVien[i].tenSV);
			strcpy(sinhVien[i].tenSV, sinhVien[i+1].tenSV);
			strcpy(sinhVien[i+1].tenSV, tempTen);

			strcpy(tempLop, sinhVien[i].lop);
			strcpy(sinhVien[i].lop, sinhVien[i+1].lop);
			strcpy(sinhVien[i+1].lop, tempLop);

			tempDiem = sinhVien[i].diemTK;
			sinhVien[i].diemTK = sinhVien[i+1].diemTK;
			sinhVien[i+1].diemTK = tempDiem;
		}
	}
}
void nhapData(duLieuSV *sinhVien, int size){
	for(int i = 0; i<size; i++){
	printf("Nhap ho ten sinh vien: ");
	fflush(stdin);
	gets(sinhVien[i].tenSV);
	printf("Nhap lop: ");
	gets(sinhVien[i].lop);
	printf("Nhap diem tong ket: ");
	scanf("%f", &sinhVien[i].diemTK);
	}
}
void xuatData(duLieuSV *sinhVien, int size){
	printf("\nDANH SACH SINH VIEN:\n");
	printf("\t\tHo ten \t\t Lop \t DiemTK\n");
	for(int i = 0; i<size; i++){
		printf("%25s \t %s \t %.2f\n", sinhVien[i].tenSV, sinhVien[i].lop, sinhVien[i].diemTK);
	}
	getch();
}
int main(){
	int size;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &size);
	duLieuSV *sinhVien = (duLieuSV*)malloc(size * sizeof(duLieuSV));
	nhapData(sinhVien, size);
	sapXepTen(sinhVien, size);
	xuatData(sinhVien, size);
	return 0;
}