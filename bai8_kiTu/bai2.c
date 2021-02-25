//2.  Nhập 1 chuỗi sắp xếp các kí tự trong chuỗi theo bảng chữ cái.
#include <stdio.h>
#include <string.h>
int main(){
	char a[100];
	fgets(a, 99, stdin);
	int size = strlen(a);
	for(int i = 0; i<size-1; i++){
		for(int j = i+1; j<size; j++){
			if(a[i]>a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	puts(a);
	return 0;
} //??