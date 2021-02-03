//bài 1
#include <stdio.h>
void menu(){
	printf("1. Kiem tra co phai ma tran vuong\n");
	printf("2. Tong cac phan tu duong cheo chinh \n");
	printf("3. Kiem tra 1 so co xuat hien trong ma tran \n");
	printf("4. Gia tri trung binh cac phan tu nho nhat tren moi cot \n");
	printf("5. Gia tri va vi tri phan tu chan lon nhat trong ma tran \n");
	printf("Any. Ket thuc \n");
}
void nhapMang(int m, int n, int a[][50]){
	printf("Nhap cac phan tu:");
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
}
int tongCheo(int m, int n, int a[][50]){
	int tong = 0;
	for(int i=0; i<m; i++){
		tong += a[i][i];
	}
	return tong;
}
int kTraXH(int k, int m, int n, int a[][50]){
	int dem = 0;
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			if(k==a[i][j]){
				dem++;
			}
		}
	}
	return dem;
}
float tongMinCot(int m, int n, int a[][50]){
	float tong  = 0;
	for(int i = 0; i<n; i++){ //quét theo chiều dọc
		int min = a[0][i];
		for(int j = 0; j<m; j++){
			if(a[j][i]<min) min = a[j][i];
		}
		tong += min;
	}

	return tong/n;
}
int timMax(int m, int n, int a[][50]){
	int max = a[0][0];
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			if(a[i][j]>max) max = a[i][j];
		}
	}
	return max;
}
void inViTri( int m, int n, int a[][50]){
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			if(timMax(m, n, a)==a[i][j]) printf("\nTai vi tri a[%d][%d]\n", i, j);
		}
	}
}
int main(){
	int m, n, a[50][50], choice, k;
	puts("Nhap so hang va cot:");
	scanf("%d%d", &m, &n);
	nhapMang(m, n, a);
	menu();
	while(choice!=6){
		printf("Nhap lua chon: \n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if(m==n) printf("Day la ma tran vuong!\n");
				else printf("Day khong phai la ma tran vuong!\n");
				break;
			case 2:
				if(m!=n) printf("Khong co duong cheo chinh!\n");
				else printf("Tong duong cheo ma tran la: %d\n", tongCheo(m, n, a));
				break;
			case 3:
				puts("Nhap k:");
				scanf("%d", &k);
				printf("%d xuat hien %d lan!\n", k, kTraXH(k, m, n, a));
				break;
			case 4:
				printf("Trung binh cong min moi cot la: %.3f\n", tongMinCot(m, n, a));
				break;
			case 5:
				printf("Max = %d", timMax(m, n, a));
				inViTri(m, n , a);
				break;
			default :
				choice = 6;
				break;
		}
	}
	return 0;
}
