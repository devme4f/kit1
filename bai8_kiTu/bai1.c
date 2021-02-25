//1. Nhập 1 chuỗi, viết hàm in ra số lượng các chữ số,  chữ cái và kí tự đặc biệt có trong chuỗi.
#include <stdio.h>
#include <string.h>
int main(){
	char str[100];
	fgets(str, 99, stdin);
	int sl = strlen(str);
	int cCai = 0, cSo = 0, space = 0;
	for(int i = 0; i<sl; i++){
		if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i] <=122)) cCai++;
		if(str[i]>=48 && str[i]<=57) cSo++;
		if(str[i]==' ') space++;
	}
	printf("\nSo chu cai: %d", cCai);
	printf("\nSo chu so: %d", cSo);
	printf("\nSo ki tu dac biet: %d", sl-cCai-cSo-space-1);
	return 0;
}