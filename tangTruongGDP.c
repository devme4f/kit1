#include <stdio.h>

int main(){
	int nam = 2014;
	float tongGDP, tTruong;
	printf("Nhap tong thu nhap GDP nam 2014: ");
	scanf("%f", &tongGDP);
	printf("Nhap toc do tang truong kinh te binh quan hang nam: ");
	scanf("%f", &tTruong);
	float endGDP = tongGDP*2;

	printf("Nam      GDP");
	while(tongGDP<=endGDP){
		tongGDP += tongGDP*(tTruong/100);
		printf("\n%d      %.2f", nam, tongGDP);
		nam++;
	}
	return 0;
}