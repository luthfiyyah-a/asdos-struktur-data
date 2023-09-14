// demo pointer

#include <stdio.h>
#include <string.h>

int main(){
	
	char s[100];
	char* ptrKiri = &s[0];
	char* ptrKanan = &s[strlen(s)-1];
	
	int flag = 0;
	while(1){
		
		if(ptrKiri >= ptrKanan )
		{
			flag = 1;
			break;	
		}
		else if(*ptrKiri == *ptrKanan)
		{
			ptrKiri++;
			ptrKanan--;
		}
		else
		{
			break;
		}
		
	}
}
