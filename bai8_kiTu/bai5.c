/* 5. Nhập 1 chuỗi gồm nhiều từ, định dạng lại chuỗi đấy sao cho các kí tự đầu tiên của mỗi từ viết hoa, 
các kí tự còn lại viết thường, giữa các từ có 1 khoảng trắng
input : "  NgUYEn VAN  A"
output : "Nguyen Van A
*/
#include <stdio.h>
#include <string.h>
int isSpace(char c){
	return (c==' ' || c=='\t');
}
void reMo(char *str, int *size){
	for(int i = 0; str[i]!='\0'; i++){
		if((isSpace(str[i])&&isSpace(str[i+1])) || isSpace(str[0])){
			for(int j = i; str[j]!='\0'; j++) str[j] = str[j+1];
			i--;
			*size -= 1;
		}
	}
}
void toup(char *str, int size){
	for(int i = 0; i<size; i++){
		if((i==0 || isSpace(str[i-1])) && (str[i]<=122 && str[i]>=97)) str[i] -= 32;
		else if(str[i]<=90 && str[i]>=65 && !isSpace(str[i-1]) && i!=0) str[i] +=32;
	}
}
int main(){
	char str[100];
	fgets(str, 99, stdin);
	int size = strlen(str);
	reMo(str, &size);
	toup(str, size);
	puts(str);
	return 0;
}