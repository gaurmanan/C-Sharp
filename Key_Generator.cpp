#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>
int main(){
	int ran, num, rand2, a[26],A[26],n[10],c;
	FILE *f=fopen("key.txt","w");
	for(num=0;num<26;num++){
		a[num]=0;
		A[num]=0;
		if(num<10)n[num]=0;
	} 
	srand(time(NULL)); 
	num =0;
	while(num < 10000){
		ran= rand() % 3;
		if(ran== 0){ran= rand()%26; putc((65+ran),f);A[ran]++;}
		else if(ran== 1){ran= rand()%26; putc((97+ran),f);a[ran]++;}
		else if(ran== 2){ran= rand()%10; putc((48+ran),f);n[ran]++;}
		num++; c++;
	}
	for(num=0;num<26;num++){if(a[num]==0){putc((97+num),f);c++;} if(A[num]==0){putc((65+num),f);c++;} if(num < 10)if(n[num]==0){ putc((48+num),f);c++;}} 
	putc('$',f);
	fclose(f);
	printf("%d characters used.\nRandomised Cipher text generated.....",c);
	Sleep(1000);
	return 0;
}
