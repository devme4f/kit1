//3. Nhập chuỗi, viết hàm xóa hết những kí tự không nằm trong bảng chữ cái.
#include <stdio.h>
#include <string.h>
int bangC(char c){
	return ((c<=90 && c>=65) || (c<=122 && c>= 97));
}
int main(){
	char c[100];
	fgets(c, 99, stdin);
	int size = strlen(c);
	for(int i = 0; i<size; i++){
		if(!bangC(c[i])){
			for(int j = i; j<size; j++){
				c[j] = c[j+1];
			}
			i--;
			size--;
		}
	}
	puts(c);
	return 0;
}