#include <stdio.h>
#include <stdlib.h> //clear screen
#include <time.h> //for random
#include <conio.h> //for getch()
#define size 4
int loose = 0, action = 0;
void menu(){
	printf("\n 1. Bat dau choi");
	printf("\n 2. Huong dan choi");
	printf("\n 3. Info");
	printf("\n 4. Thoat");
}
void hienThi(int a[][size]){
	printf("2048");
	for(int i = 0; i<size; i++){
		printf("\n");
		for(int i = 0; i<size; i++) printf("----");
		printf("\n");
		for(int j = 0; j<size; j++){
			printf("|");
			if(a[i][j]==0) printf("   ");
			else printf("%3d", a[i][j]);
		}
		printf("|");
	}
	printf("\n");
	for(int i = 0; i<size; i++) printf("----");
}
int randnum(){
	srand(time(NULL));
    int x = 1+rand()%(5); //x = minN+rand()%(maxN+1-minN); 40%=4, 60%=2
    if(x<=3) return 2;
    else return 4;
}
void randspawn(int a[][size]){
	int dem = 0, dem1 = 0;
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[i][j]==0) dem++;
		}
	}
	srand(time(NULL));
	int x = 1+rand()%(dem);
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[i][j]==0){
				dem1++;
				if(dem1==x){
					a[i][j] = randnum();
					break;
				}
			}
		}
	}
	return;
}
void begin(int a[][size]){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++) a[i][j] = 0;
	}
}
void moveUp(int a[][size]){
	for(int i = 0; i<size; i++){ //sort
		for(int j = 0; j<size; j++){
			if(a[j][i]==0){
				for(int k = 1; k<(size-j); k++){
					if(a[j+k][i]!=0){
						a[j][i] = a[j+k][i];
						a[j+k][i] = 0;
						action = 1;
						break;
					}
				}
			}
		}
	} 
	for(int i = 0; i<size; i++){ //incremental
		for(int j = 0; j<size; j++){
			if(a[j][i]==a[j+1][i]&&j!=3&&a[j][i]!=0){
				a[j][i] *= 2;
				a[j+1][i] = 0;
				action = 1;
			}
		}
	} //resort
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[j][i]==0){
				for(int k = 1; k<(size-j); k++){
					if(a[j+k][i]!=0){
						a[j][i] = a[j+k][i];
						a[j+k][i] = 0;
						action = 1;
						break;
					}
				}
			}
		}
	}
}
void moveDown(int a[][size]){
	for(int i = size-1; i>=0; i--){ //sort
		for(int j = size-1; j>=0; j--){
				if(a[j][i]==0){
				for(int k = 1; k<=j; k++){
					if(a[j-k][i]!=0){
						a[j][i] = a[j-k][i];
						a[j-k][i] = 0;
						action = 1;
						break;
					}
				}
			}

		}
	}
	for(int i = size-1; i>=0; i--){ //incremental
		for(int j = size-1; j>=0; j--){
			if(a[j][i]==a[j-1][i]&&j!=0&&a[j][i]!=0){
				a[j][i] *= 2;
				a[j-1][i] = 0;
				action = 1;
			}
		}
	}
	for(int i = size-1; i>=0; i--){ //resort
		for(int j = size-1; j>=0; j--){
				if(a[j][i]==0){
				for(int k = 1; k<=j; k++){
					if(a[j-k][i]!=0){
						a[j][i] = a[j-k][i];
						a[j-k][i] = 0;
						action = 1;
						break;
					}
				}
			}

		}
	}
}
void moveRight(int a[][size]){ //same
	for(int i = 0; i<size; i++){
		for(int j = size-1; j>=0; j--){
			if(a[i][j]==0){
				for(int k = 1; k<=j; k++){
					if(a[i][j-k]!=0){
						a[i][j] = a[i][j-k];
						a[i][j-k] = 0;
						action = 1;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i<size; i++){
		for(int j = size-1; j>=0; j--){
			if(a[i][j]==a[i][j-1]&&j!=0&&a[i][j]!=0){
				a[i][j] *= 2;
				a[i][j-1] = 0;
				action = 1;
			}
		}
	}
	for(int i = 0; i<size; i++){
		for(int j = size-1; j>=0; j--){
			if(a[i][j]==0){
				for(int k = 1; k<=j; k++){
					if(a[i][j-k]!=0){
						a[i][j] = a[i][j-k];
						a[i][j-k] = 0;
						action = 1;
						break;
					}
				}
			}
		}
	}
}
void moveLeft(int a[][size]){ //same
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[i][j]==0){
				for(int k = 1; k<size-j; k++){
					if(a[i][j+k]!=0){
						a[i][j] = a[i][j+k];
						a[i][j+k] = 0;
						action = 1;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[i][j]==a[i][j+1]&&j!=3&&a[i][j]!=0){
				a[i][j] *= 2;
				a[i][j+1] = 0;
				action = 1;
			}
		}
	}
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[i][j]==0){
				for(int k = 1; k<size-j; k++){
					if(a[i][j+k]!=0){
						a[i][j] = a[i][j+k];
						a[i][j+k] = 0;
						action = 1;
						break;
					}
				}
			}
		}
	}
}
void control(int a[][size]){
	printf("\nNhap huong di chuyen:");
	char c = getch();
        if(c == -32){
            c = getch(); //catch keypress
            if(c == 72) moveUp(a);
            if(c == 80) moveDown(a);
            if(c == 75) moveLeft(a);
            if(c == 77) moveRight(a);
            if(c == 27) return; //esc
        }
}
int checkWin(int a[][size]){
	int dem = 0;
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[i][j]==2048) return 1;
			if(a[i][j]==0){
				dem++;
			}
		}
	}
	if(dem==0){
		loose = 1;
		return 0;
	}
	loose = 0;
	return 0;
}
void huongDan(){
	printf("\n(1). Su dung cac phim mui ten de choi.");
	printf("\n(2). Score = 2048 de gianh chien thang.");
}
void info(){
	printf("\nMade by Nguyen Danh Kiet kit group");
}
int main(){
	int a[size][size], choice;
	menu();
	while(choice!=4){
		printf("\nNhap lua chon:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
			begin(a);
			randspawn(a);
			randspawn(a);
			while(1){
				system("cls");
				hienThi(a);
				control(a);
				if(checkWin(a)){
					system("cls");
					hienThi(a);
					printf("\nYOU WIN!\n");
					break;
				}
				if(loose==1){ //same
					system("cls");
					hienThi(a);
					printf("\nGAME OVER!");
					break;
				}
				if(action){
					randspawn(a);
					action = 0;
				}
			}
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
			default: break;
		}
	}
	return 0;
}