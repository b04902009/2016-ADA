#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char n[100005], ans[100005];
	scanf("%s", n);
	int len = strlen(n), n_4 = (len+1)/2, n_7 = (len+1)/2, flag = 0;
	int last_4, last_4_n;
	if(len % 2){
		while(n_4--)  printf("4");
		while(n_7--)  printf("7");
	}
	else{
		int temp = '7';
		for(int i = 0; i < len; i++) {
			if(i == len/2)  temp = '4';
			if(n[i] < temp)  break;
			if(n[i] > temp) {
				flag = 1;
				break;
			}
		}
		if(flag) {
			for(int i = 0; i < len/2+1; i++)  printf("4");
			for(int i = len/2+1; i < len+2; i++)  printf("7");
		}
		else {
			for(int i = 0; i < len; i++) {
				if(n[i] < '4' && n_4) {
					//printf("<4\n");
					for(int j = 0; j < n_4; j++)  ans[i+j] = '4';
					for(int j = i+n_4; j < len; j++)  ans[j] = '7';
					break;
				}
				else if(n[i] == '4' && n_4) {
					//printf("4\n");
					ans[i] = '4';
					n_4--;
					if(n_7){
						last_4 = i;
						last_4_n = n_4;
					}
				}
				else if(n[i] > '4' && n[i] < '7' && n_7) {
					//printf("4~7\n");
					ans[i] = '7';
					for(int j = 1; j <= n_4; j++)  ans[i+j] = '4';
					for(int j = i+n_4+1; j < len; j++)  ans[j] = '7';
					break;
				}
				else if(n[i] < '7' && !n_4){
					for(int j = i; j < len; j++)  ans[j] = '7';
					break;
				}
				else if(n[i] > '7' || !n_7) {
					//printf(">7\n");
					ans[last_4] = '7';
					for(int j = 1; j <= last_4_n+1; j++)  ans[last_4+j] = '4';
					for(int j = last_4+last_4_n+2; j < len; j++)  ans[j] = '7';
					break;
				}
				else {
					//printf("7\n");
					ans[i] = '7';
					n_7--;
				}
			}
			for(int i = 0 ; i < len; i++)  printf("%c", ans[i]);
		}
	}
	
	return 0;
}
//74777447