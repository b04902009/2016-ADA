#include <iostream>
using namespace std;
int MAX(int a, int b){return a > b ? a: b;}
int dp[1000][50];
int main(){
    int N, K; //N: number of pokemons, K: number of pokemon balls
    cin >> N >> K;
    for(int k = 1; k <= K; k++)
        for(int n = 1; n <= N; n++)
            if(k == 1 || n == 1)  dp[n][k] = n;
            else{
                dp[n][k] = 21474647;
                for(int i = 1; i <= n/2; i++){
                    int temp = MAX(dp[i-1][k-1], dp[n-i][k]) + 1;
                    if(temp < dp[n][k])  dp[n][k] = temp;
                }
            }
    cout << dp[N][K] << endl;
    return 0;
}