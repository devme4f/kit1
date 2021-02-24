#include <stdio.h>
//nhap chuoi s, ktra tinh doi xung cua chuoi
int doiXung(char *s, int dem){
	int a = dem-1;
	for(int i = 0; i==dem+1/2; i++){
		if(s[i] != s[a--]) return 0;
	}
	return 1;
}
int main(){
	char s[100];
	fgets(s, 99, stdin);
	int dem = 0;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i]!='\0') dem++;
	}
	if(doiXung(s, dem)) printf("Chuoi doi xung!");
	else printf("Chuoi khong doi xung!");
}