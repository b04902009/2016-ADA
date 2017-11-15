#include <iostream>
using namespace std;
#define V 305
int main(){
	int v, p[V][V];
	scanf("%d", &v);
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			scanf("%d", &p[i][j]);

	for(int k = 0; k < v; k++)
		for(int i = 0; i < v; i++)
			for(int j = 0; j < v; j++){
				p[i][j] -= p[i][k] * p[k][j];
				while(p[i][j] < 0)  p[i][j] += 10;
			}
	
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			printf("%d%c", p[i][j], j == v-1 ? '\n' : ' ');

	return 0;
}