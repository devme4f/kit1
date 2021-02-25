//4. Nhập 1 chuỗi, chuyển các kí từ viết thường trong chuỗi thành kí tự in hoa 
#include <stdio.h>

int main(){
	char c[100];
	fgets(c, 99, stdin);
	for(int i = 0; c[i] != '\0'; i++){
		if(c[i]<=122 && c[i]>=97){
			c[i] -= 32;
		}
	}
	puts(c);
	return 0;
}