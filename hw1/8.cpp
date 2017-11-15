#include <iostream>
#include <vector>
using namespace std;
#define mod_n 1000000007
#define MAX_n 131075
typedef long long int lli;
int N, ptr = 0, k = 2;
lli n[MAX_n] = {0};
vector<lli> add_poly(vector<lli> ans, vector<lli> addendum, int shift){
	for(int i = 0; i < addendum.size(); i++){
		ans[i+shift] += addendum[i];
		if(ans[i+shift] >= mod_n)  ans[i+shift] -= mod_n;
	}
	return ans;
}
vector<lli> subtract_poly(vector<lli> ans, vector<lli> subtrahend, int shift){
	for(int i = 0; i < subtrahend.size(); i++){
		ans[i+shift] -= subtrahend[i];
		if(ans[i+shift] < 0)  ans[i+shift] += mod_n;
	}
	return ans;
}
vector<lli> multiply_poly(vector<lli> a, vector<lli> b){
	vector<lli> ans(a.size()*2);
	int max_num = max(a.size(), b.size());
	if(max_num < 400){
		for(int i = 0; i < a.size(); i++){     //ans的次數
			for(int j = 0; j < b.size(); j++){   //j為a的次數, i-j為b的次數
				ans[i+j] += a[i] * b[j];
				ans[i+j] %= mod_n;
			}
		}
		return ans;
	}

	int a2_size = a.size()/2, b2_size = b.size()/2;
	vector<lli> a2(a.begin(), a.begin()+a2_size);
	vector<lli> a1(a.begin()+a2_size, a.end());
	vector<lli> b2(b.begin(), b.begin()+b2_size);;
	vector<lli> b1(b.begin()+b2_size, b.end());;
	vector<lli> a1_b1, a2_b2, a12_b12;

	a1_b1 = multiply_poly(a1, b1);
	ans = add_poly(ans, a1_b1, a2.size()+b2.size());

	a2_b2 = multiply_poly(a2, b2);
	ans = add_poly(ans, a2_b2, 0);
	a1 = add_poly(a1, a2, 0);
	b1 = add_poly(b1, b2, 0);

	a12_b12 = multiply_poly(a1, b1);
	a12_b12 = subtract_poly(a12_b12, a1_b1, 0);
	a12_b12 = subtract_poly(a12_b12, a2_b2, 0);
	ans = add_poly(ans, a12_b12, a2.size());

	return ans;
}
vector<lli> factor(int t){
	if(t == 1){  
		vector<lli> tmp(2);
		tmp[0] = n[ptr];
		tmp[1] = 1;
		ptr++;
		return tmp;
	}
	return multiply_poly(factor(t/2), factor(t/2));
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++)  cin >> n[i];

	vector<lli> ans;
	while(k < N)  k <<= 1;
	ans = factor(k);

	printf("0 ");
	for(int i = k; i >= k-N; i--)  printf("%lld%c", ans[i], i == k-N ? '\n' : ' ');
	return 0;
}