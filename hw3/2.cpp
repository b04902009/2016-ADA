#include <iostream>
using namespace std;
#define V 305
int v, p[V][V] = {{0}};
int adj[V][V], n[V], start;
void bfs(int s){
	for(int i = 0; i < n[s]; i++){
		if((++p[start][adj[s][i]]) == 10)
			p[start][adj[s][i]] = 0;
		bfs(adj[s][i]);
	}
}
int main(){
	int tmp;
	scanf("%d", &v);
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++){
			scanf("%d", &tmp);
			if(tmp)  adj[i][n[i]++] = j;
		}
	for(int i = 0; i < v; i++){
		start = i;
		bfs(i);
	}
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			printf("%d%c", p[i][j], j == v-1 ? '\n' : ' ');

	return 0;
}