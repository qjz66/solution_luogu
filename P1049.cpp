#include "bits/stdc++.h"

using namespace std;

int main(){
    int v,n;//v为最大体积，n为数量
    cin >> v >> n;
    int vs[n + 1], dp[v + 1];
    memset(dp,0,sizeof dp);
    for(int i = 1;i <= n;i++)
        cin >> vs[i];
    for(int i = 1;i <= n;i++)
        for(int j = v;j >= vs[i];j--){
            dp[j] = max(dp[j], dp[j - vs[i]] + vs[i]);
        }
    cout << v - dp[v];
}