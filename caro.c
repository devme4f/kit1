#include <stdio.h>
#include <stdlib.h>
#define size 10
void hienThi(int a[][size]){
	printf("\nNhap tuong ung lan luot toa do hang(<) cot(^)");
	for(int i = 0; i<size; i++){
		printf("\n");
		for(int k = 0; k<size; k++) printf("----");
		printf("\n");
		for(int j = 0; j<size; j++){ // 0==O, 1==X, 2== none
			printf("|");
			if(a[i][j]==1) printf(" X ");
			else{
				if(a[i][j]==0) printf(" O ");
				else printf("   ");
			}
		}
		printf("|<%d", i);
	}
	printf("\n");
	for(int k = 0; k<size; k++) printf("----");
		printf("\n");
	for(int k = 0; k<size; k++) printf("  ^ ");
		printf("\n");
	for(int k = 0; k<size; k++) printf("  %d ", k);
}

void player1(int a[][size]){
	int x, y;
	puts("\nPlayer1(X):");
	scanf("%d%d", &x, &y);
	if(x<0||y<0||x>9||y>9){
		printf("Toa do khong ton tai, hay nhap lai!");
		player1(a);
	}
	if(a[x][y]==1||a[x][y]==0){
		printf("Toa do khong hop le, hay nhap lai!");
		player1(a);
	}
	else a[x][y] = 1;
}
void player2(int a[][size]){
	int x, y;
	puts("\nPlayer2(O):");
	scanf("%d%d", &x, &y);
	if(x<0||y<0||x>9||y>9){
		printf("Toa do khong ton tai, hay nhap lai!");
		player2(a);
	}
	if(a[x][y]==1||a[x][y]==0){
		printf("Toa do khong hop le, hay nhap lai!");
		player2(a);
	}
	else a[x][y] = 0;
}
void begin(int a[][size]){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			a[i][j] = 2;
		}
	}
}
int checkwin00(int a[][size]){
	int dem1, dem0;
	for(int i = 0; i<size; i++){
		dem1 = 0;
		dem0 = 0;
		for(int j = 0; j<size; j++){
			if(a[i][j]==1){
				dem1++;
			}
			else dem1 = 0;
			if(a[i][j]==0){
				dem0++;
			}
			else dem0 = 0;
			if(dem1==5){
				printf("\nplayer1 win!");
				return 1;
			}
			if(dem0==5){
				printf("\nplayer2 win!");
				return 1;
			}
		}
	}
	return 0; //ngang
}
int checkwin11(int a[][size]){
	int dem1, dem0;
	for(int i = 0; i<size; i++){
		dem1 = 0;
		dem0 = 0;
		for(int j = 0; j<size; j++){
			if(a[j][i]==1){
				dem1++;
			}
			else dem1 = 0;
			if(a[j][i]==0){
				dem0++;
			}
			else dem0 = 0;
			if(dem1==5){
				printf("\nplayer1 win!");
				return 1;
			}
			if(dem0==5){
				printf("\nplayer2 win!");
				return 1; 
			}
		}
	}
	return 0; //dọc
}
int checkwin01(int a[][size]){ //chéo trái->phải
	int n = 3, dem0 = 0, dem1 = 0;
	while(n<size){
		for(int k = 0; k<=n; k++){
			if(a[k][n-k]==1) dem1++;
			else dem1 = 0;
			if(a[k][n-k]==0) dem0++;
			else dem0 = 0;
			if(dem1==5){
				printf("\nplayer1 win!");
				return 1;
			}
			if(dem0==5){
				printf("\nplayer2 win!");
				return 1;
			}
		}
		dem0 = 0;
		dem1 = 0;
		n++;
	} 
	n = 1;

	while(n<=6){
		int tnt = n; 
		for(int k = 9; k>=n; k--){
			if(a[tnt][k]==1) dem1++;
			else dem1 = 0;
			if(a[tnt][k]==0) dem0++;
			else dem0 = 0;
			if(dem1==5){
				printf("\nplayer1 win!");
				return 1;
			}
			if(dem0==5){
				printf("\nplayer2 win!");
				return 1;
			}
			tnt++;
		}
		dem0 = 0;
		dem1 = 0;
		n++; 
	} 
	return 0;
}
int checkwin10(int a[][size]){//chéo trên->xuống
	int n = 6, dem0, dem1;
	while(n>=0){
		int tnt = n;
		for(int k = 0; k<size-n; k++){
			if(a[k][tnt]==1) dem1++;
			else dem1 = 0;
			if(a[k][tnt]==0) dem0++;
			else dem0 = 0;
			if(dem1==5){
				printf("\nplayer1 win!");
				return 1;
			}
			if(dem0==5){
				printf("\nplayer2 win!");
				return 1;
			}
			tnt++;
		}
		dem1 = 0;
		dem0 = 0;
		n--;
	}
	n = 1;
	while(n<size){
		int tnt = n;
		for(int k = 0; k<size-n; k++){
			if(a[tnt][k]==1) dem1++;
			else dem1 = 0;
			if(a[tnt][k]==0) dem0++;
			else dem0 = 0;
			if(dem1==5){
				printf("\nplayer1 win!");
				return 1;
			}
			if(dem0==5){
				printf("\nplayer2 win!");
				return 1;
			}
			tnt++;
		}
		dem1 = 0;
		dem0 = 0;
		n++;
	}
	return 0;
}
void menu(){
	printf("\n1. Bat dau choi");
	printf("\n2. Huong dan choi");
	printf("\n3. Info");
	printf("\n4. Thoat\n");
}
void huongDan(){
	printf("\n1. Day la game co caro dien tich 10x10 2 nguoi choi.");
	printf("\n2. Cach choi:\n (1)Tich 5 o vuong lien tiep de gianh chien thang.");
	printf("\n (2)player1 mac dinh la X, player2 la O.");
	printf("\n (3)Nhap toa do tuong ung moi cell de choi");
}
void info(){
	printf("\n Made by Nguyen Danh Kiet kit Group");
}
int main(){
	int a[size][size], choice;
	while(choice!=4){
		menu();
		printf("\nNhap lua chon:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
			begin(a);
			while(1){
				system("cls");
				hienThi(a);
				player1(a);
				if(checkwin00(a)) break;
				if(checkwin11(a)) break;
				if(checkwin01(a)) break;
				if(checkwin10(a)) break;
				system("cls");
				hienThi(a);
				player2(a);
				if(checkwin00(a)) break;
				if(checkwin11(a)) break;
				if(checkwin01(a)) break;
				if(checkwin10(a)) break;
			}
			hienThi(a);
			break;
			case 2:
			huongDan();
			break;
			case 3:
			info();
			break;
			case 4:
			choice = 4;
			break;
		}
	}
	return 0;
}