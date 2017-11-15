#include <iostream>
using namespace std;
#define V 305
struct Node{
	int n, l[V];
} in[V], out[V];
int v, p[V][V] = {{0}};

void bfs(int s){

}
int main(){
	int tmp;
	scanf("%d", &v);
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++){
			scanf("%d", &tmp);
			if(tmp){
				out[i].l[out[i].n++] = j;
				in[j].l[in[j].n++] = i;
			}
		}
	for(int i = 0; i < v; i++){
		if(in[i])  continue;
		bfs(i);
	}
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			printf("%d%c", p[i][j], j == v-1 ? '\n' : ' ');

	return 0;
}