#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	long int max = a[0], temp = 0;
	for(int i = 0; i < n; i++){
		temp += a[i];
		if(temp >= max)	max = temp;
		if(temp < 0)  temp = 0;
	}

	cout << max << endl;

	return 0;
}