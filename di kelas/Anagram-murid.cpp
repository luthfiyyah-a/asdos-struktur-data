#include<stdio.h>
#include<string.h>

int main(){
	
	int counter = 0, lenght;
	char arr_1[100], arr_2[100];
	char *x, *y;
	
	printf("Kata pertama\n");
	scanf("%s", arr_1);
	printf("Kata kedua\n");
	scanf("%s", arr_2);
	x = &arr_1[0];
	y = &arr_2[0];
	lenght = (strlen(arr_1));
	
	while(*x!='\0'){
		printf("alhamdulillah %c\n", *x);
		while(*y!='\0'){
			printf("bismillah %c\n", *y);
			if(*x==*y){
				printf("%c", *y);
				*x='-';
				*y='+';
				counter++;
			}
			y++;
		}
		y = &arr_2[0];
		x++;
	}
	
	printf("counter = %d || lenght = %d", counter, lenght);
	if(counter==lenght){
		printf("anagram");
	}
	else{
		printf("bukan anagram");
	}
}
