#include <stdio.h>
#include <stdlib.h>
struct Edge{
	int v1, v2, w;
} e[500005];
int p[500005];
int cmp(const void* a, const void* b) {
	Edge *A = (Edge*)a, *B = (Edge*)b;
	return (A->w) > (B->w);
}
int find(int x) {
	return x == p[x] ? x : (p[x] = find(p[x]));
}
void link(int x, int y) {
	p[find(x)] = find(y);
}
int main(){
	int V, E, set = 0;
	long long int ans = 0;
	scanf("%d%d", &V, &E);
	for(int i = 0; i < E; i++){
		scanf("%d%d%d", &e[i].v1, &e[i].v2, &e[i].w);
	}
	qsort(e, E, sizeof(Edge), cmp);
	for(int i = 0; i < V; i++)  p[i] = i;

    for(int i = 0; i < E; i++) {
        if(find(e[i].v1) == find(e[i].v2)) {
        	if(!(set++) || e[i].w < 0){
        		ans += e[i].w;
        	}
        	continue;
        }
        link(e[i].v1, e[i].v2);
        ans += e[i].w;
    }

	printf("%lld\n", ans);

	return 0;
}