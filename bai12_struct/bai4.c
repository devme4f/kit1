/*
4. Tạo kiểu dữ liệu sinh viên gồm tên, lớp, điểm tổng kết, xếp loại, trong đó nếu điểm tổng kết từ
8 - 10 : xếp loại giỏi
6 - <8 : xếp loại khá
4 - <6 : xếp loại trung bình
<4 : xếp loại yếu
Nhập và in danh sánh có n sinh viên với điểm tổng kết được sắp xếp giảm dần (n nhập từ bàn phím)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct duLieuSV{
	char tenSV[30], lop[15];
	float diemTK;
	char xepLoai[11];
} duLieuSV;
void nhapData(duLieuSV *sinhVien, int size){
	for(int i = 0; i<size; i++){
		printf("Nhap ten sinh vien: ");
		fflush(stdin);
		gets(sinhVien[i].tenSV);
		printf("Nhap lop: ");
		gets(sinhVien[i].lop);
		printf("Nhap diem tong ket: ");
		scanf("%f", &sinhVien[i].diemTK);
		int xL = sinhVien[i].diemTK;
		if(xL<=10 && xL >=8) strcpy(sinhVien[i].xepLoai, "Gioi");
			else if(xL<8 && xL >= 6) strcpy(sinhVien[i].xepLoai, "Kha");
				else if(xL < 6 && xL >=4) strcpy(sinhVien[i].xepLoai, "Trung Binh");
					else if(xL < 4 && xL >=0) strcpy(sinhVien[i].xepLoai, "Yeu");
	}
}
void sapXepDiem(duLieuSV *sinhVien, int size){
	float tempDiem;
	char temp[30];
	for(int i = 0; i<size-1; i++){
		if(sinhVien[i].diemTK < sinhVien[i+1].diemTK){
			tempDiem = sinhVien[i].diemTK;
			sinhVien[i].diemTK = sinhVien[i+1].diemTK;
			sinhVien[i+1].diemTK = tempDiem;

			strcpy(temp, sinhVien[i].tenSV);
			strcpy(sinhVien[i].tenSV, sinhVien[i+1].tenSV);
			strcpy(sinhVien[i+1].tenSV, temp);

			strcpy(temp, sinhVien[i].lop);
			strcpy(sinhVien[i].lop, sinhVien[i+1].lop);
			strcpy(sinhVien[i+1].lop, temp);

			strcpy(temp, sinhVien[i].xepLoai);
			strcpy(sinhVien[i].xepLoai, sinhVien[i+1].xepLoai);
			strcpy(sinhVien[i+1].xepLoai, temp);
		}
		
	}
}
void xuatData(duLieuSV *sinhVien, int size){
	sapXepDiem(sinhVien, size);
	printf("DANH SACH SINH VIEN:\n");
	printf("\tTen Sinh Vien \t\t Lop \t  Diem Tong Ket \t Xep Loai\n");
	for(int i = 0; i<size; i++){
		printf("%25s \t %s \t    %.2f \t\t %s\n", sinhVien[i].tenSV, sinhVien[i].lop, sinhVien[i].diemTK, sinhVien[i].xepLoai);
	}
}
int main(){
	int size;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &size);
	duLieuSV *sinhVien = (duLieuSV*)malloc(size * sizeof(duLieuSV));
	nhapData(sinhVien, size);
	xuatData(sinhVien, size);
	return 0;
}