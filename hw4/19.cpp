#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
#define VMAX 20000 
vector<int> adj[VMAX], tadj[VMAX], finish;
int h, r, k = 0;  // h:house, r:road, k:# of scc
int visit[VMAX] = {0}, scc[VMAX];
int happy(int i){return h+i;}
void DFS1(int);
void DFS2(int);
void build_SCC();
struct SCC{
	int n;
	vector<int> v;
} list[VMAX];

int main(){
	scanf("%d%d", &h, &r);
	int a, b, s;
	for(int i = 0; i < r; i++){
		scanf("%d%d%d", &a, &b, &s);
		a--;  b--;
		if(!s){
			adj[happy(b)].push_back(happy(a));
			adj[a].push_back(b);
			tadj[happy(a)].push_back(happy(b));
			tadj[b].push_back(a);
		}
		else{
			adj[a].push_back(happy(b));
			adj[happy(b)].push_back(a);
			tadj[happy(b)].push_back(a);
			tadj[a].push_back(happy(b));
		}
	}

	build_SCC();
	int tmp[VMAX/2];
	for(int i = 0; i < k; i++){
		memset(tmp, 0, sizeof(tmp));
		list[i].n = 0;
		for(int j = 0; j < list[i].v.size(); j++){
			int m = list[i].v[j];
			if(m < h)  tmp[m]= 1;
			else  tmp[m-h] = 1;
		}
		for(int j = 0; j < h; j++)
			if(tmp[j])  list[i].n++;
	}

	for(int i = 0; i < h; i++)
		printf("%d\n", list[scc[happy(i)]].n);

	return 0;
}
 
void DFS1(int p){
	visit[p] = 1;
	for(int i = 0; i < adj[p].size(); i++){
		int c = adj[p][i];
		if(!visit[c])  DFS1(c);
	}
    finish.push_back(p);
}
 
void DFS2(int p){
    scc[p] = k;
    list[k].v.push_back(p);
    visit[p] = 1;
    for(int i = 0; i < tadj[p].size(); i++){
		int c = tadj[p][i];
		if(!visit[c])  DFS2(c);
	}
}

void build_SCC(){
    finish.clear();
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < 2*h; i++)
        if(!visit[i])  DFS1(i);

    memset(visit, 0, sizeof(visit));
    for(int i = 2*h-1; i >= 0; i--)
        if(!visit[finish[i]]){
        	DFS2(finish[i]);
        	k++;
        }
}