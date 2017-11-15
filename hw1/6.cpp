#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, step = 0;
char source[15], buffer[15], destination[15];

void Hanoi(int s, int e, char* src, char* buf, char* dst){
	if(s == e){
		step++;
		printf("%d: move #%d disk from rod %s to rod %s\n", step, s, src, dst);
		return;
	}
	Hanoi(s, e-1, src, dst, buf);
	Hanoi(e, e, src, buf, dst);
	Hanoi(s, e-1, buf, src, dst);
}
int main(){
	scanf("%d", &n);
	scanf("%s%s%s", source, buffer, destination);
	printf("%d\n", (int)pow(2, n)-1);
	Hanoi(1, n, source, buffer, destination);

	return 0;
}