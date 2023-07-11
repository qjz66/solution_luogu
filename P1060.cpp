#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,m; //n为总钱数 m为数量
    cin >> n >> m;
    int dp[n + 1], v[m + 1], w[m + 1], x[m + 1];
    for(int i = 1;i <= m;i++){
        cin >> v[i] >> w[i];
        x[i] = v[i] * w[i];
    }
    memset(dp, 0, sizeof dp);
    for(int i = 1;i <= m;i++)
        for(int j = n;j >= v[i];j--)
            dp[j] = max(dp[j], dp[j - v[i]] + x[i]);
    cout << dp[n];
}