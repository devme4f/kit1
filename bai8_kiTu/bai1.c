#include <stdio.h>
//tinh do dai cua chuoi ko dung ham co san
int main(){
	char str[100];
	fgets(str, sizeof(str), stdin);
	int dem = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i]!='\0') dem++;
	}
	printf("%d", dem);
	return 0;
}