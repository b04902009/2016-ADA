#include <iostream>
#include <cstdio>
using namespace std;
long long int N, K;
long long int numerator = 0;
struct Trie{
	Trie *l, *r;
	long long int n;
	Trie(){
		n = 0;
		l = NULL;
		r = NULL;
	}
};
Trie *root = (Trie*)malloc(sizeof(Trie));

void count(Trie *node){
	if(node == NULL)  return;
	if(node->l != NULL)  count(node->l);
	numerator += (node->n) * ((node->n)-1) / 2;
	if(node->r != NULL)  count(node->r);
}

int main(){
	scanf("%lld%lld", &N, &K);
	char s[K+3];
	for(int i = 0; i < N; i++){
		scanf("%s", s);
		Trie *p = root;
		for(int j = 0; j < K; j++){
			if(s[j] == 'C'){
				if(p->l == NULL)
					p->l = (Trie*)malloc(sizeof(Trie));
				p = p->l;
				p->n++;
			}
			else{
				if(p->r == NULL)
					p->r = (Trie*)malloc(sizeof(Trie));
				p = p->r;
				p->n++;
			}
		}
	}
	count(root);
	printf("%.10Lf\n", (long double)numerator / (long double)(N*(N-1)/2));
		
	return 0;
}
/*
3 3
CCC
CCP
PCP
0.6666666667
*/
/*
3 4
PPCP
PPCC
CPCC
*/

/*
8 3
CCC
CCP
CPC
CPP
PCC
PCP
PPC
PPP
0.5714285714
*/