#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
#define MAX 100005
int ans[MAX], N, n, A, B;
set<int> p[MAX];
void bfsA(){
	int visit[MAX] = {0};
	queue<int> q;
	q.push(0);
	visit[0]++;

	while(!q.empty()){
		int s = q.front();
		q.pop();
		if(ans[s] + A >= B)  break;
		for(set<int>::iterator it = p[s].begin(); it != p[s].end(); it++){
			if(visit[*it])  continue;
			q.push(*it);
			visit[*it]++;
			if(ans[s] + A < ans[*it])
				ans[*it] = ans[s] + A;
		}
	}
}
void bfsB(){
	int visit[MAX] = {0};
	queue<int> q;
	vector<int> v(N-1);
	for(int i = 1; i < N; i++)  v[i-1] = i;
	for(int i = 0; i < N; i++){
		if(visit[i])  continue;
		q.push(i);
		visit[i]++;

		while(!q.empty()){
			int s = q.front();
			q.pop();
			if(ans[s] + B >= A)  break;
			int n = 0;
			for(int j = 0; j < v.size(); j++){
				if(p[s].find(v[j]) != p[s].end() || visit[v[j]]){
					v[n++] = v[j];
					continue;
				}
				q.push(v[j]);
				visit[v[j]]++;
				if(ans[s] + B < ans[v[j]])
					ans[v[j]] = ans[s] + B;
			}
			v.resize(n);
		}
	}
}
int main(){
	int M, max;
	scanf("%d%d%d%d", &N, &M, &A, &B);
	max = (A > B) ? A : B;
	for(int i = 1; i < N; i++)  ans[i] = max;

	int u, v;
	for(int i = 0; i < M; i++){
		scanf("%d%d", &u, &v);
		p[u-1].insert(v-1);
		p[v-1].insert(u-1);
	} 
	if(A > B)  bfsB();
	else if(B > A)  bfsA();
	else
		for(int i = 1; i < N; i++)  ans[i] = A;

	for(int i = 0; i < N; i++)
		printf("%d%c", ans[i], i == N-1 ? '\n' : ' ');

	return 0;
}