#include <stdio.h>
//Nhap chuoi va 1 ki tu, ktra ki tu do co trong chuoi k?
int main(){
	char a;
	char str[100];
	printf("Nhap chuoi:");
	fgets(str, 99, stdin);
	printf("Nhap ki tu:");
	scanf("%c", &a);
	int flag = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(a==str[i]){
			flag = 1;
			break;
		}
	}
	if(flag) printf("%c co trong chuoi!", a);
	else printf("%c khong co trong chuoi!", a);
	return 0;
}