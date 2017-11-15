#include <stdio.h>
#define MaxN 100005
int min(int a, int b){return (a < b ? a : b);}
int main(){
	int N, M ,K;
	scanf("%d%d%d", &N, &M, &K);
	int p[MaxN] = {0}, child[MaxN] = {0}, k[MaxN];
	for(int i = 0; i <= N; i++)  k[i] = K;
	for(int i = 2; i <= N; i++){
		scanf("%d", &p[i]);
		child[p[i]]++;
	}
	int in, ban[MaxN] = {0}, nosuit[MaxN] = {0};
	for(int i = 0; i < M; i++){
		scanf("%d", &in);
		ban[in] = 1;
	}
	for(int i = 1; i <= N; i++)
		if(ban[p[i]])  nosuit[i] = nosuit[p[i]]+1;
	int set[MaxN] = {0}, ans = 0, solution = 1;
	for(int i = N; i > 0; i--){
		if(nosuit[i] + ban[i] > K){
			solution = 0;
			break;
		} 
		if(set[i])  continue;
		int now = p[i];
		set[i] = 1;
		ans++;
		if(nosuit[i] >= k[i])  k[i] = 0;
		for(int j = k[i]-1; j >= 0; j--){
			k[now] = min(j, k[now]);
			if(!now)  break;
			if(nosuit[now] >= j){
				k[now] = 0;
				ans--;
				break;
			}
			if(child[now] > 1){
				k[now] = min(j, k[now]);
				ans--;
				break;
			}
			set[now] = 1;
			now = p[now];
		}
	}
	if(solution == 0 || ban[1])  printf("-1\n");
	else  printf("%d\n", ans);

	return 0;
}