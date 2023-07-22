#include "bits/stdc++.h"

using namespace std;

#define INF 0x3f3f3f3f

int main(){
    int m, n;
    int ans = INF;
    cin >> m >> n;
    int a[n][m], dp[n][m];
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> a[i][j];
    for(int j = 0;j < m;j++)
        for(int i = 0;i < n;i++)
            dp[i][j] = min(dp[i][j - 1], i == 0 ? dp[n - 1][j - 1] : dp[i - 1][j - 1]) + a[i][j];
    for(int i = 0;i < n;i++)
        ans = min(dp[i][m - 1], ans);
    cout << ans;
}