#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <setjmp.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;
vector<int> adj[MAX];
int visit[MAX] = {0}, degree[MAX] = {0};
int ans = 0, path[MAX], tmp[MAX], n = 0;
jmp_buf env_alarm;
clock_t st;
int cmp(int a, int b){
	return (degree[a] < degree[b]);
}
void DFS(int p){
	sort(adj[p].begin(), adj[p].end(), cmp);
	clock_t ed = clock();
	if(((ed-st)/(double)(CLOCKS_PER_SEC)) > 1)
		longjmp(env_alarm, 1);
	
	for(int i = 0; i < adj[p].size(); i++){
		int c = adj[p][i];
		if(!visit[c]) {
			int size = adj[c].size();
			for(int j = 0; j < size; j++)
				degree[adj[c][j]]--;
			tmp[n++] = c;
			visit[c] = 1;
			DFS(c);
			visit[c] = 0;
			n--;
			for(int j = 0; j < size; j++)
				degree[adj[c][j]]++;
			
		}
	}
	if(n > ans){
		ans = n;
		for(int i = 0; i < n; i++)  path[i] = tmp[i];
	}
}
int main(){
	st = clock();
	int V, E;
	scanf("%d%d", &V, &E);
	int a, b;
	while(E--){
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	
	if(!setjmp(env_alarm))
		for(int i = 1; i <= V; i++){
			n = 0;
			memset(visit, 0, sizeof(visit));
			visit[i] = 1;
			tmp[n++] = i;
			DFS(i);
		}
	
	printf("%d\n", ans);
	for(int i = 0; i < ans; i++)
		printf("%d ", path[i]);
	
	return 0;
}