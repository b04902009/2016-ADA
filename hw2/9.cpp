#include <iostream>
using namespace std;
int min(int a, int b){return (a < b ? a : b);}
long long int F[150005] = {0}, sum[150005], value[150005];
int main()
{
    int N, V, n, p, s, begin, end;
    cin >> N >> V;
    for(int i = 0; i < N; i++){
        cin >> n >> p >> s;
        n = min(n, V/p);
        for(int j = 0; j < p; j++){
            begin = 1;
            end = 0;
            for(int k = 0; k <= (V-j)/p; k++){
                long long int temp = F[j+k*p] - k * s;
                while(begin <= end && value[end] <= temp)  end--;
                sum[++end] = k;
                value[end] = temp;
                if(k > sum[begin] + n)  begin++;
                F[j+k*p] = value[begin] + k * s;
            }
        }
    }
    cout << F[V] << endl;
    return 0;
}